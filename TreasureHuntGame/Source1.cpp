/*#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include <iostream>

using namespace sf;


float offsetX = 0, offsetY = 0;


const int H = 50;  //375
const int W = 865 / 16; //865


String TileMap[H] = {
"000000000000000000000000000000000000000000000000000000",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k            kkkk                                    r",
"k                                                    r",
"k           k                                        r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k        kkkk                                        r",
"k                                                    r",
"k                kkk                                 r",
"k                         kkkk                       r",
"k                                                    r",
"k                                                    r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                      kkk           r",
"k                                                    r",
"k                                                    r",
"k                                                    r",
"k                                      PPP           r",
"k                                                    r",
"k                                                    r",
"k                                         PPP        r",
"k                                                    r",
"k                                                    r",
"k                                      PPP           r",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"                                                      ",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
 
};




class PLAYER {

public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;

	PLAYER(Texture& image)
	{
		sprite.setTexture(image);
		rect = FloatRect(100, 600, 16, 16);

		dx = dy = 0.1;
		currentFrame = 0;
	}


	void update(float time)
	{

		rect.left += dx * time;
		Collision(0);


		if (!onGround) dy = dy + 0.0005 * time;
		rect.top += dy * time;
		onGround = false;
		Collision(1);


		currentFrame += time * 0.005;
		if (currentFrame > 3) currentFrame -= 3;


		if (dx > 0) sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame), 144, 16, 16));
		if (dx < 0) sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame) + 16, 144, -16, 16));


		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

		dx = 0;
	}


	void Collision(int num)
	{

		for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
			for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
			{
				if ((TileMap[i][j] == 'P') || (TileMap[i][j] == 'k') || (TileMap[i][j] == '0') || (TileMap[i][j] == 'r') )
				{
					if (dy > 0 && num == 1) {
						rect.top = i * 16 - rect.height;  dy = 0;   onGround = true;
					}
					if (dy < 0 && num == 1) {
						rect.top = i * 16 + 16;   dy = 0;
					}
					if (dx > 0 && num == 0)					
						rect.left = j * 16 - rect.width;					
					if (dx < 0 && num == 0)					
						rect.left = j * 16 + 16; 
					
				}

				
			}

	}

};




int main()
{

	Texture tileSet;
	tileSet.loadFromFile("Assets/Art/454.png");
	Texture player1;

	PLAYER player(player1);
	
	Sprite tile(tileSet);


	

	Clock clock;

	while (window.Renderer.isOpen())
	{

		offsetX = player.rect.left - sf::VideoMode().getDesktopMode().width / 2;
		offsetY = player.rect.top - sf::VideoMode().getDesktopMode().height / 2;
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 500; 

		if (time > 20) time = 20;

		Event event;
		while (window.Renderer.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.Renderer.close();
		}


		if (Keyboard::isKeyPressed(Keyboard::Left))    player.dx = -0.1;

		if (Keyboard::isKeyPressed(Keyboard::Right))    player.dx = 0.1;

		if (Keyboard::isKeyPressed(Keyboard::Up))	if (player.onGround) { player.dy = -0.27; player.onGround = false;  }



		player.update(time);
	

	


		//if (Mario.rect.left > 100) offsetX = Mario.rect.left -100; // нестирати!!
		




		window.Renderer.clear(Color(Color::Black));

		
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'P')  tile.setTextureRect(IntRect(240, 720, 16, 16));

				if (TileMap[i][j] == 'k')  tile.setTextureRect(IntRect(175, 672, 16, 16));

				if (TileMap[i][j] == 'r')  tile.setTextureRect(IntRect(512, 672, 16, 16));

				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0')) continue;

				tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
				window.Renderer.draw(tile);
			}


		window.Renderer.draw(player.sprite);
		

		window.Renderer.display();
	}

	return 0;
}*/



