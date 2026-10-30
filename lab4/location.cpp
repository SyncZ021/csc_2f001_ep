#include "location.h"

location_t::location_t(const std::string name, double latitude, double longitude)
  : name{name}, 
    latitude{latitude}, 
    longitude{longitude}, 
    neighbors{NULL}, 
    nb_neighbors{0}
{
        
}

location_t::~location_t(){
    delete[] neighbors;
}

void location_t::set_neighbors(location_t* list[]){
    neighbors=list;
    nb_neighbors=0;
    while (neighbors[nb_neighbors]!=nullptr){
        nb_neighbors+=1;
    }
}

double location_t::distance_to(location_t* to){
    double R=6378.0;
    double lat1=this->latitude;
    double long1=this->longitude;
    double lat2=to->latitude;
    double long2=to->longitude;
    double distance=R * (std::numbers::pi/2 - std::asin(std::sin(lat2) * std::sin(lat1) + std::cos(long2 - long1) * std::cos(lat2) * std::cos(lat1)));
    return distance;
}

