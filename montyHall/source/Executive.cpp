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
	sim = std::make_unique<Simulation>(20000, 1, false);
	try {
		sim->run();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
		std::cout << "UNKNOWN ERROR!!\n";
		//log error to file here.
	}
	displayData();
}

void Executive::displayData()
{
	std::streamsize ss = std::cout.precision();
	float *temp = sim->sendData();
	std::cout << std::fixed;
	std::cout << std::setprecision(0);

	std::cout << "Simulation Results:\n\n\tRuns Executed: ";
	std::cout << temp[0] << "\n";
	std::cout << "\tCars Won:      " << temp[1] << " (";//%'s go inside parens
	std::cout << ")\n\tGoats Won:     " << temp[2] << " (";
	std::cout << ")\n";
	
	std::cout << std::setprecision(ss);
	temp = nullptr;
}