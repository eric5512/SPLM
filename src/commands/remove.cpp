#include "remove.h"
#include "../parser_helper.h"
#include "../file_helper.h"
#include <iostream>

void RemoveCommand::execute() {
    std::string partName = modifiers[0];

    Parts parts = Parts();
    ParserHelper::unserializeParts(parts);

    if (!parts.removePart(partName)) throw std::runtime_error("Part with name " + partName + " is not present");

    

    ParserHelper::serializeParts(parts);
}

std::string RemoveCommand::usage() {
    return R"raw()raw";
}