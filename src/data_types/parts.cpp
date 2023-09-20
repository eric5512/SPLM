#include "parts.h"

bool Parts::partExists(const std::string& name) const {
    return parts.find(name) != parts.end();
}

std::unordered_map<std::string, Part>& Parts::getParts() {
    return parts;
}

void Parts::addPart(const std::string& name, const Part &part) {
    parts.insert_or_assign(name, part);
}

Part& Parts::getPartByName(const std::string& name) {
    return parts.at(name);
}

bool Parts::removePart(const std::string& name) {
    if (!partExists(name)) return false;

    parts.erase(name);
    return true;
}