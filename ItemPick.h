#pragma once
class ItemPick
{
private:
    bool keyPressed = false, eraseItem = true;
    //sf::Clock debounceTime;
    //void initTexture();
    //void initSprite();
public:
    ItemPick();
    virtual ~ItemPick();

    Item* item;
    //std::vector<sf::Texture> itemTextures;
    sf::Sprite pickSprite;
    int pickItem = -1;

    //Functions
    void updateRestore();
    void updatePick();
    void update();
    void render(sf::RenderTarget& target);
    //Functions
};

