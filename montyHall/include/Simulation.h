#pragma once

#include "Door.h"
#include <vector>
class Simulation
{
public:
	Simulation(int numRuns, int doorChoice, bool sw);
	~Simulation();

	
private:
	int m_numRuns;
	int m_initDoorChoice;
	bool m_switchDoor;

std::vector<Door> m_doors;
};

