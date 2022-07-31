//
// Created by bruno on 29/07/2022.
//

#ifndef PROGETTOASTAR_HERO_H
#define PROGETTOASTAR_HERO_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Character.h"
class Hero : public Character{
public:
     Hero(std::string sourceCharacter);

    virtual ~Hero(){};
    void moveUp() override;

    void moveDown() override;

    void moveRight() override;

    void moveLeft() override;

    bool nextFrame() override;



private:
    sf::Vector2f framePosition;
    bool up = false;

};


#endif //PROGETTOASTAR_HERO_H
