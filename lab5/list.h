#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <string>

struct list_t: node_t{
    node_t** elements;
    size_t nb_elements;
    size_t capacity;
    list_t();
    list_t* as_list();
    size_t size();
    node_t* at(size_t i);
    void set_at(size_t i, node_t* value);
    void append(node_t* value);
    std::string to_string();
};

#endif