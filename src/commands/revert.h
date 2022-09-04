#pragma once

#include "../command.h"

class RevertCommand : public Command {
public:
    RevertCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
};