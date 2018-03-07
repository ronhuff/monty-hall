#include "stdafx.h"
#include "..\include\Executive.h"


Executive::Executive()
{
	for (int i = 0; i < 3; i++)
	{
		m_doors[i] = std::make_shared<Door>();
	}

}


Executive::~Executive()
{
}
