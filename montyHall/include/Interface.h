#pragma once
#include <iostream>
#include <string>

class Interface
{
public:
	Interface();
	~Interface();

	int displaySimMenu();

private:

	void validateInteger(std::istream& stream, int& input, std::string rangeWarning = "");
};

