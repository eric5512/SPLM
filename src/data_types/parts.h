#pragma once

#include <unordered_set>
#include <string>

#include "part.h"

class Parts {
private:
    std::unordered_set<Part,HashPart> parts;
public:
    bool partExists(const Part&) const;
    std::unordered_set<Part,HashPart> getParts() const;
    void addPart(const Part&);
};
