#pragma once

#include "Door.h"
#include <vector>
#include <string>

class Simulation
{
public:
	Simulation();
	Simulation(int numRuns, int doorChoice, bool sw);
	~Simulation();

	void run();

private:
	int m_numRuns;
	int m_initDoorChoice;
	bool m_switchDoor;

	int m_numWins;
	int m_numLoss;

	std::string results;

	std::vector<Door> m_doors;

	void assignDoors();
};

