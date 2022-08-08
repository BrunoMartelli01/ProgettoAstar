//
// Created by bruno on 31/07/2022.
//

#ifndef PROGETTOASTAR_ENEMY_H
#define PROGETTOASTAR_ENEMY_H
#include "Character.h"
#include "Dungeon.h"
#include "Astar_algorithm/findpath.h"

class Enemy : public Character {
public:
    Enemy(int tileWidth = 31, int tileHeight = 31);

    ~Enemy() {};

    bool moveEnemy(Dungeon *d, const sf::Vector2i heroPosition);

};


#endif //PROGETTOASTAR_ENEMY_H
