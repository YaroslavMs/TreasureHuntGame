#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "TileMaps.h"
#include "Object.h"
#include "Scene.h"
#include "Database.h"
#include "Renderer.h"
#include "Player.h"
#include "UI.h"

class TestScene : public Scene {
	Player player;
	UI ui;
	int backgroundX;
	int backgroundY;
	float currentSprite = 0;
public:
	TestScene() : Scene(sf::FloatRect(100, 2200, 28 * 1.2, 40 * 1.2)), player(this) {
		mainTilemap = TileMap;
		tileset.setTexture(DATABASE.textures.at(1));
		coin.setTexture(DATABASE.textures.at(12));
		coin.setScale(sf::Vector2f(2, 2));
		height = 142;
		width = 300;
		backgroundX = scrW / 10;
		backgroundY = scrH / 6;
	}
	//~TestScene() {
	//	player.~Player();
	//}
	bool isOver() {
		if (player.lives <= 0) {
			player.lives = 3;
			return true;
		}
		return false;
	}
	void Update(float time) override {

		window.Renderer.draw(background);



		offsetX = player.rect.left - sf::VideoMode().getDesktopMode().width / 2;
		offsetY = player.rect.top - sf::VideoMode().getDesktopMode().height / 2;

		time = time / 200;

		if (time > 20) time = 20;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))    player.dx = -0.1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))    player.dx = 0.1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			if (player.onGround) {
				if (player.crouching)
					player.dy = -0.20;
				else  player.dy = -0.27;
				player.onGround = false; player.jumped = true;
			}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
			player.crouching = true;
			player.rect.height = 26 * 1.2;
		}
		else if (player.CheckToStandCol()) {
			sf::FloatRect crouchRect = player.rect;
			player.rect = sf::FloatRect(crouchRect.left, crouchRect.top + crouchRect.height - 40 * 1.2, crouchRect.width, 40 * 1.2);
			player.crouching = false;
		}
		currentSprite += time * 0.003;
		DrawMap();
		player.update(time);
		ui.Update(time);
		ui.Draw(player);


	};
	void DrawMap() override {


		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == ' ') continue;
				else if (TileMap[i][j] == '0') continue;//tile.setTextureRect(IntRect(1326, 864, 16, 16)); 
				else if (TileMap[i][j] == 'a')  tileset.setTextureRect(sf::IntRect(240, 720, 16, 16));// низ
				else if (TileMap[i][j] == 'c')  tileset.setTextureRect(sf::IntRect(176, 672, 16 * 2, 16 * 2));//л≥ва ст≥на
				else if (TileMap[i][j] == 'd')  tileset.setTextureRect(sf::IntRect(512, 672, 16, 16));//права ст≥на
			   // if (TileMap[i][j] == 't')  tile.setTextureRect(IntRect(160, 448, 64, 64));//л≥вий верхн≥й кут
				else if (TileMap[i][j] == 'b')  tileset.setTextureRect(sf::IntRect(240, 464, 32, 16));//потолок
				else if (TileMap[i][j] == 'm')  tileset.setTextureRect(sf::IntRect(176, 720, 16, 16));//нижн≥й л≥вий кут
				//if (TileMap[i][j] == 'w')  tile.setTextureRect(IntRect(480, 448, 64, 64));//верхн≥й правий кут
				else if (TileMap[i][j] == 'e')  tileset.setTextureRect(sf::IntRect(512, 720, 16, 16));//нижн≥й правий кут
			   // if (TileMap[i][j] == 's')  tile.setTextureRect(IntRect(480, 720, 16, 16));//зовн≥шн≥й верхн≥й кут
			  //  if (TileMap[i][j] == 'd')  tile.setTextureRect(IntRect(176, 544, 16, 16));//зовн≥шн≥й нижн≥й кут
				else if (TileMap[i][j] == 'f')  tileset.setTextureRect(sf::IntRect(512, 544, 32, 32));
				else if (TileMap[i][j] == 'g')  tileset.setTextureRect(sf::IntRect(512, 528, 16, 16));
				else if (TileMap[i][j] == 'l')  tileset.setTextureRect(sf::IntRect(176, 544, 32, 32));
				else if (TileMap[i][j] == 'k')  tileset.setTextureRect(sf::IntRect(176, 528, 16, 16));



				else if (TileMap[i][j] == 'j')  tileset.setTextureRect(sf::IntRect(208, 720, 32, 32));
				else if (TileMap[i][j] == 'i')  tileset.setTextureRect(sf::IntRect(480, 720, 32, 32));



				//  if (TileMap[i][j] == 'h')  tile.setTextureRect(IntRect(48, 544, 16, 16));//затемненн€ 
				else if (TileMap[i][j] == 'h')  tileset.setTextureRect(sf::IntRect(208, 672, 16, 16));//платформа


				else if (TileMap[i][j] == 'n') {
					tileset.setTextureRect(sf::IntRect(2440, 365, 32, 32)); // шипи
					tileset.setPosition(j * 16 - offsetX, i * 16 - offsetY + 5);
					window.Renderer.draw(tileset);
					continue;
				}

				else if (TileMap[i][j] == 'Z')  tileset.setTextureRect(sf::IntRect(2247, 409, 49, 64)); //полиц€ з книгами широка
				else if (TileMap[i][j] == 'v')  tileset.setTextureRect(sf::IntRect(2247, 313, 49, 64));//полиц€ з книгами
				else if (TileMap[i][j] == 'X')  tileset.setTextureRect(sf::IntRect(2296, 313, 49, 64));//пуста полиц€
				else if (TileMap[i][j] == 'B')  tileset.setTextureRect(sf::IntRect(2247, 233, 49, 64));//полиц€ з баночками
				else if (TileMap[i][j] == 'C')  tileset.setTextureRect(sf::IntRect(2326, 408, 40, 64));//збро€
				else if (TileMap[i][j] == 'Q')  tileset.setTextureRect(sf::IntRect(2361, 264, 32, 64));//щит
				else if (TileMap[i][j] == 'W')  tileset.setTextureRect(sf::IntRect(2536, 474, 115, 84));//червона велика павутина
				else if (TileMap[i][j] == 'T')  tileset.setTextureRect(sf::IntRect(2361, 472, 32, 64));//списи

				else if (TileMap[i][j] == 'M')  tileset.setTextureRect(sf::IntRect(1152, 464, 144, 112));
				else if (TileMap[i][j] == 'N')  tileset.setTextureRect(sf::IntRect(1312, 592, 48, 80));
				else if (TileMap[i][j] == 'K')  tileset.setTextureRect(sf::IntRect(1424, 512, 32, 32));
				else if (TileMap[i][j] == 'A')  tileset.setTextureRect(sf::IntRect(1392, 544, 16, 96));
				else if (TileMap[i][j] == 'S')  tileset.setTextureRect(sf::IntRect(1312, 464, 52, 64));
				else if (TileMap[i][j] == 'F')  tileset.setTextureRect(sf::IntRect(1424, 656, 32, 32));
				else if (TileMap[i][j] == 'D')  tileset.setTextureRect(sf::IntRect(1152, 208, 112, 16));
				else if (TileMap[i][j] == 'G')  tileset.setTextureRect(sf::IntRect(1552, 535, 33, 42));
				else if (TileMap[i][j] == 'H')  tileset.setTextureRect(sf::IntRect(1152, 464, 48, 80));
				else if (TileMap[i][j] == 'V')  tileset.setTextureRect(sf::IntRect(1392, 544, 16, 64));
				else if (TileMap[i][j] == 'E')  tileset.setTextureRect(sf::IntRect(1152, 464, 144, 80));
				else if (TileMap[i][j] == 'o')  tileset.setTextureRect(sf::IntRect(2330, 253, 32, 16));

				if (TileMap[i][j] != 'p') {
					tileset.setPosition(j * 16 - offsetX, i * 16 - offsetY);
					window.Renderer.draw(tileset);
				}
				else if (TileMap[i][j] == 'p') {
					if (currentSprite >= 5)
						currentSprite = 0;
					coin.setTextureRect(sf::IntRect(0 + 8 * (int)currentSprite, 0, 8, 9));
					coin.setPosition(j * 16 - offsetX, i * 16 - offsetY);
					window.Renderer.draw(coin);
				}
			}


		//	window.Renderer.draw(player.idle);



	};
};
