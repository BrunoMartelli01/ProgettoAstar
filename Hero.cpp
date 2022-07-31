//
// Created by bruno on 29/07/2022.
//

#include <iostream>
#include "Hero.h"

Hero::Hero(std::string sourceCharacter ): Character(1, 1,sourceCharacter) {
    spriteCharacter.setTexture(textureCharacter);
    spriteCharacter.scale(0.61, 0.61);

    spriteCharacter.setPosition(32 , 32  );
   // spriteCharacter.setOrigin(27.0f, 27.0f);

    textureRect = sf::IntRect(0,0, 52,52);
    spriteCharacter.setTextureRect( textureRect);
    frame = 0;

}

void Hero::moveUp() {




    sf::Vector2i position(0,-1);
    framePosition.x = 0;
    framePosition.y = -7.35f;
    Character::setPosition(Character::getPosition()+position);
    textureRect=sf::IntRect(0,198, 52,52);
    return;

}

void Hero::moveDown() {


    sf::Vector2i position(0,1);
    framePosition.x = 0;
    framePosition.y = 7.35f;
    Character::setPosition(Character::getPosition()+position);
      textureRect=sf::IntRect(0,0, 52,52);
    return ;

}

void Hero::moveRight() {

    framePosition.y = 0;
    framePosition.x = 7.35f;
    sf::Vector2i position(1,0);
    Character::setPosition(Character::getPosition()+position);
    textureRect=sf::IntRect(0,132, 52,52);

    return;
}

void Hero::moveLeft() {
    framePosition.y = 0;
    framePosition.x = -7.35f;

    sf::Vector2i position(-1,0);
    Character::setPosition(Character::getPosition()+position);
    textureRect = sf::IntRect(0,66, 52,52);

    return ;
}


 bool Hero::nextFrame() {
        if (frame == 4){
            frame =0;
            textureRect.left= frame*64;
            spriteCharacter.setPosition(Character::getPosition().x*31,Character::getPosition().y*31);
            spriteCharacter.setTextureRect(textureRect);
            return  false ;
        }

     spriteCharacter.move(framePosition);
    textureRect.left= frame*64;
    spriteCharacter.setTextureRect(textureRect);
     frame++;

     return true;


}



