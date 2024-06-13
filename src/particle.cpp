#include "particle.h"

Particle::Particle(sf::Vector2f position, float radius, sf::Color color) {
    this->position = position;
    this->velocity = sf::Vector2f(0, 0);
    this->acceleration = sf::Vector2f(0, 0);

    this->circle = sf::CircleShape(radius);
    this->circle.setFillColor(color);
    this->circle.setPosition(position);
    this->circle.setOrigin(radius, radius);
}

bool Particle::isCollidingWithWindow(int windowWidth, int windowHeight) {
    if (this->position.x - this->circle.getRadius() < 0 || this->position.x + this->circle.getRadius() > windowWidth)
        return true;
    if (this->position.y - this->circle.getRadius() < 0 || this->position.y + this->circle.getRadius() > windowHeight)
        return true;
    return false;
}

void Particle::update() {
    this->velocity += this->acceleration;
    this->position += this->velocity;

    if (this->isCollidingWithWindow(800, 600)) {
        this->velocity.x *= -1;
        this->velocity.y *= -1;
    }

    this->circle.setPosition(this->position);
}