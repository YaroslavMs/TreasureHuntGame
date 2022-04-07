#pragma once
#include "Scene.h"
#include "TestScene.h"
#include "Database.h"

class Player {
	Scene* scene;
	bool facingRight = true;
	bool lost = false;

public:

	float dx, dy;
	int lives = 5;
	sf::FloatRect rect;
	sf::FloatRect spawnPoint;
	bool onGround = false, jumping = false, jumped = false, crouching = false;
	sf::Sprite idle, run, jump, fall, crouch, crouchWalk;
	float currentFrame;

	Player(Scene* scene)
	{
		this->scene = scene;
		idle.setTexture(DATABASE.textures.at(3));
		run.setTexture(DATABASE.textures.at(4));
		jump.setTexture(DATABASE.textures.at(5));
		fall.setTexture(DATABASE.textures.at(6));
		crouch.setTexture(DATABASE.textures.at(7));
		crouchWalk.setTexture(DATABASE.textures.at(8));
		idle.setScale(1.2, 1.2);
		run.setScale(1.2, 1.2);
		jump.setScale(1.2, 1.2);
		fall.setScale(1.2, 1.2);
		crouch.setScale(1.1, 1.1);
		crouchWalk.setScale(1.1, 1.1);
		rect = scene->spawnPoint;
		spawnPoint = scene->spawnPoint;
		dx = dy = 0.1;
		currentFrame = 0;
	}
	~Player() {
		//	delete scene;
	}
	void LoseLife() {
		dx = 0.1;
		dy = 0.1;
		currentFrame = 0;
		lives--;
		rect = spawnPoint;
	}

	void update(float time)
	{
		if (crouching)
			rect.left += dx * time * 0.6f;
		else rect.left += dx * time;
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
		crouch.setPosition(rect.left - scene->offsetX, rect.top - scene->offsetY);
		crouchWalk.setPosition(rect.left - scene->offsetX, rect.top - scene->offsetY);

		if (dx > 0) facingRight = 1;
		if (dx < 0) facingRight = 0;
		//jump animation
		if (crouching) {
			if (dx == 0) {
				if (facingRight)crouch.setTextureRect(sf::IntRect(42, 52, 30, 30));
				else crouch.setTextureRect(sf::IntRect(42 + 30, 52, -30, 30));
				window.Renderer.draw(crouch);
			}
			else {
				if (currentFrame >= 8) currentFrame = 0;

				if (dx > 0) {
					crouchWalk.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame), 52, 40, 30));
				}
				else crouchWalk.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame) + 30, 52, -30, 30));
				window.Renderer.draw(crouchWalk);
			}


		}
		else if (jumping) {
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
					run.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame), 40, 30, 41));
				}
				else if (dx < 0) {
					run.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame) + 30, 40, -30, 41));
				}

				window.Renderer.draw(run);
			}
		}
		if (lost) {
			lost = false;
			LoseLife();
		}

		dx = 0;
	}


	void Collision(int num)
	{
		auto top = rect.top;
		auto height = rect.height;
		auto left = rect.left;
		auto width = rect.width;

		for (int i = (int)top / 16; i < (top + height) / 16; i++)
			for (int j = (int)left / 16; j < (left + width) / 16; j++)
			{
				if (i < TileMap->length()) {
					if (j < TileMap[i].length()) {
						if (TileMap[i][j] == 110) {
							lost = true;
						}
						else if (TileMap[i][j] >= 97 && TileMap[i][j] <= 109)
						{
							if (dy > 0 && num == 1)
							{
								rect.top = i * 16 - rect.height;  dy = 0;   onGround = true;
							}
							if (dy < 0 && num == 1)
							{
								rect.top = i * 16 + 16;   dy = 0;
							}
							if (dx > 0 && num == 0)
							{
								rect.left = j * 16 - rect.width;
							}
							if (dx < 0 && num == 0)
							{
								rect.left = j * 16 + 16;
							}
						}
					}
				}

			}
	}
	bool CheckToStandCol() {
		float height1 = 40 * 1.2;
		float width1 = 28 * 1.2;
		auto top = rect.top;
		auto height = rect.height;
		auto left = rect.left;
		auto width = rect.width;
		for (int i = (top + height - height1) / 16; i < (top + height) / 16; i++)
			for (int j = left / 16; j < (left + width1) / 16; j++)
			{
				if (TileMap[i][j] >= 97 && TileMap[i][j] <= 109)
				{
					return false;
				}
			}

		return true;
	}
};