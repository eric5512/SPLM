#include "parser_helper.h"

#include <iostream>

#include "serializer.h"
#include "file_helper.h"

std::string ParserHelper::parseInitFile(const std::string& filepath, Parts& parts, std::vector<std::string>& groups) {
    std::vector<std::string> lines;
    size_t pos;
    FileHelper::readFile(filepath, lines);

    if (lines.size() <= 1) {
        throw std::runtime_error("Empty init file");
    }

    std::string header = lines[0].substr(0, lines[0].find(':'));
    std::string group = "all";
    groups.emplace_back(group);

    for (int i = 1; i < (int) lines.size(); i++) {
        std::string line = lines[i];
        line = line.substr(line.find_first_not_of(' '));
        if ((pos = line.find(':')) != std::string::npos) {
            group = line.substr(0, pos);
            groups.emplace_back(group);
        } else {
            Part part = Part();
            std::string token;

            part.setGroup(group);

            if ((pos = line.find(';')) != std::string::npos) {
                token = line.substr(0, pos);
                part.setName(token);
                line.erase(0, pos + 1);
            } else {
                throw std::runtime_error("Parsing field of part");
            }

            if ((pos = line.find(';')) != std::string::npos) {
                token = line.substr(0, pos);
                part.setPath(token);
                line.erase(0, pos + 1);
            } else {
                throw std::runtime_error("Parsing field of part");
            }
            
            if ((pos = line.find(';')) != std::string::npos) {
                token = line.substr(0, pos);
                part.setExternal(true);
                part.setExternalPath(token);
                line.erase(0, pos + 1);
            } else {
                part.setExternal(false);
            }

            parts.addPart(part);
        }
    }

    return header;

}

bool ParserHelper::containsAnyChar(const std::string& str, const std::vector<char>& vec) {
    for (const char chr : str) {
        if (inVector(vec, chr)) return true;
    }
    
    return false;
}

void ParserHelper::serializeParts(const Parts& parts, const std::string& filename) {
    std::string ser = Serializer::serialize(parts);
    FileHelper::writeFile(FileHelper::composePath(std::string(FOLDER_NAME), filename), std::string(ser));
}

void ParserHelper::unserializeParts(Parts& parts, const std::string& filename) {
    std::string ser = FileHelper::readFile(filename);
    Serializer::unserialize(ser, parts);
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

std::vector<std::string> ParserHelper::splitString(const std::string& string, char separator) {
    std::vector<std::string> ret = std::vector<std::string>();

    int b = 0;
    for (size_t i = 0; i < string.length(); i++) {
        if (string[i] == separator) {
            ret.emplace_back(string.substr(b, i-b));
            b = i;
        }
    }
    
    return ret;
}