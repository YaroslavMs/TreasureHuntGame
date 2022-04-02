#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Scene.h"
#include "Textures.h"
#include "Renderer.h"
class PLAYER {
	Scene* scene;

public:

	float dx, dy;
	sf::FloatRect rect;
	bool onGround;
	sf::Sprite sprite;
	float currentFrame;

	PLAYER(Scene* scene, sf::Texture& image)
	{
		this->scene = scene;
		sprite.setTexture(image);
		rect = sf::FloatRect(100, 600, 16, 16);

		dx = dy = 0.1;
		currentFrame = 0;
	}
	~PLAYER() {
		delete scene;
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
std::string tileset1[50] = {
"000000000000000000000000000000000000000000000000000000",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k            kkkk                                    r",
"k                                                    r",
"k           k                                        r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k        kkkk                                        r",
"k                                                    r",
"k                kkk                                 r",
"k                         kkkk                       r",
"k                                                    r",
"k                                                    r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                      PPP           r",
"k                                                    r",
"k                                                    r",
"k                                         PPP        r",
"k                                                    r",
"k                                                    r",
"k                                      PPP           r",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"                                                      ",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",

};
class TestScene : public Scene {
	PLAYER player;
public:
	TestScene(sf::Texture& texture) : player(this, texture) {
		mainTilemap = tileset1;
		tileset.setTexture(texture);
		height = 50;
		width = 55;
	}

	void Update(float time) override {
		offsetX = player.rect.left - sf::VideoMode().getDesktopMode().width / 2;
		offsetY = player.rect.top - sf::VideoMode().getDesktopMode().height / 2;
		
		time = time / 500;

		if (time > 20) time = 20;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))    player.dx = -0.1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))    player.dx = 0.1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))	if (player.onGround) { player.dy = -0.27; player.onGround = false; }


		player.update(time);

		DrawMap();

	};
	void DrawMap() override {
		


		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
			{
				if (mainTilemap[i][j] == 'P')  tileset.setTextureRect(sf::IntRect(240, 720, 16, 16));

				if (mainTilemap[i][j] == 'k')  tileset.setTextureRect(sf::IntRect(175, 672, 16, 16));

				if (mainTilemap[i][j] == 'r')  tileset.setTextureRect(sf::IntRect(512, 672, 16, 16));

				if ((mainTilemap[i][j] == ' ') || (mainTilemap[i][j] == '0')) continue;

				tileset.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.Renderer.draw(tileset);
			}


		window.Renderer.draw(player.sprite);


		
	};
};
