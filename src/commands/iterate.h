#pragma once

#include "../command.h"

class IterateCommand : public Command {
public:
    IterateCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
};