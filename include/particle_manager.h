#ifndef PARTICLE_MANAGER_H
#define PARTICLE_MANAGER_H

#include <list>
#include <SFML/Graphics.hpp>

#include "particle.h"

class ParticleManager {
    private:
        sf::RenderWindow *window;
        std::list<Particle> particles;
        bool gravity;
        bool friction;

    public:
        ParticleManager(sf::RenderWindow *window, bool gravity, bool friction);
        void generate_particles(int number);
        void update();
};

#endif