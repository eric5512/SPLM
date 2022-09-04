#pragma once

#include "../command.h"

class RemoveCommand : public Command {
public:
    RemoveCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
};