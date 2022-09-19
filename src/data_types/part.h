#pragma once

#include <string>

class Part {
private:
    std::string name;
    std::string path;
    std::string externPath;
    std::string group;
    int revision;
    int iteration;
    bool external;
public:
    Part(const std::string& c_name, const std::string& c_path, std::string c_externPath, std::string c_group, bool c_external) : name(c_name), path(c_path), externPath(c_externPath), group(c_group), revision(1), iteration(0), external(c_external) {}
    Part(const std::string& c_name, const std::string& c_path, std::string c_group) : name(c_name), path(c_path), externPath(""), group(c_group), revision(1), iteration(0), external(false) {}
    Part() {}
    std::string getName() const { return name; }
    std::string getPath() const { return path; }
    std::string getExternalPath() const { return externPath; }
    std::string getGroup() const { return group; }
    std::string getVersion() const { return std::to_string(revision) + '.' + std::to_string(iteration); }
    int getIteration() const { return iteration; }
    int getRevision() const { return revision; }
    void setName(const std::string& c_name) {  name = c_name; }
    void setPath(const std::string& c_path) {  path = c_path; }
    void setExternalPath(const std::string& c_externPath) {  externPath = c_externPath; }
    void setGroup(const std::string& c_group) {  group = c_group; }
    void setIteration(int c_iteration) {  iteration = c_iteration; }
    void setRevision(int c_revision) {  revision = c_revision; }
    void setExternal(bool c_external) { external = c_external; }
    bool isExternal() const { return external; }
    int iterate() { return ++iteration; }
    int revise() { return ++revision; }
    bool operator==(const Part& part) const { return this->name == part.name; }
};

class HashPart {
public:
    size_t operator()(const Part & part) const {
        return std::hash<std::string>()(part.getName()); // Name must be unique so its ok only using that for hashing
    }
};
