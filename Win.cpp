#include "Win.h"

Win::Win()
{
	// khoi tao cua so
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHight), "Refund", sf::Style::Close | sf::Style::Titlebar);
	// cai dat toc do khung hinh
	window->setFramerateLimit(144);
	background.setSize(sf::Vector2f(screenWidth, screenHight)); // dat kich thuot cho back ground
	backgroundTexture.loadFromFile("Data/Textures/Background/Win.jpg"); // nap hinh vao
	background.setTexture(&backgroundTexture); // gan backgroundTexture cho background (lay backgroundTexture lam nen)
	font.loadFromFile("Data/Textures/Font/PixelGameFont.ttf");
	t1.setFont(font);
	t1.setCharacterSize(50);
	t1.setPosition(col + 100, 400);
	t1.setFillColor(sf::Color(255, 255, 255));

	t2.setFont(font);
	t2.setCharacterSize(50);
	t2.setPosition(col + 100, 500);
	t2.setFillColor(sf::Color(255, 255, 255));
}

Win::~Win()
{
	delete window;
}

void Win::runWin(float time)
{

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
	t1.setString("Score: " + std::to_string(time));
	while (window->isOpen()) {
		sf::Event ev;
		while (window->pollEvent(ev)) {
			// truong hop bam tat cua so
			if (ev.type == sf::Event::Closed) {
				window->close(); // dong cua so
			}
			// truong hop bam nut ESC
			else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			{
				window->close(); // dong cua so
			}
			else if (ev.type == sf::Event::TextEntered)
			{
				name += static_cast<char>(ev.text.unicode);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && name.size() > 0)
			{
				name.resize(name.size() - 1);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && name.size() > 1)
			{
				std::ofstream outputFile("Record.txt", std::ios::app);
				if (outputFile.is_open()) 
				{
					outputFile << name << "\n";
					outputFile << time << "\n";

					outputFile.close();
				}
				else 
				{
					std::cerr << "Unable to open file for appending.\n";
				}
				window->close(); // dong cua so
				Menu menu;
				menu.runMenu();
			}
			// truong hop nhan chuot
			else if (ev.type == sf::Event::MouseButtonPressed)
			{
				// nhan chuot trai
				if (ev.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i mousePosition = sf::Mouse::getPosition(*window); // lay toa do hien tai cua con tro chuot
					// kiem tra vi tri chuot nam o nut nao
					if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
					{
						window->close();
					}
				}
			}
		}
		t2.setString("Name: " + name);
		// lam sach cua so
		window->clear();
		// ve background
		window->draw(background);
		// ve nut
		window->draw(exitButton);
		// ve chu
		window->draw(t1);
		window->draw(t2);
		// day hinh ve tu bo dem len
		window->display();
	}
}
