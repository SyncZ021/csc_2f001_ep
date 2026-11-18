#ifndef ADD_H
#define ADD_H

#include "keyword.h"

struct add_t: keyword_t{
    add_t();
    node_t* apply(list_t* list);
};

#endif