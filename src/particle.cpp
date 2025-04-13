#include "particle.h"

Particle::Particle(sf::Vector2f position, float radius, sf::Color color)
{
    this->position = position;
    this->velocity = sf::Vector2f(0, 0);
    this->acceleration = sf::Vector2f(0, 0);
    this->radius = radius;
    this->mass = radius * radius * M_PI;
    this->charge = 0;

    this->circle = sf::CircleShape(radius);
    this->circle.setOrigin(radius, radius);
    this->circle.setFillColor(color);
    this->circle.setPosition(position);
}

void Particle::checkCollitionWithWindows()
{
    float x_r = this->position.x + this->radius;
    float x_l = this->position.x - this->radius;
    float y_t = this->position.y + this->radius;
    float y_b = this->position.y - this->radius;

    if (this->velocity.x == 0 && this->acceleration.y == 0)
        return;

    if (x_r >= WINDOW_WIDTH)
    {
        this->position.x = WINDOW_WIDTH - this->radius;
        this->velocity.x *= -1;
        if (this->friction)
            this->velocity.x *= FRICTION;
    }
    else if (x_l <= 0)
    {
        this->position.x = this->radius;
        this->velocity.x *= -1;
        if (this->friction)
            this->velocity.x *= FRICTION;
    }

    if (y_t >= WINDOW_HEIGHT)
    {
        this->position.y = WINDOW_HEIGHT - this->radius;
        this->velocity.y *= -1;
        if (this->friction)
            this->velocity.y *= FRICTION;
        if (this->friction)
            this->velocity.x *= FRICTION;
    }
    else if (y_b <= 0)
    {
        this->position.y = this->radius;
        this->velocity.y *= -1;
        if (this->friction)
            this->velocity.y *= FRICTION;
    }
}

void Particle::checkCollitionWithParticle(Particle &p)
{
    float distance = magnitude(p.position - this->position);
    float minDistance = this->radius + p.radius;

    if (distance >= minDistance || distance == 0.0f)
        return;

    sf::Vector2f normal = (p.position - this->position) / distance;

    float v1_n = dot(this->velocity, normal);
    float v2_n = dot(p.velocity, normal);

    float v1_f = ((this->mass - p.mass) * v1_n + 2.0f * p.mass * v2_n) / (this->mass + p.mass);
    float v2_f = ((p.mass - this->mass) * v2_n + 2.0f * this->mass * v1_n) / (this->mass + p.mass);

    this->velocity += (v1_f - v1_n) * normal;
    p.velocity += (v2_f - v2_n) * normal;

    manageOverlap(p);
}

void Particle::manageOverlap(Particle &p)
{
    sf::Vector2f delta = p.position - this->position;
    float distance = magnitude(delta);

    float minDistance = this->radius + p.radius;

    if (distance == 0.0f)
        return;

    float overlap = minDistance - distance;
    sf::Vector2f move = (overlap / distance) * delta;
    this->position -= move / 2.0f;
    p.position += move / 2.0f;
    this->circle.setPosition(this->position);
    p.circle.setPosition(p.position);
}
void Particle::update()
{
    this->velocity += this->acceleration;
    this->position += this->velocity;
    this->momentum = this->velocity * this->mass;
    this->checkCollitionWithWindows();
    this->circle.setPosition(this->position);
}

void Particle::interact(Particle &p)
{
    if (this->interaction != nullptr)
        this->interaction(*this, p);
}