#include <SFML/Graphics.hpp>
#include <list>

#include "constants.h"
#include "particle_manager.h"

int main(int argc, char** argv) {

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Physim");
    window.setFramerateLimit(FRAMES_PER_SECOND);

    ParticleManager particleManager = ParticleManager(&window);
    particleManager.generate_particles(50);

    while (window.isOpen()) {

        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::Black);
        particleManager.update();
        window.display();

    }

    return 0;
}