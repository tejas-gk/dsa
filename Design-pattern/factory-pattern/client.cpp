#include<iostream>
#include "vehicle_factory.cpp"

int main(){
    std::string vehicleType;
    std::cout << "Enter the vehicle type: ";
    std::cin >> vehicleType;
    Vehicle vehicle = vehicleFactory::getVehicle(vehicleType);
    vehicle->createVehicle();
    return 0;
}