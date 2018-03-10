#include "stdafx.h"
#include "Interface.h"


Interface::Interface()
{
}


Interface::~Interface()
{
}

int Interface::displaySimMenu() const
{
	int choice;
	std::cout << "\n\t\"Monty Hall Problem\" simulation.\n\n";
	std::cout << "Please select from the following options:\n";
	std::cout << "1) Define Simuation.\n";
	std::cout << "2) Execute Simulation.\n";
	std::cout << "3) Exit application.\n\n";
	std::cout << "Selection: ";
	validateInteger(std::cin, choice);
	//executeChoice(choice); 
	
	
	return 0;
}

void Interface::validateInteger(std::istream& input, int& variable) const
{
	while (!(input >> variable))
	{
		std::cout << "Please enter a number: \n";
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}
}