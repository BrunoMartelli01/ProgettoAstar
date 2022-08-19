//
// Created by bruno on 29/07/2022.
//

#include <iostream>

#include "Hero.h"
#include "Dungeon.h"

Hero::Hero(int tileWidth, int tileHeight) : Character(1, 1,
                                                      R"(C:\Users\bruno\CLionProjects\ProgettoAstar\Sprites\hero.png)",
                                                      0.61, 0.61, 52, 52, 66, 64,
                                                      tileWidth, tileHeight, 31, 31) {
}


bool Hero::move(Dungeon *d, const sf::Vector2i position, const sf::Event event) {
    switch (event.key.code) {
        case (sf::Keyboard::Right):

            if (d->isLegalMove(1, 0, this->getPosition())) {
                this->moveRight();
                return true;
            }
            break;
        case (sf::Keyboard::Left):
            if (d->isLegalMove(-1, 0, this->getPosition())) {
                this->moveLeft();
                return true;
            }
            break;

        case (sf::Keyboard::Up):
            if (d->isLegalMove(0, -1, this->getPosition())) {
                this->moveUp();
                return true;
            }
            break;
        case (sf::Keyboard::Down):
            if (d->isLegalMove(0, 1, this->getPosition())) {
                this->moveDown();
                return true;
            }
            break;
        default:
            break;
    }
    return false;

}



