#pragma once

class Item
{
private:
    std::vector<sf::Texture> itemTextures;
    sf::Sprite  sprite_pick, sprite_next;
    int currentItem=0, pickItem;

    sf::IntRect currentFrame;
    void initSpritePick();
    void initSpriteNext();
    void initTexture();
    void initSprite();
public:
    Item();
    virtual ~Item();
    
    //Functions
    //void updatePick();
    void updatePick();
    void updateNext();
    void update();
    void render(sf::RenderTarget& target);
    //Functions
};

