#pragma once

#include "data_types/parts.h"
#include <vector>

class ParserHelper {
public:
    static void parseInitFile(const std::string&, Parts&);
    static bool containsAnyChar(const std::string &, const std::vector<char>&);
    static void serializeParts(const Parts&, const std::string&);
    static void unserializeParts(Parts&, const std::string&);

private:
    static std::string filterChars(const std::string&, const std::vector<char>&);
    static bool inVector(const auto&vec, const auto& elem);
};

