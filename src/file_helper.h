#pragma once

#include <string>
#include <vector>

class FileHelper {
public:
    static bool createFolder(const std::string&);
    static bool move(const std::string&, const std::string&);
    static bool fileExists(const std::string&, const std::string& path = ".");
    static void writeFile(const std::string&, const std::vector<std::string>&, bool append = false);
    static void writeFile(const std::string&, const std::string&, bool append = false);
    static void readFile(const std::string&, std::vector<std::string>&);
    static std::string readFile(const std::string&);
    static std::string composePath(const std::string&, const std::string&);
};