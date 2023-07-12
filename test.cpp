#include <SFML/Graphics.hpp>
#include <iostream>

float toRad(float angle) {
    return angle * (M_PI / 180);
}

int main() {
    // open windows
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "my names deez");
    sf::Vector2u size = window.getSize();

    // enable v-sync
    window.setVerticalSyncEnabled(true);

    int x = size.x / 2;
    int y = size.y / 2;

    // int len = 200;
    // int angle = 90;

    // main loop
    while (window.isOpen()) {
        // check events
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        //     angle += 2;
        // }

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        //     angle -= 2;
        // }

        window.clear(sf::Color::Black);

        // int angle = 45
        for (int angle = 0; angle < 360; angle += 5) {
            sf::VertexArray line(sf::Lines, 2);

            line[0].position = sf::Vector2f(x, y);

            int rayCos = std::cos(toRad(angle)) * 100;
            int raySin = std::sin(toRad(angle)) * 100;

            int rayX = x + rayCos * 10;
            int rayY = y + raySin * 10;

            // int distance = std::sqrt(std::pow(x - rayX, 2) + std::pow(y - rayY, 2));
            // std::cout << distance << std::endl;

            line[1].position = sf::Vector2f(rayX, rayY);

            window.draw(line);
        }

        window.display();
    }

    return 0;
}