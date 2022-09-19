#pragma once

#include "../data_types/parts.h"
#include "../command.h"
#include <string>
#include <unordered_map>

class InitCommand : public Command {
public:
    InitCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
private:
    void checkParts(const Parts&);
    void checkPart(const Part&);
};

