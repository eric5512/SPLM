#pragma once

#include <string>
#include <vector>
#include <cstdarg>

class FileHelper {
public:
    #ifdef _WIN32
    static const char SEPARATOR = '/';
    #elif __unix__
    static const char SEPARATOR = '\\';
    #endif
    static void createFolder(const std::string&);
    static void move(const std::string&, const std::string&);
    static void copy(const std::string&, const std::string&);
    static bool fileExists(const std::string&, const std::string& path = ".");
    static void writeFile(const std::string&, const std::vector<std::string>&, bool append = false);
    static void writeFile(const std::string&, const std::string&, bool append = false);
    static void readFile(const std::string&, std::vector<std::string>&);
    static std::string readFile(const std::string&);
    template<typename... Args>
    static std::string composePath(const std::string&, Args...);
};