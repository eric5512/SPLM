#pragma once

#include "../command.h"

class ReviseCommand : public Command {
public:
    ReviseCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
};
