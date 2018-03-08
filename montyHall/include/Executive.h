#pragma once
#include <memory>
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
};

