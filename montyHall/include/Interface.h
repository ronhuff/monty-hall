#pragma once
#include <iostream>

class Interface
{
public:
	Interface();
	~Interface();

	int displaySimMenu() const;

private:

	void validateInteger(std::istream&, int&) const;
};

