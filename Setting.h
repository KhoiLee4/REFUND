#pragma once

#include "Menu.h"
#include "stdafx.h"
#include "gameConfig.h"

class Setting
{
private:
	sf::RenderWindow* window; // cua so cuar game
	sf::Texture backgroundTexture; // tao doi tuong luu anh
	sf::RectangleShape background; // background la hinh vuong
	sf::Font font; // tao font
	sf::Text t0;
	sf::Text t1;
	sf::Text t2;
	sf::Text t3;
	sf::Event ev; // bien bat su kien
	int numpage;

	void initWindow();
	void initBackGround();
	void initFont();
	void initText();

public:
	Setting();
	~Setting();

	void renderSetting();
	void runSetting();
};

