#include "Menu.h"

Menu::Menu()
{
	// khoi tao cua so
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHight), "Refund", sf::Style::Close | sf::Style::Titlebar);
	// cai dat toc do khung hinh
	window->setFramerateLimit(144);
}

Menu::~Menu()
{
	delete window;
}

void Menu::optionStart()
{
	std::cout << "start\n"; // kiem tra luong chay
	window->close();
	// chay vao game
	Game game;
	game.runGame();
}

void Menu::optionSetting()
{
}

void Menu::optionRecord()
{
	std::cout << "start record\n"; // kiem tra luong chay
	window->close();
	// chay vao game
	Record record;
	record.runRecord();
}

void Menu::runMenu()
{
	// -- khoitao -- //
	// tao backgruond
	sf::RectangleShape background; // background la hinh vuong
	background.setSize(sf::Vector2f(screenWidth, screenHight)); // dat kich thuot cho back ground
	sf::Texture backgroundTexture; // tao doi tuong luu anh
	backgroundTexture.loadFromFile("Data/Textures/Background/h_background.jpg"); // nap hinh vao
	background.setTexture(&backgroundTexture); // gan backgroundTexture cho background (lay backgroundTexture lam nen)

	// tao nut start
	sf::Texture startTexture; // tao doi tuong luu anh
	startTexture.loadFromFile("Data/Textures/Button/button_start.png"); // nap anh vao
	sf::Sprite startButton(startTexture); // gan startTexture cho startButton (startButton sua dung hinh anh tai vao startTexture)
	startButton.setPosition(screenWidth / 2 - 40, screenHight / 2 - 80); // dat vi tri cho nut

	// tao nut record
	// tuong tu nut start
	sf::Texture recordTexture;
	recordTexture.loadFromFile("Data/Textures/Button/button_record.png");
	sf::Sprite recordButton(recordTexture);
	recordButton.setPosition(startButton.getPosition().x - (20 + recordTexture.getSize().x), startButton.getPosition().y + startTexture.getSize().y + 20);

	// tao nut setting
	// tuong tu nut start
	sf::Texture settingTexture;
	settingTexture.loadFromFile("Data/Textures/Button/button_setting.png");
	sf::Sprite settingButton(settingTexture);
	settingButton.setPosition(startButton.getPosition().x + startTexture.getSize().x + 20, startButton.getPosition().y + startTexture.getSize().y + 20);

	//  tao nut exit
	// tuong tu nut start
	sf::Texture exitTexture;
	exitTexture.loadFromFile("Data/Textures/Button/button_exit.png");
	sf::Sprite exitButton(exitTexture);
	exitButton.setPosition(screenWidth - 50, screenHight - 50);

	// -- chay chuong trinh -- //
	while (window->isOpen()) {
		sf::Event event; // luu giu cac su kien
		while (window->pollEvent(event)) {
			// truong hop bam tat cua so
			if (event.type == sf::Event::Closed) {
				window->close(); // dong cua so
			}
			// truong hop nhan chuot
			if (event.type == sf::Event::MouseButtonPressed) {
				// nhan chuot trai
				if (event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i mousePosition = sf::Mouse::getPosition(*window); // lay toa do hien tai cua con tro chuot
					// kiem tra vi tri chuot nam o nut nao
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
		// lam sach cua so
		window->clear();
		// ve background
		window->draw(background);
		// ve cac nut
		window->draw(startButton);
		window->draw(recordButton);
		window->draw(settingButton);
		window->draw(exitButton);
		// day hinh ve tu bo dem len
		window->display();
	}
}

