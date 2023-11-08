#pragma once

#include "gameConfig.h"
#include "stdafx.h"


enum PLAYER_ANIMATION_STATES {
	IDLE = 0, 
	MOVING_LEFT, 
	MOVING_RIGHT, 
	MOVING_UP, 
	MOVING_DOWN
};

/*
## Class Player ##
- thuc hien cac cong viec lien quan den nhan vat
	+ 

*/

class Player
{
private:
	sf::Sprite thiefSprite; // doi tuong luu anh
	sf::Texture textureSheet; // doi tuong de ve
	sf::Clock animationTimer; // bien do thoi gia
	bool checkSlowly; // kiem tra nhan vat dang di nhanh hay cham

	//Animation
	short animState;
	sf::IntRect currentFrame;
	//Movement
	float moveSpeed; // toc do di chuyen
	
	//Core
	void initVariables(); // khoi tao trang thai nhan vat dung im
	void initTexture(); // khoi tao hinh anh
	void initSprite(); // khoi tao nhan vat
	void initAnimations(); // khoi tao thoi gian

public:
	Player();
	virtual ~Player();

	//Functions
	bool getCheckSlowly(); // tra ve checkSlowly
	short getanimState(); // tra ve animState
	float getMoveSpeed(); // tra ve toc do di chuyen
	sf::Vector2f getThiefPosition(); // tra ve vi tri nhan vat
	sf::FloatRect getThiefGlobalBounds(); // tra ve khung hinh cua nhan vat
	void checkRange(); // kiem tra nhan vat da di toi vach gioi han chua
	void setPlayerPosition(float x, float y); // dat lai vi tri nhan vat

	void updateMovement(); // cap nhat di chuyen nhat vat
	void updateAnimation(); // cap nhat hinh anh nhan vat
	void update(); // cap nhat nhan vat
	void render(sf::RenderTarget& target); // ve nhan vat

};

