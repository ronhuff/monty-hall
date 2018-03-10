#include "stdafx.h"
#include "Simulation.h"


Simulation::Simulation()
{
	for (int i = 0; i < 3; i++)
	{
		m_doors.push_back(Door());
	}
}

Simulation::Simulation(const float& numRuns, const int& doorChoice, const bool& sw = false)
	:m_numRuns(numRuns), m_chosenDoorNum(doorChoice - 1), m_switchDoorNum(-1), m_revealDoorNum(-1),
	 m_carDoorNum(-1), m_switch(sw), m_numWins(0), m_numLoss(0)
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
		m_doors[m_carDoorNum].setHasCar(true); // assign car door.

		if (m_carDoorNum != m_chosenDoorNum && !m_switch)
		{
			m_numLoss++;
			runCount++;
			goto noswitch;
		}
		else if(!m_switch)
		{
			m_numWins++;
			runCount++;
			goto noswitch;
		}

		for (int i = 0; i < 3; i++) // loop through doors.
		{
			//the problem is that we are comparing cardoor
			if (i == m_chosenDoorNum || i == m_carDoorNum) continue; // may not reveal door with car, may not reveal user's initial door.
			m_revealDoorNum = i;
			if(i  < 2) break;
		}
		if (m_carDoorNum == m_chosenDoorNum)
		{
			m_numLoss++;
			runCount++;
		}
		else
		{
			m_numWins++;
			runCount++;
		}
		noswitch:
		m_doors[m_carDoorNum].setHasCar(false);
	}//exit sim
}

std::shared_ptr<float> Simulation::sendData()
{
	std::shared_ptr<float> m_data(new float[3], std::default_delete<float[]>());
	m_data.get()[0] = m_numRuns;
	m_data.get()[1] = m_numWins;
	m_data.get()[2] = m_numLoss;

	return(m_data);
}
