#pragma once
#include "Menu.h"
#include "stdafx.h"
#include "gameConfig.h"

class Win
{
private:
	sf::RenderWindow* window; // cua so cuar game
	sf::RectangleShape background;
	sf::Texture backgroundTexture;
	sf::Font font;
	sf::Text t1;
	sf::Text t2;
	std::string name;

public:
	Win();
	~Win();
	void runWin(float time);

};

