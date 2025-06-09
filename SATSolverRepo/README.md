# SATSolverRepo

Educational C++ implementations of three SAT-solving algorithms (Resolution, DP, DPLL)  
and a reproducible Python benchmark harness.

## Requirements

- CMake ≥ 3.10  
- C++17 compiler (g++-12 tested)  
- Python 3

## Build

```bash
git clone https://github.com/your-username/SATSolverRepo.git
cd SATSolverRepo
mkdir build && cd build
cmake .. && make
```

## Run Benchmarks

From the repo root:

```bash
python3 scripts/run_benchmarks.py
```

This generates `benchmark_results.csv` with 3 runs per solver/instance.

## License

MIT © Shoaib Ahmed
