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
void Item::initcurrentSprite()
{
    this->currentSprite.setPosition(100, 200);
    this->currentSprite.setTexture(this->itemTextures.front());
}
void Item::initpickSprite()
{
    this->pickSprite.setPosition(200, 300);
}
void Item::initSprite()
{
    this->initpickSprite();
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
void Item::pickUpdate()
{
    //int eKeyPressCount = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E) && !this->keyPressed) {
        //eKeyPressCount++;
        this->pickSprite.setTexture(this->itemTextures.front());
        this->keyPressed = true;
    }
    //if (sf::Event::KeyReleased && sf::Keyboard::E) {
    //    // Thiết lập lại biến khi phím "E" được nhãn
    //    keyPressed = false;
    //}
    //std:: cout << eKeyPressCount;
}
void Item::currentUpdate()
{
    //int eKeyPressCount = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E) && !this->keyPressed1) {
        itemTextures.erase(itemTextures.begin());
        this->currentSprite.setTexture(this->itemTextures.front());
        //eKeyPressCount++;
        this->keyPressed1 = true;
    }
    //if (sf::Event::KeyReleased && sf::Keyboard::E) {
    //    // Thiết lập lại biến khi phím "E" được nhãn
    //    keyPressed = false;
    //}
    //std::cout << eKeyPressCount;
}
void Item::update()
{
    this->pickUpdate();
    this->currentUpdate();
}
void Item::render(sf::RenderTarget& target)
{
    target.draw(this->currentSprite);
    target.draw(this->pickSprite);
}

