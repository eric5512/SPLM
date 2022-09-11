#include <iostream>
#include <vector>
#include "help.h"
#include "command.h"
#include "command_builder.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printUsage();
        return 0;
    }

    std::string command = argv[1];

    std::vector<std::string> modifiers;

    for (size_t i = 2; i < (size_t) argc; i++){
        modifiers.push_back(argv[i]);
    }
    
    Command* obj_command = CommandBuilder::build_command(command, modifiers);

    if (obj_command == NULL) {
        std::cout << "splm: Invalid command" << std::endl;
        printUsage();
        return 0;
    }

    try {
        obj_command->execute();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
