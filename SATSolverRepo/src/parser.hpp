#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>

using Clause = std::vector<int>;
using CNF    = std::vector<Clause>;

// Parse a DIMACS CNF file into a CNF structure.
// Returns false on I/O error.
bool parse_cnf(const std::string &filename, CNF &cnf, int &num_vars);

#endif // PARSER_HPP
