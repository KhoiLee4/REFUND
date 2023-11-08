#pragma once

#include "gameConfig.h"
#include "stdafx.h"

/*
## Class Done ##
- thuc hien cong viec lien quan de hoan thanh tra do
    + kiem tra 
    + hien thi

*/

class Done
{
private:
    std::vector <sf::Texture> doneTexture; // doi tuong luu anh
    std::vector <sf::Sprite> doneSprite; // doi tuong de ve anh
    std::vector<bool> doneCheck; // luu tra do hoan thanh hay chua

    void initTexture(); // khoi tao hinh anh
    void initSprite(); // khoi tao doi tuong de ve
    void initCheck(); // khoi tao mang kiem tra
    void initPosition(); // khoi tao vi tri hien thi

public:
    Done();
    virtual ~Done();

    //Functions
    sf::Sprite getDoneSprite(int i); // tra ve bien doneSprite[i]
    bool getDoneCheck(int i); // tra ve bien doneCheck
    bool check(); // kiem tra da done het chua (tra do hoan thanh chua)
    void updateCheck(int i); // cap nhat bien doneCheck
    void moveDone(float x, float y);
    void update();
    void render(sf::RenderTarget& target, int i); // ve doneSprite[i]

};

