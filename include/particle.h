#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <math.h>

#include "constants.h"
#include "vector_op.h"

#include <iostream>

class Particle
{
public:
    Particle(sf::Vector2f position, float radius, sf::Color color);

    sf::CircleShape circle;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f momentum;

    void (*interaction)(Particle &p1, Particle &p2) = nullptr;

    float radius;
    float mass;
    float charge;

    bool friction = false;

    void update();
    void checkCollitionWithWindows();
    void checkCollitionWithParticle(Particle &p);
    void manageOverlap(Particle &p);
    void interact(Particle &p);
};

#endif