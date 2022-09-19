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
    std::string getName() const { return name; }
    int getRevision() const { return revision; }
    int getIteration() const { return iteration; }
    void getName(std::string c_name) { name = c_name; }
    void getRevision(int c_revision) { revision = c_revision; }
    void getIteration(int c_iteration) { iteration = c_iteration; }
    bool operator==(const Group& part) const { return this->name == part.name; }
};

class HashGroup {
public:
    size_t operator()(const Group& group) const {
        return std::hash<std::string>()(group.getName()); // Name must be unique so its ok only using that for hashing
    }
};

