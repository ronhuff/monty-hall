#include "stdafx.h"
#include "Interface.h"


Interface::Interface()
	:gui(false)
{
	displaySplash();
	//displayMain();
}

Interface::Interface(bool gui)
	:gui(true)
{
	displaySplash();
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
	if (!titleFont.loadFromFile(".\\resources\\font\\calibri.ttf"))
	{
		std::cout << "Error loading font!\n";
	}
	
	while (splashWindow.isOpen())
	{

		sf::Event event;
		while (splashWindow.pollEvent(event))
		{

			switch (event.type)
			{
			case sf::Event::KeyPressed:
			{
				if (gui)
				{
					splashWindow.close();
					this->displayMain();
					break;
				}
				else
				{
					splashWindow.close();
					break;
				}
			}
			case sf::Event::MouseButtonPressed:
			{
				if (gui)
				{
					splashWindow.close();
					this->displayMain();
					break;
				}
				else
				{
					splashWindow.close();
					break;
				}
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
		
		//Load splash screen image.
		sf::Texture texture;
		if (!texture.loadFromFile(".\\resources\\img\\splash.png", sf::IntRect(0, 0, 720, 378)));
		{
			//error...
		}
		//Define greeting
		sf::Text greeting;
		greeting.setFont(titleFont);
		greeting.setString("\t\t\t\tWelcome to the\n\"Monty Hall Problem\" simulator!");
		greeting.setCharacterSize(38);
		greeting.setFillColor(sf::Color(39, 118, 139));
		greeting.setPosition(155, 50);

		//Configure splash screen image
		texture.setSmooth(true);
		texture.setRepeated(false);
		sf::Sprite sprite;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(40, 222));

		splashWindow.draw(greeting);
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

		this->displayButtons();// This defines button parameters, size, border, color, text, etc.

		mainWindow.draw(title);
		mainWindow.draw(butOneBox);
		mainWindow.draw(butTwoBox);
		mainWindow.draw(butThreeBox);
		mainWindow.draw(butOneText);
		mainWindow.draw(butTwoText);
		mainWindow.draw(butThreeText);

		//end current frame
		mainWindow.display();
	}
}

void Interface::displayButtons() {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	//Begin title text
	if (!titleFont.loadFromFile(".\\resources\\font\\calibri.ttf"))
	{
		std::cout << "Error loading font!\n";
	}
	//Initialize Text
	title = sf::Text();
	butOneText = sf::Text();
	butTwoText = sf::Text();
	butThreeText = sf::Text();

	//Initialize Rectangles
	butOneBox = sf::RectangleShape(sf::Vector2f(240, 45));
	butTwoBox = sf::RectangleShape(sf::Vector2f(280, 60));
	butThreeBox = sf::RectangleShape(sf::Vector2f(240, 35));

	//Set Font
	title.setFont(titleFont);
	butOneText.setFont(titleFont);
	butTwoText.setFont(titleFont);
	butThreeText.setFont(titleFont);

	//Position title
	title.move(180, 25);

	//Define button text
	title.setString("\"Monty Hall Problem\" Simulation");
	butOneText.setString("Define Simulation.");
	butTwoText.setString("Execute Simulation.");
	butThreeText.setString("Exit Application.");

	//Define font text
	title.setCharacterSize(32);
	butOneText.setCharacterSize(24);
	butTwoText.setCharacterSize(24);
	butThreeText.setCharacterSize(24);

	//Define button color
	title.setFillColor(sf::Color::Black);
	butOneText.setFillColor(sf::Color::Black);
	butTwoText.setFillColor(sf::Color::Black);
	butThreeText.setFillColor(sf::Color::Black);

	//Button One/Text Positioning
	butOneBox.setFillColor(sf::Color(136, 202, 221));
	butOneBox.setOutlineThickness(2);
	butOneBox.setOutlineColor(sf::Color::Black);
	butOneBox.move(260, 125);
	butOneText.move(butOneBox.getPosition() + sf::Vector2f(30, 4));

	//Button Two/Text Positioning
	butTwoBox.setFillColor(sf::Color(108, 198, 68));
	butTwoBox.setOutlineThickness(2);
	butTwoBox.setOutlineColor(sf::Color::Black);
	butTwoBox.move(240, 190);
	butTwoText.setPosition(butTwoBox.getPosition() + sf::Vector2f(42, 12));

	//Button Three/Text Positioning
	butThreeBox.setFillColor(sf::Color(237, 82, 73));
	butThreeBox.setOutlineThickness(2);
	butThreeBox.setOutlineColor(sf::Color::Black);
	butThreeBox.move(260, 280);
	butThreeText.setPosition(butThreeBox.getPosition() + sf::Vector2f(34, 4));
}

