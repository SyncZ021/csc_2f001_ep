#ifndef LOCATION_H
#define LOCATION_H

#include <string>

struct location_t{
    std::string name;
    double lat;
    double long;
    location_t** neighbors;
    size_t nb_neighbors;
    location_t(const std::string name, double lat, double long);
};

#endif
