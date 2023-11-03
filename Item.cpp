#include "stdafx.h"
#include "Item.h"
#include <random>
#include <algorithm>

void Item::initTexture()
{
    for (int i = 1; i <= 6; i++) 
    {
        sf::Texture texture;
        
        if (texture.loadFromFile("Data/Textures/Items/item" + std::to_string(i) + ".png")) {
            this->itemTextures.push_back(texture);
        }
        else {
            std::cerr << "Failed to load item" << i << ".png" << std::endl;
        }
    }
    // Random Item
    std::default_random_engine engine(static_cast<unsigned int>(std::time(0)));
    std::shuffle(itemTextures.begin(), itemTextures.end(), engine);

    sf::Texture texture;
    if (texture.loadFromFile("Data/Textures/Items/emptyCar.jpg")) {
        this->itemTextures.push_back(texture);
    }
}

void Item::initcurrentSprite()
{
    this->currentSprite.setPosition(100, 200);
    this->currentSprite.setTexture(this->itemTextures[currentItem]);
}

void Item::initSprite()
{
    this->initcurrentSprite();
}
Item::Item()
{
	this->initTexture();
    this->initSprite();
}
Item::~Item()
{
}
sf::Vector2f Item::getItemPosition()
{
    return this->currentSprite.getPosition();
}
void Item::updateItem()
{
    this->currentItem++;
    if (currentItem < itemTextures.size())
    {
        this->currentSprite.setTexture(this->itemTextures[currentItem]);
    }
}
void Item::update()
{
}
void Item::render(sf::RenderTarget& target)
{
    target.draw(this->currentSprite);
}

