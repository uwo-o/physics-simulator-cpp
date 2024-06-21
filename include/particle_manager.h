#ifndef PARTICLE_MANAGER_H
#define PARTICLE_MANAGER_H

#include <list>
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "particle.h"


static const int MAX_RADIUS = 15;

class ParticleManager {
    private:
        sf::RenderWindow *window;
        std::list<Particle> particles;
        std::vector<std::vector<std::vector<Particle*>*>*> * grid;
        bool gravity;
        bool friction;

    public:
        ParticleManager(sf::RenderWindow *window, bool gravity, bool friction);
        void grid_search();
        void generate_particles(int number);
        void update();
};

#endif