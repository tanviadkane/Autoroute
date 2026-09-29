#include <iostream>
#include "City.h"

using namespace std;

City::City(string name)
{
    cityName = name;
}

void City::displayCity()
{
    cout << "City: " << cityName << endl;
}

string City::getCityName()
{
    return cityName;
}