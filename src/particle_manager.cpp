#include "particle_manager.h"

ParticleManager::ParticleManager(sf::RenderWindow *window, bool gravity, bool friction) {
    this->window = window;
    this->gravity = gravity;
    this->friction = friction;
}

void ParticleManager::grid_search() {
    this->grid->clear();
    this->grid = new std::vector<std::vector<std::vector<Particle*>*>*>();
    for (int i=0; i<WINDOW_WIDTH; i+=MAX_RADIUS) {
        this->grid->push_back(new std::vector<std::vector<Particle*>*>());
        for (int j=0; j<WINDOW_HEIGHT; j+=MAX_RADIUS) {
            this->grid->at(i/MAX_RADIUS)->push_back(new std::vector<Particle*>());
        }
    }
    
    for(Particle &it : this->particles){
        int x = it.position.x / MAX_RADIUS;
        int y = it.position.y / MAX_RADIUS;

        if (x < 0) x = 0;
        if (x >= WINDOW_WIDTH/MAX_RADIUS) x = WINDOW_WIDTH/MAX_RADIUS - 1;
        if (y < 0) y = 0;
        if (y >= WINDOW_HEIGHT/MAX_RADIUS) y = WINDOW_HEIGHT/MAX_RADIUS - 1;

        this->grid->at(x)->at(y)->push_back(&it);
        it.update();
    }
}

void ParticleManager::generate_particles(int number) {
    for (int i=0; i<number; i++) {
        Particle p(sf::Vector2f(0, WINDOW_HEIGHT/2), (float) MAX_RADIUS, sf::Color::White);
        p.velocity = sf::Vector2f((float)(rand() % 5 +1), (float)(rand() % 5 +1));
        p.position = sf::Vector2f(0,0);
        if (gravity) p.acceleration = sf::Vector2f(0, GRAVITY);
        if (friction) p.friction = this->friction;
        this->particles.push_back(p);
    }

}

void ParticleManager::update() {

    this->window->setTitle("Physim - " + std::to_string(this->particles.size()) + " particles");

    this->grid_search();

    //std::cout << "Iteration" << std::endl;

    for (int i=0; i<this->grid->size(); i++) {
        for (int j=0; j<this->grid->at(i)->size(); j++) {

            std::vector<Particle*> * cell = this->grid->at(i)->at(j);

            if (cell->size() == 0) continue;

            for (int dx = -1; dx<= 1; dx++) {
                for (int dy = -1; dy<= 1; dy++) {

                    if (i+dx < 0 || i+dx >= this->grid->size() || j+dy < 0 || j+dy >= this->grid->at(i)->size()) continue;

                    auto &neighbour = this->grid->at(i+dx)->at(j+dy);
                    
                    for (Particle *it : *cell) {
                        for (Particle *it2 : *neighbour) {
                            if (it != it2) {
                                it->checkCollitionWithParticle(*it2);
                                //it->manageOverlap(*it2);
                                it->update();
                                it2->update();
                            }
                        }
                    }
                }
            }
        }
    }

    for(auto row: *this->grid) {
        for(auto cell: *row) {
            for(auto& p: *cell) {
                this->window->draw(p->circle);
            }
        }
    }

}