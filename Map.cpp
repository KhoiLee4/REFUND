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
	if (!this->wall4Texture.loadFromFile("Data/Textures/Background/Wall04.png"))
	{
		std::cout << "ERROR::Could not load Wall03!" << '\n';
	}
}

void Map::initSprite()
{
	this->floorSprite.setTexture(floorTexture);
	this->floorSprite.setScale(1.f, 1.f);
	this->floorSprite.setPosition(mapX, mapY);

	this->wall1Sprite.setTexture(wall1Texture);
	this->wall1Sprite.setScale(1.f, 1.f);
	this->wall1Sprite.setPosition(mapX, mapY);

	this->wall2Sprite.setTexture(wall2Texture);
	this->wall2Sprite.setScale(1.f, 1.f);
	this->wall2Sprite.setPosition(mapX, mapY);

	this->wall3Sprite.setTexture(wall3Texture);
	this->wall3Sprite.setScale(1.f, 1.f);
	this->wall3Sprite.setPosition(mapX, mapY);

	this->wall4Sprite.setTexture(wall4Texture);
	this->wall4Sprite.setScale(1.f, 1.f);
	this->wall4Sprite.setPosition(mapX, mapY);
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
	// canh ben phai
	if (-floorSprite.getPosition().x + screenWidth > floorSprite.getGlobalBounds().width)
	{
		return true;
	}
	// canh ben trai
	if (floorSprite.getPosition().x > 0)
	{
		return true;
	}
	// xet tren truc Oy
	// canh ben duoi
	if (-floorSprite.getPosition().y + screenWidth > floorSprite.getGlobalBounds().height)
	{
		return true;
	}
	// canh ben tren
	if (floorSprite.getPosition().y > 0)
	{
		return true;
	}
	// truong hop map chua ra khoi khung hinh
	return false;
}

bool Map::checkRangePlayer(sf::Vector2f playerPosition, short move)
{
	float x = playerPosition.x - floorSprite.getPosition().x;
	float y = playerPosition.y - floorSprite.getPosition().y;
	//std::cout << x << "\t" << y << "\n";
	// xet tren truc Oy
	if (move == UP)
	{
		if (2119 < y && y <= 2120 && 1536 < x && x <= 1644)
		{
			return true;
		}
		if (2039 < y && y <= 2040 && 1644 < x && x <= 1902)
		{
			return true;
		}
		if (2119 < y && y <= 2120 && 1896 < x && x <= 2062)
		{
			return true;
		}
		if (1949 < y && y <= 1950 && 2062 < x && x <= 2626)
		{
			return true;
		}
		if (2629 < y && y <= 2630 && 2205 < x && x <= 2270)
		{
			return true;
		}
		if (2659 < y && y <= 2660 && 2340 < x && x <= 2580)
		{
			return true;
		}
		if (2679 < y && y <= 2680 && 2580 < x && x <= 2740)
		{
			return true;
		}
		if (2589 < y && y <= 2590 && 2740 < x && x <= 2860)
		{
			return true;
		}
		if (2609 < y && y <= 2610 && 2860 < x && x <= 2980)
		{
			return true;
		}
	}
	else if (move == DOWN)
	{
		if (2249 < y && y <= 2250 && 1644 < x && x <= 1902)
		{
			return true;
		}
		if (2184 < y && y <= 2185 && 1536 < x && x <= 1644)
		{
			return true;
		}
		if (2184 < y && y <= 2185 && 1896 < x && x <= 2062)
		{
			return true;
		}
		if (2279 < y && y <= 2280 && 2062 < x && x <= 2270)
		{
			return true;
		}
		if (2059 < y && y <= 2060 && 2440 < x && x <= 2546)
		{
			return true;
		}
		if (2779 < y && y <= 2780 && 2205 < x && x <= 2380)
		{
			return true;
		}
		if (2729 < y && y <= 2730 && 2380 < x && x <= 2580)
		{
			return true;
		}
		if (2709 < y && y <= 2710 && 2580 < x && x <= 2980)
		{
			return true;
		}
	}

	// xet tren truc Ox
	else if (move == LEFT)
	{
		if (1199 < x && x <= 1200 && 2000 < y && y <= 2510)
		{
			return true;
		}
		if (1643 < x && x <= 1644 && 2020 < y && y <= 2100)
		{
			return true;
		}
		if (2061 < x && x <= 2062 && 1930 < y && y <= 2100)
		{
			return true;
		}
		if (1643 < x && x <= 1644 && 2185 < y && y <= 2250)
		{
			return true;
		}
		if (2061 < x && x <= 2062 && 2185 < y && y <= 2260)
		{
			return true;
		}
		if (2269 < x && x <= 2270 && 2320 < y && y <= 2630)
		{
			return true;
		}
		if (2204 < x && x <= 2205 && 2630 < y && y <= 2780)
		{
			return true;
		}
		if (2739 < x && x <= 2740 && 2590 < y && y <= 2680)
		{
			return true;
		}
	}
	else if (move == RIGHT)
	{
		if (1535 < x && x <= 1536 && 1870 < y && y <= 2100)
		{
			return true;
		}
		if (1895 < x && x <= 1896 && 2020 < y && y <= 2100)
		{
			return true;
		}
		if (2545 < x && x <= 2546 && 1930 < y && y <= 2400)
		{
			return true;
		}
		if (1535 < x && x <= 1536 && 2185 < y && y <= 2445)
		{
			return true;
		}
		if (1895 < x && x <= 1896 && 2185 < y && y <= 2250)
		{
			return true;
		}
		if (2359 < x && x <= 2360 && 2060 < y && y <= 2320)
		{
			return true;
		}
		if (2339 < x && x <= 2340 && 2320 < y && y <= 2660)
		{
			return true;
		}
		if (2379 < x && x <= 2380 && 2730 < y && y <= 2780)
		{
			return true;
		}
		if (2579 < x && x <= 2580 && 2660 < y && y <= 2680)
		{
			return true;
		}
		if (2579 < x && x <= 2580 && 2710 < y && y <= 2730)
		{
			return true;
		}
		if (2859 < x && x <= 2860 && 2590 < y && y <= 2610)
		{
			return true;
		}
		if (2979 < x && x <= 2980 && 2610 < y && y <= 2700)
		{
			return true;
		}
	}
	return false;
}

bool Map::checkWall(float y)
{
	if (y - floorSprite.getPosition().y > 2500)
	{
		return true;
	}
	return false;
}

void Map::moveMap(float x, float y)
{
	floorSprite.move(x, y);
	wall1Sprite.move(x, y);
	wall2Sprite.move(x, y);
	wall3Sprite.move(x, y);
	wall4Sprite.move(x, y);

}


void Map::render1(sf::RenderTarget& target)
{
	target.draw(this->floorSprite);
	target.draw(this->wall1Sprite);
}

void Map::render2(sf::RenderTarget& target)
{
	target.draw(this->wall2Sprite);
}


void Map::render3(sf::RenderTarget& target)
{
	target.draw(this->wall3Sprite);
}

void Map::render4(sf::RenderTarget& target)
{
	target.draw(this->wall4Sprite);
}

