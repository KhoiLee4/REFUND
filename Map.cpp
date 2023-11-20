#include "Map.h"

void Map::initTexture()
{
	// lay hinh tu data vao
	if (!this->floorTexture.loadFromFile("Data/Textures/Background/Floor.png"))
	{
		std::cout << "ERROR::Could not load floor!" << '\n';
	}
	if (!this->wall1Texture.loadFromFile("Data/Textures/Background/Wall01.png"))
	{
		std::cout << "ERROR::Could not load Wall01!" << '\n';
	}
	if (!this->wall2Texture.loadFromFile("Data/Textures/Background/Wall02.png"))
	{
		std::cout << "ERROR::Could not load Wall02!" << '\n';
	}
	if (!this->wall3Texture.loadFromFile("Data/Textures/Background/Wall03.png"))
	{
		std::cout << "ERROR::Could not load Wall03!" << '\n';
	}

}

void Map::initSprite()
{
	this->floorSprite.setTexture(floorTexture);
	this->floorSprite.setScale(1.f, 1.f);
	this->floorSprite.setPosition(-1200, -1200);

	this->wall1Sprite.setTexture(wall1Texture);
	this->wall1Sprite.setScale(1.f, 1.f);
	this->wall1Sprite.setPosition(-1200, -1200);

	this->wall2Sprite.setTexture(wall2Texture);
	this->wall2Sprite.setScale(1.f, 1.f);
	this->wall2Sprite.setPosition(-1200, -1200);

	this->wall3Sprite.setTexture(wall3Texture);
	this->wall3Sprite.setScale(1.f, 1.f);
	this->wall3Sprite.setPosition(-1200, -1200);

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
	if (-floorSprite.getPosition().x + screenWidth > floorSprite.getGlobalBounds().width)
	{
		//mapSprite.move(-mapSprite.getPosition().x + screenWidth - mapSprite.getGlobalBounds().width, 0.f);
		return true;
	}
	if (floorSprite.getPosition().x > 0)
	{
		//mapSprite.move(-mapSprite.getPosition().x, 0.f);
		return true;
	}
	// xet tren truc Oy
	if (-floorSprite.getPosition().y + screenWidth > floorSprite.getGlobalBounds().height)
	{
		//mapSprite.move(0.f, -mapSprite.getPosition().y + screenWidth - mapSprite.getGlobalBounds().height);
		return true;
	}
	if (floorSprite.getPosition().y > 0)
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
	floorSprite.move(x, y);
	wall1Sprite.move(x, y);
	wall2Sprite.move(x, y);
	wall3Sprite.move(x, y);
}

void Map::render(sf::RenderTarget& target)
{
	target.draw(this->floorSprite);
	target.draw(this->wall1Sprite);
	target.draw(this->wall2Sprite);
	target.draw(this->wall3Sprite);

}
