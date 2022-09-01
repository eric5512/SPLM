#pragma once

#include <unordered_set>
#include <string>

class Part {
private:
    std::string name;
    std::string path;
    std::string externPath;
    bool external;
public:
    Part(const std::string& c_name, const std::string& c_path, bool c_external) : name(c_name), path(c_path), external(c_external) {}
    Part(const std::string& c_name, const std::string& c_path) : name(c_name), path(c_path), external(false) {}
    std::string getName() const { return name; }
    std::string getPath() const { return path; }
    std::string getExternalPath() const { return externPath; }
    bool isExternal() const { return external; }
};

class HashPart {
public:
    size_t operator()(const Part & part) const {
        return std::hash<std::string>()(part.getName()); // Name must be unique so its ok only using that for hashing
    }
};


class Parts {
private:
    std::unordered_set<Part,HashPart> parts;
public:
    bool partExists(Part);
};
