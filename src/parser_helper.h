#pragma once

#include "data_types/parts.h"
#include <vector>

#define SERIALIZED_PARTS_FILE "serialized.splm"
#define METAINF_FILE "meta.splm"
#define FOLDER_NAME ".splm"

class ParserHelper {
public:
    static std::string parseInitFile(const std::string&, Parts&);
    static bool containsAnyChar(const std::string &, const std::vector<char>&);
    static void serializeParts(const Parts&, const std::string&);
    static void unserializeParts(Parts&, const std::string&);
    static std::vector<std::string> splitString(const std::string&, char);

private:
    static std::string filterChars(const std::string&, const std::vector<char>&);
    static bool inVector(const auto&, const auto&);
};

