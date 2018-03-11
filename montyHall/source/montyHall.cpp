// montyHall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Executive.h"
#include <iostream>
#include <ctime>

void validateInteger(std::istream& stream, int& input, const std::string& rangeWarning = "");

int main()
{


	
	std::cout << "Please choose a graphical or console user interface.\n";
	std::cout << "1) Graphical.\n";
	std::cout << "2) Console.\n";
	int gui = 0;
	validateInteger(std::cin, gui);
	while (!(gui > 0 && gui < 3))
	{
		validateInteger(std::cin, gui, "Values must be between 1-2.\n");
	}
	if (gui == 1)
	{
		std::srand(std::time(nullptr));
		Executive exec(true);
		exec.run();
	}
	else if (gui == 2)
	{
		std::srand(std::time(nullptr));
		Executive exec(false);
		exec.run();
	}

	std::cin.get();
    return 0;
}

void validateInteger(std::istream& input, int& variable, const std::string& rangeWarning)
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