/*#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Scene.h"
#include "Database.h"
#include "Sprite.h"
#include "TestScene.h"
#include "MainMenu.h"
//#include "Object.h"

int main()
{
	bool gameStarted = false;
	MainMenu mainMenu;
	TestScene test;
	//Scene* scene = nullptr; //= &test;
	sf::Clock clock;
	while (window.Renderer.isOpen()) {
		window.Renderer.clear(sf::Color::Black);
		//window.Renderer.draw(fonSp);

		if (!gameStarted) {
			auto number = mainMenu.UpdateMenu();
		}

		float time = clock.restart().asMicroseconds(); //clock.getElapsedTime().asMicroseconds();
		if (gameStarted)
			test.Update(time);
		sf::Event event;
		while (window.Renderer.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				window.Renderer.close();
			if (event.type == sf::Event::EventType::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
					sf::Mouse mouse;
					auto number = mainMenu.MouseClicked(mouse);
					if (number == 1) {
						gameStarted = true;
					}
					if (number == 2) {
						gameStarted = false;
					}
					if (number == 3) {
						window.Renderer.close();
					}
				}
			}
		}
		if (window.Renderer.isOpen())
			window.Renderer.display();
	}
	//	if (scene != nullptr)
	//		delete scene;
		//	delete menu;
}
*/