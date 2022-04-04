#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


float offsetX = 0, offsetY = 0;


const int H = 142;  //375
const int W = 300; //132


String TileMap[H] = {
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000                                                                                                                                                                      ",
"t000ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo                                                                                                                                                                      0w00",
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0000                                                                                                                                                                                                                                                                                                    000",
"000                                                                                                                                                                                                                                                                                                      00",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                                                                                                                                                                                                         r",
"k                                                                                                                    Goooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooog                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                                                      llllllllllllllllllllr                                                                         r",
"k                                                                                                                    k                                                                   zzzzz                                  r                                                                         r",
"k                                                                                                                    k                                                                  llllllllllllllll                        r                                                                         r",
"k                                                                                                                    k                                                zzzzzz                                                    r                                                                         r",
"k                                                                                                                    k                                          llllllllllllllllll                                              r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                         lllllllllllll                                                                    r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k             lllllllll                                                                                    r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                    zzzz                                                                  r                                                                         r",
"k                                                                                                                    k                          lllllllllllllllllll                                                             r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                llllllllll                        llllllllllll            r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                                   zzz                                    r                                                                         r",
"k                                                                                                                    k                                                               llllllllllllllll                           r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                zzzz                                                      r                                                                         r",
"k                                                                                                                    k                                            llllllllllllll                                                r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                  lllllllll                                                               r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    k                                                                                                          r                                                                         r",
"k                                                                                                                    qPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPI         JPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPe                                                                         r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        klll      r                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        k      lllr                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        klll      r                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        k       llr                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        kll       r                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        k         r                                                                                                                      r",
"k                                                                                                                                                                        k     llllr                                                                                                                      r",
"k                                                                                                                                                                        k         fooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooog                        r",
"k                                                                                                                                                                        k                                                                                                       r                        r",
"k                                                                                                                                                                        klll                                                                                                    r                        r",
"k                                                                                                                                                                        k                                                                                                       r                        r",
"k                                                                                                                                                                        k                                                                                                       r                        r",
"k                                                                                                                                                                        k                                                                                                       r                        r",
"k                                                                                                                                                                        qPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPI        JPPPPPPPPPPPPPPPPPe                        r",
"k                                                                                                                                                                                                                                                     k      llr                                          r",
"k                                                                                                                                                                                                                                                     k        r                                          r",
"k                        Gooooooooooooooooooooooooooooooooooooooooooooooooooog                                                                                                                                                                        k        r                                          r",
"k                        k                                                   r                                                                                                                                                                        k        r                                          r",
"k                        k                                                   r                                                                                                                                                                        kll      r                                          r",
"k                        k                                                   r                                                                                                                                                                        k        r                                          r",
"k                        k                                                   r                                                                                                                                                                        k        r                                          r",
"k                        k                                                   r                                                                                                                                                                        k      llr                                          r",
"k                        k                                                   r                                                                                                                                                                        k        r                                          r",
"k                        k                                                   r                                                                                                                                                                        k        r                                          r",
"k                        qPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPI            r                                                                                                                                                                        k        r                                          r",
"k                                                               k            r                                                                                                                                                                        kll      r                                          r",
"k                                                               k            r                                                                                                                                                                        k        r                                          r",
"k                                                               kllllll      r                                                                                                                                                                        k      llr                                          r",
"k                                                               k            r                                                                                                                                                                        k        r                                          r",
"k                                                               k            r                                                                                                                                                                        k        r                                          r",
"k                                                               k            r                                                                                                                                                                        k        r                                          r",
"k                                                               k       lllllr                                                                                                                                                                        kll      r                                          r",
"k                                                               k            r                                                                                                                                                                        k        r                                          r",
"k                                                               k            r                                                                                                                                                                        k        r                                          r",
"k                                                               k            r                              Goooooooooooooooooooooooooooog                                                                                                            k      llr                                          r",
"k                                                               klllll       r                              k                            r                                                                   Gooooooooooog                            k        r                                          r",
"k                                                               k            r                              k                            r                                                                   k           r                            k        r                                          r",
"k                                                               k            r                              k                            r                                                                   k           0                            k        r                                          r",
"k                                                               k            r                              k                            r                                                                   k           fooooooooooooooooooooooooooooFll      r                                          r",
"k                                                               k       lllllr                              k                            r                                                                   k                                                 r                                          r",
"k                                                               k            r                              k         JPPPPPPPPPPPPPPPPPPe                                                                   k                                                 r                                          r",
"k                                                               k            r                              k         r                                                                                      k                                                 r                                          r",
"k                                                               k            r                              k         r                                                                                      k                                               llr                                          r",
"k                                                               k            fooooooooooooooooooooooooooooooF      lllfoooooooooooooooooooooooooooooooooooooooooooooooooooog                                 qPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPI        r                                          r",
"k                                                               kllll                                                                                                      r                                                                          k        r                                          r",
"k                                                               k                                               ll                                                         r                                                                          k        r                                          r",
"k                                                               k                                                                                                          r                                                                          kll      r                                          r",
"k                                                               k                                                                                                          r                                                                          k        r                                          r",
"k                                                               k       lllllJPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPI             0                                                                          k      llr                                          r",
"k                                                               k            r                                                                               k             fooooooooooooooooooooooooooooooooooooooooooooog                            k        r                                          r",
"k                                                               k            r                                                                               k                                                           r                            k        r                                          r",
"k                                                               k            r                                                                               k                                                           fooooooooooooooooooooooooooooFll      r                                          r",
"k                                                               klllll       r                                                                               k                                                                                               llr                                          r",
"k                                                               k            r                                                                               k                                                                                                 r                                          r",
"k                                                               k            r                                                                               k                                                                                                 r                                          r",
"k                                                               k            r                                                                               k                                                                                                 r                                          r",
"k                                                               k        llllr                                                                               qPPPPPPPPPPPPPPPPPPPPPI     JPPI    JPPI     JPPPI    JPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPe                                          r",
"k                                                               k            r                                                                                                     k     r  k    r  k     r   k    r                                                                                      r",
"k                                                               k            r                                                                                                     k     r  k    r  k     r   k    r                                                                                      r",
"k                                                               k            r                                                                                                     k     r  k    r  k     r   k    r                                                                                      r",
"k                                                               klllll       r                                                                                                     kzzzzzr  k    r  k     r   k    r                                                                                      r",
"kooooooooooooooooooooooog        GooooooooooooooooooooooooooooooF            r                                                                                                     qPPPPPe  qPPPPe  qPPPPPe   qPPPPe                          W                                                           r",
"k                       r        k                                           r                                                                                                                                                                                                                            r",
"k                       r        k                                           r                                                                                                                                                                                                                            r",
"k                       0        k                                       llllr                                                                                                                                                                                                                            r",
"k                       fooooooooF                                           r                                                                                                                                                                                                                            r",
"k                                                                            r                                                                                                                                                                                                                            r",
"k                                                                            r                                                                                                                                                                                                                            r",
"qPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPe                                                                                                                                                                                                                            r",
"                                                                                                                                                                                                                                                                                                           ",
"                                                                                                                                                                                                                                                                                                           ",
"                                                                                                                                                                                                                                                                                                           ",
"                                                                                                                                                                                                                                                                                                           ",

};


