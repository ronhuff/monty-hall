#include "stdafx.h"
#include "Executive.h"


Executive::Executive()
{
	for (int i = 0; i < 3; i++)
	{
		m_doors.push_back(Door());
	}

}


Executive::~Executive()
{

}