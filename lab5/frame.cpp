#include "frame.h"
#include "symbol.h"
#include "node.h"
#include "list.h"

void frame_t::set(node_t* sym, node_t* value){
    for (size_t i=0; i<size(); i++){
        node_t* symbol=at(i)->as_list()->at(0);
        if (sym->is(symbol->to_string())){
            at(i)->as_list()->set_at(1, value);
            return;
        }
    }
    list_t* new_pair=new list_t;
    new_pair->append(sym);
    new_pair->append(value);
    append(new_pair);
}

node_t* frame_t::get(node_t* sym){
    for (size_t i=0; i<size(); i++){
        node_t* symbol=at(i)->as_list()->at(0);
        if (sym->is(symbol->to_string())){
            return at(i)->as_list()->at(1);
        }
    }
    error("symbol does not exist.");
}