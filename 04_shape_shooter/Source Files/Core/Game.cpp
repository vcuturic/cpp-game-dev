#include "Game.h"
#include <fstream>
#include <iostream>

Game::Game(const std::string& configPath)
{
    init(configPath);
}

void Game::init(const std::string& configPath)
{
    std::ifstream file(configPath);

    std::string type;

    while (file >> type)
    {
        if (type == "Window")
        {
            file >> m_windowConfig.width
                 >> m_windowConfig.height
                 >> m_windowConfig.fps
                 >> m_windowConfig.fullscreen;
        }
        else if (type == "Font")
        {
            file >> m_fontConfig.fontName
                 >> m_fontConfig.fontRed
                 >> m_fontConfig.fontGreen
                 >> m_fontConfig.fontBlue;
        }
        else if (type == "Player")
        {
            file >> m_playerConfig.circleRadius
                 >> m_playerConfig.collisionRadius
                 >> m_playerConfig.fillRed
                 >> m_playerConfig.fillGreen
                 >> m_playerConfig.fillBlue
                 >> m_playerConfig.outlineThickness
                 >> m_playerConfig.outlineRed
                 >> m_playerConfig.outlineGreen
                 >> m_playerConfig.outlineBlue
                 >> m_playerConfig.speed
                 >> m_playerConfig.vertices;
        }
        else if (type == "Enemy")
        {
            file >> m_enemyConfig.circleRadius
                 >> m_enemyConfig.collisionRadius
                >> m_enemyConfig.outlineThickness
                 >> m_enemyConfig.outlineRed
                 >> m_enemyConfig.outlineGreen
                 >> m_enemyConfig.outlineBlue
                 >> m_enemyConfig.verticesMin
                 >> m_enemyConfig.verticesMax
                 >> m_enemyConfig.L
                 >> m_enemyConfig.SI
                 >> m_enemyConfig.speedMin
                 >> m_enemyConfig.speedMax;
        }
        else if (type == "Bullet")
        {
            file >> m_bulletConfig.circleRadius
                >> m_bulletConfig.collisionRadius
                >> m_bulletConfig.fillRed
                >> m_bulletConfig.fillGreen
                >> m_bulletConfig.fillBlue
                >> m_enemyConfig.outlineThickness
                >> m_bulletConfig.outlineRed
                >> m_bulletConfig.outlineGreen
                >> m_bulletConfig.outlineBlue
                >> m_bulletConfig.vertices
                >> m_bulletConfig.speed
                >> m_bulletConfig.L;
        }
    }

    std::cout << m_windowConfig.width << " " << m_windowConfig.height << std::endl;

    m_window.create(sf::VideoMode({ m_windowConfig.width, m_windowConfig.height}), "Shape Shooter");

    m_window.setFramerateLimit(m_windowConfig.fps);

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

    entity->cShape = std::make_shared<CShape>(m_playerConfig.circleRadius
                                                , m_playerConfig.fillRed
                                                , m_playerConfig.fillGreen
                                                , m_playerConfig.fillBlue
                                                , m_playerConfig.outlineThickness
                                                , m_playerConfig.outlineRed
                                                , m_playerConfig.outlineGreen
                                                , m_playerConfig.outlineBlue
                                                , m_playerConfig.vertices
                                            );

    entity->cInput = std::make_shared<CInput>();

    m_player = entity;
}
