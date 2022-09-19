#pragma once

#include <unordered_set>

#include "group.h"

class Meta {
private:
    std::unordered_set<Group> groups;
public:
    Meta();
};