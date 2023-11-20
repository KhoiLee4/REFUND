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
	sf::Texture floorTexture;
	sf::Sprite floorSprite;
	sf::Texture wall1Texture;
	sf::Sprite wall1Sprite;
	sf::Texture wall2Texture;
	sf::Sprite wall2Sprite;
	sf::Texture wall3Texture;
	sf::Sprite wall3Sprite;
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

