#include "file_helper.h"

#ifdef _WIN32
#include <direct.h>
#include <windows.h>
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
        WIN32_FIND_DATA FindFileData;
        
        WCHAR* w_file_name = new WCHAR[file_name.size() * 2 + 2];
        swprintf( w_file_name, L"%S", file_name.c_str() );
        WCHAR* w_path = new WCHAR[path.size() * 2 + 2];
        swprintf( w_path, L"%S", path.c_str() );
        
        
        HANDLE hFind = FindFirstFile(w_path, &FindFileData);
        if (hFind == INVALID_HANDLE_VALUE) {
            printf ("FindFirstFile failed (%d)\n", GetLastError());
            return;
        } 

        do {
            if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && wcscmp(w_file_name, FindFileData.cFileName) == 0)
                return true;
        } while (FindNextFile(hFind, &FindFileData) != 0);

        FindClose(hFind);

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