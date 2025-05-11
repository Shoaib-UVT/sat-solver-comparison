#pragma once
#include "solver.hpp"
class DPLL : public Solver {
public:
    bool solve(const CNF& cnf) override;
};