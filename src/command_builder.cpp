#include "command_builder.h"

Command* CommandBuilder::build_command(const std::string& command, const std::vector<std::string>& modifiers) {
    if (command == "init") {
        return new InitCommand(modifiers);
    } else if (command == "") {
        return NULL;
    } else {
        return NULL;
    }
}