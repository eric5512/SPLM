#include "parts.h"

bool Parts::partExists(const std::string& name) const {
    return parts.find(name) != parts.end();
}

std::unordered_map<std::string, Part&> Parts::getParts() const {
    return parts;
}

void Parts::addPart(const std::string& name, Part part) {
    parts.insert_or_assign(name, part);
}

Part& Parts::getPartByName(const std::string& name) const {
    return parts.at(name);
}
