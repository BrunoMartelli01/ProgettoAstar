#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>


#include<SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "TileMap.h"
#include "Dungeon.h"
#include <Windows.h>
#include "hero.h"

bool isLegalCell(int x, int y, const Dungeon &map) {
    switch (map.getTile(x, y)) {
        case TileType::Unused:
            return true;
        case TileType::DirtWall:
            return false;
        case TileType::DirtFloor:
            return true;
        case TileType::StoneWall:
            return false;
        case TileType::Corridor:
            return true;
        case TileType::Door:
            return true;
        case TileType::UpStairs:
            return true;
        case TileType::DownStairs:
            return true;
        case TileType::Chest:
            return true;
        default:
            return false;
    };
}
bool isLegalMove(int x, int y, const Dungeon &map, const Hero &h){
    int newX = h.getPosition().x+ x;
    int newY = h.getPosition().y +y;
    return(isLegalCell(newX,newY, map));
}
bool moveHero(Hero* h,const Dungeon* d, const sf::Event event ){
    switch(event.key.code) {
        case(sf::Keyboard::Right):

            if(isLegalMove(1,0, *d,*h)) {
                h->moveRight();
                return true;
            }
            break;
        case(sf::Keyboard::Left):
            if(isLegalMove(-1,0, *d,*h)) {
                h->moveLeft();
                return true;
            }
            break;

        case(sf::Keyboard::Up):
            if(isLegalMove(0,-1, *d,*h)) {
                h->moveUp();
                return true;
            }
            break;
        case(sf::Keyboard::Down):
            std::cout<<event.key.code<<std::endl;
            if(isLegalMove(0,1, *d,*h)) {
                h->moveDown();
                return true;
            }
            break;
        default: break;
    }
    return false;
}


int main() {
    sf::RenderWindow window( sf::VideoMode(32*31, 18*31), "Tilemap");
    bool dungeonOk = false;
    Dungeon dungeon;
    std::string sourceCharacter = R"(C:\Users\bruno\CLionProjects\ProgettoAstar\sprites\mage.png)";
    Hero h(sourceCharacter);
    TileMap map;
    while(!dungeonOk) {

        dungeon.createDungeon(32, 18, 50);

        if (!map.load("C:/Users/bruno/CLionProjects/ProgettoAstar/sprites/tilemap.png", sf::Vector2u(62, 62), &dungeon,
                      32, 18))
            return -1;
        if(dungeon.getCell(1,1) == 1)
            dungeonOk = true;


    }
    // run the main loop
    sf::Clock timeFrame ;
    sf::Clock timeMove;

    while (window.isOpen()) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            // check the type of the event...
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:

                        moveHero(&h,&dungeon,event);
                        break;



            }
        }


        window.clear();
        window.draw(map );
        window.draw(h);
        // draw the map


        // draw the map




        /*    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && dungeon.getCell(posX,posY) == 1 ){
                // left key is pressed: move our spriteCharacter
                h.moveRight();
                timeMove.restart();

            }else
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || dungeon.getCell(posX,posY) == 1) {
                // left key is pressed: move our spriteCharacter  ) {
                // left key is pressed: move our spriteCharacter
                h.moveLeft();
                timeMove.restart();
            }else
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                // left key is pressed: move our spriteCharacter
                h.moveUp();

                timeMove.restart();
            }else
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                // left key is pressed: move our spriteCharacter
                h.moveDown();


            }
        }*/

        if(timeFrame.getElapsedTime().asMilliseconds() > 250) {

            h.nextFrame();

            timeFrame.restart();
        }


        window.display();

    }

}
