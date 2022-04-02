/*#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


float offsetX = 0, offsetY = 0;


const int H = 50-1;  //375
const int W = 865 / 16+29+50; //865


String TileMap[H] = {
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"t000ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo0w00",
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0000                                                                                                                              000",
"000                                                                                                                                00",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                         lllllllllr",
"k0                                                                                                                                  r",
"k0                       PPPPPP                                                                       lllllllllllllll               r",
"k0PPPPPPPPPPPPPPPPPs                                                                                                                r",
"k0hhhhhhhhhhhhhhhhk0             PPPPPPPPPPP                                                llllll                                  r",
"k0hhhhhhhhhhhhhhhhk0                                                                                                                r",
"k0hhhhhhhhhhhhhhhhk0                                                                                                                r",
"k0hhhhhhhhhhhhhhhhk0     PPPPPPPP                                                                   llllllllll                      r",
"k0hhhhhhhhhhhhhhhhk0                                                                                                                r",
"k0oooooooooooooooog0                                                                 llllllllllll                                   r",
"k000000000000000000d            PPPPPP                                                                                              r",
"k0                                                                       lllllll                                                    r",
"k0                                                                                                                                  r",
"k0                       PPPPPP                              lllllllll                                                              r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"k0                                                                                                                                  r",
"q0PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPe",
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",

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
        rect = FloatRect(100, 650, 16, 16);

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
                if ((TileMap[i][j] == 'P') || (TileMap[i][j] == 'k') || (TileMap[i][j] == '0') || (TileMap[i][j] == 'r')|| (TileMap[i][j] == 't') || (TileMap[i][j] == 'o') || (TileMap[i][j] == 'q')||(TileMap[i][j] == 'w') || (TileMap[i][j] == 'e') || (TileMap[i][j] == 's') || (TileMap[i][j] == 'd') || (TileMap[i][j] == 'f') || (TileMap[i][j] == 'g') || (TileMap[i][j] == 'h') || (TileMap[i][j] == 'l'))
                {
                    if (dy > 0 && num == 1)
                    {
                        rect.top = i * 16 - rect.height;  dy = 0;   onGround = true;
                    }
                    if (dy < 0 && num == 1)
                    {
                        rect.top = i * 16 + 16;   dy = 0;
                    }
                    if (dx > 0 && num == 0)
                    {
                        rect.left = j * 16 - rect.width;
                    }
                    if (dx < 0 && num == 0)
                    {
                        rect.left = j * 16 + 16;
                    }
                }


            }

    }

};




int main()
{

    RenderWindow window(VideoMode(), "test!", Style::Fullscreen);

    Texture tileSet;
    tileSet.loadFromFile("Assets/Art/454.png");
    Texture player1;

    PLAYER player(player1);

    Sprite tile(tileSet);




    Clock clock;

    while (window.isOpen())
    {

        offsetX = player.rect.left - sf::VideoMode().getDesktopMode().width /2;
        offsetY = player.rect.top - sf::VideoMode().getDesktopMode().height /1.06 ;
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time = time / 500;

        if (time > 20) time = 20;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }


        if (Keyboard::isKeyPressed(Keyboard::Left))    player.dx = -0.1;

        if (Keyboard::isKeyPressed(Keyboard::Right))    player.dx = 0.1;

        if (Keyboard::isKeyPressed(Keyboard::Up))  if (player.onGround) { player.dy = -0.27; player.onGround = false; }



        player.update(time);





        //if (player.rect.left > 100) offsetX = player.rect.left -100; // нестирати!!





        window.clear(Color(Color::Black));


        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
            {
                if (TileMap[i][j] == 'P')  tile.setTextureRect(IntRect(240, 720, 16, 32));

                if (TileMap[i][j] == 'k')  tile.setTextureRect(IntRect(160, 672, 16*2, 16*2));

                if (TileMap[i][j] == 'r')  tile.setTextureRect(IntRect(512, 672, 16*2, 16*2));
                if (TileMap[i][j] == 't')  tile.setTextureRect(IntRect(160, 448, 64, 64));
                if (TileMap[i][j] == 'o')  tile.setTextureRect(IntRect(240, 448, 32, 32));
                if (TileMap[i][j] == 'q')  tile.setTextureRect(IntRect(160, 720, 32, 32));
                if (TileMap[i][j] == 'w')  tile.setTextureRect(IntRect(480, 448, 64, 64));
                if (TileMap[i][j] == 'e')  tile.setTextureRect(IntRect(512, 720, 32, 32));
                if (TileMap[i][j] == 's')  tile.setTextureRect(IntRect(480, 720, 32, 32));
                if (TileMap[i][j] == 'd')  tile.setTextureRect(IntRect(176, 544, 32, 32));
                if (TileMap[i][j] == ' ')  tile.setTextureRect(IntRect(1326, 864, 16, 16)); 
                if (TileMap[i][j] == 'f')  tile.setTextureRect(IntRect(160, 672, 16 , 16 ));
                if (TileMap[i][j] == 'g')  tile.setTextureRect(IntRect(240, 448, 16, 16));
                if (TileMap[i][j] == 'h')  tile.setTextureRect(IntRect(48, 544, 16, 16));
                if (TileMap[i][j] == 'l')  tile.setTextureRect(IntRect(208, 672, 16, 16));

                 if   (TileMap[i][j] == '0') continue;

                tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
                window.draw(tile);
            }


        window.draw(player.sprite);


        window.display();
    }

    return 0;
}*/