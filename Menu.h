#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#define Max_main_menu 4

class Menu
{
private:
	int MainMenuSelected; // vi tri lua chon
	sf::Font font; // font chu
	sf::Text mainMenu[Max_main_menu]; // chu tren menu


public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow& window); // 
	void MoveUp(); // di chuyen len 
	void MoveDown(); // di chuyen xuong
	void RunMenu();
	int MainMenuPressed() { return MainMenuSelected; }

};

