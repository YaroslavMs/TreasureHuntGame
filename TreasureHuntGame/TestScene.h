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
	float currentDiamond = 0, currentObelisk = 0, currentKey = 0, currentDiamond2 = 0, currentDiamond3 = 0, currentDiamond4 = 0, currentDiamond5 = 0, currentDiamond6 = 0;
public:
	
	TestScene() : Scene(sf::FloatRect(100 * sizeMultiplier, 2200 * sizeMultiplier, 28 * 1.2 * sizeMultiplier, 40 * 1.2 * sizeMultiplier)), player(this) {
	//	CheckPoint checkpoint[] = { CheckPoint(132, 61), CheckPoint(131, 61), CheckPoint(), CheckPoint(), CheckPoint() };
	//	checkpoints[0] = CheckPoint(132, 61);
	//	checkpoints[1] = CheckPoint(131, 61);
		mainTilemap = TileMap;
		doorText.setFont(DATABASE.fonts.at(0));
		doorText.setCharacterSize(20);
		doorText.setFillColor(sf::Color::Yellow);
		doorText.setOutlineColor(sf::Color::Black);
		doorText.setOutlineThickness(2);
		tileset.setTexture(DATABASE.textures.at(1));
		door.setTexture(DATABASE.textures.at(15));
		coin.setTexture(DATABASE.textures.at(12));
		healPotion.setTexture(DATABASE.textures.at(13));
		obelisk.setTexture(DATABASE.textures.at(14));
		key.setTexture(DATABASE.textures.at(16));
		trap.setTexture(DATABASE.textures.at(17));
		coin.setScale(sf::Vector2f(2 * sizeMultiplier, 2 * sizeMultiplier));
		tileset.setScale(sf::Vector2f(sizeMultiplier, sizeMultiplier));
		healPotion.setScale(sf::Vector2f(sizeMultiplier, sizeMultiplier));
		key.setScale(sf::Vector2f(2, 2));
		door.setScale(sf::Vector2f(0.3, 0.3));

	

		obelisk.setScale(sf::Vector2f(0.7, 0.7));

		height = 142;
		width = 300;
		
	}
	//~TestScene() {
	//	player.~Player();
	//}
	bool isOver() {
		if (player.lives <= 0) {
			player.lives = 5;
			return true;
		}
		return false;
	}
	void Restart() {
		player.Restart();
	}
	void Update(float time) override {

		window.Renderer.draw(background);



		offsetX = player.rect.left - sf::VideoMode().getDesktopMode().width / 2;
		offsetY = player.rect.top - sf::VideoMode().getDesktopMode().height / 2 - 150;

		time = time / 400;

	//	if (time > 6) time = 6;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))    player.dx = -0.1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))    player.dx = 0.1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))    player.Restart();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			if (player.onGround) {
				if (player.crouching)
					player.dy = -0.20 * 1.2;
				else  player.dy = -0.27 * 1.2;
				player.onGround = false; player.jumped = true;
			}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
			player.crouching = true;
			player.rect.height = 26 * 1.2 * sizeMultiplier;
		}
		else if (player.CheckToStandCol()) {
			sf::FloatRect crouchRect = player.rect;
			player.rect = sf::FloatRect(crouchRect.left, crouchRect.top + crouchRect.height - 40 * 1.2 * sizeMultiplier, crouchRect.width, 40 * 1.2 * sizeMultiplier);
			player.crouching = false;
		}
		currentDiamond += time * 0.003;
		currentDiamond2 += time * 0.003;
		currentDiamond3 += time * 0.003;
		currentDiamond4 += time * 0.003;
		currentDiamond5 += time * 0.003;
		currentDiamond6 += time * 0.003;
		currentObelisk += time * 0.003;
		currentKey += time * 0.005;
		DrawMap();
		player.update(time);
		ui.Update(time);
		ui.Draw(player);


	};
	void DrawMap() override {


		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (j * 16 * sizeMultiplier - offsetX < -600 ||
					i * 16 * sizeMultiplier - offsetY < -600  ||
					j * 16 * sizeMultiplier - offsetX > 4000 ||
					i * 16 * sizeMultiplier - offsetY > 3000) {
					continue;
				}
				else if (mainTilemap[i][j] == ' ') continue;
				else if (mainTilemap[i][j] == '0') continue;//tile.setTextureRect(IntRect(1326, 864, 16, 16)); 
				else if (mainTilemap[i][j] == 'a')  tileset.setTextureRect(sf::IntRect(240, 720, 16, 16));// низ
				else if (mainTilemap[i][j] == 'c')  tileset.setTextureRect(sf::IntRect(176, 672, 16 * 2, 16 * 2));//л≥ва ст≥на
				else if (mainTilemap[i][j] == 'd')  tileset.setTextureRect(sf::IntRect(512, 672, 16, 16));//права ст≥на
			   // if (TileMap[i][j] == 't')  tile.setTextureRect(IntRect(160, 448, 64, 64));//л≥вий верхн≥й кут
				else if (mainTilemap[i][j] == 'b')  tileset.setTextureRect(sf::IntRect(240, 464, 32, 16));//потолок
				else if (mainTilemap[i][j] == 'm')  tileset.setTextureRect(sf::IntRect(176, 720, 16, 16));//нижн≥й л≥вий кут
				//if (TileMap[i][j] == 'w')  tile.setTextureRect(IntRect(480, 448, 64, 64));//верхн≥й правий кут
				else if (mainTilemap[i][j] == 'e')  tileset.setTextureRect(sf::IntRect(512, 720, 16, 16));//нижн≥й правий кут
			   // if (TileMap[i][j] == 's')  tile.setTextureRect(IntRect(480, 720, 16, 16));//зовн≥шн≥й верхн≥й кут
			  //  if (TileMap[i][j] == 'd')  tile.setTextureRect(IntRect(176, 544, 16, 16));//зовн≥шн≥й нижн≥й кут
				else if (mainTilemap[i][j] == 'f')  tileset.setTextureRect(sf::IntRect(512, 544, 32, 32));
				else if (mainTilemap[i][j] == 'g')  tileset.setTextureRect(sf::IntRect(512, 528, 16, 16));
				else if (mainTilemap[i][j] == 'l')  tileset.setTextureRect(sf::IntRect(176, 544, 32, 32));
				else if (mainTilemap[i][j] == 'k')  tileset.setTextureRect(sf::IntRect(176, 528, 16, 16));



				else if (mainTilemap[i][j] == 'j')  tileset.setTextureRect(sf::IntRect(208, 720, 32, 32));
				else if (mainTilemap[i][j] == 'i')  tileset.setTextureRect(sf::IntRect(480, 720, 32, 32));



				//  if (TileMap[i][j] == 'h')  tile.setTextureRect(IntRect(48, 544, 16, 16));//затемненн€ 
				else if (mainTilemap[i][j] == 'h')  tileset.setTextureRect(sf::IntRect(208, 672, 16, 16));//платформа


				else if (mainTilemap[i][j] == 'n') {
					tileset.setTextureRect(sf::IntRect(2440, 365, 32, 32)); // шипи
					tileset.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY + 5 * sizeMultiplier);
					window.Renderer.draw(tileset);
					continue;
				}

				else if (mainTilemap[i][j] == 'Z')  tileset.setTextureRect(sf::IntRect(2247, 409, 49, 64)); //полиц€ з книгами широка
				else if (mainTilemap[i][j] == 'v')  tileset.setTextureRect(sf::IntRect(2247, 313, 49, 64));//полиц€ з книгами
				else if (mainTilemap[i][j] == 'X')  tileset.setTextureRect(sf::IntRect(2296, 313, 49, 64));//пуста полиц€
				else if (mainTilemap[i][j] == 'B')  tileset.setTextureRect(sf::IntRect(2247, 233, 49, 64));//полиц€ з баночками
				else if (mainTilemap[i][j] == 'C')  tileset.setTextureRect(sf::IntRect(2326, 408, 40, 64));//збро€
				else if (mainTilemap[i][j] == 'Q')  tileset.setTextureRect(sf::IntRect(2361, 264, 32, 64));//щит
				else if (mainTilemap[i][j] == 'W')  tileset.setTextureRect(sf::IntRect(2536, 474, 115, 84));//червона велика павутина
				else if (mainTilemap[i][j] == 'T')  tileset.setTextureRect(sf::IntRect(2361, 472, 32, 64));//списи

				else if (mainTilemap[i][j] == 'M')  tileset.setTextureRect(sf::IntRect(1152, 464, 144, 112));
				else if (mainTilemap[i][j] == 'N')  tileset.setTextureRect(sf::IntRect(1312, 592, 48, 80));
				else if (mainTilemap[i][j] == 'K')  tileset.setTextureRect(sf::IntRect(1424, 512, 32, 32));
				else if (mainTilemap[i][j] == 'A')  tileset.setTextureRect(sf::IntRect(1392, 544, 16, 96));
				else if (mainTilemap[i][j] == 'S')  tileset.setTextureRect(sf::IntRect(1312, 464, 52, 64));
				else if (mainTilemap[i][j] == 'F')  tileset.setTextureRect(sf::IntRect(1424, 656, 32, 32));
				else if (mainTilemap[i][j] == 'D')  tileset.setTextureRect(sf::IntRect(1152, 208, 112, 16));
				else if (mainTilemap[i][j] == 'G')  tileset.setTextureRect(sf::IntRect(1552, 535, 33, 42));
				else if (mainTilemap[i][j] == 'H')  tileset.setTextureRect(sf::IntRect(1152, 464, 48, 80));
				else if (mainTilemap[i][j] == 'V')  tileset.setTextureRect(sf::IntRect(1392, 544, 16, 64));
				else if (mainTilemap[i][j] == 'E')  tileset.setTextureRect(sf::IntRect(1152, 464, 144, 80));

				else if (mainTilemap[i][j] == 's') {
					if (currentObelisk >= 13)
						currentObelisk = 0;
					obelisk.setTextureRect(sf::IntRect(60 + (int)currentObelisk * 200, 50, 100, 350));
					obelisk.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - 130 - offsetY);
					window.Renderer.draw(obelisk);
					continue;
				}
				else if (mainTilemap[i][j] == 't')   {
					if (currentDiamond5 >= 16)
						currentDiamond5 = 0;
					trap.setTextureRect(sf::IntRect(52 + (int)currentDiamond4 * 148.2, 1579, 60, 86));
					trap.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
					window.Renderer.draw(trap);
					continue;
				}

				else if (mainTilemap[i][j] == '1') {
					trap.setTextureRect(sf::IntRect(56+(int)currentDiamond4*147.85, 2109, 56, 142));
					if (currentDiamond4 >= 30)
						currentDiamond4 = 0;
					trap.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
					window.Renderer.draw(trap);
					continue;
				}
				else if (mainTilemap[i][j] == '2') {
					if (currentDiamond2 >= 12)
						currentDiamond2 = 0;
					trap.setTextureRect(sf::IntRect(23+(int)currentDiamond2*74, 1300, 74, 170));
					trap.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
					window.Renderer.draw(trap);
					continue;
				}
				else if (mainTilemap[i][j] == '3') {
					if (currentDiamond3 >= 14)
						currentDiamond3 = 0;
					trap.setTextureRect(sf::IntRect(39 + (int)currentDiamond2*10 , 0, 114, 166));
					trap.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
					window.Renderer.draw(trap);
					continue;
				}
				else if (mainTilemap[i][j] == '4') {
				if (currentDiamond6 >= 14)
					currentDiamond6 = 0;
				trap.setTextureRect(sf::IntRect(39 + (int)currentDiamond2 * 101, 0, 114, 166));
				trap.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
				window.Renderer.draw(trap);
				continue;
				}

				else if (mainTilemap[i][j] == 'z') {

					std::string str = std::to_string(player.keysFound) + " / " + std::to_string(allKeys) + " keys found.";
					doorText.setString(str);
					//door.setTextureRect(sf::IntRect(0, 0, 25, 22));//door
					door.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY - 80);
					doorText.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY - 100);
					window.Renderer.draw(door);
					window.Renderer.draw(doorText);
					continue;
				}

				else if (mainTilemap[i][j] == 'o') {
					healPotion.setTextureRect(sf::IntRect(232, 230, 245 - 232, 18));
					healPotion.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
					window.Renderer.draw(healPotion);
					continue;

				}
				else if (mainTilemap[i][j] == 'p') {
					if (currentDiamond >= 5)
						currentDiamond = 0;
					coin.setTextureRect(sf::IntRect(0 + 8 * (int)currentDiamond, 0, 8, 9));
					coin.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
					window.Renderer.draw(coin);
					continue;
				}
				else if (mainTilemap[i][j] == '+') {
					if (currentKey >= 12)
						currentKey = 0;
					key.setTextureRect(sf::IntRect(10 + (int)currentKey * 32, 0, 12, 32));
					key.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
					window.Renderer.draw(key);
					continue;


				}
					tileset.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
					window.Renderer.draw(tileset);
			}


		//	window.Renderer.draw(player.idle);



	};
};
