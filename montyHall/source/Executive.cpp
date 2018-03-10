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
	sim = std::make_unique<Simulation>(20000, 1, true);
	try {
		sim->run();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		std::cout << "UNKNOWN ERROR!!\n";
		//log error to file here.
	}
}