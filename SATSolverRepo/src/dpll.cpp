#include "parser.hpp"
#include <vector>
#include <optional>

bool unit_propagate(CNF &cnf, std::vector<int> &assign) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto it = cnf.begin(); it != cnf.end(); ) {
            if (it->empty()) return false;
            if (it->size() == 1) {
                int lit = (*it)[0], var = abs(lit), val = lit>0;
                assign[var] = val;
                CNF new_cnf;
                for (auto &cl : cnf) {
                    bool sat = false;
                    Clause tmp;
                    for (int l : cl) {
                        if ((l>0 && assign[abs(l)]==1) || (l<0 && assign[abs(l)]==0)) {
                            sat = true; break;
                        }
                        if (assign[abs(l)] == -1) tmp.push_back(l);
                    }
                    if (!sat) new_cnf.push_back(tmp);
                }
                cnf.swap(new_cnf);
                changed = true;
                break;
            } else ++it;
        }
    }
    return true;
}

bool dpll_rec(CNF cnf, std::vector<int> &assign) {
    if (!unit_propagate(cnf, assign)) return false;
    if (cnf.empty()) return true;
    int lit = cnf[0][0], var = abs(lit);
    for (int val : {1,0}) {
        auto asn2 = assign;
        asn2[var] = val;
        CNF cnf2 = cnf;
        cnf2.push_back(Clause{ val? var : -var });
        if (dpll_rec(cnf2, asn2)) {
            assign = asn2;
            return true;
        }
    }
    return false;
}

bool solve_dpll(const CNF &cnf, int num_vars) {
    std::vector<int> assign(num_vars+1, -1);
    return dpll_rec(cnf, assign);
}
