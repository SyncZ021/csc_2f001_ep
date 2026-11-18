#ifndef NODE_H
#define NODE_H

#include <string>
#include <cstdint>

struct list_t;

struct node_t{
    virtual node_t* eval();
    virtual node_t* apply(list_t* list);
    virtual std::string to_string();
    virtual list_t* as_list();
    virtual uintptr_t int_value();
};

void error(std::string str) __attribute__((noreturn));

#endif