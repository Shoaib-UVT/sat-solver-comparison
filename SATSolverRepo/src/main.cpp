#include "parser.hpp"
#include <iostream>
#include <chrono>

extern bool solve_dpll(const CNF&, int);
extern bool solve_dp(CNF, int);
extern bool solve_resolution(CNF, int);

int main(int argc, char** argv) {
    if (argc<3) { std::cerr<<"Usage: satsolver <dpll|dp|resolution> <input.cnf>\n"; return 1; }
    std::string m=argv[1], f=argv[2];
    CNF cnf; int num_vars;
    if (!parse_cnf(f, cnf, num_vars)) return 1;
    auto t1=std::chrono::high_resolution_clock::now();
    bool sat = (m=="dpll")? solve_dpll(cnf,num_vars)
               : (m=="dp")? solve_dp(cnf,num_vars)
               : solve_resolution(cnf,num_vars);
    auto t2=std::chrono::high_resolution_clock::now();
    std::cout<<(sat?"SAT":"UNSAT")<<"\n";
    std::cout<<"Time: "<<std::chrono::duration<double>(t2-t1).count()<<"s\n";
    return 0;
}
