#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Scene.h"
#include "Textures.h"
#include "Sprite.h"
#include "TestScene.h"
#include "MainMenu.h"
//#include "Object.h"


sf::CircleShape MouseRound(sf::Vector2i mousePos);
int main()
{
	bool gameStarted = false;
	TexturesDatabase texture;
	sf::Texture texture1;
	//if (!texture1.loadFromFile("Assets/Art/plus.png")) {
	//	std::cout << "MistakeOccured";
	//	return 0;
	//}
	sf::Font font;
	font.loadFromFile("Assets/Fonts/CaslonAntique.ttf");
	//texture.AddTextureToDatabase(texture1);
	sf::Texture tileset;
	sf::Texture button;
	button.loadFromFile("Assets/Art/background.png");
	sf::Texture fon;
	fon.loadFromFile("Assets/Art/12.png");
	tileset.loadFromFile("Assets/Art/454.png");
	texture.AddTextureToDatabase(tileset);
	texture.AddTextureToDatabase(button);
	sf::Sprite fonSp(fon);
	fonSp.setScale(sf::Vector2f(sf::VideoMode().getDesktopMode().width / fonSp.getGlobalBounds().width, sf::VideoMode().getDesktopMode().height / fonSp.getGlobalBounds().height));
	MainMenu mainMenu(texture.textures.at(0), texture.textures.at(1), font);
	TestScene test(texture.textures.at(0));
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
		//	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		//		window.Renderer.draw(MouseRound(sf::Mouse::getPosition(window.Renderer)));
		//	}
		if (window.Renderer.isOpen())
			window.Renderer.display();
	}
	//	if (scene != nullptr)
	//		delete scene;
		//	delete menu;
}

sf::CircleShape MouseRound(sf::Vector2i mousePos) {

	sf::CircleShape colo(20);
	colo.setFillColor(sf::Color::Red);
	auto screen = sf::VideoMode::getDesktopMode();
	colo.setPosition(sf::Vector2f(mousePos.x - 20, mousePos.y - 20));
	return colo;
}