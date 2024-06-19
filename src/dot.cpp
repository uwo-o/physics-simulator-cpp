#include "dot.h"

Dot::Dot(sf::Vector2f position) {
    this->position = position;

    this->circle = sf::CircleShape(RADIUS);
    this->circle.setOrigin(RADIUS, RADIUS);
    this->circle.setFillColor(sf::Color::White);
    this->circle.setPosition(position);
}