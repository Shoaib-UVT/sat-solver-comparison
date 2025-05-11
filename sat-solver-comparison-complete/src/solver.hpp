#pragma once
#include "cnf.hpp"
class Solver {
public:
    virtual bool solve(const CNF& cnf) = 0;
    virtual ~Solver() {}
};
