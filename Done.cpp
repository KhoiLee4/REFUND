#include "stdafx.h"
#include "Done.h"

void Done::initTexture()
{
    for (int i = 0; i < 6; i++)
    {
        sf::Texture texture;

        if (texture.loadFromFile("Data/Textures/Done/done.jpg")) {
            this->doneTexture.push_back(texture);
        }
        else {
            std::cerr << "Failed to load done" << i << ".jpg" << std::endl;
        }
    }
}

void Done::initSprite()
{
    for (int i = 0; i < 6; i++)
    {
        sf::Sprite sprite;
        if (i < this->doneTexture.size())
        {
            sprite.setTexture(this->doneTexture[i]);
            this->doneSprite.push_back(sprite);
        }
    }
}

void Done::initCheck()
{
    for (int i = 0; i < 6; i++)
    {
        doneCheck.push_back(false);
    }
}

void Done::initPosition()
{
    if (this->doneSprite.size() == 6)
    {
        this->doneSprite[0].setPosition(250, 350 - 1);
        this->doneSprite[1].setPosition(300, 400 - 1);
        this->doneSprite[2].setPosition(350, 450 - 1);
        this->doneSprite[3].setPosition(400, 500 - 1);
        this->doneSprite[4].setPosition(450, 500 - 1);
        this->doneSprite[5].setPosition(500, 550 - 1);
    }
}

Done::Done()
{
    this->initTexture();
    this->initSprite();
    this->initPosition();
    this->initCheck();
}

Done::~Done()
{
}

sf::Sprite Done::getDoneSprite(int i)
{
    return this->doneSprite[i];
}

bool Done::getDoneCheck(int i)
{
    return this->doneCheck[i];
}

bool Done::check()
{
    for (int i = 0; i < 6; i++)
    {
        if (doneCheck[i] == false) return false;
    }
    return true;
}

void Done::updateCheck(int i)
{
    this->doneCheck[i] = true;
}

void Done::update()
{
}

void Done::render(sf::RenderTarget& target, int i)
{
    target.draw(this->doneSprite[i]);
}
