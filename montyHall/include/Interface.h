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
	Interface(bool gui);
	~Interface();

	int displaySimMenu();
	
	std::shared_ptr<int> generateSimRequest();

private:
	void validateInteger(std::istream& stream, int& input, const std::string& rangeWarning = "");
	void displaySplash();
	void displayMain();
	void displayButtons();

	bool butClicked(sf::Event& event, sf::RectangleShape& but);


	bool gui;
	sf::Font titleFont;
	sf::Text title;
	sf::Text butOneText;
	sf::Text butTwoText;
	sf::Text butThreeText;

	sf::RectangleShape butOneBox;
	sf::RectangleShape butTwoBox;
	sf::RectangleShape butThreeBox;
};

