#ifndef WAVE_MANAGER_H
#define WAVE_MANAGER_H

#include <vector>
#include <cmath>
#include <time.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "dot.h"

static const int SEGMENTS = 30;
static const float K = 0.025;
static const float W = 0.1;
class WaveManager {
    private:
        sf::RenderWindow *window;
        std::vector<std::vector<Dot>> dots;
        int frame;

    public:
        WaveManager(sf::RenderWindow *window);
        void generate_grid();
        void update();
};

#endif