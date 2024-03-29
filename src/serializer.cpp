#include "serializer.h"

#include "parser_helper.h"

#include <stdexcept>

std::string Serializer::serialize(Parts& parts) {
    std::string aux = "";

    for (auto& pair : parts.getParts()) {
        aux += serialize(pair.second) + PART_SEPARATOR;
    }

    return aux;
}


std::string Serializer::serialize(const Part& part) {
    std::string aux = "";
    if (part.verify()) throw std::runtime_error("Invalid character in part");
    aux += part.getName() + FIELD_SEPARATOR;
    aux += part.getPath() + FIELD_SEPARATOR;
    aux += part.getGroup() + FIELD_SEPARATOR;
    aux += std::to_string(part.getRevision()) + FIELD_SEPARATOR;
    aux += std::to_string(part.getIteration()) + FIELD_SEPARATOR;
    aux += std::string(part.isExternal() ? "1":"0") + FIELD_SEPARATOR;
    aux += part.getExternalPath();

    return aux;
}


void Serializer::unserialize(const std::string& string, Parts& parts) {
    for (std::string part : ParserHelper::splitString(string, PART_SEPARATOR)) {
        Part aux = unserialize(part);
        parts.addPart(aux.getName(), aux);
    }
}

Part Serializer::unserialize(const std::string& string) {
    Part ret = Part();
    
    const auto fields = ParserHelper::splitString(string, FIELD_SEPARATOR);
    if (fields.size() == 7) {
        ret.setName(fields[0]);
        ret.setPath(fields[1]);
        ret.setGroup(fields[2]);
        ret.setRevision(std::stoi(fields[3]));
        ret.setIteration(std::stoi(fields[4]));
        ret.setExternal((fields[5][0] == '0') ? 0 : 1);
        ret.setExternalPath(fields[6]);
    } else {
        throw std::runtime_error("error unserializing part");
    }

    return ret;
}