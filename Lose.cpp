#include "Lose.h"

Lose::Lose()
{
	// khoi tao cua so
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHight), "Refund", sf::Style::Close | sf::Style::Titlebar);
	// cai dat toc do khung hinh
	window->setFramerateLimit(144);
	background.setSize(sf::Vector2f(screenWidth, screenHight)); // dat kich thuot cho back ground
	backgroundTexture.loadFromFile("Data/Textures/Background/Lose.jpg"); // nap hinh vao
	background.setTexture(&backgroundTexture); // gan backgroundTexture cho background (lay backgroundTexture lam nen)
}

Lose::~Lose()
{
	delete window;
}

void Lose::runLose()
{
	sf::Texture returnTexture; // tao doi tuong luu anh
	returnTexture.loadFromFile("Data/Textures/Button/button_return.png"); // nap anh vao
	sf::Sprite returnButton(returnTexture); // gan startTexture cho startButton (startButton sua dung hinh anh tai vao startTexture)
	returnButton.setPosition(screenWidth / 2 - 55, screenHight / 2); // dat vi tri cho nut
	
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
	while (window->isOpen()) 
	{
		sf::Event ev;
		while (window->pollEvent(ev)) 
		{
			// truong hop bam tat cua so
			if (ev.type == sf::Event::Closed) 
			{
				window->close(); // dong cua so
			}
			// truong hop bam nut ESC
			else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			{
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
					if (returnButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) 
					{
						window->close(); // dong cua so
						Menu menu;
						menu.runMenu();
					}
					if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) 
					{
						window->close();
					}
				}
			}
		}
		// lam sach cua so
		window->clear();
		// ve background
		window->draw(background);
		// ve nut
		window->draw(returnButton);
		window->draw(exitButton);
		// day hinh ve tu bo dem len
		window->display();
	}
}
