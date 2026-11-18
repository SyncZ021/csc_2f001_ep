#ifndef SET_H
#define SET_H

#include "keyword.h"
#include "frame.h"
#include "list.h"
#include "node.h"

struct set_t: keyword_t{
    set_t();
    node_t* apply(list_t* list, frame_t* frame);
};

#endif