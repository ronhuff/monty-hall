#pragma once

#include "Door.h"
#include <vector>
#include <string>
#include <exception>
#include <iostream>

class Simulation
{
public:
	Simulation();
	Simulation(int numRuns, int doorChoice, bool sw);
	~Simulation();

	void run() throw(std::exception);

private:
	int m_numRuns;
	int m_initDoorChoice;
	bool m_switchDoor;


	int m_numWins;
	int m_numLoss;
	bool m_firstOpen; // true if one door has been revealed, else false.
	int m_doorChoice;

	std::string m_results;

	std::vector<Door> m_doors;

	void assignDoors();
	void resetDoors();
	bool openDoor() throw(std::exception);// true if car, false if goat.
	void switchDoor();
};

