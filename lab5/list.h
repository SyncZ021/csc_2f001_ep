#ifndef LIST_H
#define LIST_H

#include "node.h"

struct list_t: node_t{
    node_t** elements;
    size_t nb_elements;
    size_t capacity;
    list_t();
};

#endif