#include "info.h"

#include "../file_helper.h"
#include "../parser_helper.h"

void InfoCommand::execute() {
    std::vector<std::string> lines = std::vector<std::string>();
    FileHelper::readFile(FileHelper::composePath(FOLDER_NAME, METAINF_FILE), lines);
    printf("%s: v%s.%s\n", lines[0].c_str(), lines[1].c_str(), lines[2].c_str());
}

std::string InfoCommand::usage() {
    return R"raw()raw";
}