#pragma once

#include <unordered_map>
#include <string>

#include "part.h"

class Parts {
private:
    std::unordered_map<std::string, Part&> parts;
public:
    bool partExists(const std::string&) const;
    std::unordered_map<std::string, Part&> getParts() const;
    Part& getPartByName(const std::string&) const;
    void addPart(const std::string&, Part);
};