#include "node.h"
#include "integer.h"
#include <iostream>
#include "list.h"
#include "add.h"
#include "frame.h"
#include "symbol.h"

int main(){
    frame_t* frame = new frame_t;
    node_t* ast1 = new integer_t { 3 };
    std::cout << ast1->to_string() << " => " << ast1->eval(frame)->to_string() << std::endl;
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

    std::cout << ast->to_string() << " => " << ast->eval(frame)->to_string() << std::endl;
    // should output (<+> (<+> 1 2) 3)

    frame->set(new symbol_t { "a" }, new integer_t { 666 });
    frame->set(new symbol_t { "b" }, new integer_t { 21 });
    frame->set(new symbol_t { "a" }, new integer_t { 42 });

    std::cout << frame->to_string() << ": a=" << frame->get(new symbol_t { "a" })->to_string() << std::endl;
    node_t* add1 = new add_t;
    symbol_t* a = new symbol_t { "a" };
    frame_t* frame1 = new frame_t;

    frame1->set(a, new integer_t { 37 });

    list_t* ast3 = new list_t;

    ast3->append(add1);
    ast3->append(new list_t);
    ast3->at(1)->as_list()->append(add1);
    ast3->at(1)->as_list()->append(a);
    ast3->at(1)->as_list()->append(new integer_t { 2 });
    ast3->append(new integer_t { 3 });

    std::cout << ast3->to_string() << " => " << ast3->eval(frame1)->to_string() << std::endl;
        return 0;
}