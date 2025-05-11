#pragma once
#include "cnf.hpp"
class Heuristic {
public:
    virtual int select(const CNF& cnf) = 0;
    virtual void notifyConflict() {}
    virtual ~Heuristic() {}
};
