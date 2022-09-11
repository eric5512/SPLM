#include "serializer.h"

const char* Serializer::serialize(const Parts& parts) {
    std::string aux = "";

    for (const auto& part : parts.getParts()) {
        aux += serialize(part) + PART_SEPARATOR;
    }

    return aux.c_str();
}


std::string Serializer::serialize(const Part& part) {
    std::string aux = "";

    aux += part.getName() + FIELD_SEPARATOR;
    aux += part.getPath() + FIELD_SEPARATOR;
    aux += part.getGroup() + FIELD_SEPARATOR;
    aux += std::string(part.isExternal() ? "1":"0") + FIELD_SEPARATOR;
    aux += part.getExternalPath();

    return aux;
}