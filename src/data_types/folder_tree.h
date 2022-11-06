#pragma once

#include <string>
#include <vector>
#include <unordered_set>

#include "parts.h"

class FolderTree {
private:
    std::vector<FolderTree*> sub_folders;
    std::string name;

    bool hasSubFolder(const std::string&);
    void createFolder(const std::string&);
    void fromStrings(const std::unordered_set<std::string>&);
public:
    FolderTree(const std::string& c_name) : name(c_name) { sub_folders = std::vector<FolderTree*>(); }
    FolderTree(Parts&);
    ~FolderTree();
    void addFolder(FolderTree*);
    void createFolderRec();
};