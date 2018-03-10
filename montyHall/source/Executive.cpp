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
	std::shared_ptr<int> simRequestData;
	int choice = m_interface->displaySimMenu();
	if (choice == 1)
	{
		simRequestData = m_interface->generateSimRequest();
		sim = std::make_unique<Simulation>(simRequestData.get()[0], simRequestData.get()[1], simRequestData.get()[2]);
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
	else
	{
		std::cout << "\nExiting application...\n";
	}

	
	
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