#include "wave_manager.h"

WaveManager::WaveManager(sf::RenderWindow *window)
{
    this->window = window;
    this->frame = 0;
}

void WaveManager::generate_grid()
{

    this->dots = std::vector<std::vector<Dot>>();

    for (int i = 0; i < WINDOW_WIDTH; i = i + WINDOW_WIDTH / SEGMENTS)
    {

        std::vector<Dot> dots_col = std::vector<Dot>();

        for (int j = 0; j < WINDOW_HEIGHT; j = j + WINDOW_HEIGHT / SEGMENTS)
        {

            Dot d(sf::Vector2f(i, j));
            dots_col.push_back(d);
        }

        this->dots.push_back(dots_col);
    }
}

void WaveManager::update()
{
    this->frame++;
    for (int i = 0; i < this->dots.size(); i++)
    {
        for (int j = 0; j < this->dots.at(i).size(); j++)
        {
            Dot d = this->dots.at(i).at(j);
            d.position.x += (float)10 * sin(K * d.position.x - W * this->frame);
            d.circle.setPosition(d.position);
            this->window->draw(d.circle);
        }
    }
}