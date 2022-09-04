#pragma once

#include "command.h"

class CommandBuilder {
public:
    static Command* build_command(const std::string&, const std::vector<std::string>&);
};
