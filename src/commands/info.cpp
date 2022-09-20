#include "info.h"

#include "../file_helper.h"
#include "../parser_helper.h"

#include <iostream>

void InfoCommand::execute() {
    Meta meta_inf = Meta();
    Parts parts = Parts();
    ParserHelper::parseMetaFile(meta_inf);
    ParserHelper::unserializeParts(parts);

    if (modifiers.size() == 0) {
        std::cout << meta_inf.getName() << ": v" << meta_inf.getRevision() << "." << meta_inf.getIteration();
        return;
    }

    if (modifiers.size() != 2) {
        throw std::runtime_error("bad argument format");
    }

    if (modifiers[0] == "group") {
        if (modifiers[1] != "all") {
            Group group = meta_inf.getGroup(modifiers[1]);
            std::cout << group.getName() << ": v" << group.getRevision() << "." << group.getIteration() << '\n';
        } else {
            for (const auto& pair : meta_inf.getGroups()) {
                std::cout << pair.second.getName() << ": v" << pair.second.getRevision() << "." << pair.second.getIteration() << '\n';
            }
        }
        return;
    }

    if (modifiers[0] == "part") {
        if (modifiers[1] != "all") {
            Part part = parts.getPartByName(modifiers[1]);
            std::cout << part.getName() << ": v" << part.getRevision() << "." << part.getIteration() << '\n';
        } else {
            for (const auto& pair : parts.getParts()) {
                std::cout << pair.second.getName() << ": v" << pair.second.getRevision() << "." << pair.second.getIteration() << '\n';
            }
        }
        return;
    }

    throw std::runtime_error("unknown modifier " + modifiers[0]);
}

std::string InfoCommand::usage() {
    return R"raw()raw";
}