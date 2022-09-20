#pragma once

#include <unordered_set>

#include "group.h"

class Meta {
private:
    std::string name;
    int revision;
    int iteration;
    std::unordered_map<std::string, Group&> groups;
public:
    Meta(std::string c_name) : name(c_name), revision(1), iteration(0), groups() {}
    Meta() : name(""), revision(1), iteration(0), groups() {}
    bool groupExists(std::string name) const { return groups.find(name) != groups.end(); }
    std::string getName() const { return name; }
    int getRevision() const { return revision; }
    int getIteration() const { return iteration; }
    void setName(std::string c_name) { name = c_name; }
    void setRevision(int c_revision) { revision = c_revision; }
    void setIteration(int c_iteration) { iteration = c_iteration; }
    void addGroup(const Group& group) { groups.insert_or_assign(group.getName(), group); }
    std::unordered_map<std::string, Group&> getGroups() const { return groups; }
    Group& getGroup(std::string name) { return groups.at(name); }
    int iterate() { return ++iteration; }
    int revise() { return ++revision; }
};

