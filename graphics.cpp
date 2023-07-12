#include <iostream>

#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[]) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "graphikz :O");

    // window.setFramerateLimit(5);
    window.setVerticalSyncEnabled(true);

    // load font
    sf::Font roboto;
    if (!roboto.loadFromFile("Roboto-Light.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        return -1;
    }

    // create text
    sf::Text text;
    text.setFont(roboto);
    text.setString("speeeeen!");
    text.setFillColor(sf::Color::Cyan);
    text.setCharacterSize(24); // px
    text.setPosition(200, 150);

    sf::Text help;
    help.setFont(roboto);
    help.setString("Up and down to change rotation angle");
    help.setFillColor(sf::Color::Green);
    help.setCharacterSize(16);
    help.setPosition(20, 560);

    // create sprite
    sf::Texture texture;
    if (!texture.loadFromFile("speen.gif")) {
        std::cerr << "Error loading texture" << std::endl;
        return -1;
    }

    sf::Sprite speen;
    speen.setTexture(texture);
    speen.setScale(0.2, 0.2);
    speen.setPosition(400, 300);

    // create vertex array triangle
    sf::VertexArray triangle(sf::Triangles, 3);

    sf::RenderStates states;
    sf::Transform transform;
    states.texture = &texture;
    states.transform = transform;

    triangle[0].position = sf::Vector2f(550, 100);
    triangle[1].position = sf::Vector2f(650, 80);
    triangle[2].position = sf::Vector2f(650, 180);

    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Green;
    triangle[2].color = sf::Color::Blue;

    triangle[0].texCoords = sf::Vector2f(0, 0);
    triangle[1].texCoords = sf::Vector2f(0, 640);
    triangle[2].texCoords = sf::Vector2f(640, 640);

    int angle = 0;
    int step = 2; // angle + step % 360

    while (window.isOpen()) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Up)
                    step++;
                if (event.key.code == sf::Keyboard::Down)
                    step--;
                break;
            default:
                break;
            }
        }

        // clear window
        window.clear(sf::Color::Black);

        // set text and image rotation
        angle = static_cast<float>((angle + step) % 360);

        text.setRotation(angle);
        speen.setRotation(-angle);
        // triangle.setRotation(angle);

        // draw everything to screen
        window.draw(text);
        window.draw(speen);
        window.draw(help);
        window.draw(triangle, states);

        // display window
        window.display();
    }

    return 0;
}
