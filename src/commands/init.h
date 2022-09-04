#pragma once

#include "../command.h"
#include <string>
#include <unordered_map>
#include "../data_types/parts.h"

#define INIT_FILE "init.splm"

class InitCommand : public Command {
public:
    InitCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
private:
    void checkParts(const Parts&);
};

