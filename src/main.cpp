#include <SFML/Graphics.hpp>
#include <list>

#include "constants.h"
#include "particle.h"

std::list<Particle> particles;
const int MAX_PARTICLES = 50;

int main(int argc, char** argv) {

    for (int i=0; i<MAX_PARTICLES; i++) {
        Particle p(sf::Vector2f(0, WINDOW_HEIGHT/2), (float) (rand() % 5 + 2), sf::Color::White);
        p.velocity = sf::Vector2f(rand() % 10 + 1, rand() % 10 + 1);
        p.position = sf::Vector2f(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT);
        particles.push_back(p);
    }

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Physim");
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();
        }
        

        window.clear(sf::Color::Black);

        for (auto it = particles.begin(); it != particles.end(); it++) {

            for(auto it2 = particles.begin(); it2 != particles.end(); it2++)
                if(it!=it2) it->checkCollitionWithParticle(*it2);
            it->update();
            window.draw(it->circle);
        }
        window.display();

    }

    return 0;
}