#pragma once

#include "gameConfig.h"
#include "stdafx.h"

enum HOST_ANIMATION_STATES {SLEEP, WAKEUP};

/*
## Class Host ##
- thuc hien cac cong viec lien quan den nhan vat chu nha
	+ hien thi
	+ thay doi
*/

class Host
{
	sf::Sprite hostSprite; // doi tuong in ra man hinh
	sf::Texture textureSheet; // doi tuong luu anh
	sf::Clock animationTimer; // do thoi gian 
	//Animation
	short animState; // trang thai cua chu nha
	sf::IntRect currentFrame; // khung hinh de cat anh
	//Movement

	//Core
	void initVariables(); // khoi tao trang thai cua chu nha la ngu (SLEEP)
	void initTexture(); // khoi tao hinh anh
	void initSprite(); // khoi tao doi tuong de ve
	void initAnimations(); // khoi tao thoi gian

public:
	Host();
	virtual ~Host();

	//Functions
	sf::Vector2f getHostPosition(); // tra ve vi tri cua chu nha
	void moveHost(float x, float y);
	
	void updateVariables(); // cap nhat trang thai cua chu nha (thuc day : WAKEUP)
	void updateAnimation(); // cap nhat chuyen dong cua chu nha
	void update(); // cap nhat thay doi cua chu nha
	void render(sf::RenderTarget& target); // ve chu nha

};

