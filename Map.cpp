#include "Map.h"

void Map::initTexture()
{
	// lay hinh tu data vao
	if (!this->mapTexture.loadFromFile("Data/Textures/Background/sky.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the player sheet!" << '\n';
	}
}

void Map::initSprite()
{
	//this->mapSprite.setSize(sf::Vector2f(screenWidth+20, screenHight+20));
	this->mapSprite.setTexture(mapTexture);
	//this->mapSprite.setPosition(0, mapSprite.getGlobalBounds().height / 2);
	//this->mapSprite.setPosition(0, 0);
	this->mapSprite.setScale(10.f, 10.f);

}

Map::Map()
{
	initTexture();
	initSprite();
}

Map::~Map()
{

}



bool Map::checkFrame()
{
	// xet tren truc Ox
	if (-mapSprite.getPosition().x + screenWidth > mapSprite.getGlobalBounds().width)
	{
		//mapSprite.move(-mapSprite.getPosition().x + screenWidth - mapSprite.getGlobalBounds().width, 0.f);
		return true;
	}
	if (mapSprite.getPosition().x > 0)
	{
		//mapSprite.move(-mapSprite.getPosition().x, 0.f);
		return true;
	}
	// xet tren truc Oy
	if (-mapSprite.getPosition().y + screenWidth > mapSprite.getGlobalBounds().height)
	{
		//mapSprite.move(0.f, -mapSprite.getPosition().y + screenWidth - mapSprite.getGlobalBounds().height);
		return true;
	}
	if (mapSprite.getPosition().y > 0)
	{
		//mapSprite.move(0.f, -mapSprite.getPosition().y);
		return true;
	}
	// truong hop map chua ra khoi khung hinh
	return false;
}


//bool Map::checkRangePlayer(Player* player)
//{
//	float x = (player->getThiefPosition().x + player->getThiefGlobalBounds().width) / 2;
//	float y = (player->getThiefPosition().y + player->getThiefGlobalBounds().height) / 2;
//	// truong hop nhat vat di toi gua va chua het map
//	if (x >= screenWidth / 2 && !checkFrame())
//	{
//		return true;
//	}
//
//	if (y >= screenHight / 2 && !checkFrame())
//	{
//		return true;
//	}
//	return false;
//}
//
//void Map::update(Player *player)
//{
//	float moveSpeed = player->getMoveSpeed();
//	
//	// truong hop nhat vat dang o giua
//	// chi di chuyen map khong di chuyen nhan vat
//	if (checkRangePlayer(player))
//	{
//		if (player->getanimState() == UP)
//		{
//			mapSprite.move(0.f, moveSpeed);
//			player->setPlayerPosition(0.f, moveSpeed);
//		}
//	
//		// truong hop nhan vat di xuong
//		else if (player->getanimState() == DOWN)
//		{
//			mapSprite.move(0.f, -moveSpeed);
//			player->setPlayerPosition(0.f, -moveSpeed);
//		}
//
//		// truong hop nnhan vat di qu trai
//		else if (player->getanimState() == LEFT)
//		{
//			mapSprite.move(moveSpeed, 0.f);
//			player->setPlayerPosition(moveSpeed, 0.f);
//		}
//
//		// truong hop nhan vat di qua phai
//		else if (player->getanimState() == RIGHT)
//		{
//			mapSprite.move(-moveSpeed, 0.f);
//			player->setPlayerPosition(-moveSpeed, 0.f);
//		}
//	}
//}

void Map::moveMap(float x, float y)
{
	mapSprite.move(x, y);
}

void Map::render(sf::RenderTarget& target)
{
	target.draw(this->mapSprite);
}
