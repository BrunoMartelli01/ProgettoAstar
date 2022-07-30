//
// Created by bruno on 29/07/2022.
//

#ifndef PROGETTOASTAR_CHARACTER_H
#define PROGETTOASTAR_CHARACTER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Character : public sf::Drawable, public sf::Transformable{
public:
    Character(int posX, int posY, std::string spriteCharacter) : posX(posX), posY(posY) {
        this->textureCharacter.loadFromFile(spriteCharacter);

    }

    virtual ~Character(){};
    virtual void moveUp()=0;
    virtual void moveDown() =0;
    virtual void moveRight()=0;
    virtual void moveLeft()=0;
    virtual bool nextFrame()=0;


    sf::Vector2i getPosition()const{
        sf::Vector2i position( posX, posY);
        return  position;
    }
    bool setPosition(sf::Vector2i position){
        if(position.x>=0 && position.y>=0){
            this->posX = position.x;
            this->posY = position.y;
            return true;
            }
        return false;
    }

private:
    int posX;
    int posY;
protected:
    sf::Texture textureCharacter;
    sf::Sprite spriteCharacter;
    sf::IntRect textureRect;
    int frame;


};
#endif //PROGETTOASTAR_CHARACTER_H
