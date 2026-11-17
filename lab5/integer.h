#ifndef INTEGER_H
#define INTEGER_H

#include "node.h"
#include <string>
#include <cstdint>

struct integer_t: node_t{
    uintptr_t integ;
    integer_t(uintptr_t v);
    std::string to_string();
};

#endif