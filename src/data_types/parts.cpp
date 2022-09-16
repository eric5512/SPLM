#include "parts.h"

bool Parts::partExists(const Part& part) const {
    for (const auto &part_iter : parts) {
        if (part == part_iter) return true;
    }

    return false;
}

std::unordered_set<Part,HashPart> Parts::getParts() const {
    return parts;
}

void Parts::addPart(const Part& part) {
    parts.emplace(part);
}
