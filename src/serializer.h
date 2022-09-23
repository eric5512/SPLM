#pragma once

#include "data_types/part.h"
#include "data_types/parts.h"

#define PART_SEPARATOR '&'
#define FIELD_SEPARATOR '@'

class Serializer {
public:
    static std::string serialize(Parts&);
    static void unserialize(const std::string&, Parts&);
private:
    static std::string serialize(const Part&);
    static Part unserialize(const std::string&);
};
