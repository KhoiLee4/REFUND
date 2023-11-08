#include "Noise.h"

void Noise::initNoiseBar()
{
    // tao khung tieng on
    noiseBarLayer.setSize(sf::Vector2f(noiseWidth, noiseHight));
    noiseBarLayer.setPosition(noiseX, noiseY);
    noiseBarLayer.setFillColor(sf::Color::White);
    // tao phan hien thi luong tieng on
    noiseBar.setSize(sf::Vector2f(0, noiseHight));
    noiseBar.setPosition(noiseX, noiseY);
    noiseBar.setFillColor(sf::Color::Green);
}

void Noise::initNoiseIndex()
{
    this->currentNoise = 0.f; // luong tieng on ban dau
    this->maxNoise = 200.f; // luong tieng on toi da
}

Noise::Noise()
{
    this->initNoiseBar();
    this->initNoiseIndex();
}

Noise::~Noise()
{
}

bool Noise::checkNoiseMax()
{
    // kiem tra luong tieng on dat toi da chua
    if (this->currentNoise >= this->maxNoise) return true;
    else return false;
}

void Noise::updateNoiseBar()
{
    noiseBar.setSize(sf::Vector2f(currentNoise * 3, 30)); // thay doi hien thi luong teng on
}

void Noise::setNoiseIndex(float index)
{
    this->currentNoise += index; // tang luong tieng on
}

void Noise::update()
{
    this->updateNoiseBar(); // thay doi thanh tieng on
}

void Noise::render(sf::RenderTarget& target)
{
    // ve khung tieng on
    target.draw(this->noiseBarLayer); 
    // ve luong tieng on
    target.draw(this->noiseBar);
}
