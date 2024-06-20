#include "particle.h"

Particle::Particle(sf::Vector2f position, float radius, sf::Color color) {
    this->position = position;
    this->velocity = sf::Vector2f(0, 0);
    this->acceleration = sf::Vector2f(0, 0);
    this->radius = radius;
    this->mass = radius * radius * M_PI;

    this->circle = sf::CircleShape(radius);
    this->circle.setOrigin(radius, radius);
    this->circle.setFillColor(color);
    this->circle.setPosition(position);
}

void Particle::checkCollitionWithWindows() {
    float x = this->position.x + this->radius;
    float y = this->position.y + this->radius;

    if (this->velocity.x == 0 && this->acceleration.y == 0) return;

    if (x >= WINDOW_WIDTH) {
        this->position.x = WINDOW_WIDTH - this->radius;
        this->velocity.x *= -1;
        if(this->friction) this->velocity.x *= FRICTION;
    }
    else if (x <= 0) {
        this->position.x = this->radius;
        this->velocity.x *= -1;
        if(this->friction) this->velocity.x *= FRICTION;
    }

    if (y >= WINDOW_HEIGHT) {
        this->position.y = WINDOW_HEIGHT - this->radius;
        this->velocity.y *= -1;
        if(this->friction) this->velocity.y *= FRICTION;
        if(this->friction) this->velocity.x *= FRICTION;
    }
    else if (y <= 0) {
        this->position.y = this->radius;
        this->velocity.y *= -1;
        if(this->friction) this->velocity.y *= FRICTION;
    }
}

void Particle::checkCollitionWithParticle(Particle &p) {

    float distance = sqrt(pow(p.position.x - this->position.x, 2) + pow(p.position.y - this->position.y, 2));
    if (distance > this->radius + p.radius) return;

    sf::Vector2f normal = p.position - this->position;
    float mag = magnitude(normal);
    normal = normal / mag;

    float v1_n = dot(this->velocity, normal);
    float v2_n = dot(p.velocity, normal);

    float v1_f = ((this->mass - p.mass)*v1_n + 2.0f * p.mass* v2_n)/(this->mass + p.mass);
    float v2_f = ((p.mass - this->mass)*v2_n + 2.0f * this->mass * v1_n)/(this->mass + p.mass);

    // Update the velocities of both particles
    this->velocity += (v1_f - v1_n) * normal;
    p.velocity += (v2_f - v2_n) * normal;
}

void Particle::update() {
    this->velocity += this->acceleration;
    this->position += this->velocity;
    this->momentum = this->velocity * this->mass;
    this->checkCollitionWithWindows();
    this->circle.setPosition(this->position);
}

void Particle::set_friction(bool state) {
    this->friction = state;
}