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
	:m_numRuns(numRuns), m_initDoorChoice(doorChoice), m_switchDoor(sw), m_numWins(0), m_numLoss(0), m_firstOpen(false), m_results("")
{
	for (int i = 0; i < 3; i++)
	{
		m_doors.push_back(Door());
	}
}

Simulation::~Simulation()
{

}

void Simulation::run() throw(std::exception)
{
	int runCount = 0;
	while (runCount < m_numRuns)
	{
		assignDoors();
		m_doors.at(m_initDoorChoice).setIsPicked(true);
		try {
			if (openDoor())
			{
				m_numWins++;
				runCount++;
				m_firstOpen = false;
			}
			else
			{
				m_numLoss++;
				runCount++;
				m_firstOpen = false;
			}
		}
		catch (std::exception& e)
		{
			// log error to file(implemented later.
			switchDoor();
			if (m_doors.at(m_doorChoice).getHasCar())
			{
				m_numWins++;
				runCount++;
				m_firstOpen = false;
			}
			else if (m_doors.at(m_doorChoice).getHasGoat())
			{
				m_numLoss++;
				runCount++;
				m_firstOpen = false;
			}
			else
			{
				resetDoors();
				//throw std::exception("Error occured, final door did not have car or goat.\n");
			}
		}
		resetDoors();
	}
	std::cin.get();
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
		doorit->setIsPicked(false);//possibly redundant.
	}
}

bool Simulation::openDoor() throw(std::exception)
{
	for (std::vector<Door>::iterator doorit = m_doors.begin(); doorit != m_doors.end(); ++doorit)
	{
		if ((doorit->getIsPicked() && !m_firstOpen) || doorit->getIsOpen()) continue;
		else if (!(doorit->getHasCar()) && !m_firstOpen)
		{
			doorit->setIsOpen(true);
			if (doorit->getHasGoat() == true)
			{
				return(false);
			}
			else
			{
				throw std::exception("Empty door, nothing to return.\n");
				return(true);
			}
		}
		else if (m_firstOpen)
		{
			if (doorit->getIsPicked() && doorit->getHasCar())
			{
				return(true);
			}
			else if (doorit->getIsPicked() && doorit->getHasGoat())
			{
				return(false);
			}
		}
	}
}

void Simulation::switchDoor()
{
	if (!m_switchDoor) return;
	for (std::vector<Door>::iterator doorit = m_doors.begin(); doorit != m_doors.end(); ++doorit)
	{
		if (doorit->getIsOpen()) continue;
		if (doorit->getIsPicked())
		{
			doorit->setIsPicked(false);
			++doorit;
			doorit->setIsPicked(true);
			m_doorChoice = doorit - m_doors.begin();
			return;
		}
		else if (!doorit->getIsPicked())
		{
			doorit->setIsPicked(true);
			++doorit;
			m_doorChoice = doorit - m_doors.begin();
			doorit->setIsPicked(false);
			return;
		}
	}
}