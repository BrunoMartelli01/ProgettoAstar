//
// Created by bruno on 29/07/2022.
//

#include <iostream>
#include "Hero.h"

Hero::Hero(int tileWidth, int tileHeight) : Character(1, 1,
                                                      R"(C:\Users\bruno\CLionProjects\ProgettoAstar\Sprites\hero.png)",
                                                      0.61, 0.61, 52, 52, 66, 64,
                                                      tileWidth, tileHeight, 31, 31) {
    this->spriteCharacter.setPosition(tileWidth, tileHeight);

}




