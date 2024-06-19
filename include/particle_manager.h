#ifndef PARTICLE_MANAGER_H
#define PARTICLE_MANAGER_H

#include <list>
#include <SFML/Graphics.hpp>

#include "particle.h"

class ParticleManager {
    private:
        sf::RenderWindow *window;
        std::list<Particle> particles;

    public:
        ParticleManager(sf::RenderWindow *window);
        void generate_particles(int number);
        void update();
};

#endif