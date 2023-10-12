#include "Menu.h"

Menu::Menu(float width, float height)
{
	//cai dat font chu
	if (!font.loadFromFile("PixelGameFont.ttf"))
	{
		std::cout << "No font is here";
	}

	//PLAY
	mainMenu[0].setFont(font); // cai dat font chu
	mainMenu[0].setFillColor(sf::Color::White); // mau chu
	mainMenu[0].setString("Play"); // noi dung cua chu
	mainMenu[0].setCharacterSize(70); // kich thuoc
	mainMenu[0].setPosition(400, 200); // vi tri chu tren mang hinh

	//OPTION
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 300);

	//ABOUT
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("About");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 400);

	//EXIT
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(400, 500);

	MainMenuSelected = -1;
}
Menu::~Menu()
{

}
// draw main menu
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; i++)
	{
		window.draw(mainMenu[i]);
	}
}
// move up
void Menu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected--;
		if (MainMenuSelected == -1)
		{
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}
// move down
void Menu::MoveDown()
{
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Blue);
	}
}

void Menu::RunMenu()
{
	// make window
	sf::RenderWindow menu(sf::VideoMode(960, 720), "Menu", sf::Style::Default);
	Menu mainMenu(menu.getSize().x, menu.getSize().y);

	// set background
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(960, 720));
	sf::Texture mainTexture;
	mainTexture.loadFromFile("cyberpunk-street.png");
	background.setTexture(&mainTexture);

	// photo to the game 
	// window play, option, about
	////


	////
	// game loop
	while (menu.isOpen())
	{
		sf::Event ev;
		while (menu.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				menu.close();
			if (ev.type == sf::Event::KeyReleased)
			{
				if (ev.key.code == sf::Keyboard::Up)
				{
					mainMenu.MoveUp();
					break;
				}
				if (ev.key.code == sf::Keyboard::Down)
				{
					mainMenu.MoveDown();
					break;
				}
				if (ev.key.code == sf::Keyboard::Return)
				{
					sf::RenderWindow PLAY(sf::VideoMode(960, 720), "game_play");
					sf::RenderWindow OPTION(sf::VideoMode(960, 720), "game_option");
					sf::RenderWindow ABOUT(sf::VideoMode(960, 720), "game_about");

					int x = mainMenu.MainMenuPressed();
					if (x == 0)
					{
						while (PLAY.isOpen())
						{
							sf::Event evplay;
							while (PLAY.pollEvent(evplay))
							{
								if (evplay.type == sf::Event::Closed)
									PLAY.close();
								if (evplay.type == sf::Event::KeyPressed)
								{
									if (evplay.key.code == sf::Keyboard::Escape)
										PLAY.close();
								}
							}
							OPTION.close();
							ABOUT.close();
							PLAY.clear();
							//PLAY.draw(Pbackgruond); // draw window play
							PLAY.display();
						}
					}
					if (x == 1)
					{
						while (OPTION.isOpen())
						{
							sf::Event evop;
							while (OPTION.pollEvent(evop))
							{
								if (evop.type == sf::Event::Closed)
									OPTION.close();
								if (evop.type == sf::Event::KeyPressed)
								{
									if (evop.key.code == sf::Keyboard::Escape)
										OPTION.close();
								}
							}
							PLAY.close();
							OPTION.clear();
							//OPTION.draw(Obackgruond); // draw window option
							ABOUT.close();
							OPTION.display();
						}
					}
					if (x == 2)
					{
						while (ABOUT.isOpen())
						{
							sf::Event evab;
							while (ABOUT.pollEvent(evab))
							{
								if (evab.type == sf::Event::Closed)
									ABOUT.close();
								if (evab.type == sf::Event::KeyPressed)
								{
									if (evab.key.code == sf::Keyboard::Escape)
										ABOUT.close();
								}
							}
							PLAY.close();
							OPTION.clear();
							ABOUT.clear();
							//ABOUT.draw(Abackgruond); // draw window about
							ABOUT.display();
						}
					}
					if (x == 3)
						menu.close();
					break;
				}
			}
		}
		menu.clear();
		menu.draw(background);
		mainMenu.draw(menu);
		menu.display();
	}
}


