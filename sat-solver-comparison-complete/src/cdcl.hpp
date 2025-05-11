#pragma once
#include "solver.hpp"
class CDCL : public Solver {
public:
    bool solve(const CNF& cnf) override;
};