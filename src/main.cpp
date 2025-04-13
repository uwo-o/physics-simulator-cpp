#include <SFML/Graphics.hpp>
#include <list>

#include "constants.h"
#include "particle_manager.h"
#include "wave_manager.h"
#include "field.h"

int main(int argc, char **argv)
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Physim");
    window.setFramerateLimit(FRAMES_PER_SECOND);

    ParticleManager pm(&window, true, true);

    while (window.isOpen())
    {

        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        pm.generate_particles(1);

        window.clear(sf::Color::Black);

        pm.update();
        window.display();
    }

    return 0;
}