#include "parser_helper.h"

#include <iostream>

#include "serializer.h"
#include "file_helper.h"

void ParserHelper::parseInitFile(Parts& parts, Meta& meta_inf) {
    std::vector<std::string> lines;
    size_t pos;

    FileHelper::readFile(INIT_FILE, lines);

    if (lines.size() <= 1) {
        throw std::runtime_error("empty init file");
    }

    std::string header = lines[0].substr(0, lines[0].find(':'));
    meta_inf.setName(header);
    std::string group = "all";
    meta_inf.addGroup(Group(group));

    for (int i = 1; i < (int) lines.size(); i++) {
        std::string line = lines[i];
        line = line.substr(line.find_first_not_of(' '));
        if ((pos = line.find(':')) != std::string::npos) {
            group = line.substr(0, pos);
            meta_inf.addGroup(Group(group));
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
}

void ParserHelper::parseMetaFile(Meta& meta_inf) {
    std::vector<std::string> lines;
    FileHelper::readFile(FileHelper::composePath(FOLDER_NAME, METAINF_FILE), lines);

    if (lines.size() <= 1) {
        throw std::runtime_error("empty meta file");
    }

    meta_inf.setName(lines[0]);
    meta_inf.setRevision(std::stoi(lines[1]));
    meta_inf.setIteration(std::stoi(lines[2]));

    for (size_t i = 3; i < lines.size() && lines[i] != ""; i += 3) {
        meta_inf.addGroup(Group(lines[i], std::stoi(lines[i+1]), std::stoi(lines[i+2])));
    }
}

void ParserHelper::persistMetaFile(const Meta& meta_inf) {
    FileHelper::writeFile(FileHelper::composePath(FOLDER_NAME, METAINF_FILE), meta_inf.getName() + '\n' + std::to_string(meta_inf.getRevision()) + '\n' + std::to_string(meta_inf.getIteration()) +'\n');
    for (const auto& group : meta_inf.getGroups())
        FileHelper::writeFile(FileHelper::composePath(FOLDER_NAME, METAINF_FILE), group.getName() + '\n' + std::to_string(group.getRevision()) + '\n' + std::to_string(group.getIteration()) +'\n', true);
}

bool ParserHelper::containsAnyChar(const std::string& str, const std::vector<char>& vec) {
    for (const char chr : str) {
        if (inVector(vec, chr)) return true;
    }
    
    return false;
}

void ParserHelper::serializeParts(const Parts& parts) {
    std::string ser = Serializer::serialize(parts);
    FileHelper::writeFile(FileHelper::composePath(std::string(FOLDER_NAME), SERIALIZED_PARTS_FILE), std::string(ser));
}

void ParserHelper::unserializeParts(Parts& parts) {
    std::string ser = FileHelper::readFile(FileHelper::composePath(std::string(FOLDER_NAME), SERIALIZED_PARTS_FILE));
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
            b = i + 1;
            if (i == string.length() - 1)
                ret.emplace_back(""); 
        }
    }
    
    return ret;
}