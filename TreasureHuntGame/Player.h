#pragma once
#include "Scene.h"
#include "TestScene.h"
#include "Database.h"

class Player {
	Scene* scene;

public:

	float dx, dy;
	sf::FloatRect rect;
	bool onGround;
	sf::Sprite sprite;
	float currentFrame;

	Player(Scene* scene)
	{
		this->scene = scene;
		sprite.setTexture(DATABASE.textures.at(0));
		rect = sf::FloatRect(100, 600, 16, 16);

		dx = dy = 0.1;
		currentFrame = 0;
	}
	~Player() {
	//	delete scene;
	}


	void update(float time)
	{

		rect.left += dx * time;
		Collision(0);


		if (!onGround) dy = dy + 0.0005 * time;
		rect.top += dy * time;
		onGround = false;
		Collision(1);


		currentFrame += time * 0.005;
		if (currentFrame > 3) currentFrame -= 3;


		if (dx > 0) sprite.setTextureRect(sf::IntRect(112 + 31 * int(currentFrame), 144, 16, 16));
		if (dx < 0) sprite.setTextureRect(sf::IntRect(112 + 31 * int(currentFrame) + 16, 144, -16, 16));


		sprite.setPosition(rect.left - scene->offsetX, rect.top - scene->offsetY);

		dx = 0;
	}


	void Collision(int num)
	{

		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
			{
				if ((scene->mainTilemap[i][j] == 'P') || (scene->mainTilemap[i][j] == 'k') || (scene->mainTilemap[i][j] == '0') || (scene->mainTilemap[i][j] == 'r'))
				{
					if (dy > 0 && num == 1) {
						rect.top = i * 16 - rect.height;  dy = 0;   onGround = true;
					}
					if (dy < 0 && num == 1) {
						rect.top = i * 16 + 16;   dy = 0;
					}
					if (dx > 0 && num == 0)
						rect.left = j * 16 - rect.width;
					if (dx < 0 && num == 0)
						rect.left = j * 16 + 16;

				}


			}

	}

};