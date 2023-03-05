#include "collider.h"

/*
Shapes:

    * * * | * * *
    * X X | * X X  CORNER
    * X X | * X *

*/

Collider::Collider(sf::Sprite& sprite): mSprite(&sprite) {

    sf::Texture texture = *mSprite->getTexture();
    sf::Vector2u textureSize = texture.getSize();
    sf::Image image = texture.copyToImage();

    std::vector<std::vector<bool>> isFull(textureSize.x, std::vector<bool>(textureSize.y, false));
    this->points.setPrimitiveType(sf::PrimitiveType::Lines);

    for (unsigned int x = 0; x < textureSize.x; ++x) {
        for (unsigned int y = 0; y < textureSize.y; ++y) {
            if (image.getPixel(x, y).a == 0) continue;
            isFull[x][y] = true;
        }
    }

    for (unsigned int y = 0; y < textureSize.y; ++y) { // 72
        for (unsigned int x = 0; x < textureSize.x; ++x) { // 5
            bool current = isFull[x][y];

            // Sides
            bool left =    x > 0 ? isFull[x - 1][y] : false;
            bool right =   x < textureSize.x - 1 ? isFull[x + 1][y] : false;
            bool up =      y > 0 ? isFull[x][y - 1] : true;                 // Discard last line
            bool down =    y < textureSize.y - 1 ? isFull[x][y + 1] : true; // Discard last line

            // Corners
            bool uLeft =   x > 0 && y < 0 ? isFull[x - 1][y - 1] : false;
            bool uRight =  x < textureSize.x - 1 && y < 0 ? isFull[x + 1][y - 1] : false;
            bool dLeft =   y < textureSize.y - 1 && x > 0 ? isFull[x - 1][y + 1] : true;
            bool dRight =  y < textureSize.y - 1 && x < textureSize.x - 1 ? isFull[x + 1][y + 1] : true;

            // std::cout << uLeft << ", " << up << ", " << uRight << std::endl;     // Debug
            // std::cout << left << ", " << current << ", " << right << std::endl;  // Debug
            // std::cout << dLeft << ", " << down << ", " << dRight << std::endl;   // Debug

            if (current) {
                // Detect corners
                if ((!left && right && !up && down) || // Top left
                    (left && !right && !up && down) || // Top right
                    (!left && right && up && !down) || // Bottom left
                    (left && !right && up && !down))   // Bottom right
                {
                    this->points.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Blue));
                }
                // Detect edge
                else if ((left && right && !up && down) || // Top
                         (left && right && up && !down) || // Bottom
                         (!left && right && up && down) || // Left
                         (left && !right && up && down))   // Right
                {
                }
            }
        }
    }
}

sf::VertexArray& Collider::getList() {
    return this->points;
}

sf::Vector2f Collider::checkCollision(sf::Vector2f a, sf::Vector2f b, float scaleFactor) {
    for (int i = 0; i < this->points.getVertexCount(); i++) {
        if (i % 2 == 1) continue;

        sf::Vector2f positionA = this->points[i].position * scaleFactor;
        sf::Vector2f positionB = this->points[i + 1].position * scaleFactor;

        if (a.y == b.y) { // Horizontal line
            if ((a.x > positionA.x && a.x < positionB.x) || (b.x > positionA.x && b.x < positionB.x) ||
                (positionA.x > a.x && positionA.x < b.x) || (positionB.x > a.x && positionB.x < b.x)) // If inside X range

                if (positionA.y - threshold <= a.y && positionA.y + threshold <= a.y) return sf::Vector2f(0, positionA.y); // If touching line
        } else if (a.x == b.x) { // Vertical line
        }
    }

    return sf::Vector2f(-1, -1);
}
