#include "Setting.h"

void Setting::initWindow()
{
	//Create game window
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHight), "Refund", sf::Style::Close | sf::Style::Titlebar);
	//Set frame rate
	window->setFramerateLimit(144);
}

void Setting::initBackGround()
{
	// tao backgruond
	backgroundTexture.loadFromFile("Data/Textures/Background/Home.jpg"); // nap hinh vao
	background.setTexture(&backgroundTexture); // gan backgroundTexture cho background (lay backgroundTexture lam nen)
	background.setSize(sf::Vector2f(screenWidth, screenHight)); // dat kich thuot cho back ground
}

void Setting::initFont()
{
	// Tao 1 doi tuong van ban de hien thi thoi gian
	if (!font.loadFromFile("Data/Textures/Font/PixelGameFont.ttf")) {
		std::cerr << "Failed to load font." << std::endl;
	}
}

void Setting::initText()
{
	t0.setFont(font);
	t0.setCharacterSize(sizetext + 15);
	t0.setPosition(col + 200, 100);
	t0.setFillColor(sf::Color(0, 0, 0));
	t0.setString("TUTORIAL");

	t1.setFont(font);
	t1.setCharacterSize(sizetext);
	t1.setPosition(100, rowDef);
	t1.setFillColor(sf::Color(0, 0, 0));

	t2.setFont(font);
	t2.setCharacterSize(sizetext);
	t2.setPosition(100, rowDef);
	t2.setFillColor(sf::Color(0, 0, 0));

	t3.setFont(font);
	t3.setCharacterSize(sizetext);
	t3.setPosition(100, rowDef);
	t3.setFillColor(sf::Color(0, 0, 0));
}


Setting::Setting()
{
	initWindow();
	initBackGround();
	initFont();
	initText();
	numpage = 1;
}

Setting::~Setting()
{
}

void Setting::renderSetting()
{
	window->draw(t0);
	if (numpage == 1)
	{
		t1.setString("Use A, S, D, W to move.\n");
		window->draw(t1);
	}
	else if (numpage == 2)
	{
		t2.setString("");
		window->draw(t2);
	}
	else if (numpage == 3)
	{
		t3.setString("");
		window->draw(t3);
	}
}

void Setting::runSetting()
{
	sf::Texture leftTexture;
	leftTexture.loadFromFile("Data/Textures/Button/button_left.png");
	sf::Sprite leftButton(leftTexture);
	leftButton.setPosition(screenWidth / 2 - 45, screenHight - 90);

	sf::Texture rightTexture;
	rightTexture.loadFromFile("Data/Textures/Button/button_right.png");
	sf::Sprite rightButton(rightTexture);
	rightButton.setPosition(screenWidth / 2 + 45, screenHight - 90);

	sf::Texture exitTexture;
	exitTexture.loadFromFile("Data/Textures/Button/button_exit.png");
	sf::Sprite exitButton(exitTexture);
	exitButton.setPosition(screenWidth - 90, screenHight - 90);

	// -- chay chuong trinh -- //
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
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
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
					if (leftButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
					{
						if (numpage > 1)
						{
							numpage--;
						}
					}
					if (rightButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
					{
						if (numpage < 3)
						{
							numpage++;
						}
					}
					if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
					{
						window->close();
						Menu menu;
						menu.runMenu();
					}
				}
			}
		}
		// lam sach cua so
		window->clear();
		// ve background
		window->draw(background);
		// ve nut
		window->draw(leftButton);
		window->draw(rightButton);
		window->draw(exitButton);
		// ve chu
		renderSetting();
		// day hinh ve tu bo dem len
		window->display();
	}
}
