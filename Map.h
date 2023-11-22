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
	sf::Texture wall4Texture;
	sf::Sprite wall4Sprite;
	//Player player;

	void initTexture();
	void initSprite();


public:
	Map();
	virtual ~Map();

	bool checkFrame(); // kiem tra map da vuot khung hinh chua
	bool checkRangePlayer(sf::Vector2f playerPosition, short move); // kiem tra vi tri cua nha vat
	bool checkWall(float y); // kiem tra vi tri nhan vat de in tuong
	//void update(Player *player);
	void moveMap(float x, float y);
	void render1(sf::RenderTarget& target); // ve tuong 1
	void render2(sf::RenderTarget& target); // ve tuong 2
	void render3(sf::RenderTarget& target); // ve tuong 3
	void render4(sf::RenderTarget& target); // ve tuong 4
};

