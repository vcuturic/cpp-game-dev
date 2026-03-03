#include "Game.h"

Game::Game() 
    :m_window(sf::VideoMode({ WIDTH, HEIGHT }), "Shape Shooter")
{
    m_window.setFramerateLimit(FPS);
}

void Game::Run()
{
    auto& player = m_entityManager.addEntity("Player");

    player.cTransform = std::make_shared<CTransform>();
    player.cTransform->position = sf::Vector2f(100, 100);

    player.cShape = std::make_shared<CShape>(15.0f, sf::Color::Red);

    while (m_window.isOpen())
    {
        m_entityManager.update();
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = m_window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                m_window.close();
        }

        m_window.clear(sf::Color::Black);

        for (auto& e : m_entityManager.getEntities())
        {
            if (e.cShape && e.cTransform)
            {
                e.cShape->circle.setPosition(e.cTransform->position);
                m_window.draw(e.cShape->circle);
            }
        }

        m_window.display();
    }
}