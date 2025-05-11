# SAT Solver Comparison

This project implements three SAT solvers — DP Resolution, DPLL, and CDCL — in a unified C++ framework.
Each solver can be selected via command-line and benchmarked on random and industrial SAT instances.

## Features

- Shared parser and CNF structure
- Solver selection: `--solver=dp|dpll|cdcl`
- Heuristics: JW, VSIDS, Random
- Benchmarking: runtime, memory, clause growth

## Build

```bash
mkdir build && cd build
cmake ..
make
```

## Run

```bash
./satsolver --solver=cdcl input.cnf
```

## License

This project is for academic use.
