#include "stdafx.h"
#include "..\include\Simulation.h"


Simulation::Simulation()
{
	for (int i = 0; i < 3; i++)
	{
		m_doors.push_back(Door());
	}
}


Simulation::~Simulation()
{
}
