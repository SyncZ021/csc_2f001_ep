#include "symbol.h"
#include "frame.h"

symbol_t::symbol_t(std::string id)
  : id{id}
{

}

bool symbol_t::is(std::string id){
    if (this->id==id){
        return true;
    }
    else{
        return false;
    }
}

std::string symbol_t::to_string(){
    return id;
}

node_t* symbol_t::eval(frame_t* frame){
    node_t* value=frame->get(this);
    return value;
}