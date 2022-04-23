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
      // Renderer.create(sf::VideoMode(width, height), "New Title", sf::Style::Fullscreen);
        width = 1600;
       height = 1000;
      Renderer.create(sf::VideoMode(1600, 1000), "New Title");
    }
};

Window window;

