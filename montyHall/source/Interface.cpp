#include "stdafx.h"
#include "Interface.h"


Interface::Interface()
{
	displaySplash();
	//displayMain();
}


Interface::~Interface()
{
}

int Interface::displaySimMenu()
{
	int choice = 0;
	std::cout << "\n     \"Monty Hall Problem\" simulation.\n\n";
	std::cout << "Please select from the following options:\n";
	std::cout << "1) Define Simuation.\n";
	std::cout << "2) Execute Simulation.\n";
	std::cout << "3) Exit Application.\n\n";
	std::cout << "Selection: ";
	validateInteger(std::cin, choice);
	while (!(choice > 0 && choice < 4))
	{
		validateInteger(std::cin, choice, "\nPlease choose one of the given options(1-3).\n");
	}
	return choice;
}

std::shared_ptr<int> Interface::generateSimRequest()
{
	std::shared_ptr<int> temp(new int[3], std::default_delete<int[]>());
	//Now temp.get()[0] = numRuns, temp.get()[1] = doorChoice, temp.get()[2] = switchCase.

	std::cout << "\nPlease enter a number of times you wish to run the simulation(max 500,000): ";
	validateInteger(std::cin, temp.get()[0]);
	while (!(temp.get()[0] > 0 && temp.get()[0] < 500001))
	{
		validateInteger(std::cin, temp.get()[0], "\nPlease select a number of runs between 1 and 500,000.\n");
	}

	std::cout << "\nPlease indicate which door you wish to initially choose in each run of the simulation:\n";
	std::cout << "1)Door #1.\n";
	std::cout << "2)Door #2.\n";
	std::cout << "3)Door #3.\n\n";
	std::cout << "Selection: ";
	validateInteger(std::cin, temp.get()[1]);
	while (!(temp.get()[1] > 0 && temp.get()[1] < 4))
	{
		validateInteger(std::cin, temp.get()[1], "\nPlease choose one of the given options(1-3).\n");
	}

	std::cout << "\nChoose whether to switch doors after the\nfirst door is opened:\n";
	std::cout << "1)Yes.\n";
	std::cout << "2)No.\n\n";
	std::cout << "Selection: ";
	validateInteger(std::cin, temp.get()[2]);
	while (!(temp.get()[2] > 0 && temp.get()[2] < 3))
	{
		validateInteger(std::cin, temp.get()[2], "\n Invalid selection.\n");
	}
	temp.get()[2] = temp.get()[2] == 1 ? 1 : 0; // this will give us a 1 or 0 for our switch case which we can pass as a true or false param to the simulation.
	return(temp);
}

void Interface::validateInteger(std::istream& input, int& variable, const std::string& rangeWarning)
{
	if (rangeWarning != "")
	{
		std::cout << rangeWarning;

	}
	while (!(input >> variable))
	{
		std::cout << "\nPlease enter a number: \n";
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}
}


void Interface::displaySplash()
{
	sf::RenderWindow splashWindow(sf::VideoMode(800, 600), "Splash Screen", sf::Style::None);
	splashWindow.setPosition(sf::Vector2i(500, 170));
	splashWindow.setVerticalSyncEnabled(true);

	while (splashWindow.isOpen())
	{

		sf::Event event;
		while (splashWindow.pollEvent(event))
		{

			switch (event.type)
			{
			case sf::Event::KeyPressed:
				{
					this->displayMain();
					splashWindow.close();
					break;
				}
			case sf::Event::MouseButtonPressed:
				{
					splashWindow.close();
					this->displayMain();
					break;
				}
			case sf::Event::TextEntered:
				{
				
				}
			case sf::Event::Closed:
				{
					splashWindow.close();
				}
			}
		}

		splashWindow.clear(sf::Color(248, 248, 248));
		//draw things
		sf::Texture texture;
		if (!texture.loadFromFile(".\\resources\\img\\splash.png", sf::IntRect(0, 0, 720, 378)));
		{
			//error...
		}
		texture.setSmooth(true);
		texture.setRepeated(false);

		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(40, 222));

		splashWindow.draw(sprite);
		//end current frame
		splashWindow.display();
	}
}

void Interface::displayMain()
{
	sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "Monty Hall Problem Simulator", sf::Style::Close);
	mainWindow.setPosition(sf::Vector2i(500, 170));
	mainWindow.setVerticalSyncEnabled(true);

	while (mainWindow.isOpen())
	{

		sf::Event event;
		while (mainWindow.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::KeyPressed:
				{

				}
				case sf::Event::MouseButtonPressed:
				{

				}
				case sf::Event::TextEntered:
				{

				}
				case sf::Event::Closed:
				{
					mainWindow.close();
				}
			}
		}

		mainWindow.clear(sf::Color(248, 248, 248));

		//Begin Title Def
		sf::Font titleFont;
		sf::Text title;
		sf::Text but1;
		sf::Text but2;
		sf::Text but3;

		sf::RectangleShape defineSimButton(sf::Vector2f(240, 35));
		this->displayButtons(title, but1, but2, but3, titleFont, defineSimButton);
		

		mainWindow.draw(title);
		mainWindow.draw(defineSimButton);
		mainWindow.draw(but1);

		//draw things
		//sf::Texture texture;
		//if (!texture.loadFromFile(".\\resources\\img\\splash.png", sf::IntRect(0, 0, 720, 378)));
		//{
		//	//error...
		//}
		//texture.setSmooth(true);
		//texture.setRepeated(false);

		//sf::Sprite sprite;
		//sprite.setTexture(texture);
		//sprite.setPosition(sf::Vector2f(40, 222));

		//mainWindow.draw(sprite);
		//end current frame
		mainWindow.display();
	}
}

void Interface::displayButtons(sf::Text& title, sf::Text& but1, sf::Text& but2, sf::Text& but3, sf::Font& titleFont, sf::RectangleShape& defineSimButton) {

	//Begin title text
	if (!titleFont.loadFromFile(".\\resources\\font\\calibri.ttf"))
	{
		std::cout << "Error loading font!\n";
	}

	title.setFont(titleFont);
	but1.setFont(titleFont);
	but2.setFont(titleFont);
	but3.setFont(titleFont);

	title.setString("\"Monty Hall Problem\" Simulation");
	but1.setString("Define Simulation.");
	but2.setString("Execute Simulation.");
	but3.setString("Exit Application.");

	title.setCharacterSize(32);
	but1.setCharacterSize(24);
	but2.setCharacterSize(24);
	but3.setCharacterSize(24);

	title.setFillColor(sf::Color::Black);
	but1.setFillColor(sf::Color::Black);
	but2.setFillColor(sf::Color::Black);
	but3.setFillColor(sf::Color::Black);

	float titleWidth = title.getLocalBounds().width;
	float titleStartX = (800 - titleWidth) / 2;
	title.move((800 - titleWidth) / 2, 25);
	//End title text


	defineSimButton.setFillColor(sf::Color(136, 202, 221));
	defineSimButton.setOutlineThickness(2);
	defineSimButton.setOutlineColor(sf::Color::Black);
	defineSimButton.move(titleStartX - 80, 125);
	sf::Vector2f but1Pos = defineSimButton.getPosition();

	but1.move(but1Pos.x + 30, but1Pos.y + 1);
}

