//
// Created by bruno on 29/07/2022.
//

#ifndef PROGETTOASTAR_CHARACTER_H
#define PROGETTOASTAR_CHARACTER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Character : public sf::Drawable, public sf::Transformable {
public:
    Character(const int posX, const int posY, const std::string spriteCharacter, float scaleX, float scaleY,
              int rectWidth, int rectHeight, int offsetTop, int offsetLeft, int tileWidth, int tileHeight, int startX,
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

    virtual void moveUp();

    virtual void moveDown();

    virtual void moveRight();

    virtual void moveLeft();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    virtual bool nextFrame();

    sf::Vector2i getPosition() const;

    bool setPosition(sf::Vector2i position);

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
