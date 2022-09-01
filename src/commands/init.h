#include "../command.h"
#include <string>
#include <unordered_map>

#define INIT_FILE "init.splm"

typedef std::unordered_map<std::string, std::unordered_map<std::string, std::string>> Parts;

class InitCommand : public Command {
public:
    InitCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
private:
    void checkParts(const Parts&);
    void saveExternals(Parts&);
};

