#include "particle.h"
#include "constants.h"

Particle::Particle(sf::Vector2f position, float radius, sf::Color color) {
    this->position = position;
    this->velocity = sf::Vector2f(0, 0);
    this->acceleration = sf::Vector2f(0, 0);
    this->radius = radius;

    this->circle = sf::CircleShape(radius);
    this->circle.setFillColor(color);
    this->circle.setPosition(position);
}

void Particle::checkCollitionWithWindows(int windowWidth, int windowHeight) {
    float x = this->position.x + this->radius;
    float y = this->position.y + this->radius;

    if (this->velocity.x == 0 && this->acceleration.y == 0) return;

    if (x >= windowWidth) {
        this->position.x = windowWidth - this->radius;
        this->velocity.x *= -1*FRICTION;
    }
    else if (x <= 0) {
        this->position.x = this->radius;
        this->velocity.x *= -1*FRICTION;
    }

    if (y >= windowHeight) {
        this->position.y = windowHeight - this->radius;
        this->velocity.y *= -1*FRICTION;
        this->velocity.x *= FRICTION;
    }
    else if (y <= 0) {
        this->position.y = this->radius;
        this->velocity.y *= -1*FRICTION;
    }
}

void Particle::update() {
    this->velocity += this->acceleration * AIR_RESISTANCE;
    this->position += this->velocity;

    this->circle.setPosition(this->position);
}