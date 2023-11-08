#pragma once

#include "gameConfig.h"
#include "stdafx.h"

//#include "Item.h"

/*
## Class ItemPick ##
- thuc hien cac cong viec lien quan den do vat ma nhan vat cam
    + hien thi
    + thay doi

*/

class ItemPick
{
private:
    std::vector<sf::Texture> itemTextures; // doi tuong luu anh
    sf::Sprite pickSprite; // do in ra mang hinh
    int pickItem; // vi tri hinh do hien tai
    bool keyPressed;
    bool eraseItem; // xac nhan khi nao thi duoc ve
    //sf::Clock debounceTime;
    void initTexture(); // khoi tao hinh anh
    //void initSprite();

public:
    ItemPick();
    virtual ~ItemPick();

    //Functions
    void setPickSpritePosition(float X, float Y); // cai dat vi tri cua do vat theo nhan vat
    void updateRestore(); // cap nhat bien eraseItem
    void updatePick(); // cap nhat do vat cam tren tay nhan vat
    void update();
    void render(sf::RenderTarget& target); // ve do vat

};

