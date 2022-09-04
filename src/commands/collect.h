#pragma once

#include "../command.h"

class CollectCommand : public Command {
public:
    CollectCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
};