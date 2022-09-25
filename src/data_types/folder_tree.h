#pragma once

#include <string>
#include <vector>

class FolderTree {
private:
    std::vector<FolderTree*> sub_folders;
    std::string name;

    bool hasSubFolder(std::string folder_name);
public:
    FolderTree(std::string c_name) : name(c_name) { sub_folders = std::vector<FolderTree*>(); }
    void addFolder(FolderTree*);
};