//
// Created by bruno on 29/07/2022.
//

#ifndef PROGETTOASTAR_CHARACTER_H
#define PROGETTOASTAR_CHARACTER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include "Dungeon.h"

class Character : public sf::Drawable, public sf::Transformable {
public:

    Character(const int posX, const int posY, const std::string spriteCharacter, const float scaleX, const float scaleY,
              const int rectWidth, const int rectHeight, const int offsetTop, const int offsetLeft, const int tileWidth,
              const int tileHeight, const int startX, const
              int startY)
            : posX(posX), posY(posY), tileWidth(tileWidth), tileHeight(tileHeight), rectWidth(rectWidth),
              rectHeight(rectHeight), offsetTop(offsetTop), offsetLeft(offsetLeft) {

        this->textureCharacter.loadFromFile(spriteCharacter);
        this->spriteCharacter.setTexture(textureCharacter);
        this->spriteCharacter.scale(scaleX, scaleY);
        this->spriteCharacter.setPosition(startX, startY);
        // spriteCharacter.setOrigin(27.0f, 27.0f);
        textureRect = sf::IntRect(0, 0, rectWidth, rectHeight);
        this->spriteCharacter.setTextureRect(textureRect);
        frame = 0;
    }

    virtual ~Character() {};


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    virtual bool nextFrame();

    sf::Vector2i getPos() const;

    virtual bool move(Dungeon *d, const sf::Vector2i position, const sf::Event event) = 0;

    bool setPosition(sf::Vector2i position);


protected:

    virtual void moveUp();

    virtual void moveDown();

    virtual void moveRight();

    virtual void moveLeft();

private:
    int posX;
    int posY;
    sf::Vector2f framePosition;
    int rectWidth;
    int rectHeight;
    int tileWidth;
    int tileHeight;
    int offsetTop;
    int offsetLeft;

protected:
    sf::Texture textureCharacter;
    sf::Sprite spriteCharacter;
    sf::IntRect textureRect;
    int frame;


};

#endif //PROGETTOASTAR_CHARACTER_H
