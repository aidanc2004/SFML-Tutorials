#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles,
              unsigned int width, unsigned int height) {
        // load tileset texture
        if (!m_tileset.loadFromFile(tileset))
            return false;
        
        // resize vertex array to fit level size
        m_verticies.setPrimitiveType(sf::Quads);
        m_verticies.resize(width * height * 4);

        // populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < width; i++) {
            for (unsigned int j = 0; j < height; j++) {
                // get current tile number
                int tileNumber = tiles[i + j * width];

                // find its position in tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / m_tileset.getSize().y);
                int tv = tileNumber / (m_tileset.getSize().x / m_tileset.getSize().y);

                // get a pointer to current tile's quad
                sf::Vertex *quad = &m_verticies[(i + j * width) * 4];

                // define 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // define 4 texture coords
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }
        }

        return true;
    }
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        // apply transformation
        states.transform *= getTransform();

        // apply tileset texture
        states.texture = &m_tileset;

        // draw vertex array
        target.draw(m_verticies, states);
    }

    sf::VertexArray m_verticies;
    sf::Texture m_tileset;
};