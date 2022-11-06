#include "folder_tree.h"

#include "../file_helper.h"

#ifdef _WIN32
#define SEPARATOR '\\'
#elif __unix__
#define SEPARATOR '/'
#endif

FolderTree::FolderTree(Parts& parts) {
    auto paths = std::unordered_set<std::string>();
    
    for (const auto &pair : parts.getParts()) {
        paths.emplace(pair.second.getPath());
    }

    this->name = ".";
    this->fromStrings(paths);
}

void FolderTree::fromStrings(const std::unordered_set<std::string>& set) {
    auto paths = std::unordered_map<std::string,std::unordered_set<std::string>>();

    for (const auto& str : set) {
        std::string aux = str;
        
        std::string::size_type pos;

        if (aux != "") {
            std::string prefix;
            
            if ((pos = aux.find(SEPARATOR)) != std::string::npos) {
                prefix = aux.substr(0, pos);
                aux = aux.substr(pos+1);
            } else {
                prefix = aux;
                aux = "";
            }

            if (paths.find(prefix) == paths.end()) {
                paths[prefix] = std::unordered_set<std::string>();
            }

            if (aux != "") {
                paths[prefix].emplace(aux);
            }
        }
    }

    for (const auto& pair : paths) {
        FolderTree* ptr = new FolderTree(pair.first);
        ptr->fromStrings(pair.second);
        this->addFolder(ptr);
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
    for (FolderTree* node : this->sub_folders) {
        node->createFolder(this->name);
    }
}

void FolderTree::createFolder(const std::string& acc_path) {
    std::string new_acc_path = FileHelper::composePath(acc_path, this->name);
    
    FileHelper::createFolder(new_acc_path);

    for (FolderTree* node : this->sub_folders) {
        node->createFolder(new_acc_path);
    }
}

FolderTree::~FolderTree() {
    for (const auto& node : this->sub_folders) {
        node->~FolderTree();
        delete node;
    }
}