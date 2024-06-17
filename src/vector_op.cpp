#include "vector_op.h"

float dot(sf::Vector2f v1, sf::Vector2f v2) {
    return v1.x*v2.x + v1.y*v2.y;
}

float magnitude(sf::Vector2f v) {
    return sqrt(pow(v.x, 2) + pow(v.y,2));
}