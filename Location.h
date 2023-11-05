#pragma once

#include "stdafx.h"

/*
## Class Location ##
- thuc hien cac cong viec lien quan den do vat tai noi tra
	+ 

*/

class Location
{
private:
	std::vector<sf::Texture> locationTextures; // luu hinh anh do vat cam tra
	std::vector<sf::Texture> itemTextures; // luu hinh anh vi tri de do vat
	std::vector<sf::Sprite> locationSprite; // doi tuong in vi tri
	std::vector<sf::Sprite> itemSprite; // doi tuong in do vat
	std::vector<bool> eraseItem; // kiem tra mon do nao da duoc tra
	bool keyPressed = false;

	/*sf::Texture itemTextures;
	sf::Texture locationTextures;
	sf::Sprite itemSprite;
	sf::Sprite locationSprite;*/

	
	//bool keyE = true;

	void initItemTextures(); // khoi tao hinh anh
	void initItemSprite(); // khoi tao doi tuong in ra man hinh
	void initItemPosition(); // khoi tao vi tri cho do vat
	void initItem(); // khoi tao cac do vat

	// cho de tra do
	void initLocationTextures();
	void initLocationSprite();
	void initLocationPosition();
	void initLocation();

	void initEraseItem(); // khoi tao doi tuong kiem tra tra do 

public:
	Location();
	virtual ~Location();
	
	//std::vector<sf::Texture> itemTextures;
	//std::vector<sf::Sprite> locationSprite;
	//std::vector<sf::Sprite> itemSprite;
	//std::vector<bool> eraseItem; // kiem tra mon do nao da duoc tra

	//Fuctions
	sf::Vector2f getLocationPosition(int i); // tra ve vi tri noi tra do thu i
	bool getEraseItem(int i); // tra ve eraseItem[i]
	std::vector<sf::Sprite> getLocationSprite();
	void updateItem(int i); // cap nhat tra do tai vi tri i
	void update();
	void renderItem(sf::RenderTarget& target, int i); // ve cac mon do
	void render(sf::RenderTarget& target, int i); // ve cac noi tra do

};

