//
// Created by bruno on 29/07/2022.
//

#include <iostream>
#include "Hero.h"

Hero::Hero(std::string sourceCharacter): Character(1, 1,sourceCharacter) {
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
    framePositon.x = 0;
    framePositon.y = -7.35f;
    Character::setPosition(Character::getPosition()+position);
    textureRect=sf::IntRect(0,198, 52,52);
    return;

}

void Hero::moveDown() {


    sf::Vector2i position(0,1);
    framePositon.x = 0;
    framePositon.y = 7.35f;
    Character::setPosition(Character::getPosition()+position);
      textureRect=sf::IntRect(0,0, 52,52);
    return ;

}

void Hero::moveRight() {

    framePositon.y = 0;
    framePositon.x = 7.35f;
    sf::Vector2i position(1,0);
    Character::setPosition(Character::getPosition()+position);
    textureRect=sf::IntRect(0,132, 52,52);

    return;
}

void Hero::moveLeft() {
    framePositon.y = 0;
    framePositon.x = -7.35f;

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

     spriteCharacter.move(framePositon);
    textureRect.left= frame*64;
    spriteCharacter.setTextureRect(textureRect);
     frame++;

     return true;
}

void Hero::draw(sf::RenderTarget &target, sf::RenderStates states) const {


    // apply the tileset texture
    states.transform *= getTransform();
    // draw the vertex array
    target.draw(spriteCharacter, states);
}


