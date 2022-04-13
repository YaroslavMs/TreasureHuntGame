/*#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


float offsetX = 0, offsetY = 0;


const int H = 142;  //375
const int W = 300; //132


String TileMap[H] = {
"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000                                                                                                                                                                      ",
"t000bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb                                                                                                                                                                      0w00",
"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0000                                                                                                                                                                                                                                                                                                    000",
"000                                                                                                                                                                                                                                                                                                      00",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                                                                                                                                                                                                         d",
"c                                                                                                                    kbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbg                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                                                      hhhhhhhhhhhhhhhhhhhhd                                                                         d",
"c                                                                                                                    c                                                                   nnnnn                                  d                                                                         d",
"c                                                                                                                    c                                                                 hhhhhhhhhhhhhhhhh                        d                                                                         d",
"c                                                                                                                    c                                                nnnnnn                                                    d                                                                         d",
"c                                                                                                                    c                                          hhhhhhhhhhhhhhhhhh                                              d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                          hhhhhhhhhhhh                                                                    d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c             hhhhhhhhh                                                                                    d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                    nnnn                                                                  d                                                                         d",
"c                                                                                                                    c                          hhhhhhhhhhhhhhhhhhh                                                             d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                hhhhhhhhhh                        hhhhhhhhhhhh            d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                                   nnn                                    d                                                                         d",
"c                                                                                                                    c                                                               hhhhhhhhhhhhhhhh                           d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                nnnn                                                      d                                                                         d",
"c                                                                                                                    c                                            hhhhhhhhhhhhhh                                                d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                  hhhhhhhhh                                                               d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    c                                                                                                          d                                                                         d",
"c                                                                                                                    maaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaai         jaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaae                                                                         d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        chhh      d                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        c      hhhd                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        chhh      d                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        c       hhd                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        chh       d                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        c         d                                                                                                                      d",
"c                                                                                                                                                                        c     hhhhd                                                                                                                      d",
"c                                                                                                                                                                        c         fbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbg                        d",
"c                                                                                                                                                                        cAAH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH AH  AH H  K H AH AH  d                        d",
"c                                                                                                                                                                        chhh                                                                                                    d                        d",
"c                                                                                                                                                                        c                                                                                            F          d                        d",
"c                                                                                                                                                                        c                                                                                                       d                        d",
"c                                                                                                                                                                        c                                                                             M A  A         K          d                        d",
"c                                                                                                                                                                        maaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaai        jaaaaaaaaaaaaaaaaae                        d",
"c                                                                                                                                                                                                                                                     c  A  Ahhd                                          d",
"c                                                                                                                                                                                                                                                     c        d                                          d",
"c                        kbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbg                                                                                                                                                                        c        d                                          d",
"c                        cM        AM        AM        AM        AM AM       d                                                                                                                                                                        c        d                                          d",
"c                        c                                                   d                                                                                                                                                                        chh      d                                          d",
"c                        c         A         A         A         AM AM       d                                                                                                                                                                        cM A  A  d                                          d",
"c                        c    G         G         G        G     A           d                                                                                                                                                                        c        d                                          d",
"c                        c                                                   d                                                                                                                                                                        c  A  Ahhd                                          d",
"c                        c                                                   d                                                                                                                                                                        c        d                                          d",
"c                        c                                                   d                                                                                                                                                                        c        d                                          d",
"c                        maaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaiM  AM       d                                                                                                                                                                        c        d                                          d",
"c                                                               cF           d                                                                                                                                                                        chh      d                                          d",
"c                                                               c            d                                                                                                                                                                        cM A  A  d                                          d",
"c                                                               chhhhhh      d                                                                                                                                                                        c      hhd                                          d",
"c                                                               c            d                                                                                                                                                                        c        d                                          d",
"c                                                               c            d                                                                                                                                                                        c        d                                          d",
"c                                                               cM  AM       d                                                                                                                                                                        c        d                                          d",
"c                                                               c       hhhhhd                                                                                                                                                                        chhA  A  d                                          d",
"c                                                               c            d                                                                                                                                                                        c        d                                          d",
"c                                                               c            d                                                                                                                                                                        cM A  A  d                                          d",
"c                                                               c            d                              kbbbbbbbbbbbbbbbbbbbbbbbbbbbbg                                                                                                            c      hhd                                          d",
"c                                                               chhhhh       d                              cAM  A   A AE      AE        d                                                                   kbbbbbbbbbbg                             c        d                                          d",
"c                                                               cM  AM       d                              c                            d                                                                   cF K F K F d                             c  A  A  d                                          d",
"c                                                               c            d                              c                            d                                                                   c          d                             c        d                                          d",
"c                                                               c            d                              c                            d                                                                   cVH VH  VH fbbbbbbbbbbbbbbbbbbbbbbbbbbbbblhh      d                                          d",
"c                                                               c       hhhhhd                              cA                           d                                                                   cVH VH  VH  VH  VH  VN  VHW VH  VH  VH  VV        d                                          d",
"c                                                               c            d                              c M  A   Ajaaaaaaaaaaaaaaaaaae                                                                   c                                         M A  A  d                                          d",
"c                                                               c            d                              c         d                                                                                      c                             Q                   d                                          d",
"c                                                               cM  AM       d                              c         d                                                                                      c                                           A  Ahhd                                          d",
"c                                                               chhh         fbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbl      hhhfbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbg                                 maaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaai        d                                          d",
"c                                                               c            VH  VH  VH  VH  VN  VH  VH  VH  VH  VH  VH  VH  VH  VN  VH  VH  VH  VH  VN  VH  VH  VH  VH  F d                                                                          c   Q    d                                          d",
"c                                                               c       h                                       hh                                                         d                                                                          c        d                                          d",
"c                                                               c                                                                                                        K d                                                                          chh      d                                          d",
"c                                                               c                                                                                                          d                                                                          cM A  Ahhd                                          d",
"c                                                               c   A   hhhhhjaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaiM  AM  A   K d                                                                          c        d                                          d",
"c                                                               cM  AM       d                                                                               c       A     fbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbg                            c        d                                          d",
"c                                                               c            d                                                                               c        M  F     AM        AM       AM        AM        AK d                            c        d                                          d",
"c                                                               c            d                                                                               cE  A   A         A         A        A         A            fbbbbbbbbbbbbbbbbbbbbbbbbbbbblhh      d                                          d",
"c                                                               chhhhh       d                                                                               c           F                                             F VH  VH  VH  VH  VH  VH  VH  VH  VH Vhhd                                          d",
"c                                                               c            d                                                                               c                                                                                                 d                                          d",
"c                                                               c            d                                                                               c           F                                             K                                     F d                                          d",
"c                                                               c   A        d                                                                               c                                                                                                 d                                          d",
"c                                                               cM  AM   hhhhd                                                                               maaaaaaaaaaaaaaaaaaaaaiVH  VjaaiVH  jaaiVH  VjaaaiVH  jaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaae                                          d",
"c                                                               c            d                                                                                                     c     d  c    d  c     d   c    d                                                                                      d",
"c                                                               c            d                                                                                                     c     d  c    d  c     d   c    d                                                                                      d",
"c                                                               c            d                                                                                                     c     d  c    d  c     d   c    d                                                                                      d",
"c                                                               chhhhh       d                                                                                                     cnnnnnd  cnnnnd  cnnnnnd   cnnnnd                                                                                      d",
"cbbbbbbbbbbbbbbbbbbbbbbbg        kbbbbbbbbbbbbbbbbbbbbbbbbbbbbbblD    D      d                                                                                                     maaaaae  maaaae  maaaaae   maaaae                                                                                      d",
"c          A W      AS  d        c          AM N      AAF AA       AM        d                                                                                                                                                                                                                            d",
"c                       d        c                                           d                                                                                                                                                                                                                            d",
"c     B        Z        d        c                     K                 hhhhd                                                                                                                                                                                                                            d",
"c                    S  fbbbbbbbbl        v     C                Q      T    d                                                                                                                                                                                                                            d",
"c                       F K F K F                      K                     d                                                                                                                                                                                                                            d",
"c                                                                            d                                                                                                                                                                                                                            d",
"maaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaae                                                                                                                                                                                                                            d",
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
/*
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
        rect = FloatRect(100, 2200, 16, 16);

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
                if (static_cast<int>(TileMap[i][j] >= 97 && TileMap[i][j] <= 110))
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
class ENEMY
{

public:
    float dx, dy;
    FloatRect rect;
    Sprite sprite;
    float currentFrame;
    bool life;


    void set(Texture& image, int x, int y)
    {
        sprite.setTexture(image);
        rect = FloatRect(x, y, 32, 16*2);

        dx = 0.05;
        currentFrame = 0;
        life = true;
    }

    void update(float time)
    {
        rect.left += dx * time;

        Collision();


        currentFrame += time * 0.005;
        if (currentFrame >= 4)
            currentFrame =0;

        if (dx > 0) sprite.setTextureRect(IntRect(11 +48* int(currentFrame), 18, 32, 32));
        if (dx < 0) sprite.setTextureRect(IntRect(11 + 48 * int(currentFrame)+32, 18, -32, 32));
     //   sprite.setPosition(j * 16 * sizeMultiplier - offsetX, i * 16 * sizeMultiplier - offsetY - 85);

        if (!life) sprite.setTextureRect(IntRect(10, 18, 16*2, 16*2));


        sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

    }


    void Collision()
    {

        for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
            for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
                if ((TileMap[i][j] == 'a') || (TileMap[i][j] == 'd') || (TileMap[i][j] == 'c'))
                {
                    if (dx > 0)
                    {
                        rect.left = j * 16 - rect.width; dx *= -1;
                    }
                    else if (dx < 0)
                    {
                        rect.left = j * 16 + 16;  dx *= -1;
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
    tileSet.loadFromFile("s.png");

    Texture player1;
    ENEMY  enemy;
    enemy.set(tileSet, 130, 2100);
    PLAYER player(player1);

    Sprite tile(tileSet);




    Clock clock;

    while (window.isOpen())
    {

        offsetX = player.rect.left - sf::VideoMode().getDesktopMode().width / 4;
        offsetY = player.rect.top - sf::VideoMode().getDesktopMode().height / 2;

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time = time / 1;

        if (time > 10) time = 10;

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
        enemy.update(time);
        if (player.rect.intersects(enemy.rect))
        {
            if (enemy.life) {
                if (player.dy > 0) { enemy.dx = 0; player.dy = -0.2; enemy.life = false; }
                else player.sprite.setColor(Color::Red);
            }
        }


        if (player.rect.left > 200) offsetX = player.rect.left - 200;           //смещение




        window.clear(Color(Color::Black));


        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
            {
                if (TileMap[i][j] == ' ') continue;
                else if (TileMap[i][j] == '0') continue;//tile.setTextureRect(IntRect(1326, 864, 16, 16)); 
                else if (TileMap[i][j] == 'a')  tile.setTextureRect(IntRect(240, 720, 16, 16));// низ
                else if (TileMap[i][j] == 'c')  tile.setTextureRect(IntRect(176, 672, 16 * 2, 16 * 2));//л≥ва ст≥на
                else if (TileMap[i][j] == 'd')  tile.setTextureRect(IntRect(512, 672, 16, 16));//права ст≥на
               // if (TileMap[i][j] == 't')  tile.setTextureRect(IntRect(160, 448, 64, 64));//л≥вий верхн≥й кут
                else if (TileMap[i][j] == 'b')  tile.setTextureRect(IntRect(240, 464, 32, 16));//потолок
                else if (TileMap[i][j] == 'm')  tile.setTextureRect(IntRect(176, 720, 16, 16));//нижн≥й л≥вий кут
                //if (TileMap[i][j] == 'w')  tile.setTextureRect(IntRect(480, 448, 64, 64));//верхн≥й правий кут
                else if (TileMap[i][j] == 'e')  tile.setTextureRect(IntRect(512, 720, 16, 16));//нижн≥й правий кут
               // if (TileMap[i][j] == 's')  tile.setTextureRect(IntRect(480, 720, 16, 16));//зовн≥шн≥й верхн≥й кут
              //  if (TileMap[i][j] == 'd')  tile.setTextureRect(IntRect(176, 544, 16, 16));//зовн≥шн≥й нижн≥й кут
                else if (TileMap[i][j] == 'f')  tile.setTextureRect(IntRect(512, 544, 32, 32));
                else if (TileMap[i][j] == 'g')  tile.setTextureRect(IntRect(512, 528, 16, 16));
                else if (TileMap[i][j] == 'l')  tile.setTextureRect(IntRect(176, 544, 32, 32));
                else if (TileMap[i][j] == 'k')  tile.setTextureRect(IntRect(176, 528, 16, 16));



                else if (TileMap[i][j] == 'j')  tile.setTextureRect(IntRect(208, 720, 32, 32));
                else if (TileMap[i][j] == 'i')  tile.setTextureRect(IntRect(480, 720, 32, 32));



                //  if (TileMap[i][j] == 'h')  tile.setTextureRect(IntRect(48, 544, 16, 16));//затемненн€ 
                else if (TileMap[i][j] == 'h')  tile.setTextureRect(IntRect(208, 672, 16, 16));//платформа


                else if (TileMap[i][j] == 'n')  tile.setTextureRect(IntRect(2440, 365, 32, 32));// шипи




                else if (TileMap[i][j] == 'Z')  tile.setTextureRect(IntRect(2247, 409, 49, 64)); //полиц€ з книгами широка
                else if (TileMap[i][j] == 'v')  tile.setTextureRect(IntRect(2247, 313, 49, 64));//полиц€ з книгами
                else if (TileMap[i][j] == 'X')  tile.setTextureRect(IntRect(2296, 313, 49, 64));//пуста полиц€
                else if (TileMap[i][j] == 'B')  tile.setTextureRect(IntRect(2247, 233, 49, 64));//полиц€ з баночками
                else if (TileMap[i][j] == 'C')  tile.setTextureRect(IntRect(2326, 408, 40, 64));//збро€
                else if (TileMap[i][j] == 'Q')  tile.setTextureRect(IntRect(2361, 264, 32, 64));//щит
                else if (TileMap[i][j] == 'W')  tile.setTextureRect(IntRect(2536, 474, 115, 84));//червона велика павутина
                else if (TileMap[i][j] == 'T')  tile.setTextureRect(IntRect(2361, 472, 32, 64));//списи

                else if (TileMap[i][j] == 'M')  tile.setTextureRect(IntRect(1152, 464, 144, 112));
                else if (TileMap[i][j] == 'N')  tile.setTextureRect(IntRect(1312, 592, 48, 80));
                else if (TileMap[i][j] == 'K')  tile.setTextureRect(IntRect(1424, 512, 32, 32));
                else if (TileMap[i][j] == 'A')  tile.setTextureRect(IntRect(1392, 544, 16, 96));
                else if (TileMap[i][j] == 'S')  tile.setTextureRect(IntRect(1312, 464, 52, 64));
                else if (TileMap[i][j] == 'F')  tile.setTextureRect(IntRect(1424, 656, 32, 32));
                else if (TileMap[i][j] == 'D')  tile.setTextureRect(IntRect(1152, 208, 112, 16));
                else if (TileMap[i][j] == 'G')  tile.setTextureRect(IntRect(1552, 535, 33, 42));
                else if (TileMap[i][j] == 'H')  tile.setTextureRect(IntRect(1152, 464, 48, 80));
                else if (TileMap[i][j] == 'V')  tile.setTextureRect(IntRect(1392, 544, 16, 64));
                else if (TileMap[i][j] == 'E')  tile.setTextureRect(IntRect(1152, 464, 144, 80));
                tile.setPosition(j * 16 - offsetX, i * 16 - offsetY);
                window.draw(tile);


            }


        window.draw(player.sprite);
        window.draw(enemy.sprite);

        window.display();
    }

    return 0;
}*/