#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

std::vector<std::string> KeyNames = { "A", "B", "C",
"D", "E", "F", "G",
"H", "I", "J", "K",
"L", "M", "N", "O",
"P", "Q", "R", "S",
"T", "U", "V", "W",
"X", "Y", "Z", "Num0",
"Num1", "Num2", "Num3", "Num4",
"Num5", "Num6", "Num7", "Num8",
"Num9", "Escape", "LControl", "LShift",
"LAlt", "LSystem", "RControl", "RShift",
"RAlt", "RSystem", "Menu", "LBracket",
"RBracket", "Semicolon", "Comma", "Period",
"Quote", "Slash", "Backslash", "Tilde",
"Equal", "Hyphen", "Space", "Enter",
"Backspace", "Tab", "PageUp", "PageDown",
"End", "Home", "Insert", "Delete",
"Add", "Subtract", "Multiply", "Divide",
"Left", "Right", "Up", "Down",
"Numpad0", "Numpad1", "Numpad2", "Numpad3",
"Numpad4", "Numpad5", "Numpad6", "Numpad7",
"Numpad8", "Numpad9", "F1", "F2",
"F3", "F4", "F5", "F6",
"F7", "F8", "F9", "F10",
"F11", "F12", "F13", "F14",
"F15", "Pause", "KeyCount", "Dash",
"Backspace", "Backslash", "Semicolon", "Return" };

class KeyButtons {
public:
	sf::Keyboard::Key Jump = sf::Keyboard::Space, secondaryJump = sf::Keyboard::W;               //00 01
	sf::Keyboard::Key Left = sf::Keyboard::A, secondaryLeft = sf::Keyboard::Left;                //10 11
	sf::Keyboard::Key Right = sf::Keyboard::D, secondaryRight = sf::Keyboard::Right;             //20 21
	sf::Keyboard::Key Crouch = sf::Keyboard::LControl, secondaryCrouch = sf::Keyboard::C;        //30 31

	sf::Keyboard::Key keys[4][2] = {
		{sf::Keyboard::Space, sf::Keyboard::W},
		{sf::Keyboard::A, sf::Keyboard::Left},
	    {sf::Keyboard::D, sf::Keyboard::Right },
	     {sf::Keyboard::LControl, sf::Keyboard::C}
	};
};
KeyButtons Controls;