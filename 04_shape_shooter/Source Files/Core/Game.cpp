#include "Game.h"

Game::Game(const std::string& config)
{
    init(config);
}

void Game::init(const std::string& config)
{
    m_window.create(sf::VideoMode({ WIDTH, HEIGHT }), "Shape Shooter");

    m_window.setFramerateLimit(FPS);

    SpawnPlayer();
}

void Game::Run()
{  
    while (m_running)
    {
        m_entityManager.update();
        
        sUserInput();
        sMovement();
        sRender();
    }
}

void Game::sRender()
{
    m_window.clear(sf::Color::Black);

    for (auto& e : m_entityManager.getEntities())
    {
        if (e->cShape && e->cTransform)
        {
            e->cShape->circle.setPosition(e->cTransform->position);

            m_window.draw(e->cShape->circle);
        }
    }

    m_window.display();
}

void Game::sUserInput()
{
    // check all the window's events that were triggered since the last iteration of the loop
    while (const std::optional event = m_window.pollEvent())
    {
        // "close requested" event: we close the window
        if (event->is<sf::Event::Closed>())
        {
            m_running = false;
            m_window.close();
        }

        if (const auto& keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            switch (keyPressed->scancode)
            {
                case sf::Keyboard::Scan::W:
                    m_player->cInput->up = true;
                    break;
                case sf::Keyboard::Scan::S:
                    m_player->cInput->down = true;
                    break;
                case sf::Keyboard::Scan::A:
                    m_player->cInput->left = true;
                    break;
                case sf::Keyboard::Scan::D:
                    m_player->cInput->right = true;
                    break;
                default: break;
            }
        }

        if (const auto& keyReleased = event->getIf<sf::Event::KeyReleased>())
        {
            switch (keyReleased->scancode)
            {
                case sf::Keyboard::Scan::W:
                    m_player->cInput->up = false;
                    break;
                case sf::Keyboard::Scan::S:
                    m_player->cInput->down = false;
                    break;
                case sf::Keyboard::Scan::A:
                    m_player->cInput->left = false;
                    break;
                case sf::Keyboard::Scan::D:
                    m_player->cInput->right = false;
                    break;
                default: break;
            }
        }
    }
}

void Game::sMovement()
{
    // We must reset the velocity or it stays, as the last key pressed indefinitely :)
    m_player->cTransform->velocity = { 0, 0 };

    if (m_player->cInput->up)
    {
        m_player->cTransform->velocity.y = -5;
    }

    if (m_player->cInput->down)
    {
        m_player->cTransform->velocity.y = 5;
    }

    if (m_player->cInput->left)
    {
        m_player->cTransform->velocity.x = -5;
    }

    if (m_player->cInput->right)
    {
        m_player->cTransform->velocity.x = 5;
    }

    // Sample movement
    m_player->cTransform->position.x += m_player->cTransform->velocity.x;
    m_player->cTransform->position.y += m_player->cTransform->velocity.y;
}

void Game::SpawnPlayer()
{
    auto entity = m_entityManager.addEntity("Player");

    entity->cTransform = std::make_shared<CTransform>();
    entity->cTransform->position = Vec2(100, 100);

    entity->cShape = std::make_shared<CShape>(15.0f, sf::Color::Red);

    entity->cInput = std::make_shared<CInput>();

    m_player = entity;
}
