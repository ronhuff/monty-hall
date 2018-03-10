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

	void run();

private:
	int m_numRuns;
	int m_chosenDoorNum;
	int m_switchDoorNum;
	int m_revealDoorNum;

	int m_carDoorNum;

	bool m_switch;


	int m_numWins;
	int m_numLoss;
	

	std::string m_results;

	std::vector<Door> m_doors;
};

