#pragma once
#include <iostream>
#include <string>
#include <memory>

class Interface
{
public:
	Interface();
	~Interface();

	int displaySimMenu();
	void executeChoice(const int& menuChoice);
	
	std::shared_ptr<int> generateSimRequest();
private:

	void validateInteger(std::istream& stream, int& input, const std::string& rangeWarning = "");
};

