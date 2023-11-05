#pragma once
class Noise
{
private:
	sf::RectangleShape noiseBar;
	sf::RectangleShape noiseBarLayer;
	float currentNoise;
	float maxNoise;

	void initNoiseBar();
	void initNoiseIndex();
public:
	Noise();
	virtual ~Noise();

	//Functions
	bool checkNoiseMax();
	void updateNoiseBar();
	void setNoiseIndex(float index);
	void update();
	void render(sf::RenderTarget& target);
	//Functions
};

