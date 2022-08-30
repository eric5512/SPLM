#include "file_helper.h"

#include <direct.h>
#include <dirent.h>

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