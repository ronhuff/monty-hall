#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "Executive.h"
#include <SFML/Graphics.hpp>

class Interface
{
public:
	Interface();
	~Interface();

	int displaySimMenu();
	
	std::shared_ptr<int> generateSimRequest();

private:
	void validateInteger(std::istream& stream, int& input, const std::string& rangeWarning = "");
	void displaySplash();
	void displayMain();
};

