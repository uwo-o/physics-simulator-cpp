#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>
#include <math.h>

#include "constants.h"

class Particle{
public:
    Particle(sf::Vector2f position, float radius, sf::Color color);

    sf::CircleShape circle;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    float radius;
    float mass;

    void update();
    void checkCollitionWithWindows();
    void checkCollitionWithParticle(Particle &p);
    void unOverlap(Particle &p);
};

#endif