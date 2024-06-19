#include "particle_manager.h"

ParticleManager::ParticleManager(sf::RenderWindow *window) {
    this->window = window;
}
void ParticleManager::generate_particles(int number) {

    for (int i=0; i<number; i++) {
        Particle p(sf::Vector2f(0, WINDOW_HEIGHT/2), (float) (rand() % 5 + 2), sf::Color::White);
        p.velocity = sf::Vector2f(rand() % 10 + 1, rand() % 10 + 1);
        p.position = sf::Vector2f(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT);
        this->particles.push_back(p);
    }

}

void ParticleManager::update() {
    for (auto it = this->particles.begin(); it != this->particles.end(); it++) {
        for(auto it2 = this->particles.begin(); it2 != this->particles.end(); it2++)
            if(it!=it2) it->checkCollitionWithParticle(*it2);
        it->update();
        this->window->draw(it->circle);
    }
}