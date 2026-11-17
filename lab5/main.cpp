#include "node.h"
#include "integer.h"
#include <iostream>

int main(){
    node_t* ast = new integer_t { 3 };
    std::cout << ast->to_string() << " => " << ast->eval()->to_string() << std::endl;
    return 0;
}