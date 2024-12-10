#include <cstdlib>
#include <cmath>
#include <SFML/Window/Window.hpp>
#include <glad/glad.h>

#include "test/test.h"

int main() {
    test123();

    sf::Window window(sf::VideoMode(800, 600), "OpenGL");

    if (!gladLoadGL()) {
        return EXIT_FAILURE;
    }

    glEnable(GL_TEXTURE_2D);

    sf::Vector2<int> winCenter = {0, 0 };
    if (window.getSize().x <= 640) {
        winCenter = {
                int(std::floor(sf::VideoMode::getDesktopMode().width / 3.5)),
                int(std::floor(sf::VideoMode::getDesktopMode().height / 4))
        };
    }
    window.setPosition(winCenter);

    while (window.isOpen()) {

    }

    return EXIT_SUCCESS;
}
