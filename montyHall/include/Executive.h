#pragma once
#include <memory>
#include <iomanip>
#include "Simulation.h"

class Simulation;
class Door;

class Executive
{
public:
	Executive();
	~Executive();

	void run();
private:
	std::unique_ptr<Simulation> sim;

	void displayData();

};

