#include "list.h"

list_t::list_t()
  :elements{nullptr}, 
  nb_elements{0}, 
  capacity{0}
{

}

list_t* list_t::as_list(){
    return this;
}

size_t list_t::size(){
    return nb_elements;
}

node_t* list_t::at(size_t i){
    if (i>=nb_elements){
        error("index out of bound.");
    }
    return elements[i];
}

void list_t::set_at(size_t i, node_t* value){
    if (i>=nb_elements){
        error("index out of bound.");
    }
    elements[i]=value;
}

void list_t::append(node_t* value){
    if (nb_elements==capacity){
        size_t new_capacity=capacity+1;
        node_t** new_elements=new node_t*[new_capacity];
        for (size_t i=0; i<nb_elements; i++){
            new_elements[i]=elements[i];
        }
        capacity=new_capacity;
        elements=new_elements;
    }
    elements[nb_elements]=value;
    nb_elements+=1;
}

std::string list_t::to_string(){
    std::string res="(";
    for (size_t i=0; i<nb_elements; i++){
        res+=elements[i]->to_string();
        if (i<nb_elements-1){
            res+=" ";
        }
    }
    res+=")";
    return res;
}

node_t* list_t::eval(){
    node_t* first=elements[0]->eval();
    node_t* res=first->apply(this);
    return res;
}