#include "stdafx.h"
#include "Simulation.h"


Simulation::Simulation(int numRuns, int doorChoice, bool sw)
{
	for (int i = 0; i < 3; i++)
	{
		m_doors.push_back(Door());
	}

	m_numRuns = numRuns;
	m_initDoorChoice = doorChoice;
	m_switchDoor = sw;

}


Simulation::~Simulation()
{
}
