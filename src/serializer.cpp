#include "serializer.h"

#include "parser_helper.h"

std::string Serializer::serialize(const Parts& parts) {
    std::string aux = "";

    for (const auto& part : parts.getParts()) {
        aux += serialize(part) + PART_SEPARATOR;
    }

    return aux;
}


std::string Serializer::serialize(const Part& part) {
    std::string aux = "";

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
    for (const std::string& part : ParserHelper::splitString(string, PART_SEPARATOR)) {
        parts.addPart(unserialize(part));
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