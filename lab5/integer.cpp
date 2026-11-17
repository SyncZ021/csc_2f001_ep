#include "integer.h"

integer_t::integer_t(uintptr_t v){
    integ=v;
}

std::string integer_t::to_string(){
    return std::to_string(integ);
}