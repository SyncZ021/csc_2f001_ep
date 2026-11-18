#include "add.h"
#include <cstdint>
#include "integer.h"
#include "list.h"

add_t::add_t()
  : keyword_t{"+"}
{
    
}

node_t* add_t::apply(list_t* list){
    uintptr_t sum=0;
    for (size_t i=1; i<list->size(); i++){
        node_t* value=list->at(i)->eval(); // list is a pointer so at() must be used
        uintptr_t v=value->int_value(); // same for value
        sum+=v;
    }
    node_t* res=new integer_t{sum}; // int_value() returns an uintptr_t but we need a node_t*
    return res;
}