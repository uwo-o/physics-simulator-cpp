#include <SFML/Graphics.hpp>
#include <list>

#include "constants.h"
#include "particle_manager.h"
#include "wave_manager.h"

float gravity_atractor(Particle &p1, Particle &p2) {
    float distance = sqrt(pow(p1.position.x - p2.position.x, 2) + pow(p1.position.y - p2.position.y, 2));

    float d = (distance*distance == 0) ? 1 : distance*distance;

    return (150 * p1.mass * p2.mass) / d;
}

int main(int argc, char** argv) {

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Physim");

    window.setFramerateLimit(FRAMES_PER_SECOND);

    Particle p1 = Particle(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), 10, sf::Color::Red);

    // CENTER P1 
    p1.circle.setPosition(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));
    Particle p2 = Particle(sf::Vector2f(WINDOW_WIDTH/2 - 15, WINDOW_HEIGHT/2), 10, sf::Color::Blue);

    p2.velocity = sf::Vector2f(0, 0);

    while (window.isOpen()) {

        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();
        }

        sf::Vector2f normal = p2.position - p1.position;
        float mag = sqrt(normal.x*normal.x + normal.y*normal.y);
        normal = normal / mag;

        float force = gravity_atractor(p1, p2);
        p1.acceleration += normal * force / p1.mass;
        p2.acceleration += normal * force / p2.mass;

        p1.velocity = sf::Vector2f(0, 3);
        p2.velocity = sf::Vector2f(0, -1);

        p1.update();
        p2.update();


        window.clear(sf::Color::Black);

        window.draw(p1.circle);
        window.draw(p2.circle);
        window.display();

    }

    return 0;
}