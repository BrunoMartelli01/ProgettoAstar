//
// Created by bruno on 29/07/2022.
//


#ifndef PROGETTOASTAR_HERO_H
#define PROGETTOASTAR_HERO_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Character.h"
#include <SFML/Window/Event.hpp>
#include "Dungeon.h"

class Hero : public Character {
public:
    Hero(int tileWidth = 31, int tileHeight = 31);

    virtual ~Hero() {};

    bool moveHero(const Dungeon *d, const sf::Event event);


private:


};


#endif //PROGETTOASTAR_HERO_H
