#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Window
{

public:
    sf::RenderWindow Renderer;
    int width, height;
    Window() {
        width = sf::VideoMode::getDesktopMode().width;
        height = sf::VideoMode::getDesktopMode().height;
        SetFullscreenWindow();
    }
    void SetFullscreenWindow() {
        Renderer.clear();
        Renderer.create(sf::VideoMode(width, height), "New Title", sf::Style::Fullscreen);
    }
};

Window window;

