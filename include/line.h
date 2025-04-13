#ifndef LINE_H
#define LINE_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "constants.h"

class Line
{
private:
    sf::VertexArray line;
    sf::Vector2f start;
    sf::Vector2f end;
    sf::Color color;
    float thickness;

public:
    Line(sf::Vector2f start, sf::Vector2f end, sf::Color color, float thickness);
};
#endif