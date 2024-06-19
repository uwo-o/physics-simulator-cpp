#ifndef DOT_H
#define DOT_H

#include <SFML/Graphics.hpp>
#include <math.h>

#include "constants.h"
#include "vector_op.h"

static const int RADIUS = 2;

class Dot{
public:
    Dot(sf::Vector2f position);

    sf::Vector2f position;
    sf::CircleShape circle;

    void update();
};

#endif