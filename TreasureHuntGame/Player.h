#pragma once
#include "Scene.h"
#include "TestScene.h"
#include "Database.h"

class Player {
	Scene* scene;
	bool facingRight = true;

public:

	float dx, dy;
	sf::FloatRect rect;
	bool onGround = false, jumping = false, jumped = false;
	sf::Sprite idle, run, jump, fall;
	float currentFrame;

	Player(Scene* scene)
	{
		this->scene = scene;
		idle.setTexture(DATABASE.textures.at(3));
		run.setTexture(DATABASE.textures.at(4));
		jump.setTexture(DATABASE.textures.at(5));
		fall.setTexture(DATABASE.textures.at(6));
		idle.setScale(1.2, 1.2);
		run.setScale(1.2, 1.2);
		jump.setScale(1.2, 1.2);
		fall.setScale(1.2, 1.2);
		rect = sf::FloatRect(100, 600, 28 * 1.2, 40 * 1.2);

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

		if (jumped) {
			currentFrame = 0;
			jumped = 0;
			jumping = 1;
		}
		currentFrame += time * 0.005;
		idle.setPosition(rect.left - scene->offsetX, rect.top - scene->offsetY);
		jump.setPosition(rect.left - scene->offsetX, rect.top - scene->offsetY);
		run.setPosition(rect.left - scene->offsetX, rect.top - scene->offsetY);
		fall.setPosition(rect.left - scene->offsetX, rect.top - scene->offsetY);

		if (dx > 0) facingRight = 1;
		if (dx < 0) facingRight = 0;
		//jump animation
		if (jumping) {
			if (currentFrame >= 3) jumping = 0;
			if (facingRight) jump.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame), 40, 30, 41));
			else jump.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame) + 30, 40, -30, 41));
			window.Renderer.draw(jump);
		}
		else {
			//Fall animation
			if (dy > 0) {
				if (currentFrame >= 3) currentFrame = 0;
				if (facingRight) {
					fall.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame), 40, 30, 41));
				}
				else if (!facingRight) {
					fall.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame) + 30, 40, -30, 41));
				}
				window.Renderer.draw(fall);
			}
			//Idle animation
			else if (dx == 0) {

				if (currentFrame >= 10) currentFrame = 0;
				if (facingRight) idle.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame), 40, 30, 41));
				else idle.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame) + 30, 40, -30, 41));
				window.Renderer.draw(idle);
			}
			//Running animation
			else {
				if (currentFrame >= 10) currentFrame = 0;
				if (dx > 0) {
				//	facingRight = true;
					run.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame), 40, 30, 41));
				}
				else if (dx < 0) {
				//	facingRight = false;
					run.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame) + 30, 40, -30, 41));
				}

				window.Renderer.draw(run);
			}
		}

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