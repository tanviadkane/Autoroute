#include <iostream>
#include "RoutePlanner.h"
#include <vector>
#include <queue>
#include <map>
#include <limits>
#include <algorithm>


using namespace std;

double RoutePlanner::calculateTotalTrafficDelay()
{
    double totalDelay = 0;

    for (vector<Road>::iterator it = roads.begin();
         it != roads.end();
         it++)
    {
        totalDelay += it->getTrafficDelay();
    }

    return totalDelay;
}

void RoutePlanner::addRoad(Road road)
{
    roads.push_back(road);
}

void RoutePlanner::displayRoute()
{
    cout << "Route:" << endl;

    for (Road road : roads)
    {
        road.displayRoad();
    }
}

double RoutePlanner::calculateTotalDistance()
{
    double totalDistance = 0;

    for (Road road : roads)
    {
        totalDistance += road.getDistance();
    }

    return totalDistance;
}
double RoutePlanner::findShortestRoute()
{
    double route1 = 5 + 8 + 6;   // A -> B -> C -> D
    double route2 = 10 + 6;      // A -> C -> D

    if (route1 < route2)
        return route1;
    else
        return route2;
}
void RoutePlanner::displayShortestRoute()
{
    cout << "Path: A -> C -> D" << endl;
    cout << "Distance: 16 km" << endl;
}
double RoutePlanner::findFastestRoute(double speed)
{
    // Route 1: A -> B -> C -> D
    double route1Distance = 19;
    double route1Delay = 8;

    double route1Time = (route1Distance / speed) * 60 + route1Delay;

    // Route 2: A -> C -> D
    double route2Distance = 16;
    double route2Delay = 1;

    double route2Time = (route2Distance / speed) * 60 + route2Delay;

    cout << "\n===== Fastest Route Analysis =====" << endl;

    cout << "Route 1 Time: " << route1Time << " minutes" << endl;
    cout << "Route 2 Time: " << route2Time << " minutes" << endl;

    if (route1Time < route2Time)
    {
        cout << "Fastest Route: A -> B -> C -> D" << endl;
        return route1Time;
    }
    else
    {
        cout << "Fastest Route: A -> C -> D" << endl;
        return route2Time;
    }
}
double RoutePlanner::calculateShortestPath()
{
    // Current graph:
    // A -> B = 5
    // B -> C = 8
    // C -> D = 6
    // A -> C = 10

    double distanceAtoB = 5;
    double distanceBtoC = 8;
    double distanceAtoC = 10;
    double distanceCtoD = 6;

    double route1 = distanceAtoB + distanceBtoC + distanceCtoD;
    double route2 = distanceAtoC + distanceCtoD;

    cout << "\n===== Dijkstra Shortest Path =====" << endl;

    if (route1 < route2)
    {
        cout << "Shortest Path: A -> B -> C -> D" << endl;
        cout << "Distance: " << route1 << " km" << endl;
        return route1;
    }
    else
    {
        cout << "Shortest Path: A -> C -> D" << endl;
        cout << "Distance: " << route2 << " km" << endl;
        return route2;
    }
}
double RoutePlanner::dijkstra(string start, string destination)
{
    map<string, vector<pair<string, double>>> graph;

    // Roads
    graph["A"].push_back({"B", 5});
    graph["B"].push_back({"A", 5});

    graph["B"].push_back({"C", 8});
    graph["C"].push_back({"B", 8});

    graph["C"].push_back({"D", 6});
    graph["D"].push_back({"C", 6});

    graph["A"].push_back({"C", 10});
    graph["C"].push_back({"A", 10});

    map<string, double> distance;

    distance["A"] = numeric_limits<double>::infinity();
    distance["B"] = numeric_limits<double>::infinity();
    distance["C"] = numeric_limits<double>::infinity();
    distance["D"] = numeric_limits<double>::infinity();

    priority_queue<
        pair<double, string>,
        vector<pair<double, string>>,
        greater<pair<double, string>>
    > pq;

    distance[start] = 0;

    pq.push({0, start});

    while (!pq.empty())
    {
        double currentDistance = pq.top().first;
        string currentCity = pq.top().second;

        pq.pop();

        if (currentDistance > distance[currentCity])
            continue;

        for (auto road : graph[currentCity])
        {
            string nextCity = road.first;
            double roadDistance = road.second;

            double newDistance =
                currentDistance + roadDistance;

            if (newDistance < distance[nextCity])
            {
                distance[nextCity] = newDistance;

                pq.push({
                    newDistance,
                    nextCity
                });
            }
        }
    }

    cout << "\n===== Actual Dijkstra Algorithm =====" << endl;
    cout << "Start: " << start << endl;
    cout << "Destination: " << destination << endl;
    cout << "Shortest Distance: "
         << distance[destination]
         << " km" << endl;

    return distance[destination];
}
void RoutePlanner::displayDijkstraPath(string start, string destination)
{
    map<string, vector<pair<string, double>>> graph;

    graph["A"].push_back({"B", 5});
    graph["B"].push_back({"A", 5});

    graph["B"].push_back({"C", 8});
    graph["C"].push_back({"B", 8});

    graph["C"].push_back({"D", 6});
    graph["D"].push_back({"C", 6});

    graph["A"].push_back({"C", 10});
    graph["C"].push_back({"A", 10});

    map<string, double> distance;
    map<string, string> previous;

    distance["A"] = numeric_limits<double>::infinity();
    distance["B"] = numeric_limits<double>::infinity();
    distance["C"] = numeric_limits<double>::infinity();
    distance["D"] = numeric_limits<double>::infinity();

    priority_queue<
        pair<double, string>,
        vector<pair<double, string>>,
        greater<pair<double, string>>
    > pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        double currentDistance = pq.top().first;
        string currentCity = pq.top().second;

        pq.pop();

        if (currentDistance > distance[currentCity])
            continue;

        for (auto road : graph[currentCity])
        {
            string nextCity = road.first;
            double roadDistance = road.second;

            double newDistance =
                currentDistance + roadDistance;

            if (newDistance < distance[nextCity])
            {
                distance[nextCity] = newDistance;
                previous[nextCity] = currentCity;

                pq.push({newDistance, nextCity});
            }
        }
    }

    vector<string> path;
    string current = destination;

    while (current != start)
    {
        path.push_back(current);
        current = previous[current];
    }

    path.push_back(start);

    reverse(path.begin(), path.end());

    cout << "\n===== Shortest Path =====" << endl;

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }

    cout << endl;

    cout << "Distance: "
         << distance[destination]
         << " km" << endl;
}
double RoutePlanner::calculateSmartRoute(double speed)
{
    // Route 1: A -> B -> C -> D
    double route1Distance = 19;
    double route1Traffic = 8;
    double route1ConditionPenalty = 5;

    double route1Time =
        (route1Distance / speed) * 60
        + route1Traffic
        + route1ConditionPenalty;

    // Route 2: A -> C -> D
    double route2Distance = 16;
    double route2Traffic = 1;
    double route2ConditionPenalty = 0;

    double route2Time =
        (route2Distance / speed) * 60
        + route2Traffic
        + route2ConditionPenalty;

    cout << "\n===== Smart Route Analysis =====" << endl;

    cout << "Route 1 Time: "
         << route1Time << " minutes" << endl;

    cout << "Route 2 Time: "
         << route2Time << " minutes" << endl;

    if (route1Time < route2Time)
    {
        cout << "Recommended Route: A -> B -> C -> D" << endl;
        return route1Time;
    }
    else
    {
        cout << "Recommended Route: A -> C -> D" << endl;
        return route2Time;
    }
}