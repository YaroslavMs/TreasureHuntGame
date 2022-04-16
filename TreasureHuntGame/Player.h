#pragma once
#include "Scene.h"
#include "TestScene.h"
#include "Database.h"

class Player {

	bool facingRight = true;
	float soundTimer = 0;
	sf::Sound footstep, coinSound, keySound, healSound, finishSound;
public:
	sf::Sound hitSound;
	Scene* scene;
	bool lost = false;
	int keysFound = 0;
	float dx, dy;
	int lives = 5, coinsCollected = 0;
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
		idle.setScale(1.2 * sizeMultiplier, 1.2 * sizeMultiplier);
		run.setScale(1.2 * sizeMultiplier, 1.2 * sizeMultiplier);
		jump.setScale(1.2 * sizeMultiplier, 1.2 * sizeMultiplier);
		fall.setScale(1.2 * sizeMultiplier, 1.2 * sizeMultiplier);
		crouch.setScale(1.1 * sizeMultiplier, 1.1 * sizeMultiplier);
		crouchWalk.setScale(1.1 * sizeMultiplier, 1.1 * sizeMultiplier);
		rect = scene->spawnPoint;
		spawnPoint = scene->spawnPoint;
		dx = dy = 0.1;
		currentFrame = 0;
		footstep.setBuffer(DATABASE.soundBuffers.at(0));
		footstep.setVolume(Volume);
		coinSound.setBuffer(DATABASE.soundBuffers.at(1));
		coinSound.setVolume(Volume);
		keySound.setBuffer(DATABASE.soundBuffers.at(2));
		keySound.setVolume(Volume);
		hitSound.setBuffer(DATABASE.soundBuffers.at(3));
		hitSound.setVolume(Volume);
		healSound.setBuffer(DATABASE.soundBuffers.at(4));
		healSound.setVolume(Volume);
		finishSound.setBuffer(DATABASE.soundBuffers.at(5));
		finishSound.setVolume(Volume);
	}
	~Player() {
		//	delete scene;
	}
	void LoseLife() {
		lost = false;
		dx = 0.1;
		dy = 0.1;
		currentFrame = 0;
		lives--;
		rect = spawnPoint;
	}
	void Restart() {
		spawnPoint = scene->spawnPoint;
		coinsCollected = 0;
		keysFound = 0;
		dx = 0.1;
		dy = 0.1;
		currentFrame = 0;
		lives = 5;
		scene->mainTilemap = TileMap;
		rect = spawnPoint;
	}

	void update(float time)
	{
		soundTimer += time * 0.05;
		if (crouching)
			rect.left += dx * time * 0.6f * sizeMultiplier;
		else rect.left += dx * time * sizeMultiplier;
		Collision(0);


		if (!onGround) dy = dy + 0.0005 * time;
		rect.top += dy * time * 2;
		onGround = false;
		Collision(1);

		if (jumped) {
			if (soundTimer > 40) {
				soundTimer = 0;
				footstep.play();
			}
			currentFrame = 0;
			jumping = 1;
			jumped = 0;

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

		if (crouching) {

			if (dx == 0) {
				if (facingRight)crouch.setTextureRect(sf::IntRect(42, 52, 30, 30));
				else crouch.setTextureRect(sf::IntRect(42 + 30, 52, -30, 30));
				window.Renderer.draw(crouch);
			}
			else {
				if (soundTimer > 60) {
					soundTimer = 0;
					footstep.play();
				}
				if (currentFrame >= 8) currentFrame = 0;

				if (dx > 0) {
					crouchWalk.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame), 52, 40, 30));
				}
				else crouchWalk.setTextureRect(sf::IntRect(41 + 120 * int(currentFrame) + 30, 52, -30, 30));
				window.Renderer.draw(crouchWalk);
			}


		}
		//jump animation
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
				if (soundTimer > 40) {
					soundTimer = 0;
					footstep.play();
				}
				window.Renderer.draw(run);
			}
		}
		//	if (lost) {
		//		lost = false;
		//		LoseLife();
		//	}
		dx = 0;
	}


	void Collision(int num)
	{
		auto top = rect.top;
		auto height = rect.height;
		auto left = rect.left;
		auto width = rect.width;

		for (int i = (int)top / 16 / sizeMultiplier; i < (top + height) / 16 / sizeMultiplier; i++)
			for (int j = (int)left / 16 / sizeMultiplier; j < (left + width) / 16 / sizeMultiplier; j++)
			{
				if (i < scene->mainTilemap.size()) {
					if (j < scene->mainTilemap[i].length()) {
						if (scene->mainTilemap[i][j] == ' ')
							continue;
						if (scene->mainTilemap[i][j] == '+') {
							scene->mainTilemap[i][j] = ' ';
							keySound.play();
							keysFound++;

						}
						else if (scene->mainTilemap[i][j] == 'z') {
							if (keysFound == scene->allKeys) {
								finishSound.play();
								scene->score = ((float)coinsCollected / (float)scene->allCoins) * 3;
								scene->levelCompleted = true;
							}
						}
						else if (scene->mainTilemap[i][j] == 's') {
							spawnPoint.left = j * 16 * sizeMultiplier - 10;
							spawnPoint.top = i * 16 * sizeMultiplier - 30;

						}
						else if (scene->mainTilemap[i][j] == 'p') {
							scene->mainTilemap[i][j] = ' ';
							coinSound.play();
							coinsCollected++;

						}
						else if (scene->mainTilemap[i][j] == 'o' && lives < 5) {
							healSound.play();
							scene->mainTilemap[i][j] = ' ';
							lives++;

						}
						else if (scene->mainTilemap[i][j] == '2' && ((int)scene->currentFireTrap >= 4 && (int)scene->currentFireTrap <= 5)) {
							hitSound.play();
							lost = true;
						}
						else if (scene->mainTilemap[i][j] == 110 || scene->mainTilemap[i][j] == 't' || scene->mainTilemap[i][j] == '0' || scene->mainTilemap[i][j] == '3') {
							hitSound.play();
							lost = true;
						}
						else if (scene->mainTilemap[i][j] >= 97 && scene->mainTilemap[i][j] <= 109)
						{
							if (dy > 0 && num == 1)
							{
								rect.top = i * 16 * sizeMultiplier - rect.height;  dy = 0;   onGround = true;
							}
							if (dy < 0 && num == 1)
							{
								rect.top = i * 16 * sizeMultiplier + 16 * sizeMultiplier;   dy = 0;
							}
							if (dx > 0 && num == 0)
							{
								rect.left = j * 16 * sizeMultiplier - rect.width;
							}
							if (dx < 0 && num == 0)
							{
								rect.left = j * 16 * sizeMultiplier + 16 * sizeMultiplier;
							}
						}
					}
				}

			}
		//	for (auto i : scene->enemies)
		//		if (rect.intersects(i.rect))
		//			lost = true;
	}
	bool CheckToStandCol() {
		float height1 = 40 * 1.2 * sizeMultiplier;
		float width1 = 28 * 1.2 * sizeMultiplier;
		auto top = rect.top;
		auto height = rect.height;
		auto left = rect.left;
		auto width = rect.width;
		for (int i = (top + height - height1) / 16 / sizeMultiplier; i < (top + height) / 16 / sizeMultiplier; i++)
			for (int j = left / 16 / sizeMultiplier; j < (left + width1) / 16 / sizeMultiplier; j++)
			{
				if (scene->mainTilemap[i][j] >= 97 && scene->mainTilemap[i][j] <= 109)
				{
					return false;
				}
			}

		return true;
	}
	bool CanJump() {
		auto top = rect.top;
		auto height = rect.height;
		auto left = rect.left;
		auto width = rect.width;

		int i = int(top) / 16 / sizeMultiplier - 1;
		for (int j = (int)left / 16 / sizeMultiplier; j < (left + width) / 16 / sizeMultiplier; j++)
		{
			if (scene->mainTilemap[i][j] >= 97 && scene->mainTilemap[i][j] <= 109)
			{
				return false;
			}
		}
		return true;


	}
};