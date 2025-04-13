#ifndef FIELD_H
#define FIELD_H

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "line.h"
class Field
{
public:
    Field(sf::RenderWindow *window, int segments);
    double calculate(float x, float y, double (*function)(double, double));
    void define_functions(double (*function)(double, double), double (*function2)(double, double));
    void generate_grid();
    void update();

private:
    sf::RenderWindow *window;
    int frame;
    int segments;
    double (*function)(double, double);
    double (*function2)(double, double);
    std::vector<std::vector<Line>> lines;
};

#endif