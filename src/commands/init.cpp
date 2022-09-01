#include "init.h"

#include <iostream>
#include "../file_helper.h"
#include <unordered_map>
#include <sstream>
#include <fstream>

void InitCommand::execute() {
    if (!FileHelper::createFolder(".splm")) {
        throw std::runtime_error("splm could not create the .splm folder");
    }

    if (!FileHelper::fileExists(INIT_FILE)) {
        throw std::runtime_error("parts file not found in the current directory");
    }

    std::ifstream file(INIT_FILE);
    Parts parts;
    parseInitFile(file, parts);
    checkInitFile(parts);
    saveExternals(parts);
}

std::string InitCommand::usage() {
    return R"raw()raw";
}

void InitCommand::parseInitFile(std::ifstream& file, Parts& parts) {
    std::unordered_map<std::string, std::string> aux = std::unordered_map<std::string, std::string>();
    std::string line;

    if (std::getline(file, line)) {

    }

    while (std::getline(file, line)) {
        
    }
}

void InitCommand::checkParts(const Parts& parts) {
    throw new std::runtime_error("not implemented");
}

void InitCommand::saveExternals(Parts& parts) {

}