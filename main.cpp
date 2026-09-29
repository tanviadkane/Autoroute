#include <iostream>
#include<vector>
#include<algorithm>
#include "Vehicle.h"
#include "Road.h"
#include "City.h"
#include "RoutePlanner.h"
#include "SimulationEngine.h"

using namespace std;

int main()
{
    // Cities
    City c1("A");
    City c2("B");
    City c3("C");
    City c4("D");

    cout << "===== Cities =====" << endl;

    c1.displayCity();
    c2.displayCity();
    c3.displayCity();
    c4.displayCity();

    cout << endl;

   Vehicle v1(101, "Car", "A", "D", 60);
Vehicle v2(102, "Bus", "A", "D", 40);
Vehicle v3(103, "Bike", "B", "D", 50);
vector<Vehicle> vehicles;

vehicles.push_back(v1);
vehicles.push_back(v2);
vehicles.push_back(v3);

cout << "===== Vehicle Information =====" << endl;

for(vector<Vehicle>::iterator it =vehicles.begin();
it != vehicles.end();
it ++)
{
it-> displayInfo();
cout<<endl;
}
sort(vehicles.begin(), vehicles.end(),
     [](Vehicle &a, Vehicle &b)
     {
         return a.getSpeed() > b.getSpeed();
     });
     cout << "===== Vehicles Sorted By Speed =====" << endl;

for (Vehicle &v : vehicles)
{
    v.displayInfo();
    cout << endl;
}

    // Roads
    Road r1("A", "B", 5);
    Road r2("B", "C", 8);
    Road r3("C", "D", 6);
    Road r4("A", "C", 10);
    r1.setTrafficDelay(2);
r2.setTrafficDelay(5);
r3.setTrafficDelay(1);

    // Route Planner
    RoutePlanner planner;

    planner.addRoad(r1);
    planner.addRoad(r2);
    planner.addRoad(r3);

    cout << "===== Route =====" << endl;

    planner.displayRoute();
    planner.displayShortestRoute();

    cout << "\n===== Traffic Information =====" << endl;

cout << "A -> B | Traffic Delay: "
     << r1.getTrafficDelay()
     << " minutes" << endl;

cout << "B -> C | Traffic Delay: "
     << r2.getTrafficDelay()
     << " minutes" << endl;

cout << "C -> D | Traffic Delay: "
     << r3.getTrafficDelay()
     << " minutes" << endl;

    cout << endl;

    cout << "Total Distance: "
         << planner.calculateTotalDistance()
         << " km" << endl;cout << "Shortest Route Distance: "
     << planner.findShortestRoute()
     << " km" << endl;
     cout << "\n===== Fastest Route =====" << endl;

cout << "Fastest Route Time: "
     << planner.findFastestRoute(v1.getSpeed())
     << " minutes" << endl;
     cout << "\n===== Dijkstra Route Calculation =====" << endl;
     

planner.dijkstra("A", "D");
planner.displayDijkstraPath("A", "D");

cout << "\n===== Smart Route =====" << endl;

double smartTime =
    planner.calculateSmartRoute(v1.getSpeed());

cout << "Estimated Arrival Time: "
     << smartTime
     << " minutes" << endl;

planner.calculateShortestPath();

     cout << "\n===== Shortest Route =====" << endl;

planner.displayShortestRoute();

cout << "Total Traffic Delay: "
     << planner.calculateTotalTrafficDelay()
     << " minutes" << endl;

double baseTime = v1.calculateTravelTime(planner.calculateTotalDistance()) * 60;
double trafficDelay = planner.calculateTotalTrafficDelay();
double actualTime = baseTime + trafficDelay;

cout << "Base Travel Time: "
     << baseTime
     << " minutes" << endl;

cout << "Actual Travel Time: "
     << actualTime
     << " minutes" << endl;

cout << endl;
         cout << "\n===== Travel Time Analysis =====" << endl;

cout << "Vehicle ID: 101" << endl;
cout << "Travel Time: "
     << v1.calculateTravelTime(planner.calculateTotalDistance()) * 60
     << " minutes" << endl;

cout << "\nVehicle ID: 102" << endl;
cout << "Travel Time: "
     << v2.calculateTravelTime(planner.calculateTotalDistance()) * 60
     << " minutes" << endl;

cout << "\nVehicle ID: 103" << endl;
cout << "Travel Time: "
     << v3.calculateTravelTime(planner.calculateTotalDistance()) * 60
     << " minutes" << endl;

cout << endl;

    // Simulation
    SimulationEngine simulation(&v1, &planner);

    simulation.startSimulation();

    return 0;
}