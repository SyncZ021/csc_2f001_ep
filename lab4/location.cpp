#include "location.h"

location_t::location_t(const std::string name, double lat, double long)
    : name{name}, 
    lat{lat}, 
    long{long}
    neighbors{NULL}, 
    nb_neighbors{0}{
        
    }

