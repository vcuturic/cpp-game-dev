#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EntityManager.h"

#pragma once

class Game {
    sf::RenderWindow m_window;
    EntityManager m_entityManager;

    static constexpr unsigned WIDTH = 800;
    static constexpr unsigned HEIGHT = 600;
    static constexpr unsigned FPS = 60;

public:
    Game();
    void Run();
};