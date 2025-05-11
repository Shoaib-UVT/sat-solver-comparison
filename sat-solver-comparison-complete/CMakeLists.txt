cmake_minimum_required(VERSION 3.10)
project(SATSolverComparison)
set(CMAKE_CXX_STANDARD 17)
add_executable(satsolver
    src/main.cpp
    src/parser.cpp
    src/dp.cpp
    src/dpll.cpp
    src/cdcl.cpp
    src/heuristics.cpp
)
