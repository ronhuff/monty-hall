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
	:m_numRuns(numRuns), m_chosenDoorNum(doorChoice), m_switchDoorNum(-1), m_revealDoorNum(-1),
	 m_carDoorNum(-1), m_switch(sw), m_numWins(0), m_numLoss(0), m_results("")
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
	int runCount = 0;
	while (runCount < m_numRuns)
	{
		m_carDoorNum = rand() % 3;
		m_doors.at(m_carDoorNum).setHasCar(true); // assign car door.
		for (int i = 0; i < 3; i++) // loop through doors.
		{
			if (i == m_chosenDoorNum || i == m_carDoorNum) continue;
			m_revealDoorNum = i;
			break;
		}
		if (m_carDoorNum == m_chosenDoorNum && !m_switch)
		{
			m_numWins++;
			runCount++;
			goto noswitch;
		}
		else if(!m_switch)
		{
			m_numLoss++;
			runCount++;
			goto noswitch;
		}
		for (int i = 0; i < 3; i++)
		{
			if (!(i == m_chosenDoorNum || i == m_revealDoorNum) && m_switch)
			{
				if (m_doors.at(i).getHasCar())
				{
					m_numWins++;
					runCount++;
					break;
				}
				else
				{
					m_numLoss++;
					runCount++;
					break;
				}
			}
		}
		noswitch:
		m_doors.at(m_carDoorNum).setHasCar(false);
	}
}
