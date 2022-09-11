#pragma once

#include "data_types/parts.h"
#include <vector>

class ParserHelper {
public:
    static void parseInitFile(std::ifstream &, Parts&);
    static bool containsAnyChar(const std::string &, const std::vector<char>&);
};

