#include "folder_tree.h"

void FolderTree::addFolder(FolderTree* folder_tree) {
    if (folder_tree != nullptr && !hasSubFolder(folder_tree->name))
        sub_folders.emplace_back(folder_tree);
}

bool FolderTree::hasSubFolder(std::string folder_name) {
    for (FolderTree* node : sub_folders) {
        if (node->name == folder_name)
            return true;
    }

    return false;
}

