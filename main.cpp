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

bool isLegalCell(sf::Vector2i position, const Dungeon &map) {
    switch (map.getTile(position.x, position.y)) {
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

    sf::Vector2i addPosition= sf::Vector2i ( x, y);
    addPosition += h.getPosition();
    return(isLegalCell(addPosition, map));
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
    while (window.isOpen()) {
    Dungeon dungeon;
    std::string sourceCharacterH = R"(C:\Users\bruno\CLionProjects\ProgettoAstar\sprites\hero.png)";
    Hero h(sourceCharacterH);
    std::string sourceCharacterE = R"(C:\Users\bruno\CLionProjects\ProgettoAstar\sprites\enemy.png)";
    bool gameOn=false;
    Enemy e(sourceCharacterE);

    TileMap map;
    while(!gameOn) {
        dungeon.createDungeon(32, 18, 50);

        if(e.moveEnemy(&dungeon, h.getPosition())&& isLegalCell(h.getPosition(),dungeon) && isLegalCell(e.getPosition(),dungeon)) {
            if (!map.load("C:/Users/bruno/CLionProjects/ProgettoAstar/sprites/tilemap.png", sf::Vector2u(62, 62), &dungeon,
                          32, 18))
                return -1;

             gameOn = true;
        }
    }
    // run the main loop
    sf::Clock timeFrame ;
    sf::Clock timeMove;
    bool endGame = true;
    bool drawMove = false;


            while(gameOn) {
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
                        if (timeMove.getElapsedTime().asMilliseconds() > 250) {

                            if (moveHero(&h, &dungeon, event)) {
                                endGame=e.moveEnemy(&dungeon, h.getPosition());
                                drawMove = true;
                                timeMove.restart();
                            }
                        }
                        break;


                }
            }


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
            if(!endGame && timeMove.getElapsedTime().asSeconds()>1) {
                gameOn = false;
                endGame = true;
            }

            window.display();

        }

    }

}
