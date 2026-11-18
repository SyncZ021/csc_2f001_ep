#include "node.h"
#include "integer.h"
#include <iostream>
#include "list.h"
#include "add.h"

int main(){
    node_t* ast1 = new integer_t { 3 };
    std::cout << ast1->to_string() << " => " << ast1->eval()->to_string() << std::endl;
    list_t* ast2 = new list_t;
    ast2->append(new integer_t { 1 });
    ast2->append(new integer_t { 2 });
    ast2->append(new integer_t { 3 });
    std::cout << ast2->to_string() << std::endl; // should output (1 2 3)
    node_t* add = new add_t;
    list_t* ast = new list_t;

    ast->append(add);
    ast->append(new list_t);
    ast->at(1)->as_list()->append(add);
    ast->at(1)->as_list()->append(new integer_t { 1 });
    ast->at(1)->as_list()->append(new integer_t { 2 });
    ast->append(new integer_t { 3 });

    std::cout << ast->to_string() << " => " << ast->eval()->to_string() << std::endl;
    // should output (<+> (<+> 1 2) 3)
    return 0;
}