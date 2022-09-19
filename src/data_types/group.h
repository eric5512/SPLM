#pragma once

#include <string>

class Group {
private:
    std::string name;
    int revision;
    int iteration;
public:
    Group(std::string c_name) : name(c_name), revision(1), iteration(0) {}
    Group(std::string c_name, int c_revision, int c_iteration) : name(c_name), revision(c_revision), iteration(c_iteration) {}

};