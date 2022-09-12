#include "file_helper.h"

#ifdef _WIN32
#include <direct.h>
#elif __unix__
#include <unistd.h>
#endif
#include <dirent.h>

#include <sstream>
#include <fstream>


bool FileHelper::createFolder(const std::string& folder_name) {
    return mkdir(folder_name.c_str());
}

bool FileHelper::move(const std::string& src, const std::string& dst) {
    return rename(src.c_str(), dst.c_str()) == 0;
}

bool FileHelper::fileExists(const std::string& file_name) {
    DIR *dir;
    dirent *pdir;
    const char* c_file = file_name.c_str();
    dir = opendir(".");

    while((pdir=readdir(dir)) != NULL) {
        if (strcmp(pdir->d_name, c_file) == 0) {
            closedir(dir);
            return true;
        }
    }

    closedir(dir);
    return false;
}

void FileHelper::writeFile(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream outfile = std::ofstream(filename);

    for (const auto& line : lines){
        outfile << line << "\n";
    }

    outfile.close();
}

void FileHelper::readFile(const std::string& filename, std::vector<std::string>& lines) {
    std::ifstream infile = std::ifstream(filename);

    std::string line;
    while (std::getline(infile, line)) {
        lines.push_back(line);
    }

    infile.close();
}
