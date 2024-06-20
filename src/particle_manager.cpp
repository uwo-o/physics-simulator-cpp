#include "particle_manager.h"

ParticleManager::ParticleManager(sf::RenderWindow *window, bool gravity, bool friction) {
    this->window = window;
    this->gravity = gravity;
    this->friction = friction;
}

void ParticleManager::grid_search() {
    this->grid.clear();
    this->grid = std::vector<std::vector<std::vector<Particle>>>();
    for (int i=0; i<WINDOW_WIDTH/MAX_RADIUS; i++) {
        this->grid.push_back(std::vector<std::vector<Particle>>());
        for (int j=0; j<WINDOW_HEIGHT/MAX_RADIUS; j++) {
            this->grid[i].push_back(std::vector<Particle>());
            for (auto it = this->particles.begin(); it != this->particles.end(); it++) {
                std::cout << it->position.x << " " << it->position.y << std::endl;
                if (it->position.x >= i*MAX_RADIUS && it->position.x < (i+1)*MAX_RADIUS && it->position.y >= j*MAX_RADIUS && it->position.y < (j+1)*MAX_RADIUS) {
                    this->grid[i][j].push_back(*it);
                }
                it->update();
                this->window->draw(it->circle);
            }    
        }
    }
}
void ParticleManager::generate_particles(int number) {
    for (int i=0; i<number; i++) {
        Particle p(sf::Vector2f(0, WINDOW_HEIGHT/2), (float) MAX_RADIUS, sf::Color::White);
        p.velocity = sf::Vector2f(rand() % 10 + 1, rand() % 10 + 1);
        p.position = sf::Vector2f(0,0);
        if (gravity) p.acceleration = sf::Vector2f(0, GRAVITY);
        if (friction) p.friction = this->friction;
        this->particles.push_back(p);
    }

}

void ParticleManager::update() {
    this->grid_search();
//
    //for (auto i = this->grid.begin(); i != this->grid.end(); i++) {
//
    //    for (Particle* j = &(*i)[0]; j != &(*i)[i->size()]; j++) {
    //        for (Particle* k = &(*i)[0]; k != &(*i)[i->size()]; k++) {
    //            if (j != k) j->checkCollitionWithParticle(*k);
    //        }
    //        j->update();
    //        this->window->draw(j->circle);
    //    }
    //}

    //for (auto it = this->particles.begin(); it != this->particles.end(); it++) {
    //    for(auto it2 = this->particles.begin(); it2 != this->particles.end(); it2++)
    //        if(it!=it2) it->checkCollitionWithParticle(*it2);
    //    it->update();
    //    this->window->draw(it->circle);
    //}
}