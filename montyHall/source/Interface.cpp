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
	std::cout << "\n\t\"Monty Hall Problem\" simulation.\n\n";
	std::cout << "Please select from the following options:\n";
	std::cout << "1) Define Simuation.\n";
	std::cout << "2) Execute Simulation.\n";
	std::cout << "3) Exit application.\n\n";
	std::cout << "Selection: ";
	validateInteger(std::cin, choice);
	while (!(choice > 0 && choice < 4))
	{
		validateInteger(std::cin, choice, "\nPlease choose one of the given options(1-3). \n");
	}
	
	
	return choice;
}

void Interface::validateInteger(std::istream& input, int& variable, std::string rangeWarning)
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