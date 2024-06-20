#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <math.h>

#include "constants.h"
#include "vector_op.h"

#include <iostream>

class Particle{
public:
    Particle(sf::Vector2f position, float radius, sf::Color color);

    sf::CircleShape circle;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    sf::Vector2f momentum;
    
    float radius;
    float mass;
    bool friction = false;

    void update();
    void checkCollitionWithWindows();
    void checkCollitionWithParticle(Particle &p);

    void set_friction(bool state);
};

#endif