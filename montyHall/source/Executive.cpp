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
	sim = std::make_unique<Simulation>(200, 1, true);
	try {
		sim->run();
	}
	catch (std::exception& e)
	{
		std::cout << "UNKNOWN ERROR!!\n";
		//log error to file here.
	}
}