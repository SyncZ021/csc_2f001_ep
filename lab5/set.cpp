#include "set.h"
#include "keyword.h"

set_t::set_t()
  : keyword_t{"set!"}
{

}

node_t* set_t::apply(list_t* list, frame_t* frame){
    node_t* symbol=list->at(1);
    node_t* value=list->at(2)->eval(frame);
    frame->set(symbol, value);
    return value;
}
