#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Scene.h"
#include "Database.h"
#include "Renderer.h"
#include "Player.h"
std::string tilemapForTestScene[50] = {
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
"k                      kkk                           r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                             kkk                    r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"                                                      ",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",

};
class TestScene : public Scene {
	Player player;
public:
	TestScene() : player(this) {
		mainTilemap = tilemapForTestScene;
		tileset.setTexture(DATABASE.textures.at(0));
		height = 50;
		width = 55;
	}
	//~TestScene() {
	//	player.~Player();
	//}

	void Update(float time) override {
		offsetX = player.rect.left - sf::VideoMode().getDesktopMode().width / 2;
		offsetY = player.rect.top - sf::VideoMode().getDesktopMode().height / 2;
		
		time = time / 500;

		if (time > 20) time = 20;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))    player.dx = -0.1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))    player.dx = 0.1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))	if (player.onGround) { player.dy = -0.27; player.onGround = false; player.jumped = true; }


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


	//	window.Renderer.draw(player.idle);


		
	};
};
