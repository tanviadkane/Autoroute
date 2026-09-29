#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include "Vehicle.h"
#include "RoutePlanner.h"

using namespace std;

class SimulationEngine
{
private:
    Vehicle* vehicle;
    RoutePlanner* routePlanner;

public:
    SimulationEngine(Vehicle* v, RoutePlanner* r);

    void startSimulation();
};

#endif