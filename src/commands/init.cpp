#include "init.h"

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <fstream>

#include "../parser_helper.h"
#include "../file_helper.h"

void InitCommand::execute() {
    if (!FileHelper::createFolder(".splm")) {
        throw std::runtime_error("splm could not create the .splm folder");
    }

    if (!FileHelper::fileExists(INIT_FILE)) {
        throw std::runtime_error("parts file not found in the current directory");
    }

    Parts parts;
    std::vector<std::string> groups = std::vector<std::string>();
    std::string header = ParserHelper::parseInitFile(INIT_FILE, parts, groups);
    checkParts(parts);
    ParserHelper::serializeParts(parts, SERIALIZED_PARTS_FILE);
    FileHelper::writeFile(FileHelper::composePath(FOLDER_NAME, METAINF_FILE), header + "\n1\n0\n");
    for (std::string group : groups)
        FileHelper::writeFile(FileHelper::composePath(FOLDER_NAME, METAINF_FILE), group + "\n1\n0\n", true);
}

std::string InitCommand::usage() {
    return R"raw()raw";
}

void InitCommand::checkParts(const Parts& parts) {
    for (const auto& part : parts.getParts()) {
        checkPart(part);
    }
}

void InitCommand::checkPart(const Part& part) {
    std::runtime_error err = std::runtime_error("Invalid character in the part " + part.getName());

    if (ParserHelper::containsAnyChar(part.getName(), {'@', '&'})) {
        throw err;
    }

    if (ParserHelper::containsAnyChar(part.getExternalPath(), {'@', '&'})) {
        throw err;
    }

    if (ParserHelper::containsAnyChar(part.getPath(), {'@', '&'})) {
        throw err;
    }

    if (ParserHelper::containsAnyChar(part.getGroup(), {'@', '&'})) {
        throw err;
    }
}