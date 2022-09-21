#pragma once

#include <unordered_map>
#include <string>

#include "part.h"

class Parts {
private:
    std::unordered_map<std::string, Part> parts;
public:
    bool partExists(const std::string&) const;
    auto& getParts() const;
    Part& getPartByName(const std::string&);
    void addPart(const std::string&, const Part&);
};