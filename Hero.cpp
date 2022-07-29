//
// Created by bruno on 29/07/2022.
//

#include <iostream>
#include "Hero.h"

Hero::Hero(std::string sourceCharacter ): Character(62, 62,sourceCharacter) {
    spriteCharacter.setTexture(textureCharacter);
    spriteCharacter.scale(0.18, 0.18);
    spriteCharacter.setPosition(62 + 16, 62 + 16 );
    spriteCharacter.setOrigin(85.0f, 85.0f);


    sf::IntRect rect(0,0, 170,170);
    textureRect = rect;

    spriteCharacter.setTextureRect(textureRect);
    frame = 0;

}

bool Hero::moveUp() {
    if(spriteCharacter.getScale().x<0)
        spriteCharacter.setRotation(-90);
    else
    spriteCharacter.setRotation(90);
        spriteCharacter.move(0, -31);
    return false;

}

bool Hero::moveDown() {
    if(spriteCharacter.getScale().x < 0)
       spriteCharacter.setRotation(90);
    else
        spriteCharacter.setRotation(-90);

    spriteCharacter.move(0, 31);
    return false;
}

bool Hero::moveRight() {
    spriteCharacter.setRotation(0);
    if(spriteCharacter.getScale().x>0) {
        spriteCharacter.scale(5.3125, 5.3125);
        spriteCharacter.scale(-0.18823529411, 0.18823529411);
    }
    spriteCharacter.move(31,0 );

    return false;
}

bool Hero::moveLeft() {
    spriteCharacter.move(-31, 0);
    spriteCharacter.setRotation(0);
    if(spriteCharacter.getScale().x< 0)
    spriteCharacter.scale(-1, 1);
    else
        spriteCharacter.scale(1, 1);

    return false;
}


void Hero::nextFrame() {


        if (frame == 3)
            frame =0;

    textureRect.left= frame*170;

    spriteCharacter.setTextureRect(textureRect);
        frame++;
}

void Hero::draw(sf::RenderTarget &target, sf::RenderStates states) const {


    // apply the tileset texture
    states.transform *= getTransform();
    // draw the vertex array
    target.draw(spriteCharacter, states);
}


