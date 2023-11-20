#include "Game.h"


void Game::initWindow()
{
	//Create game window
	this->window.create(sf::VideoMode(screenWidth, screenHight), "Refund", sf::Style::Close | sf::Style::Titlebar);
	//Set frame rate
	this->window.setFramerateLimit(144);
}

void Game::initNoise()
{
	this->noise = new Noise();
}

void Game::initHost()
{
	this->host = new Host();
}

void Game::initDone()
{
	this->done = new Done();
}

//void Game::initDone()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		this->done[i] = false;
//	}
//	this->doneTexture.loadFromFile("Data/Textures/Done/done.jpg");
//	this->doneSprite.setTexture(this->doneTexture);
//}

void Game::initLocation()
{
	this->location = new Location();
}

void Game::initView()
{
	view.reset(sf::FloatRect(0, 0, screenWidth, screenHight));
	window.setView(view);
}

void Game::initRecordTime()
{
	this->recordTime.restart();
}

void Game::initItemPick()
{
	this->itemPick = new ItemPick();
}

void Game::initItem()
{
	this->item = new Item();
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initMap()
{
	this->map = new Map();
}

Game::Game()
{
	thresholdDistance = 30.0f;
	checkGameWinner = false;
	checkGameOver = false;
	keyE = true;
	keyPressed = false;
	count = 0;

	this->initWindow();
	//this->initView();
	this->initNoise();
	this->initHost();
	this->initDone();
	this->initLocation();
	this->initItemPick();
	this->initItem();
	this->initPlayer();
	this->initMap();
}

Game::~Game()
{
	delete this->noise;
	delete this->host;
	delete this->done;
	delete this->location;
	delete this->itemPick;
	delete this->item;
	delete this->player;
}

void Game::gameWinner()
{
	// tra het do thi THANG
	if (this->done->check())
	{
		this->checkGameWinner = true; // xac nhan thang
	}
}

void Game::gameOver()
{
	// dat tieng on toi da thi THUA
	if (this->noise->checkNoiseMax() == true)
	{
		this->checkGameOver = true; // xac nhan thua
		this->host->updateVariables(); // cap nhat lai trang thai chu nha (thuc day)
	}

}

void Game::increaseNoise()
{
	// truong hop nhan vat dang di chuyen
	if (player->getanimState() != IDLE)
		// neu di cham thi tang 0.01 (giu nut shift)
		// neu di binh thuong tang 0.1
		if(player->getCheckSlowly() == true)
			this->noise->setNoiseIndex(0.05f);
		else
			this->noise->setNoiseIndex(0.1f);
}

// kiem tra da lai gan vi tri do chua
bool Game::isNearObject(const sf::Vector2f& objectPosition, const sf::Vector2f& targetPosition)
{
	// tinh khoang cach tu nhan vat toi vi tri do
	// cong thuc tinh khoang cach giua 2 diem
	float distance = std::sqrt(powf((objectPosition.x - targetPosition.x) , 2) 
		+ powf((objectPosition.y - targetPosition.y), 2));
	// khoang cach be hon hoac bang khoang cach quy dinh (o gan vi tri do) tra ve true nguoc lai tra ve false
	return distance <= thresholdDistance;
}

void Game::move(float moveSpeed)
{
	if (player->getanimState() == UP)
	{
		moveBackGround(0.f, moveSpeed);
	}

	// truong hop nhan vat di xuong
	else if (player->getanimState() == DOWN)
	{
		moveBackGround(0.f, -moveSpeed);
	}

	// truong hop nnhan vat di qua trai
	else if (player->getanimState() == LEFT)
	{
		moveBackGround(moveSpeed, 0.f);
	}

	// truong hop nhan vat di qua phai
	else if (player->getanimState() == RIGHT)
	{
		moveBackGround(-moveSpeed, 0.f);
	}
}

void Game::remove(float moveSpeed)
{
	if (player->getanimState() == UP)
	{
		moveBackGround(0.f, -moveSpeed);
	}

	// truong hop nhan vat di xuong
	else if (player->getanimState() == DOWN)
	{
		moveBackGround(0.f, moveSpeed);
	}

	// truong hop nnhan vat di qua trai
	else if (player->getanimState() == LEFT)
	{
		moveBackGround(-moveSpeed, 0.f);
	}

	// truong hop nhan vat di qua phai
	else if (player->getanimState() == RIGHT)
	{
		moveBackGround(moveSpeed, 0.f);
	}
}

void Game::moveBackGround(float x, float y)
{
	map->moveMap(x, y);
	host->moveHost(x, y);
	location->moveLocation(x, y);
	done->moveDone(x, y);
	item->moveItem(x, y);

}

void Game::checkRangePlayer(float moveSpeed)
{
	//bool flag{false};
	sf::Vector2f playerSize(player->getThiefGlobalBounds().width, player->getThiefGlobalBounds().height);
	// x, y trong truong hop toa do tang
	float centerX_inc = (window.getSize().x - playerSize.x) / 2;
	float centerY_inc = (window.getSize().y - playerSize.y) / 2;
	//x, y trong truong hop toa do giam
	float centerX_dec = (window.getSize().x - playerSize.x) / 2 - 1;
	float centerY_dec = (window.getSize().y - playerSize.y) / 2 - 1;
	float x = player->getThiefPosition().x;
	float y = player->getThiefPosition().y;

	std::cout << x << "\t" << y << "\n";
		//std::cout << window.getSize().x << "\t" << window.getSize().y << "\n";

	move(moveSpeed);

	// truong hop nhat vat di toi gua va chua het map
	if (!map->checkFrame())
	{
		if (player->getanimState() == DOWN && y >= centerY_inc)
		{
			//std::cout << "map 0000\n";
			player->setPlayerPosition(0.f, -moveSpeed);
			//flag = false;
			//return true;
		}
		else if (player->getanimState() == RIGHT && x >= centerX_inc)
		{
			//std::cout << "map 1111\n";
			player->setPlayerPosition(-moveSpeed, 0.f);
			//flag = false;

			//return true;
		}
		else if (player->getanimState() == UP && y - centerY_dec <= 0)
		{
			//std::cout << "map 2222\n";
			player->setPlayerPosition(0.f, moveSpeed);
			//flag = false;

			//return true;
		}
		else if (player->getanimState() == LEFT && x - centerX_dec <= 0)
		{
			//std::cout << "map 3333\n";
			player->setPlayerPosition(moveSpeed, 0.f);
			//flag = false;

			//return true;
		}
		//else flag = true;
	}
	else
	{
		remove(moveSpeed);
	}
	//if (flag == true)
	//{
	//	if (player->getanimState() == UP)
	//	{
	//		map->moveMap(0.f, -moveSpeed);
	//	}

	//	// truong hop nhan vat di xuong
	//	else if (player->getanimState() == DOWN)
	//	{
	//		map->moveMap(0.f, moveSpeed);
	//	}

	//	// truong hop nnhan vat di qu trai
	//	else if (player->getanimState() == LEFT)
	//	{
	//		map->moveMap(-moveSpeed, 0.f);
	//	}

	//	// truong hop nhan vat di qua phai
	//	else if (player->getanimState() == RIGHT)
	//	{
	//		map->moveMap(moveSpeed, 0.f);
	//	}
	//}

	/*if (y >= screenHight / 4 && !map->checkFrame())
	{
		std::cout << "background di chuyen\n";
		return true;
	}*/
	//return false;
}


void Game::updateRecordTime()
{
	std::getline(std::cin, name);
	outFile.open("Record.txt");
	outFile << name << std::endl;
	
	this->elapsedTime = recordTime.getElapsedTime().asSeconds(); // lay thoi gian ky luc
	outFile << elapsedTime << std::endl;

	outFile.close();
}

/* Cac ham de cap nhat */
void Game::updateNoise()
{
	this->noise->update();
}

void Game::updateHost()
{
	this->host->update();
}
// *****
void Game::updatePickSpritePosition()
{
	float pickX, pickY;
	pickX = this->player->getThiefPosition().x;
	pickY = this->player->getThiefPosition().y;
	this->itemPick->setPickSpritePosition(pickX - 4.0f, pickY); // can sua lai //

}

//bool Game::checkDone()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		if (done[i] == false) return false;
//	}
//	return true;
//}

//void Game::shuffle(std::vector<sf::Texture>& texture)
//{
//	std::random_device rd;  // Tạo một thiết bị ngẫu nhiên
//	std::mt19937 g(rd());   // Tạo một generator ngẫu nhiên
//
//	std::shuffle(texture.begin(), texture.end()-1, g);  // Sử dụng std::shuffle để xáo trộn vector
//}

void Game::updateLocation(int i)
{
	this->location->updateItem(i);
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateMap()
{
	float moveSpeed = player->getMoveSpeed();
	checkRangePlayer(moveSpeed);
	// truong hop nhat vat dang o giua
	// chi di chuyen map khong di chuyen nhan vat
	//if (checkRangePlayer(moveSpeed))
	//{
	//	if (player->getanimState() == UP)
	//	{
	//		map->moveMap(0.f, moveSpeed);
	//		player->setPlayerPosition(0.f, moveSpeed);
	//	}

	//	// truong hop nhan vat di xuong
	//	else if (player->getanimState() == DOWN)
	//	{
	//		map->moveMap(0.f, -moveSpeed);
	//		player->setPlayerPosition(0.f, -moveSpeed);
	//	}

	//	// truong hop nnhan vat di qu trai
	//	else if (player->getanimState() == LEFT)
	//	{
	//		map->moveMap(moveSpeed + 0.5, 0.f);
	//		player->setPlayerPosition(moveSpeed, 0.f);
	//	}

	//	// truong hop nhan vat di qua phai
	//	else if (player->getanimState() == RIGHT)
	//	{
	//		map->moveMap(-moveSpeed - 0.5, 0.f);
	//		player->setPlayerPosition(-moveSpeed, 0.f);
	//	}
	//}
	//map->updateFrame();
}

void Game::update()
{
	/*this->shuffle(this->item->itemTextures);
	this->shuffle(this->location->itemTextures);*/
	
	
	// -- chay chuong trinh -- //
	while (this->window.pollEvent(this->ev))
	//if (this->window.pollEvent(this->ev))
	{
		// truong hop bam tat cua so
		if (this->ev.type == sf::Event::Closed)
			this->window.close(); // dong cua so

		// truong hop bam nut ESC
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close(); // dong cua so

		// truong hop van dang choi (chua thang va chua thua)
		else if (!this->checkGameOver && !this->checkGameWinner)
		{
		// -- Xet cac truong hop bam E -- //
			// truong hop nhan phim E
			//if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::E && !this->keyPressed)
			if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::E)
			{
				//std::cout << "Phim E duoc nhan" << std::endl;
				// trung hop chua lay do va chua tra het do
				if (this->keyE == true && !this->done->check())
				{
					std::cout << "Phim E lay duoc nhan" << std::endl;
					// kiem tra nhan vat da lai gan vi tri do hay chua
					if (isNearObject(this->player->getThiefPosition(), this->item->getItemPosition()))
					{
						this->item->updateItem(); // chuyen qua mon do tiep theo (tai cho lay do)
						this->itemPick->updatePick(); // lay do cho nhan vat
						this->keyE = false; // xac nhan da lay do
					}
				}
				// trung hop da lay do va chua tra het do
				else if (this->keyE == false && !this->done->check())
				{
					std::cout << "Phim E tra duoc nhan" << std::endl;
					// kiem tra nhan vat da lai gan vi tri do hay chua
					if (isNearObject(this->player->getThiefPosition(), this->location->getLocationPosition(count)))
					{
						std::cout << "count = " << count << std::endl;
						this->updateLocation(count); // xac nhan mon do vi tri count da duoc tra (do tai vi tri tra)
						this->itemPick->updateRestore(); // xac nhan da tra xong (do nhan vat cam bi mat)
						this->keyE = true; // xac nhan tra do xong
						this->done->updateCheck(count); // xac nhan dau hoan thanh
						this->count++; // chuyen qua do ke tiep
					}
				}
				this->keyPressed = true;
			}
			/*else if (this->ev.type == sf::Event::KeyReleased && this->ev.key.code == sf::Keyboard::E)
			{
				std::cout << "Phim E duoc tha ra" << std::endl;
				this->keyPressed = false;
			}*/
		}
	}
	// truong hop van dang choi (chua thang va chua thua)
	if (!this->checkGameOver && !this->checkGameWinner)
	{
		this->increaseNoise(); // tang tieng on
		this->updateNoise(); // cap nhat tieng on
		this->updatePickSpritePosition(); // cap nhat do tren tay nhan vat
		this->updatePlayer(); // cap nhat chuyen dong nhan vat
		this->updateMap();
	}
	this->gameWinner(); // kiem tra dieu kien thang
	this->gameOver(); // kiem tra dieu kien thua
	this->updateHost(); // cap nhat chu nha
}


/* Cac ham de ve */
void Game::renderNoise()
{
	this->noise->render(this->window);
}


void Game::renderHost()
{
	this->host->render(this->window);
}

void Game::renderItemLocation(int i)
{
	if (this->location->getEraseItem(i) == true)
			this->location->renderItem(this->window, i);
}
void Game::renderNearLocation()
{
	// kiem tra tat ca cac vi tri
	for (int i = 0; i < 6; i++)
	{
		// truong hop chua tra do
		if (this->done->getDoneCheck(i) == false)
		{
			// truong hop nhan vat o gan
			if (isNearObject(this->player->getThiefPosition(), this->location->getLocationPosition(i)))
				this->renderItemLocation(i); // hien do vat khi nhan vat lai gan
		}
		// truong hop tra roi thi hien done
		else
		{
			this->done->render(this->window, i);
		}
	}
}

void Game::renderLocation()
{
	for (int i = 0; i < 6; i++)
	{
		if (i < this->location->getLocationSprite().size())
			this->location->render(this->window, i);
		else std::cout << "Khong the render duoc location thu " << i;
	}
}

void Game::renderItemPick()
{
	this->itemPick->render(this->window);
}

void Game::renderItem()
{
	this->item->render(this->window);
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::renderMap()
{
	this->map->render(this->window);
}

void Game::render()
{
	// lam sach mang hinh
	this->window.clear();

	//Render game
	this->renderMap();
	this->renderNoise();
	this->renderHost();
	this->renderNearLocation();
	this->renderLocation();
	this->renderItemPick();
	this->renderItem();
	this->renderPlayer();

	// day hinh ve tu bo dem len
	this->window.display();
}

const sf::RenderWindow & Game::getWindow() const
{
	return this->window;
}

void Game::runGame()
{
	this->initRecordTime();
	// thoiwf bat dau
	while (window.isOpen())
	{
		update();
		render();
	}
}



