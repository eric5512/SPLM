#include "parts.h"

bool Parts::partExists(const std::string& name) const {
    return parts.contains(Part(name));
}

std::unordered_set<Part,HashPart> Parts::getParts() const {
    return parts;
}

void Parts::addPart(const Part& part) {
    parts.emplace(part);
}

Part Parts::getPartByName(const std::string& name) const {
    return *parts.find(Part(name));
}
