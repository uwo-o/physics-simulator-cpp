#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

class Particle{
public:
    Particle(sf::Vector2f position, float radius, sf::Color color);

    sf::CircleShape circle;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

    void update();
    bool isCollidingWithWindow(int windowWidth, int windowHeight);
};

#endif