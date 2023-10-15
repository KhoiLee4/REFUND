#pragma once
class ItemPick
{
private:
    std::vector<sf::Texture> itemTextures;
    bool keyPressed = false;
    int pickItem = 0;

    //sf::Clock debounceTime;
    void initTexture();
    //void initSprite();
public:
    ItemPick();
    virtual ~ItemPick();

    sf::Sprite pickSprite;
    //Functions
    void update();
    void render(sf::RenderTarget& target);
    //Functions
};

