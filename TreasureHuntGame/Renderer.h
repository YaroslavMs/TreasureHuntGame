#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Window
{

public:
	sf::RenderWindow Renderer;
	float width, height;
	Window() {
		width = sf::VideoMode::getDesktopMode().width;
		height = sf::VideoMode::getDesktopMode().height;
		SetFullscreenWindow();
	}
	void SetFullscreenWindow() {
		Renderer.clear();
		Renderer.create(sf::VideoMode(width, height), "New Title", sf::Style::Fullscreen);
		//       width = 1200;
		//      height = 900;
		//   Renderer.create(sf::VideoMode(1200, 900), "New Title");
	}
};

Window window;

