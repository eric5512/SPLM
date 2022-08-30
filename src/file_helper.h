#pragma once

#include <string>

class FileHelper {
public:
    static bool createFolder(const std::string&);
    static bool move(const std::string&, const std::string&);
    static bool fileExists(const std::string&);
};

