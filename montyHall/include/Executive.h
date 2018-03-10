#pragma once
#include <memory>
#include <iomanip>
#include "Simulation.h"
#include "Interface.h"

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

	std::unique_ptr<Interface> m_interface;

	void displayData();

};

