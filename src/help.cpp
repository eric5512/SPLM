#include "help.h"
#include <iostream>

void printUsage() {
    const std::string usage = R"raw(Usage goes here)raw";
    std::cout << usage; 
}

void printCommandHelp(std::string command) {
    if (command == "collect") {

    } else if (command == "upgrade") {

    } else {
        std::cout << "Command uknown\n";
    }
}