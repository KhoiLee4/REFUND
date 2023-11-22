#include "Record.h"

void Record::initWindow()
{
	//Create game window
	window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHight), "Refund", sf::Style::Close | sf::Style::Titlebar);
	//Set frame rate
	window->setFramerateLimit(144);
}

void Record::initBackGround()
{
	// tao backgruond
	backgroundTexture.loadFromFile("Data/Textures/Background/Home.jpg"); // nap hinh vao
	background.setTexture(&backgroundTexture); // gan backgroundTexture cho background (lay backgroundTexture lam nen)
	background.setSize(sf::Vector2f(screenWidth, screenHight)); // dat kich thuot cho back ground
}

void Record::initFont()
{
	// Tao 1 doi tuong van ban de hien thi thoi gian
	if (!font.loadFromFile("Data/Textures/Font/PixelGameFont.ttf")) {
		std::cerr << "Failed to load font." << std::endl;
	}
}

void Record::initText()
{
	t0.setFont(font);
	t0.setCharacterSize(sizetext + 15);
	t0.setPosition(col + 200, 100);
	t0.setFillColor(sf::Color(0, 0, 0));

	t1.setFont(font);
	t1.setCharacterSize(sizetext);
	t1.setPosition(col, rowDef);
	t1.setFillColor(sf::Color(0, 0, 0));

	t2.setFont(font);
	t2.setCharacterSize(sizetext);
	t2.setPosition(col + 100, rowDef);
	t2.setFillColor(sf::Color(0, 0, 0));

	t3.setFont(font);
	t3.setCharacterSize(sizetext);
	t3.setPosition(col + 400, rowDef);
	t3.setFillColor(sf::Color(0, 0, 0));
}

void Record::initData()
{
	data = new Data[11];
	std::ifstream inFile("Record.txt");

	if (inFile.is_open()) 
	{
		for (int i = 0; i < 11; i++)
		{
			if (std::getline(inFile, data[i].name));

			std::string score;
			if (std::getline(inFile, score))
			{
				data[i].score = std::stof(score);
			}
		}

		inFile.close();
	}
	else 
	{
		std::cerr << "Unable to open file for reading." << std::endl;
	}
	now = data[10];
}

Record::Record()
{
	initWindow();
	initBackGround();
	initFont();
	initText();
	initData();
}

Record::~Record()
{
	delete[] data;
}

void Record::merge(Data *arr, int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;
	// Tạo các mảng tạm thời
	Data *L = new Data[n1];
	Data *R = new Data[n2];
	// Sao chép dữ liệu vào các mảng tạm thời L[] và R[]
	for (int i = 0; i < n1; i++) 
	{
		L[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++) 
	{
		R[j] = arr[middle + 1 + j];
	}
	// Merge các mảng tạm thời thành mảng chính arr[]
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i].score <= R[j].score) {
			arr[k++] = L[i++];
		}
		else {
			arr[k++] = R[j++];
		}
	}
	// Sao chép các phần tử còn lại của L[] (nếu có)
	while (i < n1) {
		arr[k++] = L[i++];
	}
	// Sao chép các phần tử còn lại của R[] (nếu có)
	while (j < n2) {
		arr[k++] = R[j++];
	}
	delete[] L;
	delete[] R;
}

void Record::mergeSort(Data *arr, int left, int right)
{
	if (left < right) {
		int middle = left + (right - left) / 2;  // Tim diem giua cua mang
		// Sap xep phan dau va phan cuoi
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);  // Merge hai mang con da sap xep
	}
}

void Record::sortRecord()
{
	mergeSort(data, 0, 11 - 1);
	std::ofstream outputFile("Record.txt");
	if (outputFile.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			outputFile << data[i].name << "\n";
			outputFile << data[i].score << "\n";
		}

		outputFile.close();
	}
	else
	{
		std::cerr << "Unable to open file for appending.\n";
	}
}

void Record::renderRecord()
{
	window->draw(t0);
	for (int i = 0; i < 10; i++)
	{
		updateRecord(i);
		t1.setPosition(col, rowDef + i * row);
		t2.setPosition(col + 100, rowDef + i * row);
		t3.setPosition(col + 400, rowDef + i * row);
		window->draw(t1);
		window->draw(t2);
		window->draw(t3);
	}
	t1.setString("Current record:");
	t2.setString(now.name);
	t3.setString(std::to_string(now.score));
	t1.setPosition(col - 150, 700);
	t2.setPosition(col + 170 , 700);
	t3.setPosition(col + 320, 700);
	window->draw(t1);
	window->draw(t2);
	window->draw(t3);
}

void Record::updateRecord(int i)
{
	t1.setString(std::to_string(i+1));
	t2.setString(data[i].name);
	t3.setString(std::to_string(data[i].score));
}

void Record::runRecord()
{
	sf::Texture exitTexture;
	exitTexture.loadFromFile("Data/Textures/Button/button_exit.png");
	sf::Sprite exitButton(exitTexture);
	exitButton.setPosition(screenWidth - 90, screenHight - 90);

	// -- chay chuong trinh -- //
	t0.setString("RECORD");
	while (window->isOpen()) {
		sf::Event ev;
		while (window->pollEvent(ev)) {
			// truong hop bam tat cua so
			if (ev.type == sf::Event::Closed) {
				window->close(); // dong cua so
			}
			// truong hop bam nut ESC
			else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			{
				window->close(); // dong cua so
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				window->close(); // dong cua so
				Menu menu;
				menu.runMenu();
			}
			// truong hop nhan chuot
			else if (ev.type == sf::Event::MouseButtonPressed)
			{
				// nhan chuot trai
				if (ev.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i mousePosition = sf::Mouse::getPosition(*window); // lay toa do hien tai cua con tro chuot
					// kiem tra vi tri chuot nam o nut nao
					if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
					{
						window->close();
						Menu menu;
						menu.runMenu();
					}
				}
			}
		}
		// lam sach cua so
		window->clear();
		// ve background
		window->draw(background);
		// ve nut
		window->draw(exitButton);
		// ve chu
		sortRecord();
		renderRecord();
		// day hinh ve tu bo dem len
		window->display();
	}
}
