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

    if (!FileHelper::fileExists(PARTS_FILE)) {
        throw std::runtime_error("parts file not found in the current directory");
    }

    std::ifstream file(PARTS_FILE);
    parsePartsFile(file);
}

std::string InitCommand::usage() {
    return R"raw()raw";
}

Parts& InitCommand::parsePartsFile(std::ifstream& file) {
    Parts parts = Parts();
    std::unordered_map<std::string, std::string> aux = std::unordered_map<std::string, std::string>();
    std::string line;

    while (std::getline(file, line)) {
        
    }
    
}