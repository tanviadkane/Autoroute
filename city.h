#ifndef CITY_H
#define CITY_H

#include <string>
using namespace std;

class City
{
private:
    string cityName;

public:
    City(string name);

    void displayCity();
    string getCityName();
};

#endif