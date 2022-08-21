#pragma once

#include <string>
#include <vector>

class Command {
protected:
    std::vector<std::string> modifiers;
public:
    Command(const std::vector<std::string>& mod) : modifiers(mod) {};
    virtual void execute() = 0;
    virtual std::string usage() = 0;
};