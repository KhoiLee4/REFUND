#pragma once

#include <fstream>
#include <string.h>
#include "Noise.h"
#include "Host.h"
#include "Done.h"
#include "Location.h"
#include "ItemPick.h"
#include "Item.h"
#include "Player.h"
#include "Map.h"
#include "stdafx.h"
#include "gameConfig.h"
#include <random>

/*
## Class Game ##
- class nay thuc hien qua trinh choi game bao gom:
	+ map 
	+ logic game
	+ tinh diem
	+ ...

*/

class Game
{
private:
	sf::RenderWindow window; // cua so cuar game
	sf::Event ev; // bien bat su kien
	std::ofstream outFile;
	std::string name;
	sf::Clock recordTime;
	float elapsedTime; // luu thoi gian ky luc
	float thresholdDistance; // khoang cach toi thieu de xem la da den gan
	bool checkGameWinner; // kiem tra da thang hay chua
	bool checkGameOver; // kiem tra da thua hay chua
	bool keyE; // kiem tra da nhan E chua
	bool keyPressed; // kiem tra da nhan phim hay chua
	int count;
	//std::vector<bool> done;
	//sf::Texture doneTexture;
	//sf::Sprite doneSprite;
	Noise *noise; // tieng on
	Host *host; // chu nha
	Done *done; // hoan thanh tra do
	Location *location; // do taij vi tri tra
	ItemPick *itemPick; // do tren tay nhan vat
	Item *item; // do tai vi tri ban dau
	Player *player; // nhan vat
	Map* map;

	void initWindow(); // khoi tao cua so
	void initRecordTime(); // khoi tao thoi gian luu ky luc
	void initNoise(); // khoi tao tieng on
	void initHost(); // khoi tao chu nha
	void initDone(); // khoi tao bien hoan thanh tra do
	void initLocation(); // kho taoj do tai vi tri tra
	void initItemPick(); // khoi tao do tren tay nhan vat
	void initItem(); // khoi tao do tai vi tri ban dau
	void initPlayer(); // khoi tao nhan vat
	void initMap(); // khoi tao map

public:
	Game(); 
	virtual ~Game();

	//Functions 
	void gameWinner(); // kiem tra thang
	void gameOver(); // kiem tra thua
	void increaseNoise(); // tao tieng on
	bool isNearObject(const sf::Vector2f& objectPosition, const sf::Vector2f& targetPosition); // kiem tra gan xa cua nhan vat voi vi tri do
	
	//void updateDone();
	//void shuffle(std::vector<sf::Texture>& texture);
	void moveBackGround(float x, float y);
	void move(float moveSpeed);
	void remove(float moveSpeed);
	void checkRangePlayer(float moveSpeed); // kiem tra vi tri cua nha vat

	void updateRecordTime(); // cap nhat ky luc
	void updateNoise(); // cap nhat tieng on
	void updateHost(); // cap nhat chu nha
	void updateLocation(int i); // cap nhat do tai vi tri tra
	void updatePickSpritePosition(); // cap nhat vi tri do tren tay nhan vat
	void updatePlayer(); // cap nhat nha vat
	void updateMap();
	void update();

	void renderNoise(); // ve thanh tieng on
	void renderHost(); // ve chu nha
	void renderItemLocation(int i); // ve do tai vi tri tra
	void renderNearLocation(); // hien do tai vi tri tra
	void renderLocation(); // ve vi tri tra do
	void renderItemPick(); // ve do vat tren tay nhan vat
	void renderItem(); // ve do tren xe tai
	void renderPlayer(); // ve nhan vat
	void renderMap();
	void render(); // ve cua so game

	const sf::RenderWindow& getWindow() const;

	void runGame(); // chay cua so game

};

