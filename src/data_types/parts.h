#pragma once

#include <unordered_set>
#include <string>

#include "part.h"

class Parts {
private:
    std::unordered_set<Part,HashPart> parts;
public:
    bool partExists(const std::string&) const;
    std::unordered_set<Part,HashPart> getParts() const;
    Part getPartByName(const std::string&) const;
    void addPart(const Part&);
};
