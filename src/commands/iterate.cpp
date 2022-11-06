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

    Meta meta_inf = Meta();
    ParserHelper::parseMetaFile(meta_inf);

    for (std::string modifier : modifiers) {
        Part part = parts.getPartByName(modifier);

        try {
            ParserHelper::savePartVersion(part);
        } catch (const std::runtime_error& err) {
            throw std::runtime_error("Could not copy the part \"" + std::string(err.what()) + '"');
        }

        part.iterate();

        meta_inf.getGroup(parts.getPartByName(modifier).getGroup()).iterate();

        meta_inf.iterate();
    }

    ParserHelper::persistMetaFile(meta_inf);
    ParserHelper::serializeParts(parts);
}

std::string IterateCommand::usage() {
    return R"raw()raw";
}