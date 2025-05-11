#pragma once
#include "solver.hpp"
class DP : public Solver {
public:
    bool solve(const CNF& cnf) override;
};