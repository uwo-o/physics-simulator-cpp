#include <SFML/Graphics.hpp>
#include <list>

#include "constants.h"
#include "particle.h"

std::list<Particle> particles;

int main(int argc, char** argv) {

    Particle p(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), 20.0f, sf::Color::Red);
    p.velocity = sf::Vector2f(5,5);
    particles.push_back(p);
    Particle p2(sf::Vector2f((WINDOW_WIDTH / 2), WINDOW_HEIGHT / 2), 10.0f, sf::Color::Blue);
    p2.velocity = sf::Vector2f(-5,-5);
    particles.push_back(p2);
    Particle p3(sf::Vector2f((WINDOW_WIDTH / 2), WINDOW_HEIGHT / 2), 10.0f, sf::Color::Green);
    particles.push_back(p3);

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Physim");
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();
        }
        

        window.clear(sf::Color::Black);

        for (auto it = particles.begin(); it != particles.end(); it++) {

            for (auto it2 = particles.begin(); it2 != particles.end(); it2++) {
                if (it != it2) it->checkCollitionWithParticle(*it2);
            }

            it->update();
            window.draw(it->circle);
        }
        window.display();

    }

    return 0;
}