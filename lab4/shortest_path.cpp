#include "shortest_path.h"
#include "location.h"
#include <iostream>

node_t::node_t(location_t* loc, node_t* frm, double f_orig, double tot)
  : next{nullptr}, 
  location{loc}, 
  from{frm},
  from_origin{f_orig}, 
  total{tot}, 
  visited{false}{

  }

shortest_path_t::shortest_path_t(location_t* from, location_t* to)
  : head{nullptr}, 
  base{nullptr}, 
  from{from}, 
  to{to}{

  }

void shortest_path_t::compute(){
    // The distance from the start to the end
    double start_total=from->distance_to(to);
    // Initialise the starting node
    head=new node_t(from, nullptr, 0.0, start_total);
    while (true){
        node_t* current=head;
        base=nullptr;
        // base is the unvisited node with the smallest total
        double min_total=10000;
        while (current!=nullptr){ // Search for base in the list
            if (!current->visited && current->total<min_total){
                min_total=current->total;
                base=current;
            }
            current=current->next;
        }
        
        if (base==nullptr){ // If base does not exist
            break;
        }
        if (base->location==to){ // If base is the end
            break;
        }
        base->visited=true;
        // i is of type size_t because nb_neighbors is
        // The loop deals with every base
        for (size_t i=0; i<base->location->nb_neighbors; i++){
            location_t* cur=base->location->neighbors[i];
            // Calculate the distance from base to cur
            double new_from_origin=base->from_origin+base->location->distance_to(cur);
            // Calculate the distance from cur to the end
            double new_total=new_from_origin+cur->distance_to(to);
            // Find if cur is already in the set of nodes starting from head and connected by next
            node_t* existing=head;
            while (existing!=nullptr){
                if (existing->location==cur){
                    break;
                }
                existing=existing->next;
            }
            if (existing==nullptr){ // The while loop stops without finding cur
                node_t* n=new node_t(cur, base, new_from_origin, new_total);
                // Put n into the set
                n->next=head;
                head=n;
            }
            else{ // The while loop stops because we found cur in the set
                if (new_from_origin<existing->from_origin){
                    existing->from=base; // To form a list starting from the end and connected by from
                    existing->from_origin=new_from_origin;
                    existing->total=new_total;
                    existing->visited=false;
                }
            }
        }
    }
    return;
}

void shortest_path_t::display(){
    if (base==nullptr || base->location!=to){
        std::cout << "unable to find a path from " << from->name << " to " << to->name << std::endl;
        return;
    }
    node_t* current=base;
    std::cout << "path from " << from->name << " to " << to->name << std::endl;
    // The list is in reversed order, so reverse it
    node_t* path[100];
    int count=0;
    while (current!=nullptr){
        path[count]=current;
        count+=1;
        current=current->from;
    }
    for (int i=count-1; i>=0; i--){
        std::cout << "  * " << path[i]->location->name << " at " << path[i]->from_origin << " km from " << from->name << std::endl;
    }
}