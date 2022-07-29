//
// Created by bruno on 29/07/2022.
//

#ifndef PROGETTOASTAR_CHARACTER_H
#define PROGETTOASTAR_CHARACTER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Character : public sf::Drawable, public sf::Transformable{
public:
    Character(int posX, int posY, std::string spriteCharacter) : posX(posX), posY(posY) {
        this->textureCharacter.loadFromFile(spriteCharacter);

    }

    virtual ~Character(){};
    virtual bool moveUp()=0;
    virtual bool moveDown() =0;
    virtual bool moveRight()=0;
    virtual bool moveLeft()=0;
    virtual void nextFrame()=0;

    int getPosX() const {
        return posX;
    }


    int getPosY() const {
        return posY;
    }
    sf::Vector2<int> getPosition(){
        sf::Vector2<int> position( posX, posY);
        return  position;
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
