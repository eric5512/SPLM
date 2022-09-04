#include "command_builder.h"

#include "commands/init.h"
#include "commands/add.h"
#include "commands/collect.h"
#include "commands/iterate.h"
#include "commands/remove.h"
#include "commands/revert.h"
#include "commands/revise.h"

Command* CommandBuilder::build_command(const std::string& command, const std::vector<std::string>& modifiers) {
    if (command == "init") {
        return new InitCommand(modifiers);
    } else if (command == "add") {
        return new AddCommand(modifiers);
    } else if (command == "collect") {
        return new CollectCommand(modifiers);
    } else if (command == "iterate") {
        return new IterateCommand(modifiers);
    } else if (command == "remove") {
        return new RemoveCommand(modifiers);
    } else if (command == "revert") {
        return new RevertCommand(modifiers);
    } else if (command == "revise") {
        return new ReviseCommand(modifiers);
    } else {
        return NULL;
    }
}