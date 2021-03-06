#include "stdafx.h"
#include "Executive.h"



Executive::Executive()
	:m_interface(std::make_unique<Interface>())
{
	
}


Executive::~Executive()
{

}

void Executive::run()
{
	std::shared_ptr<int> simRequestData;
	bool quit = false;
	while (!quit)
	{
		int choice = m_interface->displaySimMenu();
		if (choice == 1)
		{
			simRequestData = m_interface->generateSimRequest();
			bool switchCase = false;
			if (simRequestData.get()[2] == 1)
			{
				switchCase = true;
			}
			m_sim = std::make_unique<Simulation>(simRequestData.get()[0], simRequestData.get()[1], switchCase);
			std::cout << "\nSimulation parameters accepted.\n";
		}
		else if (choice == 2)
		{
			if (m_sim == nullptr)
			{
				std::cout << "\nThere is currently no simulation available for execution,\nfeel free to define one.\n";
			}
			else
			{
				m_sim->run();
				displayData();
				m_sim.reset(nullptr);
			}
		}
		else if (choice == 3)
		{
			quit = true;// control condition.
			std::cout << "\nExiting application...\n";
		}
	}
}

void Executive::displayData()
{
	std::streamsize ss = std::cout.precision();
	std::shared_ptr<float> temp = m_sim->sendData();
	std::cout << std::fixed;
	std::cout << std::setprecision(0);

	std::cout << "Simulation Results:\n\n\tRuns Executed: ";
	std::cout << temp.get()[0] << "\n";
	std::cout << "\tCars Won:      " << temp.get()[1];
	std::cout << "\n\tGoats Won:     " << temp.get()[2];
	std::cout << "\n\n";
	
	std::cout << std::setprecision(ss);
	temp = nullptr;
}
