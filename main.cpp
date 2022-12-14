#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include<SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "TileMap.h"
#include "Dungeon.h"
#include <Windows.h>

#include "hero.h"
#include "Enemy.h"


using namespace std;


int main() {


    bool closed = false;
    sf::RenderWindow window(sf::VideoMode(32 * 31, 18 * 31), "Tilemap");
    while (window.isOpen()) {
        Dungeon dungeon;

        Hero h;

        bool gameOn = false;
        Enemy e;

        TileMap map;



        //dungeon.createDungeon(32, 18, 50);
        dungeon.createDungeon(R"(.\Test\map.txt)", 32, 18);


        if (!map.load("./Sprites/tilemap.png", sf::Vector2u(62, 62), &dungeon,
                      32, 18))
            return -1;

        gameOn = true;

        // run the main loop
        sf::Clock timeFrame;
        sf::Clock timeMove;
        bool endGame = true;
        bool drawMove = false;


        while (gameOn) {
            // handle events
            sf::Event event;
            while (window.pollEvent(event)) {
                // check the type of the event...
                switch (event.type) {
                    // window closed
                    case sf::Event::Closed:
                        closed = true;
                        break;
                    case sf::Event::KeyPressed:
                        if (timeMove.getElapsedTime().asMilliseconds() > 250) {

                            if (h.move(&dungeon, h.getPos(), event)) {
                                e.getPos();
                                endGame = e.move(&dungeon, h.getPos(), event);
                                drawMove = true;
                                timeMove.restart();
                            }
                        }
                        break;


                }
            }

            if (closed)
                break;
            window.clear();
            window.draw(map);
            window.draw(h);
            window.draw(e);
            // draw the map
            if (timeFrame.getElapsedTime().asMilliseconds() > 50 && drawMove) {
                drawMove = h.nextFrame();
                e.nextFrame();
                timeFrame.restart();
            }
            if (!endGame && timeMove.getElapsedTime().asMilliseconds() > 150) {
                gameOn = false;
                endGame = true;
            }

            window.display();

        }
        if (closed)
            window.close();

    }

}
