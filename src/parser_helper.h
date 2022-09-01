#pragma once

#include "data_types/parts.h"

class ParserHepler {
public:
    static void parseInitFile(std::ifstream &, Parts&);
};

