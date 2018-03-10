#pragma once
#include <memory>
#include <iomanip>
#include "Simulation.h"
#include "Interface.h"

class Simulation;
class Door;
class Interface;

class Executive
{
public:
	Executive();
	~Executive();

	void run();

private:
	std::unique_ptr<Simulation> m_sim;
	std::unique_ptr<Interface> m_interface;

	void displayData();
};
