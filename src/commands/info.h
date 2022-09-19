#pragma once

#include "../command.h"

class InfoCommand : public Command {
public:
    InfoCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
};