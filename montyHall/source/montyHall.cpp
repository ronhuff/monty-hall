// montyHall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Executive.h"
#include <iostream>
#include <ctime>

int main()
{
	std::srand(std::time(nullptr));

	Executive exec;
	exec.run();

	std::cin.get();
    return 0;
}

