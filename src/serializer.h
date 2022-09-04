#pragma once

#include "data_types/parts.h"

#define PART_SEPARATOR "&"
#define FIELD_SEPARATOR "@"

class Serializer {
public:
    static const char* serialize(const Parts&);
private:
    static std::string serialize(const Part&);
};
