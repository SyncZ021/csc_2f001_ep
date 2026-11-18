#ifndef FRAME_H
#define FRAME_H

#include "list.h"

struct frame_t: list_t{
    void set(node_t* sym, node_t* value);
    node_t* get(node_t* sym);
};

#endif