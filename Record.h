#pragma once
#include "Menu.h"
#include "stdafx.h"
#include "gameConfig.h"
#include <fstream>

struct Data
{
	std::string name;
	float score;
};

class Record
{
private:
	sf::RenderWindow *window; // cua so cuar game
	sf::Texture backgroundTexture; // tao doi tuong luu anh
	sf::RectangleShape background; // background la hinh vuong
	sf::Font font; // tao font
	sf::Text t0;
	sf::Text t1;
	sf::Text t2;
	sf::Text t3;
	sf::Event ev; // bien bat su kien
	Data *data;
	Data now;
	
	void initWindow();
	void initBackGround();
	void initFont();
	void initText();
	void initData();

public:
	Record();
	~Record();

	void merge(Data *arr, int left, int middle, int right); // Ham merge hai mang con da sap xep thanh 1 mang da sap xep
	void mergeSort(Data* arr, int left, int right); // Ham sap xep vector su dung merge sort
	void sortRecord();
	void renderRecord();
	void updateRecord(int i);
	void runRecord();
};

