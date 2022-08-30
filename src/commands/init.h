#include "../command.h"
#include <string>
#include <unordered_map>

#define PARTS_FILE "parts.splm"

typedef std::unordered_map<std::string, std::unordered_map<std::string, std::string>> Parts;

class InitCommand : public Command {
public:
    InitCommand(const std::vector<std::string>& mod) : Command(mod) {};
    void execute() override;
    std::string usage() override;
private:
    Parts& InitCommand::parsePartsFile(std::ifstream &);
};

