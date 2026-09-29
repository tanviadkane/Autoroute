#ifndef ROUTEPLANNER_H
#define ROUTEPLANNER_H

#include "Road.h"
#include <vector>

using namespace std;

class RoutePlanner
{
private:
    vector<Road> roads;

public:
    void addRoad(Road road);
    void displayRoute();
    double calculateTotalDistance();
    double calculateTotalTrafficDelay();
    double findShortestRoute();
    void displayShortestRoute();
    void findAllRoutes();
    double findFastestRoute(double speed);
    double calculateShortestPath();
    double dijkstra(string start, string destination);
    void displayDijkstraPath(string start, string destination);
    double calculateSmartRoute(double speed);
};

#endif