#ifndef KEYWORD_H
#define KEYWORD_H

#include "node.h"
#include <string>

struct keyword_t: node_t{
    std::string id;
    keyword_t(std::string id);
    std::string to_string();
};

#endif