#pragma once
class Done
{
private:
    std::vector <sf::Texture> doneTexture;
    std::vector <sf::Sprite> doneSprite;
    std::vector<bool> doneCheck;

    void initTexture();
    void initSprite();
    void initCheck();
    void initPosition();
public:
    Done();
    virtual ~Done();

    //Functions
    sf::Sprite getDoneSprite(int i);
    bool getDoneCheck(int i);
    bool check();
    void updateCheck(int i);
    void update();
    void render(sf::RenderTarget& target, int i);
    //Functions
};

