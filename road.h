#ifndef ROAD_H
#define ROAD_H

#include <string>
using namespace std;

class Road
{
private:
    string startPoint;
    string endPoint;
    double distance;
    double trafficDelay;

public:
    Road(string start, string end, double dist);

    void displayRoad();
    double getDistance();
    string getStart();
    string getEnd();
    void setTrafficDelay(double delay);
double getTrafficDelay();
};

#endif