#include "vehicle_factory.hpp"
Vehicle *vehicleFactory::getVehicle(string vehicleType){
    Vehicle *vehicle;
    if(vehicleType == "car"){
        vehicle = new Car();
    }
    else if(vehicleType == "bike"){
        vehicle = new bike();
    }
    return *vehicle;
}
