#include "parser.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool parse_cnf(const std::string &filename, CNF &cnf, int &num_vars) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return false;
    }
    std::string line;
    num_vars = 0;
    while (std::getline(in, line)) {
        if (line.empty() || line[0] == 'c') continue;
        if (line[0] == 'p') {
            std::istringstream iss(line);
            std::string tmp; int vars,clauses;
            iss >> tmp >> tmp >> vars >> clauses;
            num_vars = vars;
            cnf.reserve(clauses);
        } else {
            std::istringstream iss(line);
            Clause clause;
            int lit;
            while (iss >> lit, lit != 0) {
                clause.push_back(lit);
            }
            if (!clause.empty())
                cnf.push_back(clause);
        }
    }
    return true;
}
