//
// Created by bruno on 09/08/2022.
//
#include "Character.h"

sf::Vector2i Character::getPosition() const {
    sf::Vector2i position(posX, posY);
    return position;
}

bool Character::setPosition(sf::Vector2i position) {
    if (position.x >= 0 && position.y >= 0) {
        this->posX = position.x;
        this->posY = position.y;
        return true;
    }
    return false;
}

void Character::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    // draw the vertex array
    target.draw(spriteCharacter, states);
}


void Character::moveUp() {

    sf::Vector2i position(0, -1);
    framePosition.x = 0;
    framePosition.y = -7.35f;
    Character::setPosition(Character::getPosition() + position);
    textureRect = sf::IntRect(0, 3 * offsetTop, rectWidth, rectHeight);
    return;

}

void Character::moveDown() {


    sf::Vector2i position(0, 1);
    framePosition.x = 0;
    framePosition.y = 7.35f;
    Character::setPosition(Character::getPosition() + position);
    textureRect = sf::IntRect(0, 0, rectWidth, rectHeight);
    return;

}

void Character::moveRight() {

    framePosition.y = 0;
    framePosition.x = 7.35f;
    sf::Vector2i position(1, 0);
    Character::setPosition(Character::getPosition() + position);
    textureRect = sf::IntRect(0, 2 * offsetTop, rectWidth, rectHeight);

    return;
}

void Character::moveLeft() {
    framePosition.y = 0;
    framePosition.x = -7.35f;

    sf::Vector2i position(-1, 0);
    Character::setPosition(Character::getPosition() + position);
    textureRect = sf::IntRect(0, offsetTop, rectWidth, rectHeight);

    return;
}


bool Character::nextFrame() {
    if (frame == 4) {
        frame = 0;
        textureRect.left = frame * offsetLeft;
        spriteCharacter.setPosition(Character::getPosition().x * tileWidth, Character::getPosition().y * tileHeight);
        spriteCharacter.setTextureRect(textureRect);
        return false;
    }

    spriteCharacter.move(framePosition);
    textureRect.left = frame * offsetLeft;
    spriteCharacter.setTextureRect(textureRect);
    frame++;

    return true;


}