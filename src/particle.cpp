#include "particle.h"
#include <iostream>

Particle::Particle(sf::Vector2f position, float radius, sf::Color color) {
    this->position = position;
    this->velocity = sf::Vector2f(0, 0);
    this->acceleration = sf::Vector2f(0, 0);
    this->radius = radius;
    this->mass = radius * radius * M_PI;

    this->circle = sf::CircleShape(radius);
    this->circle.setFillColor(color);
    this->circle.setPosition(position);
}

void Particle::checkCollitionWithWindows() {
    float x = this->position.x + this->radius;
    float y = this->position.y + this->radius;

    if (this->velocity.x == 0 && this->acceleration.y == 0) return;

    if (x >= WINDOW_WIDTH) {
        this->position.x = WINDOW_WIDTH - this->radius;
        this->velocity.x *= -1*FRICTION;
    }
    else if (x <= 0) {
        this->position.x = this->radius;
        this->velocity.x *= -1*FRICTION;
    }

    if (y >= WINDOW_HEIGHT) {
        this->position.y = WINDOW_HEIGHT - this->radius;
        this->velocity.y *= -1*FRICTION;
        this->velocity.x *= FRICTION;
    }
    else if (y <= 0) {
        this->position.y = this->radius;
        this->velocity.y *= -1*FRICTION;
    }
}

void Particle::checkCollitionWithParticle(Particle &p) {
    float distance = sqrt(pow(this->position.x - p.position.x, 2) + pow(this->position.y - p.position.y, 2));
    if (distance > p.radius + this->radius) return;
    this->velocity.x *= -1;
    this->velocity.y *= -1;
    p.velocity.x *= -1;
    p.velocity.y *= -1;
}

void Particle::unOverlap(Particle &p) {
    sf::Vector2f direction = p.position - this->position;
    float distance = sqrt(pow(this->position.x - p.position.x, 2) + pow(this->position.y - p.position.y, 2));

    if (distance > this->radius + p.radius) return;

    std::cout << distance << std::endl;

    this->position.x = distance - this->radius;
    this->position.y = distance - this->radius;
}

void Particle::update() {
    this->position += this->velocity;
    this->checkCollitionWithWindows();
    this->circle.setPosition(this->position);
}