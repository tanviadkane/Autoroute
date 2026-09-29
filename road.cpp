#include <iostream>
#include "Road.h"

using namespace std;

Road::Road(string start, string end, double dist)
{
    startPoint = start;
    endPoint = end;
    distance = dist;
     trafficDelay = 0;
}

void Road::displayRoad()
{
    cout << startPoint << " -> " << endPoint
         << " | Distance: " << distance << " km" << endl;
}

double Road::getDistance()
{
    return distance;
}

string Road::getStart()
{
    return startPoint;
}

string Road::getEnd()
{
    return endPoint;
}
void Road::setTrafficDelay(double delay)
{
    trafficDelay = delay;
}

double Road::getTrafficDelay()
{
    return trafficDelay;
}