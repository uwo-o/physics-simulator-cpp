#include <SFML/Graphics.hpp>
#include <list>

#include "constants.h"
#include "particle.h"

std::list<Particle> particles;

int main(int argc, char** argv) {

    Particle p(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), 10.0f, sf::Color::White);
    p.acceleration = sf::Vector2f(0, 2);
    p.velocity = sf::Vector2f(20, -10);

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Physim");
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::Black);

        p.checkCollitionWithWindows(WINDOW_WIDTH, WINDOW_HEIGHT);
        p.update();

        window.draw(p.circle);
        window.display();

    }

    return 0;
}