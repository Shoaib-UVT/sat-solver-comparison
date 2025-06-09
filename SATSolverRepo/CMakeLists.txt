cmake_minimum_required(VERSION 3.10)
project(SATSolverRepo)
set(CMAKE_CXX_STANDARD 17)
include_directories(src)
add_executable(satsolver
    src/main.cpp
    src/parser.cpp
    src/dp.cpp
    src/dpll.cpp
    src/resolution.cpp
)
