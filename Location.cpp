#include "Location.h"

void Location::initItemTextures()
{
    // lay hinh tu data vao
    for (int i = 1; i <= 6; i++)
    {
        sf::Texture texture;
        if (texture.loadFromFile("Data/Textures/Items/item" + std::to_string(i) + ".png"))
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
   for (int i = 0; i < 6; i++)
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
    if (this->itemSprite.size() == 6)
    {
        this->itemSprite[0].setPosition(250, 350 - 20);
        this->itemSprite[1].setPosition(300, 400 - 20);
        this->itemSprite[2].setPosition(350, 450 - 20);
        this->itemSprite[3].setPosition(400, 500 - 20);
        this->itemSprite[4].setPosition(450, 500 - 20);
        this->itemSprite[5].setPosition(500, 550 - 20);
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
    for (int i = 1; i <= 6; i++)
    {
        sf::Texture texture;

        if (texture.loadFromFile("Data/Textures/Locations/location" + std::to_string(i) + ".png")) {
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
    for (int i = 0; i < 6; i++)
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
    if (this->locationSprite.size() == 6)
    {
        this->locationSprite[0].setPosition(250, 350);
        this->locationSprite[1].setPosition(300, 400);
        this->locationSprite[2].setPosition(350, 450);
        this->locationSprite[3].setPosition(400, 500);
        this->locationSprite[4].setPosition(450, 500);
        this->locationSprite[5].setPosition(500, 550);
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
    for (int i = 0; i < 6; i++)
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
    return this->locationSprite[i].getPosition();
}

bool Location::getEraseItem(int i)
{
    return eraseItem[i];
}

std::vector<sf::Sprite> Location::getLocationSprite()
{
    return locationSprite;
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
