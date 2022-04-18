#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Scene.h"
#include "Database.h"
#include "TestScene.h"
#include "MainMenu.h"

void SaveVolume();
void LoadVolume();

int main()
{
	LoadVolume();
	
	MainMenu mainMenu;
	Level* levels = new Level[]{ Level(FirstMap, sf::Vector2f(100, 1100), 0), Level(SecondMap, sf::Vector2f(100, 180), 1), Level(TreeMap, sf::Vector2f(100, 2200), 2) };
	sf::Clock clock;
	int currentLevel = 0;
	while (window.Renderer.isOpen()) {
		window.Renderer.clear(sf::Color::Black);
		if (!gameStarted) {
			auto number = mainMenu.UpdateMenu(levels);
		}
		if (levels[currentLevel].isOver()) {
			levels[currentLevel].Restart();
			gameStarted = false;
		}
		float time = clock.restart().asMicroseconds();
		if (gameStarted)
			levels[currentLevel].Update(time);
		sf::Event event;
		while (window.Renderer.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				window.Renderer.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !levels[currentLevel].Lost()) {
				levels[currentLevel].ui.gamePaused = true;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				if (mainMenu.currentMenu == ActiveMenu::OptionsMenu && !gameStarted) {
					mainMenu.ChangeVolume();
					levels[currentLevel].UpdateVolume();
					mainMenu.UpdateVolume();
				}
			}
			if (event.type == sf::Event::EventType::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
					sf::Mouse mouse;
					if (!gameStarted) {
						auto number = mainMenu.MouseClicked(mouse, levels);
						if (number != -1) {
							gameStarted = true;
							currentLevel = number;
						}
					}
					else if (levels[currentLevel].ui.gamePaused) {
						auto number = levels[currentLevel].ui.MouseClicked(mouse);
						if (number == 2) {
							levels[currentLevel].ui.gamePaused = false;
						}
						else if (number == 3) {
							levels[currentLevel].ui.gamePaused = false;
							levels[currentLevel].Restart();
						}
						else if (number == 4) {
							levels[currentLevel].ui.gamePaused = false;
							mainMenu.currentMenu = ActiveMenu::MainMenu;
							gameStarted = false;
						}
					}
					else if (levels[currentLevel].Lost()) {
						if (levels[currentLevel].ui.RespawnButton(mouse.getPosition())) {
							levels[currentLevel].Respawn();
							if (levels[currentLevel].isOver())
								levels[currentLevel].Restart();
						}
					}
					else if (levels[currentLevel].levelCompleted) {
						auto number = levels[currentLevel].ui.MouseClickedWinMenu(mouse);
						levels[currentLevel].SaveScore();
						if (number == 0) {
							levels[currentLevel].levelCompleted = false;
							levels[currentLevel].Restart();
							gameStarted = false;
						}
						else if (number == 1) {
							levels[currentLevel].levelCompleted = false;
							levels[currentLevel].Restart();
						}
						else if (number == 2) {
							if (currentLevel < 1)
								currentLevel++;
						}

					}
				}
			}
		}
		if (window.Renderer.isOpen())
			window.Renderer.display();
	}
	SaveVolume();
	delete[] levels;
}


void SaveVolume() {

		std::ofstream saveFile("Saves/Volume.dat", std::ios::out | std::ios::binary);
		if (saveFile) {
			saveFile.write((char*)&Volume, sizeof(Volume));
			saveFile.close();
		}
}
void LoadVolume() {
	std::ifstream loadFile("Saves/Volume.dat", std::ios::out | std::ios::binary);
	if (loadFile) {
		loadFile.read((char*)&Volume, sizeof(Volume));
		loadFile.close();
	}
}