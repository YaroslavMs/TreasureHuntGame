#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Window
{

public:
    sf::RenderWindow Renderer;
    Window() {
        SetFullscreenWindow();
    }
    void SetFullscreenWindow() {
        auto x = sf::VideoMode::getDesktopMode().width;
        auto y = sf::VideoMode::getDesktopMode().height;
        Renderer.clear();
        Renderer.create(sf::VideoMode(x, y), "New Title", sf::Style::Fullscreen);
    }
  /*  void SetRenderWindow(sf::VideoMode videoMode, std::string NameOfWindow) {
        Renderer.clear();
        Renderer.create(videoMode, NameOfWindow);
    }*/
};

Window window;

