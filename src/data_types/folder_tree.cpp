#include "folder_tree.h"

#include "../file_helper.h"

FolderTree::FolderTree(Parts& parts) {
    for (const auto& part : parts.getParts()) {
        // TODO: add create path tree structure from parts
    }
}

void FolderTree::addFolder(FolderTree* folder_tree) {
    if (folder_tree != nullptr && !hasSubFolder(folder_tree->name))
        sub_folders.emplace_back(folder_tree);
}

bool FolderTree::hasSubFolder(const std::string& folder_name) {
    for (FolderTree* node : sub_folders) {
        if (node->name == folder_name)
            return true;
    }

    return false;
}

void FolderTree::createFolderRec() {
    createFolder(FileHelper::composePath(".", this->name));
}

void FolderTree::createFolder(const std::string& acc_path) {
    FileHelper::createFolder(acc_path);

    for (FolderTree* nodes : this->sub_folders) {
        nodes->createFolder(FileHelper::composePath(acc_path, nodes->name));
    }
}