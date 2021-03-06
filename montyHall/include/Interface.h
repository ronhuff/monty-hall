#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Executive.h"

class Interface
{
public:
	Interface();
	~Interface();

	int displaySimMenu();
	
	std::shared_ptr<int> generateSimRequest();

private:
	void validateInteger(std::istream& stream, int& input, const std::string& rangeWarning = "");

};

