#pragma once
#include "Menu.h"
#include "stdafx.h"
#include "gameConfig.h"

class Lose
{
private:
	sf::RenderWindow *window; // cua so cuar game
	sf::RectangleShape background;
	sf::Texture backgroundTexture;

public:
	Lose();
	~Lose();
	void runLose();

};

