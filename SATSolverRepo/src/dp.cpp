#include "parser.hpp"
#include <set>

bool solve_dp(CNF cnf, int n) {
    if (cnf.empty()) return true;
    for (auto &cl : cnf) if (cl.empty()) return false;
    CNF pos, neg, others;
    for (auto &cl : cnf) {
        bool found = false;
        for (int lit : cl) {
            if (abs(lit) == n) {
                found = true;
                if (lit > 0) pos.push_back(cl);
                else          neg.push_back(cl);
                break;
            }
        }
        if (!found) others.push_back(cl);
    }
    CNF resol;
    for (auto &p : pos) {
        for (auto &q : neg) {
            std::set<int> seen(p.begin(), p.end());
            Clause r;
            bool taut = false;
            for (int lit : q) {
                if (abs(lit) == n) continue;
                if (seen.count(-lit)) { taut = true; break; }
                r.push_back(lit);
            }
            if (taut) continue;
            for (int lit : p) if (abs(lit) != n) r.push_back(lit);
            if (!r.empty()) resol.push_back(r);
        }
    }
    for (auto &o : others) resol.push_back(o);
    return solve_dp(resol, n-1);
}
