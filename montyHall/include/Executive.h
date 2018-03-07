#pragma once
#include "Door.h"
#include <memory>

class Executive
{
public:
	Executive();
	~Executive();

private:
	std::shared_ptr<Door> m_doors[3];
};

