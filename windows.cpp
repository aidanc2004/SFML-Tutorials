#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    // open windows
    sf::Window window(sf::VideoMode(800, 600), "my names deez");
    // sf::Window window(sf::VideoMode::getDesktopMode(), "ljfkdsaljkfds");

    // change window settings
    window.setPosition(sf::Vector2i(10, 50));
    window.setSize(sf::Vector2u(640, 480));
    window.setTitle("asdf asdf asdf");

    // get window size    
    sf::Vector2u size = window.getSize();
    int width = size.x;
    int height = size.y;

    std::cout << width << " " << height << "\n";

    // enable v-sync
    window.setVerticalSyncEnabled(true);

    // main loop
    while (window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            std::cout << "go left!!!" << '\n';
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            std::cout << "mouse down" << '\n';

        // check events
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::TextEntered:
                if (event.text.unicode < 128)
                    std::cout << static_cast<char>(event.text.unicode) << '\n';
                break;
            case sf::Event::MouseButtonPressed:
                std::cout << "stop fuggin pokin me >:(" << '\n';
                break;
            case sf::Event::Resized:
                std::cout << event.size.width << " " << event.size.height << '\n';
                break;
            case sf::Event::LostFocus:
                std::cout << "where did you go :(" << '\n';
                break;
            default:
                break;
            }
        }
    }

    return 0;
}