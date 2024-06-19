#include <SFML/Graphics.hpp>
#include <list>

#include "constants.h"
#include "particle_manager.h"
#include "wave_manager.h"

int main(int argc, char** argv) {

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Physim");
    window.setFramerateLimit(FRAMES_PER_SECOND);

    WaveManager waveManager = WaveManager(&window);
    waveManager.generate_grid();

    while (window.isOpen()) {

        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::Black);
        waveManager.update();
        window.display();

    }

    return 0;
}