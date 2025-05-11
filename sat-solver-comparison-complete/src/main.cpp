#include <iostream>
#include "parser.hpp"
#include "dp.hpp"
#include "dpll.hpp"
#include "cdcl.hpp"

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: satsolver --solver=dp|dpll|cdcl input.cnf" << std::endl;
        return 1;
    }
    std::string solver_type = argv[1];
    std::string input_file = argv[2];

    parseDIMACS(input_file);
    CNF cnf;

    Solver* solver = nullptr;
    if (solver_type == "--solver=dp") solver = new DP();
    else if (solver_type == "--solver=dpll") solver = new DPLL();
    else if (solver_type == "--solver=cdcl") solver = new CDCL();

    if (solver) {
        bool result = solver->solve(cnf);
        std::cout << (result ? "SAT" : "UNSAT") << std::endl;
        delete solver;
    } else {
        std::cerr << "Invalid solver type." << std::endl;
    }
    return 0;
}
