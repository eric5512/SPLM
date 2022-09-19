#include "iterate.h"

#include "../parser_helper.h"
#include "../file_helper.h"

#include <stdexcept>

void IterateCommand::execute() {
    if (modifiers.size() < 1) throw std::runtime_error("Bad arguments for Iterate command");
    
    Parts parts = Parts();

    ParserHelper::unserializeParts(parts);

    for (std::string modifier : modifiers) {
        if (!parts.partExists(modifier)) throw std::runtime_error("Invalid part " + modifier);
    }

    std::vector<std::string> groups = std::vector<std::string>();
    FileHelper::readFile(FileHelper::composePath(FOLDER_NAME, METAINF_FILE), groups);

    for (std::string modifier : modifiers) {
        Part part = parts.getPartByName(modifier);

        part.setIteration(part.getIteration() + 1);
    }


    ParserHelper::serializeParts(parts);
}

std::string IterateCommand::usage() {
    return R"raw()raw";
}