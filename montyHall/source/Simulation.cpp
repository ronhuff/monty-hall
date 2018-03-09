#include "stdafx.h"
#include "Simulation.h"

Simulation::Simulation()
{
	for (int i = 0; i < 3; i++)
	{
		m_doors.push_back(Door());
	}
}

Simulation::Simulation(int numRuns, int doorChoice, bool sw)
	:m_numRuns(numRuns), m_initDoorChoice(doorChoice), m_switchDoor(sw)
{
	for (int i = 0; i < 3; i++)
	{
		m_doors.push_back(Door());
	}
}

Simulation::~Simulation()
{

}

void Simulation::run()
{
	assignDoors();

}

void Simulation::assignDoors()
{
	int carDoorNum = rand() % 3;
	m_doors.at(carDoorNum).setHasCar(true);

	int goatNum;
	while (1)
	{
		goatNum = rand() % 3;
		if (goatNum != carDoorNum) break;
	}
	m_doors.at(goatNum).setHasGoat(true);
}

void Simulation::resetDoors()
{
	for (std::vector<Door>::iterator doorit = m_doors.begin(); doorit != m_doors.end(); ++doorit)
	{
		doorit->setHasCar(false);
		doorit->setHasGoat(false);
		doorit->setIsOpen(false);
	}
}