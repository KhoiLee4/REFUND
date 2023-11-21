#include "ItemPick.h"

void ItemPick::initTexture()
{
    // lay hinh trong data vao
    for (int i = 1; i <= 5; i++) 
    {
        sf::Texture texture; // doi tuong luu anh do

        if (texture.loadFromFile("Data/Textures/Items/item" + std::to_string(i) + ".png"))
        {
            this->itemTextures.push_back(texture); // them vao cuoi (bat dau tu 0)
        }
        else
        {
            std::cerr << "Failed to load item-1" << i << ".png" << std::endl;
        }
    }
}

ItemPick::ItemPick()
{
    this->initTexture();
    //this->item = new Item();
    pickItem = 0;
    keyPressed = false;
    eraseItem = false;
}

ItemPick::~ItemPick()
{
    //delete this->item;
}

void ItemPick::updatePick()
{
    if (pickItem < this->itemTextures.size())
    {
        this->pickSprite.setTexture(this->itemTextures[this->pickItem]); // gan hinh do de in ra man hinh
        this->pickItem++; // chuan bi cho lan ke tiep
        this->eraseItem = true; // xac nhan ve
    }
}

void ItemPick::setPickSpritePosition(float X, float Y)
{
    pickSprite.setPosition(X, Y);
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

