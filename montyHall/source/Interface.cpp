#include "stdafx.h"
#include "Interface.h"


Interface::Interface()
{
}


Interface::~Interface()
{
}

int Interface::displaySimMenu()
{
	int choice = 0;
	std::cout << "\n     \"Monty Hall Problem\" simulation.\n\n";
	std::cout << "Please select from the following options:\n";
	std::cout << "1) Define Simuation.\n";
	std::cout << "2) Execute Simulation.\n";
	std::cout << "3) Exit application.\n\n";
	std::cout << "Selection: ";
	validateInteger(std::cin, choice);
	while (!(choice > 0 && choice < 4))
	{
		validateInteger(std::cin, choice, "\nPlease choose one of the given options(1-3).\n");
	}
	return choice;
}

std::shared_ptr<int> Interface::generateSimRequest()
{
	std::shared_ptr<int> temp(new int[3], std::default_delete<int[]>());
	//Now temp.get()[0] = numRuns, temp.get()[1] = doorChoice, temp.get()[2] = switchCase.

	std::cout << "\nPlease enter a number of times you wish to run the simulation(max 500,000): ";
	validateInteger(std::cin, temp.get()[0]);
	while (!(temp.get()[0] > 0 && temp.get()[0] < 500001))
	{
		validateInteger(std::cin, temp.get()[0], "\nPlease select a number of runs between 1 and 500,000.\n");
	}

	std::cout << "\nPlease indicate which door you wish to initially choose in each run of the simulation:\n";
	std::cout << "1)Door #1.\n";
	std::cout << "2)Door #2.\n";
	std::cout << "3)Door #3.\n\n";
	std::cout << "Selection: ";
	validateInteger(std::cin, temp.get()[1]);
	while (!(temp.get()[1] > 0 && temp.get()[1] < 4))
	{
		validateInteger(std::cin, temp.get()[1], "\nPlease choose one of the given options(1-3).\n");
	}

	std::cout << "\nChoose whether to switch doors after the\nfirst door is opened:\n";
	std::cout << "1)Yes.\n";
	std::cout << "2)No.\n\n";
	std::cout << "Selection: ";
	validateInteger(std::cin, temp.get()[2]);
	while (!(temp.get()[2] > 0 && temp.get()[2] < 3))
	{
		validateInteger(std::cin, temp.get()[2], "\n Invalid selection.\n");
	}
	temp.get()[2] = temp.get()[2] == 1 ? 1 : 0; // this will give us a 1 or 0 for our switch case which we can pass as a true or false param to the simulation.
	return(temp);
}

void Interface::validateInteger(std::istream& input, int& variable, const std::string& rangeWarning)
{
	if (rangeWarning != "")
	{
		std::cout << rangeWarning;

	}
	while (!(input >> variable))
	{
		std::cout << "\nPlease enter a number: \n";
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}
}
