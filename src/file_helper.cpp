#include "file_helper.h"

#include <system_error>

#ifdef _WIN32
#include <direct.h>
#include <windows.h>
#include <string>
#include <codecvt>
#include <locale>
#elif __unix__
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <dirent.h>
#endif

#include <sstream>
#include <fstream>


void FileHelper::createFolder(const std::string& folder_name) {
    #ifdef _WIN32
        if (CreateDirectoryA(folder_name.c_str(), NULL) == 0) {
            throw std::runtime_error(std::system_category().message(::GetLastError()));
        }
    #elif __unix__
        if (mkdir(folder_name.c_str()) != 0) {
            throw std::runtime_error(std::strerror(errno));
        }
    #endif
}

void FileHelper::move(const std::string& src, const std::string& dst) {
    if (rename(src.c_str(), dst.c_str()) != 0) {
        #ifdef _WIN32
            throw std::runtime_error(std::system_category().message(::GetLastError()));
        #elif __unix__
            throw std::runtime_error(std::strerror(errno));
        #endif
    }
}

void FileHelper::copy(const std::string& src, const std::string& dst) {
    #ifdef _WIN32
        if (CopyFile(src.c_str(), dst.c_str(), true) == 0) {
            throw std::runtime_error(std::system_category().message(::GetLastError()));
        }
    #elif __unix__
        if (copy(src.c_str(), dst.c_str()) != 0) {
            throw std::runtime_error(std::strerror(errno));
        }
    #endif
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

void FileHelper::writeFile(const std::string& filename, const std::vector<std::string>& lines, bool append) {
    std::ofstream outfile = append ? std::ofstream(filename, std::ios_base::app) : std::ofstream(filename);

    for (const auto& line : lines){
        outfile << line << "\n";
    }

    outfile.close();
}

void FileHelper::writeFile(const std::string& filename, const std::string& text, bool append) {
    std::ofstream outfile = append ? std::ofstream(filename, std::ios_base::app) : std::ofstream(filename);

    outfile << text;

    outfile.close();
}

void FileHelper::readFile(const std::string& filename, std::vector<std::string>& lines) {
    std::ifstream infile = std::ifstream(filename);
    
    if (infile.fail())
        throw std::runtime_error("File " + filename + " doesn't exists");

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

    return acc;
}

void FileHelper::removeFile(const std::string& filename) {
    
}

template <typename... Args>
std::string FileHelper::composePath(const std::string& str, Args... args) {
    return str + SEPARATOR + composePath(args...);
}