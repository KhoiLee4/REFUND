#include "Menu.h"

Menu::Menu()
{
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHight), "Refund", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(144);

}

Menu::~Menu()
{
}

void Menu::optionStart()
{
	std::cout << "start\n";
	//window->close();
	Game game;
	while (game.getWindow().isOpen())
	{
		game.update();
		game.render();
	}
}

void Menu::optionSetting()
{
}

void Menu::optionRecord()
{
}

void Menu::runMenu()
{
	// tao backgruond
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(screenWidth, screenHight));
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Data/Textures/Background/h_background.jpg");
	background.setTexture(&backgroundTexture);

	// tao nut start
	sf::Texture startTexture;
	startTexture.loadFromFile("Data/Textures/Button/button_start.png");
	sf::Sprite startButton(startTexture);
	startButton.setPosition(screenWidth / 2 - 40, screenHight / 2 - 80);

	// tao nut record
	sf::Texture recordTexture;
	recordTexture.loadFromFile("Data/Textures/Button/button_record.png");
	sf::Sprite recordButton(recordTexture);
	recordButton.setPosition(startButton.getPosition().x - (20 + recordTexture.getSize().x), startButton.getPosition().y + startTexture.getSize().y + 20);

	// tao nut setting
	sf::Texture settingTexture;
	settingTexture.loadFromFile("Data/Textures/Button/button_setting.png");
	sf::Sprite settingButton(settingTexture);
	settingButton.setPosition(startButton.getPosition().x + startTexture.getSize().x + 20, startButton.getPosition().y + startTexture.getSize().y + 20);

	//  tao nut exit
	sf::Texture exitTexture;
	exitTexture.loadFromFile("Data/Textures/Button/button_exit.png");
	sf::Sprite exitButton(exitTexture);
	exitButton.setPosition(screenWidth - 50, screenHight - 50);

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

					if (startButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
						optionStart();
					}

					if (recordButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
						optionRecord();
					}

					if (settingButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
						optionSetting();
					}

					if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
						window->close();
					}
				}
			}
		}

		window->clear();
		// ve background
		window->draw(background);
		// ve cac nut
		window->draw(startButton);
		window->draw(recordButton);
		window->draw(settingButton);
		window->draw(exitButton);

		window->display();
	}
}

