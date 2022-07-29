#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>


#include<SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "TileMap.h"
#include "Dungeon.h"
#include <Windows.h>
#include "hero.h"

int main() {
    sf::RenderWindow window( sf::VideoMode(32*31, 18*31), "Tilemap");

        Dungeon dungeon;
        dungeon.createDungeon(32, 18, 50);
        TileMap map;
        if (!map.load("C:/Users/bruno/CLionProjects/ProgettoAstar/sprites/tilemap.png", sf::Vector2u(62, 62), &dungeon,32, 18))
            return -1;

    std::string  sourceCharacter =R"(C:\Users\bruno\CLionProjects\ProgettoAstar\sprites\mage.png)";
    Hero h(sourceCharacter);

    // run the main loop
    sf::Clock timeFrame ;
    sf::Clock timeMove;

    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(map );
        // draw the map


        // draw the map

        if(timeMove.getElapsedTime().asMilliseconds()>200) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                // left key is pressed: move our spriteCharacter
                h.moveRight();
                timeMove.restart();

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                // left key is pressed: move our spriteCharacter
                h.moveLeft();
                timeMove.restart();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                // left key is pressed: move our spriteCharacter
                h.moveUp();

                timeMove.restart();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                // left key is pressed: move our spriteCharacter
                h.moveDown();

                timeMove.restart();
            }
        }

        if(timeFrame.getElapsedTime().asMilliseconds() > 250) {

            h.nextFrame();
            window.draw(h);

            timeFrame.restart();
        }


        window.display();

    }

}