/*   if (TileMap[i][j] == 'P')  tile.setTextureRect(IntRect(240, 720, 16, 32));// низ
                if (TileMap[i][j] == 'k')  tile.setTextureRect(IntRect(176, 672, 16*2, 16*2));//л≥ва ст≥на
                if (TileMap[i][j] == 'r')  tile.setTextureRect(IntRect(512, 672, 16*2, 16*2));//права ст≥на
                if (TileMap[i][j] == 't')  tile.setTextureRect(IntRect(160, 448, 64, 64));//л≥вий верхн≥й кут
                if (TileMap[i][j] == 'o')  tile.setTextureRect(IntRect(240, 448, 32, 32));//потолок
                if (TileMap[i][j] == 'q')  tile.setTextureRect(IntRect(160, 720, 32, 32));//нижн≥й л≥вий кут
                if (TileMap[i][j] == 'w')  tile.setTextureRect(IntRect(480, 448, 64, 64));//верхн≥й правий кут
                if (TileMap[i][j] == 'e')  tile.setTextureRect(IntRect(512, 720, 32, 32));//нижн≥й правий кут
                if (TileMap[i][j] == 's')  tile.setTextureRect(IntRect(480, 720, 16, 16));//зовн≥шн≥й верхн≥й кут
                if (TileMap[i][j] == 'd')  tile.setTextureRect(IntRect(176, 544, 16, 16));//зовн≥шн≥й нижн≥й кут
                if (TileMap[i][j] == ' ') continue; //tile.setTextureRect(IntRect(1326, 864, 16, 16)); 
                if (TileMap[i][j] == 'f')  tile.setTextureRect(IntRect(160, 672, 16 , 16 ));
                if (TileMap[i][j] == 'g')  tile.setTextureRect(IntRect(240, 448, 16, 16));
                if (TileMap[i][j] == 'h')  tile.setTextureRect(IntRect(48, 544, 16, 16));//затемненн€ 

                if (TileMap[i][j] == 'l')  tile.setTextureRect(IntRect(208, 672, 16, 16));//платформа
                if (TileMap[i][j] == '0') continue;

                if (TileMap[i][j] == 'z')  tile.setTextureRect(IntRect(2440, 365, 32, 32));// шипи
                if (TileMap[i][j] == 'c')  tile.setTextureRect(IntRect(2247, 409, 49, 64)); //полиц€ з книгами широка
                if (TileMap[i][j] == 'v')  tile.setTextureRect(IntRect(2247, 313, 49, 64));//полиц€ з книгами
                if (TileMap[i][j] == 'b')  tile.setTextureRect(IntRect(2296, 313, 49, 64));//пуста полиц€
                if (TileMap[i][j] == 'n')  tile.setTextureRect(IntRect(2247, 233, 49, 64));//полиц€ з баночками
                if (TileMap[i][j] == 'm')  tile.setTextureRect(IntRect(2326, 408, 40, 64));//збро€
                if (TileMap[i][j] == 'Q')  tile.setTextureRect(IntRect(2361, 264, 32, 64));//щит
                if (TileMap[i][j] == 'W')  tile.setTextureRect(IntRect(2536, 474, 115, 84));//червона велика павутина
                if (TileMap[i][j] == 'T')  tile.setTextureRect(IntRect(2361, 472, 32, 64));//списи*/

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
        rect = FloatRect(100,2200, 16, 16);

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
                if ((TileMap[i][j] == 'P') || (TileMap[i][j] == 'k') || (TileMap[i][j] == '0') || (TileMap[i][j] == 'r')|| (TileMap[i][j] == 't') || (TileMap[i][j] == 'o') || (TileMap[i][j] == 'q')||(TileMap[i][j] == 'w') || (TileMap[i][j] == 'e') || (TileMap[i][j] == 's') || (TileMap[i][j] == 'd') || (TileMap[i][j] == 'f') || (TileMap[i][j] == 'g') || (TileMap[i][j] == 'h') || (TileMap[i][j] == 'l') )
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

    RenderWindow window(VideoMode(300, 400), "test!", Style::Fullscreen);
    std::cout << sf::VideoMode(1920, 1080).isValid() << "   " << sf::VideoMode().getDesktopMode().width;

    sf::Texture fon;
    fon.loadFromFile("3.png");
    sf::Sprite fonSp(fon);
    fonSp.setScale(sf::Vector2f(sf::VideoMode().getDesktopMode().width / fonSp.getGlobalBounds().width, sf::VideoMode().getDesktopMode().height / fonSp.getGlobalBounds().height));

    Texture tileSet;
    tileSet.loadFromFile("0000.png");

    Texture player1;

    PLAYER player(player1);

    Sprite tile(tileSet);
   



    Clock clock;

    while (window.isOpen())
    {

       offsetX = player.rect.left - sf::VideoMode().getDesktopMode().width /4;
       offsetY = player.rect.top - sf::VideoMode().getDesktopMode().height/2 ;

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time = time / 10;

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





       //if (player.rect.left > -300) offsetX = player.rect.left -300; // нестирати!!
        //if (player.rect.left > 100) offsetX = player.rect.left +200;
    



        window.clear(Color(Color::Black));


        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
            {
                if (TileMap[i][j] == 'P')  tile.setTextureRect(IntRect(240, 720, 16, 16));// низ
                if (TileMap[i][j] == 'k')  tile.setTextureRect(IntRect(176, 672, 16*2, 16*2));//л≥ва ст≥на
                if (TileMap[i][j] == 'r')  tile.setTextureRect(IntRect(512, 672, 16, 16));//права ст≥на
                if (TileMap[i][j] == 't')  tile.setTextureRect(IntRect(160, 448, 64, 64));//л≥вий верхн≥й кут
                if (TileMap[i][j] == 'o')  tile.setTextureRect(IntRect(240, 464, 32, 16));//потолок
                if (TileMap[i][j] == 'q')  tile.setTextureRect(IntRect(176, 720, 16, 16));//нижн≥й л≥вий кут
                if (TileMap[i][j] == 'w')  tile.setTextureRect(IntRect(480, 448, 64, 64));//верхн≥й правий кут
                if (TileMap[i][j] == 'e')  tile.setTextureRect(IntRect(512, 720, 16, 16));//нижн≥й правий кут
                if (TileMap[i][j] == 's')  tile.setTextureRect(IntRect(480, 720, 16, 16));//зовн≥шн≥й верхн≥й кут
                if (TileMap[i][j] == 'd')  tile.setTextureRect(IntRect(176, 544, 16, 16));//зовн≥шн≥й нижн≥й кут
                if (TileMap[i][j] == ' ') continue; //tile.setTextureRect(IntRect(1326, 864, 16, 16)); 
                if (TileMap[i][j] == 'f')  tile.setTextureRect(IntRect(512, 544, 32 , 32 ));
                if (TileMap[i][j] == 'g')  tile.setTextureRect(IntRect(512, 528, 16, 16));
                if (TileMap[i][j] == 'F')  tile.setTextureRect(IntRect(176, 544, 32, 32));
                if (TileMap[i][j] == 'G')  tile.setTextureRect(IntRect(176, 528, 16, 16));



                if (TileMap[i][j] == 'J')  tile.setTextureRect(IntRect(208, 720, 32, 32));
                if (TileMap[i][j] == 'I')  tile.setTextureRect(IntRect(480, 720, 32, 32));



                if (TileMap[i][j] == 'h')  tile.setTextureRect(IntRect(48, 544, 16, 16));//затемненн€ 
                if (TileMap[i][j] == 'l')  tile.setTextureRect(IntRect(208, 672, 16, 16));//платформа
                if (TileMap[i][j] == '0') continue;

                if (TileMap[i][j] == 'z')  tile.setTextureRect(IntRect(2440, 365, 32, 32));// шипи
                if (TileMap[i][j] == 'c')  tile.setTextureRect(IntRect(2247, 409, 49, 64)); //полиц€ з книгами широка
                if (TileMap[i][j] == 'v')  tile.setTextureRect(IntRect(2247, 313, 49, 64));//полиц€ з книгами
                if (TileMap[i][j] == 'b')  tile.setTextureRect(IntRect(2296, 313, 49, 64));//пуста полиц€
                if (TileMap[i][j] == 'n')  tile.setTextureRect(IntRect(2247, 233, 49, 64));//полиц€ з баночками
                if (TileMap[i][j] == 'm')  tile.setTextureRect(IntRect(2326, 408, 40, 64));//збро€
                if (TileMap[i][j] == 'Q')  tile.setTextureRect(IntRect(2361, 264, 32, 64));//щит
                if (TileMap[i][j] == 'W')  tile.setTextureRect(IntRect(2536, 474, 115, 84));//червона велика павутина
                if (TileMap[i][j] == 'T')  tile.setTextureRect(IntRect(2361, 472, 32, 64));//списи



                tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
                window.draw(tile);

               
            }
       

        window.draw(player.sprite);


        window.display();
    }

    return 0;
}