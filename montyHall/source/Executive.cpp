#include "stdafx.h"
#include "Executive.h"


Executive::Executive()
{
	
}


Executive::~Executive()
{

}

void Executive::run()
{
	sim = std::make_unique<Simulation>();
	sim->run();
}