#pragma once
#include "Scene.h"
#include "TestScene.h"
#include "Database.h"
#include "Renderer.h"

class Enemy {
public:
	float dx;
	sf::FloatRect rect;
	sf::Sprite sprite;
	float currentFrame = 0;
	bool alive = true;
	Scene* scene;
	int i, j;

	Enemy(int i, int j, Scene* _scene) {

		scene = _scene;
		sprite.setTexture(DATABASE.textures.at(22));
		sprite.setScale(2, 2);
		rect = sf::FloatRect(j * 16 * sizeMultiplier, i * 16 * sizeMultiplier, 64, 64);//4848, 5568, 32 * 2, 32 * 2));
		this->i = i;
		this->j = j;
		dx = 0.05;
	}
	void Update(float time)
	{
		if (alive) {
			rect.left += dx * time;

			Collision();
			currentFrame += time * 0.005;
			if (currentFrame >= 4)
				currentFrame = 0;
			if (dx > 0) sprite.setTextureRect(sf::IntRect(11 + 48 * int(currentFrame), 18, 32, 32));
			if (dx < 0) sprite.setTextureRect(sf::IntRect(11 + 48 * int(currentFrame) + 32, 18, -32, 32));
			sprite.setPosition(rect.left - scene->offsetX, i * 16 * sizeMultiplier - scene->offsetY);
			window.Renderer.draw(sprite);
		}

	}
	void Collision()
	{

		for (int k = rect.top / 16 / sizeMultiplier; k < (rect.top + rect.height) / 16 / sizeMultiplier; k++)
			for (int l = rect.left / 16 / sizeMultiplier; l < (rect.left + rect.width) / 16 / sizeMultiplier; l++)
				if ((scene->mainTilemap[k][l] == '5'))
				{
					if (dx > 0) {
						dx *= -1;
					}
					else if (dx < 0)
						dx *= -1; 

				}
	}
};
