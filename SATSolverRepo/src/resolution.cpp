#include "parser.hpp"
#include <set>
#include <vector>
#include <algorithm>

bool solve_resolution(CNF cnf, int num_vars) {
    std::set<Clause> clauses(cnf.begin(), cnf.end());
    bool added = true;
    while (added) {
        added = false;
        auto cur = std::vector<Clause>(clauses.begin(), clauses.end());
        for (size_t i=0; i<cur.size(); ++i) {
            for (size_t j=i+1; j<cur.size(); ++j) {
                for (int l1 : cur[i]) {
                    for (int l2 : cur[j]) {
                        if (l1 + l2 == 0) {
                            Clause r;
                            for (int x : cur[i]) if (x!=l1) r.push_back(x);
                            for (int x : cur[j]) if (x!=l2) r.push_back(x);
                            std::sort(r.begin(), r.end());
                            if (r.empty()) return false;
                            if (!clauses.count(r)) {
                                clauses.insert(r);
                                added = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}
