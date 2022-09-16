#include "file_helper.h"

#ifdef _WIN32
#include <direct.h>
#include <windows.h>
#include <string>
#include <codecvt>
#include <locale>
#elif __unix__
#include <unistd.h>
#include <dirent.h>
#endif

#include <sstream>
#include <fstream>


bool FileHelper::createFolder(const std::string& folder_name) {
    return mkdir(folder_name.c_str());
}

bool FileHelper::move(const std::string& src, const std::string& dst) {
    return rename(src.c_str(), dst.c_str()) == 0;
}

bool FileHelper::fileExists(const std::string& file_name, const std::string& path) {
    #ifdef _WIN32
        std::string pathAndPattern = path + '\\' + file_name;
        WIN32_FIND_DATA fd;
        #ifdef UNICODE
            std::wstring w_pathAndPattern = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(pathAndPattern);
            HANDLE hFind = ::FindFirstFile(w_pathAndPattern.c_str(), &fd);
        #else
            HANDLE hFind = ::FindFirstFile(pathAndPattern.c_str(), &fd);
        #endif
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                    return true;
                }
            } while (::FindNextFile(hFind, &fd));
            
            {
                ::FindClose(hFind);
            }
        }

        return false;
    #elif __unix__
        DIR *dir;
        dirent *pdir;
        const char* c_file = file_name.c_str();
        dir = opendir(path.c_str());

        while((pdir=readdir(dir)) != NULL) {
            if (strcmp(pdir->d_name, c_file) == 0) {
                closedir(dir);
                return true;
            }
        }

        closedir(dir);
        return false;
    #endif
}

void FileHelper::writeFile(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream outfile = std::ofstream(filename);

    for (const auto& line : lines){
        outfile << line << "\n";
    }

    outfile.close();
}

void FileHelper::writeFile(const std::string& filename, const std::string& text) {
    std::ofstream outfile = std::ofstream(filename);

    outfile << text;

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


std::string FileHelper::readFile(const std::string& filename) {
    std::ifstream infile = std::ifstream(filename);

    std::string acc = "";
    std::string line;
    while (std::getline(infile, line)) {
        acc += line;
        acc += '\n';
    }

    infile.close();

}

std::string FileHelper::composePath(const std::string& path, const std::string& file_or_dir) {
    #ifdef _WIN32
        return path + '\\' + file_or_dir;
    #elif __unix__
        return path + '/' + file_or_dir;
    #endif
}