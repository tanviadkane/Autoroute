#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle
{
private:
    int vehicleId;
    string vehicleType;
    string currentLocation;
    string destination;
    double speed;

public:
    Vehicle(int id, string type, string location, string destination, double speed);

    void displayInfo();
    void setDestination(string newDestination);
string getLocation();
void changeSpeed(double newSpeed);
double getSpeed();
double calculateTravelTime(double distance);
void move();
};

#endif