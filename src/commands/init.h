#include "../command.h"

class InitCommand : public Command {
public:
    InitCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
};