#ifndef ADD_H
#define ADD_H

#include "keyword.h"
#include "frame.h"

struct add_t: keyword_t{
    add_t();
    node_t* apply(list_t* list, frame_t* frame);
};

#endif