#pragma once

#include "Player.h"
#include "stdafx.h"

enum ANIMATION_STATES {
	LEFT = 1,
	RIGHT,
	UP,
	DOWN
};

/*
## Class Map ##
- thuc hien cong viet lien quan den 
*/

class Map
{
private:
	sf::Texture mapTexture;
	sf::Sprite mapSprite;
	//Player player;

	void initTexture();
	void initSprite();


public:
	Map();
	virtual ~Map();

	bool checkFrame(); // kiem tra map da vuot khung hinh chua
	//bool checkRangePlayer(Player *player); // kiem tra vi tri cua nha vat
	//void update(Player *player);
	void moveMap(float x, float y);
	void render(sf::RenderTarget& target); // ve map

};

