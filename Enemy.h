//
// Created by bruno on 31/07/2022.
//

#ifndef PROGETTOASTAR_ENEMY_H
#define PROGETTOASTAR_ENEMY_H
#include "Character.h"
#include "Dungeon.h"
#include "Astar_algorithm/findpath.h"

class Enemy: public  Character{
public:
    Enemy(std::string sourceCharacter);
    void moveUp() override;

    void moveDown() override;

    void moveRight() override;

    void moveLeft() override;

    bool nextFrame() override;
    bool moveEnemy(Dungeon *d, const sf::Vector2i heroPosition);

private:
    sf::Vector2f  framePosition;
};


#endif //PROGETTOASTAR_ENEMY_H
