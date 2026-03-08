#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EntityManager.h"

#pragma once

class Game {
    sf::RenderWindow m_window;
    EntityManager m_entityManager;
    bool m_running = true;
    bool m_paused = false;

    std::shared_ptr<Entity> m_player;

    static constexpr unsigned WIDTH = 800;
    static constexpr unsigned HEIGHT = 600;
    static constexpr unsigned FPS = 60;

public:
    Game(const std::string& config);

    void init(const std::string &config);
    void Run();

    void sRender();
    void sUserInput();
    void sMovement();

    void SpawnPlayer();
};