#pragma once

#include "Door.h"
#include <vector>
#include <string>
#include <exception>
#include <iostream>
#include <memory>

class Simulation
{
public:
	Simulation();
	Simulation(const float& numRuns, const int& doorChoice, const bool& sw);
	~Simulation();

	void run();
	std::shared_ptr<float> sendData();
private:
	float m_numRuns;
	int m_chosenDoorNum;
	int m_switchDoorNum;
	int m_revealDoorNum;
	int m_carDoorNum;

	bool m_switch;
	float m_numWins;
	float m_numLoss;

	std::vector<Door> m_doors;
	float m_data[3]; //this array contains data that is sent back to Executive.

};

