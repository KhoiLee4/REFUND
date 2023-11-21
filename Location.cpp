#include "Location.h"

void Location::initItemTextures()
{
    // lay hinh tu data vao
    for (int i = 1; i <= 5; i++)
    {
        sf::Texture texture;
        if (texture.loadFromFile("Data/Textures/Locations/item" + std::to_string(i) + ".png"))
        {
            this->itemTextures.push_back(texture); // them vao cuoi (bat dau tu 0)
        }
        else
        {
            std::cerr << "Failed to load item" << i << ".png" << std::endl;
        }
    }
}

void Location::initItemSprite()
{
   for (int i = 0; i < 5; i++)
    {
       sf::Sprite sprite;
       if (i < this->itemTextures.size())
       {
           sprite.setTexture(this->itemTextures[i]);
           this->itemSprite.push_back(sprite);
       }
    }
}

void Location::initItemPosition()
{
    if (this->itemSprite.size() == 5)
    {
        this->itemSprite[0].setPosition(itemLocationX_01, itemLocationY_01);
        this->itemSprite[1].setPosition(itemLocationX_02, itemLocationY_02);
        this->itemSprite[2].setPosition(itemLocationX_03, itemLocationY_03);
        this->itemSprite[3].setPosition(itemLocationX_04, itemLocationY_04);
        this->itemSprite[4].setPosition(itemLocationX_05, itemLocationY_05);
    }
}

void Location::initItem()
{
    this->initItemTextures();
    this->initItemSprite();
    this->initItemPosition();
}

void Location::initLocationTextures()
{
    for (int i = 0; i < 5; i++)
    {
        sf::Texture texture;

        if (texture.loadFromFile("Data/Textures/Locations/location.png")) {
            this->locationTextures.push_back(texture);
        }
        else {
            std::cerr << "Failed to load location" << i << ".png" << std::endl;
        }
    }
    //this->locationTextures.loadFromFile("Data/Textures/Locations/location1.png");
}

void Location::initLocationSprite()
{
    for (int i = 0; i < 5; i++)
    {
        sf::Sprite sprite;
        if (i < this->locationTextures.size())
        {
            sprite.setTexture(this->locationTextures[i]);
            this->locationSprite.push_back(sprite);
        }
    }
    //this->locationSprite.setTexture(this->locationTextures);
}

void Location::initLocationPosition()
{
    if (this->locationSprite.size() == 5)
    {
        this->locationSprite[0].setPosition(locationX_01, locationY_01);
        this->locationSprite[1].setPosition(locationX_02, locationY_02);
        this->locationSprite[2].setPosition(locationX_03, locationY_03);
        this->locationSprite[3].setPosition(locationX_04, locationY_04);
        this->locationSprite[4].setPosition(locationX_05, locationY_05);
    }
    //this->locationSprite.setPosition(300, 400);
}

void Location::initLocation()
{
    this->initLocationTextures();
    this->initLocationSprite();
    this->initLocationPosition();
}

void Location::initEraseItem()
{
    for (int i = 0; i < 5; i++)
    {
        eraseItem.push_back(true);
    }
}

Location::Location()
{
    this->initItem();
    this->initLocation();
    this->initEraseItem();
}

Location::~Location()
{
}

sf::Vector2f Location::getLocationPosition(int i)
{
    sf::Vector2f position;
    position.x = this->locationSprite[i].getPosition().x;
    if (i == 0)
    {
        position.y = this->locationSprite[i].getPosition().y + 150;
    }
    else if (i == 1)
    {
        position.y = this->locationSprite[i].getPosition().y;
    }
    else if (i == 2)
    {
        position.y = this->locationSprite[i].getPosition().y + 140;
    }
    else if (i == 3)
    {
        position.y = this->locationSprite[i].getPosition().y + 160;
    }
    else
    {
        position.y = this->locationSprite[i].getPosition().y + 100;
    }
    return position;
}

bool Location::getEraseItem(int i)
{
    return eraseItem[i];
}

std::vector<sf::Sprite> Location::getLocationSprite()
{
    return locationSprite;
}

void Location::moveLocation(float x, float y)
{
    for (int i = 0; i < 5; i++)
    {
        itemSprite[i].move(x, y);
        locationSprite[i].move(x, y);
    }
}

void Location::updateItem(int i)
{
    this->eraseItem[i] = false;
}

void Location::update()
{
}

void Location::renderItem(sf::RenderTarget& target, int i)
{
    if (this->eraseItem[i] == true) target.draw(this->itemSprite[i]);
}

void Location::render(sf::RenderTarget& target, int i)
{
    target.draw(this->locationSprite[i]);
}
