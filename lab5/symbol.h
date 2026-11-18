#ifndef SYMBOL_H
#define SYMBOL_H

#include "node.h"
#include <string>

struct symbol_t: node_t{
    std::string id;
    symbol_t(std::string id);
    bool is(std::string id);
    std::string to_string();
};

#endif