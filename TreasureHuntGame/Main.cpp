#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Scene.h"
#include "Textures.h"
#include "Sprite.h"
#include "TestScene.h"
//#include "Object.h"


sf::CircleShape MouseRound(sf::Vector2i mousePos);
int main()
{
	TexturesDatabase texture;
	sf::Texture texture1;
	//if (!texture1.loadFromFile("Assets/Art/plus.png")) {
	//	std::cout << "MistakeOccured";
	//	return 0;
	//}
	
	//texture.AddTextureToDatabase(texture1);
	std::cout << "here OK 0";
	sf::Texture tileset;
	tileset.loadFromFile("Assets/Art/454.png");
	TestScene test(tileset);
	Scene* scene = &test;
	sf::Clock clock;
	while (window.Renderer.isOpen()) {
		window.Renderer.clear(sf::Color::Black);

		float time = clock.restart().asMicroseconds(); //clock.getElapsedTime().asMicroseconds();
		scene->Update(time);
		sf::Event event;
		while (window.Renderer.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				window.Renderer.close();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			window.Renderer.draw(MouseRound(sf::Mouse::getPosition(window.Renderer)));
		}

		window.Renderer.display();
	}
}

sf::CircleShape MouseRound(sf::Vector2i mousePos) {

	sf::CircleShape colo(20);
	colo.setFillColor(sf::Color::Red);
	auto screen = sf::VideoMode::getDesktopMode();
	colo.setPosition(sf::Vector2f(mousePos.x - 20, mousePos.y - 20));
	return colo;
}