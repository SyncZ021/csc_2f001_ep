#include "node.h"
#include "integer.h"
#include <iostream>
#include "list.h"

int main(){
    node_t* ast1 = new integer_t { 3 };
    std::cout << ast1->to_string() << " => " << ast1->eval()->to_string() << std::endl;
    list_t* ast = new list_t;
    ast->append(new integer_t { 1 });
    ast->append(new integer_t { 2 });
    ast->append(new integer_t { 3 });
    std::cout << ast->to_string() << std::endl; // should output (1 2 3)
    return 0;
}