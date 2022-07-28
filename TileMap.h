//
// Created by bruno on 28/07/2022.
//

#ifndef PROGETTOASTAR_TILEMAP_H
#define PROGETTOASTAR_TILEMAP_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <string>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "WorldMap.h"

class TileMap : public sf::Drawable, public sf::Transformable {
public:

    bool load(const std::string &tileset, sf::Vector2u tileSize, const WorldMap *mapTiles, unsigned int width, unsigned int height);

private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};
#endif //PROGETTOASTAR_TILEMAP_H
