#include "init.h"

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <fstream>

#include "../parser_helper.h"
#include "../file_helper.h"

#include "../data_types/folder_tree.h"

void InitCommand::execute() {
    try {
        FileHelper::createFolder(FileHelper::composePath(".", ".splm"));
    } catch (const std::runtime_error &error) {
        throw std::runtime_error("SPLM could not create the .splm folder \"" + std::string(error.what()) + "\"");
    }
        

    if (!FileHelper::fileExists(INIT_FILE)) {
        throw std::runtime_error("parts file not found in the current directory");
    }

    Parts parts;
    Meta meta_info;
    ParserHelper::parseInitFile(parts, meta_info);
    checkParts(parts);
    ParserHelper::serializeParts(parts);
    ParserHelper::persistMetaFile(meta_info);
    createFolderStructures(parts);
}

std::string InitCommand::usage() {
    return R"raw()raw";
}

void InitCommand::checkParts(Parts& parts) {
    for (const auto& pair : parts.getParts()) {
        checkPart(pair.second);
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

void InitCommand::createFolderStructures(Parts& parts) {
    FolderTree tree = FolderTree(parts);

    tree.createFolderRec();
}