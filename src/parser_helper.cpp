#include "parser_helper.h"

#include <iostream>

#include "serializer.h"
#include "file_helper.h"

void ParserHelper::parseInitFile(const std::string& filepath, Parts& parts) {
    std::vector<std::string> lines;
    FileHelper::readFile(filepath, lines);

    if (lines.size() <= 1) {
        throw new std::runtime_error("Empty init file");
    }

    std::string header = lines[0];

    for (int i = 1; i < lines.size(); i++) return;
}

bool ParserHelper::containsAnyChar(const std::string& str, const std::vector<char>& vec) {
    for (const char chr : str) {
        if (inVector(vec, chr)) return true;
    }
    
    return false;
}

void ParserHelper::serializeParts(const Parts& parts, const std::string& filename) {
    

    Serializer::serialize(parts);
}

void ParserHelper::unserializeParts(Parts& parts, const std::string& filename) {

}


std::string ParserHelper::filterChars(const std::string& str, const std::vector<char>& vec) {
    std::string filtered;

    for (const char chr : str) {
        if (!inVector(vec, chr))
            filtered += chr;
    }

    return filtered;
}

bool ParserHelper::inVector(const auto&vec, const auto& elem) {
    for (const auto& match : vec) {
        if (match == elem) {
            return true;
        }
    }

    return false;
}