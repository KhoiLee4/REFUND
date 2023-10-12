#include "stdafx.h"
#include "Item.h"


void Item::initTexture()
{
    for (int i = 1; i <= 6; i++) {
        sf::Texture texture;
        if (texture.loadFromFile("Data/Textures/Items/item" + std::to_string(i) + ".png")) {
            this->itemTextures.push_back(texture);
        }
        else {
            std::cerr << "Failed to load item" << i << ".png" << std::endl;
        }
    }
}
void Item::initSpritePick()
{
    sprite_pick.setPosition(100, 200);
    this->sprite_pick.setTexture(this->itemTextures[currentItem]);
}
void Item::initSpriteNext()
{
    sprite_next.setPosition(200, 300);
    this->sprite_next.setTexture(this->itemTextures[currentItem]);
}
void Item::initSprite()
{
    this->initSpriteNext();
    this->initSpritePick();
}
Item::Item()
{
	this->initTexture();
    this->initSprite();
}

Item::~Item()
{
}
void Item::updatePick()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
        if (this->currentItem < this->itemTextures.size()) {
            this->currentItem++;
            this->initSpritePick();
        }
    }
}
void Item::updateNext()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
        if (this->currentItem < this->itemTextures.size()) {
            this->pickItem = this->currentItem;
            this->initSpriteNext();
        }
    }
}
void Item::update()
{
    this->updatePick();
    this->updateNext();
}
void Item::render(sf::RenderTarget& target)
{
    target.draw(this->sprite_next);
    target.draw(this->sprite_pick);
}

