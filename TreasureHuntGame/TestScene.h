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
#include "Enemy.h"
#include "UI.h"

class TestScene : public Scene {
	Player player;
	std::vector<Enemy> enemies;
public:
	UI ui;
	TestScene() : Scene(sf::FloatRect(100 * sizeMultiplier, 2200 * sizeMultiplier, 28 * 1.2 * sizeMultiplier, 40 * 1.2 * sizeMultiplier)), player(this){
		//	CheckPoint checkpoint[] = { CheckPoint(132, 61), CheckPoint(131, 61), CheckPoint(), CheckPoint(), CheckPoint() };
		//	checkpoints[0] = CheckPoint(132, 61);
		//	checkpoints[1] = CheckPoint(131, 61);
		offsetX = player.rect.left - sf::VideoMode().getDesktopMode().width / 2;
		offsetY = player.rect.top - sf::VideoMode().getDesktopMode().height / 2 - 150;

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
		saw.setTexture(DATABASE.textures.at(17));
		fireTrap.setTexture(DATABASE.textures.at(18));
		lightningTrap.setTexture(DATABASE.textures.at(19));
		ceilingTrap.setTexture(DATABASE.textures.at(20));
		coin.setScale(sf::Vector2f(2 * sizeMultiplier, 2 * sizeMultiplier));
		tileset.setScale(sf::Vector2f(sizeMultiplier, sizeMultiplier));
		healPotion.setScale(sf::Vector2f(sizeMultiplier, sizeMultiplier));
		saw.setScale(sf::Vector2f(sizeMultiplier, sizeMultiplier));
		fireTrap.setScale(sf::Vector2f(sizeMultiplier, sizeMultiplier));
		lightningTrap.setScale(sf::Vector2f(sizeMultiplier, sizeMultiplier));
		ceilingTrap.setScale(sf::Vector2f(sizeMultiplier, sizeMultiplier));
		key.setScale(sf::Vector2f(2, 2));
		door.setScale(sf::Vector2f(0.3, 0.3));
		allCoins = 0;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				if (mainTilemap[i][j] == 'p')
					allCoins++;
				else if (mainTilemap[i][j] == '4') {
					Enemy enemy(i, j, this);
					enemies.push_back(enemy);
				}
			}

		obelisk.setScale(sf::Vector2f(0.7, 0.7));

		//height = 142;
	//	width = 300;
	}
	~TestScene() {
	//	delete enemy;
	}
	bool isOver() {
		if (player.lives <= 0) {
			player.lives = 5;
			return true;
		}
		return false;
	}
	bool Lost() {
		return player.lost;
	}
	void Restart()override {
		player.Restart();
	}
	void Respawn() {
		player.LoseLife();
	}
	void Update(float time) override {
		if (!player.lost && !levelCompleted) {
			window.Renderer.draw(background);

			offsetX = player.rect.left - sf::VideoMode().getDesktopMode().width / 2;
			offsetY = player.rect.top - sf::VideoMode().getDesktopMode().height / 2 - 150;

			time = time / 400;

			if (!ui.gamePaused) {
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
				
				//enemy->
				//
				currentDiamond += time * 0.003;
				currentObelisk += time * 0.003;
				currentKey += time * 0.005;
				currentFireTrap += time * 0.002;
				currentCeilingTrap += time * 0.0025;
				currentLightningTrap += time * 0.002;
				currentSaw += time * 0.003;
				DrawMap();
				player.update(time);
			}
			ui.Update(time);
			ui.Draw(player);
			for (int i = 0; i < enemies.size(); i++)
			{
				enemies[i].Update(time);
				if (player.rect.intersects(enemies[i].rect)) {
					player.hitSound.play();
					player.lost = true;
				}
			}
		}
		else if (player.lost) {
			DrawMap();
			ui.YouDiedMenu(player);
		}
		else if (levelCompleted) {
			DrawMap();
			ui.WinMenu(score);
		}

	};
	void DrawMap() override {


		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (j * 16 * sizeMultiplier - offsetX < -600 ||
					i * 16 * sizeMultiplier - offsetY < -600 ||
					j * 16 * sizeMultiplier - offsetX > window.width + 600 ||
					i * 16 * sizeMultiplier - offsetY > window.height + 600) {
					continue;
				}
				else if (mainTilemap[i][j] == ' ') continue;
				else if (mainTilemap[i][j] == '0') continue; //trap colliders
				else if (mainTilemap[i][j] == '4' || mainTilemap[i][j] == '5') continue;
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

				else if (mainTilemap[i][j] == '1') {
					if (currentLightningTrap >= 12)
						currentLightningTrap = 0;
					if ((int)currentLightningTrap == 3) {
						for (int k = 1; k <= 5; k++) {
							mainTilemap[i + k][j] = '0';
						}
					}
					else if ((int)currentLightningTrap == 10) {
						for (int k = 1; k <= 5; k++) {
							mainTilemap[i + k][j] = ' ';
						}
					}
					lightningTrap.setTextureRect(sf::IntRect(32 + (int)currentLightningTrap * 96, 0, 38, 98));
					lightningTrap.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
					window.Renderer.draw(lightningTrap);
					continue;
				}
				else if (mainTilemap[i][j] == '2') {
					if (currentFireTrap >= 9)
						currentFireTrap = 0;
					fireTrap.setTextureRect(sf::IntRect(10 + (int)currentFireTrap * 32, 20, 14, 44));
					fireTrap.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY - 85);
					window.Renderer.draw(fireTrap);
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
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (j * 16 * sizeMultiplier - offsetX < -600 ||
					i * 16 * sizeMultiplier - offsetY < -600 ||
					j * 16 * sizeMultiplier - offsetX > window.width + 600 ||
					i * 16 * sizeMultiplier - offsetY > window.height + 600) {
					continue;
				}
				if (mainTilemap[i][j] != '3' && mainTilemap[i][j] != 't') {
					continue;
				}
				else if (mainTilemap[i][j] == '3') {
					mainTilemap[i][j + 1] == 0;
					if (currentCeilingTrap >= 14)
						currentCeilingTrap = 0;
					if ((int)currentCeilingTrap == 1) {
						for (int k = 1; k <= 3; k++) {
							mainTilemap[i + k][j] = '0';
							mainTilemap[i + k][j + 1] = '0';
						}
					}
					else if ((int)currentCeilingTrap == 5) {
						mainTilemap[i + 3][j] = ' ';
						mainTilemap[i + 3][j + 1] = ' ';
					}
					else if ((int)currentCeilingTrap == 7) {
						mainTilemap[i + 2][j] = ' ';
						mainTilemap[i + 2][j + 1] = ' ';
					}
					else if ((int)currentCeilingTrap == 9) {
						mainTilemap[i + 1][j] = ' ';
						mainTilemap[i + 1][j + 1] = ' ';
					}
					ceilingTrap.setTextureRect(sf::IntRect(10 + (int)currentCeilingTrap * 64, 0, 50, 64));
					ceilingTrap.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
					window.Renderer.draw(ceilingTrap);
					continue;
				}
				else if (mainTilemap[i][j] == 't') {
					mainTilemap[i + 1][j] = '0';
					if (currentSaw >= 16)
						currentSaw = 0;
					saw.setTextureRect(sf::IntRect(16 + (int)currentSaw * 64, 0, 48 - 16, 36));
					saw.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY);
					window.Renderer.draw(saw);
					continue;
				}
			}


		//	window.Renderer.draw(player.idle);



	}
};
