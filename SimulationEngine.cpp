#include <iostream>
#include "SimulationEngine.h"

using namespace std;

SimulationEngine::SimulationEngine(Vehicle* v, RoutePlanner* r)
{
    vehicle = v;
    routePlanner = r;
}

void SimulationEngine::startSimulation()
{
    cout << endl;
    cout << "===== AutoRoute Simulation =====" << endl;

    cout << "Vehicle Starting Location: "
         << vehicle->getLocation() << endl;

    cout << "Total Route Distance: "
         << routePlanner->calculateTotalDistance()
         << " km" << endl;

    cout << endl;
    cout << "===== Vehicle Movement =====" << endl;

    cout << "Vehicle moving from A to B" << endl;
    cout << "Distance covered: 5 km" << endl;

    cout << endl;

    cout << "Vehicle moving from B to C" << endl;
    cout << "Distance covered: 8 km" << endl;

    cout << endl;

    cout << "Vehicle moving from C to D" << endl;
    cout << "Distance covered: 6 km" << endl;

    cout << endl;

    cout << "Total Distance Covered: "
         << routePlanner->calculateTotalDistance()
         << " km" << endl;

    cout << "Destination D reached!" << endl;
    double distance = routePlanner->calculateTotalDistance();
double speed = 60;

double travelTime = distance / speed;

cout << "Vehicle Speed: " << speed << " km/h" << endl;

cout << "Estimated Travel Time: "
     << travelTime << " hours" << endl;
}