#include <iostream>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(int id, string type, string location, string destination, double speed)
{
    vehicleId = id;
    vehicleType = type;
    currentLocation = location;
    this->destination = destination;
    this->speed = speed;
}

void Vehicle::displayInfo()
{
    cout << "Vehicle ID: " << vehicleId << endl;
    cout << "Vehicle Type: " << vehicleType << endl;
    cout << "Current Location: " << currentLocation << endl;
    cout << "Destination: " << destination << endl;
    cout << "Speed: " << speed << " km/h" << endl;
}

void Vehicle::setDestination(string newDestination)
{
    destination = newDestination;
}

string Vehicle::getLocation()
{
    return currentLocation;
}

void Vehicle::changeSpeed(double newSpeed)
{
    speed = newSpeed;
}

double Vehicle::getSpeed()
{
    return speed;
}

void Vehicle::move()
{
    cout << "Vehicle is moving from " << currentLocation
         << " towards " << destination << endl;
}
double Vehicle::calculateTravelTime(double distance)
{
    return distance / speed;
}