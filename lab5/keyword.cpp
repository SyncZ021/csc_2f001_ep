#include "keyword.h"
#include <string>

keyword_t::keyword_t(std::string id)
  : id{id}
{
    
}

std::string keyword_t::to_string(){
    return "<"+id+">";
}