#include "stdafx.h"
#include "ItemPick.h"

void ItemPick::initTexture()
{
    for (int i = 1; i <= 6; i++) 
    {
        sf::Texture texture;

        if (texture.loadFromFile("Data/Textures/Items/item" + std::to_string(i) + ".png")) {
            this->itemTextures.push_back(texture);
        }
        else {
            std::cerr << "Failed to load item-1" << i << ".png" << std::endl;
        }
    }
}

ItemPick::ItemPick()
{
    this->initTexture();
}

ItemPick::~ItemPick()
{
}

void ItemPick::updatePick()
{
    if (pickItem < itemTextures.size())
    {
        this->pickSprite.setTexture(this->itemTextures[pickItem]);
        this->pickItem++;
        this->eraseItem = true;
    }
}

void ItemPick::updateRestore()
{
    this->eraseItem = false;
}

void ItemPick::update()
{
}

void ItemPick::render(sf::RenderTarget& target)
{
	if(this->eraseItem == true) 
        target.draw(this->pickSprite);
}
