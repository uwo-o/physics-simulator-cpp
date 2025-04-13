#include "field.h"

Field::Field(sf::RenderWindow *window, int segments)
{
    this->window = window;
    this->frame = 0;
    this->segments = segments;
}

double Field::calculate(float x, float y, double (*function)(double, double))
{
    return function(x, y);
}
void Field::define_functions(double((*function)(double, double)), double (*function2)(double, double))
{
    this->function = function;
    this->function2 = function2;
}

void Field::generate_grid()
{
    // this->dots = std::vector<std::vector<Dot>>();
    // this->eval_dots = std::vector<std::vector<Dot>>();
    this->lines = std::vector<std::vector<Line>>();
}
void Field::update()
{
}