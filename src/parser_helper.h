#pragma once

#include "data_types/parts.h"
#include "data_types/meta.h"
#include <vector>

#define SERIALIZED_PARTS_FILE "serialized.splm"
#define INIT_FILE "init.splm"
#define METAINF_FILE "meta.splm"
#define FOLDER_NAME ".splm"

class ParserHelper {
public:
    static void parseInitFile(Parts&, Meta&);
    static void parseMetaFile(Meta&);
    static void persistMetaFile(const Meta&);
    static bool containsAnyChar(const std::string &, const std::vector<char>&);
    static void serializeParts(Parts&);
    static void unserializeParts(Parts&);
    static std::vector<std::string> splitString(const std::string&, char);

private:
    static std::string filterChars(const std::string&, const std::vector<char>&);
    static bool inVector(const auto&, const auto&);
};

