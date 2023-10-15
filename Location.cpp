#include "stdafx.h"
#include "Location.h"

void Location::initItemTextures()
{
    for (int i = 1; i <= 6; i++)
    {
        sf::Texture texture;

        if (texture.loadFromFile("Data/Textures/Items/item" + std::to_string(i) + ".png")) {
            this->itemTextures.push_back(texture);
        }
        else {
            std::cerr << "Failed to load item-2" << i << ".png" << std::endl;
        }
    }
}

void Location::initItemSprite()
{
    for (int i = 0; i < 6; i++)
    {
        //if(i < this->itemTextures.size() && i < this->itemSprite.size())
            this->itemSprite[i].setTexture(this->itemTextures[i]);
    }
}

void Location::initItemPosition()
{
    //if (this->itemSprite.size() == 6)
    //{
        this->itemSprite[0].setPosition(250, 350 - 1);
        this->itemSprite[1].setPosition(300, 400 - 1);
        this->itemSprite[2].setPosition(350, 450 - 1);
        this->itemSprite[3].setPosition(400, 500 - 1);
        this->itemSprite[4].setPosition(450, 500 - 1);
        this->itemSprite[5].setPosition(50, 55 - 1);
    //}
}

void Location::initItem()
{
    this->initItemTextures();
    //this->initItemSprite();
    //this->initItemPosition();
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
}

void Location::initLocationSprite()
{
    for (int i = 0; i < 6; i++)
    {
        //if (i < this->locationTextures.size() && i < this->locationSprite.size())
            this->locationSprite[i].setTexture(this->locationTextures[i]);
    }
}

void Location::initLocationPosition()
{
    //if (this->locationSprite.size() == 6)
    //{
        this->locationSprite[0].setPosition(250, 350);
        this->locationSprite[1].setPosition(300, 400);
        this->locationSprite[2].setPosition(350, 450);
        this->locationSprite[3].setPosition(400, 500);
        this->locationSprite[4].setPosition(450, 500);
        this->locationSprite[5].setPosition(50, 55);
    //}
}

void Location::initLocation()
{
    this->initLocationTextures();
    //this->initLocationSprite();
    //this->initLocationPosition();
}

Location::Location()
{
    this->initItem();
    this->initLocation();
}

Location::~Location()
{
}

void Location::update()
{
}

void Location::render(sf::RenderTarget& target)
{
    /*for (int i = 0; i < 6; i++)
    {
        target.draw(this->itemSprite[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        target.draw(this->locationSprite[i]);
    }*/
    //target.draw(this->itemSprite[1]);
}
