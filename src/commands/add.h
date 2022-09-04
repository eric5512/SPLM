#pragma once

#include "../command.h"

class AddCommand : public Command {
public:
    AddCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
};