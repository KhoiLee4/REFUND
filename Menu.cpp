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
	std::cout << "start setting\n"; // kiem tra luong chay
	window->close();
	// chay vao game
	Setting setting;
	setting.runSetting();
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
	//sf::Font font; // tao font
	//sf::Text t0;
	//if (!font.loadFromFile("Data/Textures/Font/PixelGameFont.ttf")) {
	//	std::cerr << "Failed to load font." << std::endl;
	//}
	//t0.setFont(font);
	//t0.setCharacterSize(80);
	//t0.setPosition(700, 100);
	//t0.setFillColor(sf::Color(0, 0, 0));
	//t0.setString("REFUND");
	// -- khoitao -- //
	// tao backgruond
	sf::RectangleShape background; // background la hinh vuong
	background.setSize(sf::Vector2f(screenWidth, screenHight)); // dat kich thuot cho back ground
	sf::Texture backgroundTexture; // tao doi tuong luu anh
	backgroundTexture.loadFromFile("Data/Textures/Background/Home.jpg"); // nap hinh vao
	background.setTexture(&backgroundTexture); // gan backgroundTexture cho background (lay backgroundTexture lam nen)

	// tao nut start
	sf::Texture startTexture; // tao doi tuong luu anh
	startTexture.loadFromFile("Data/Textures/Button/button_start.png"); // nap anh vao
	sf::Sprite startButton(startTexture); // gan startTexture cho startButton (startButton sua dung hinh anh tai vao startTexture)
	startButton.setPosition(screenWidth / 2 - 55, screenHight / 2 - 110); // dat vi tri cho nut

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
	exitButton.setPosition(screenWidth - 90, screenHight - 90);

	// tao am thanh
	sf::SoundBuffer buffer;
	buffer.loadFromFile("Data/Textures/Sound/Menu.flac");
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

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
						sound.stop();
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
		//window->draw(t0);
		// ve cac nut
		window->draw(startButton);
		window->draw(recordButton);
		window->draw(settingButton);
		window->draw(exitButton);
		// day hinh ve tu bo dem len
		window->display();
	}
}

