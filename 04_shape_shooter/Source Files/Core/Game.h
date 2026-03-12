#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EntityManager.h"
#include "../Config.h"

#pragma once

class Game {
    EntityManager m_entityManager;

    sf::RenderWindow m_window;
    std::shared_ptr<Entity> m_player;

    WindowConfig m_windowConfig;
    FontConfig m_fontConfig;
    PlayerConfig m_playerConfig;
    EnemyConfig m_enemyConfig;
    BulletConfig m_bulletConfig;

    bool m_running = true;
    bool m_paused = false;
    int m_currentFrame = 0;
    int m_lastEnemySpawnTime = 0;
public:
    Game(const std::string& configPath);

    void init(const std::string & configPath);
    void Run();

    void sRender();
    void sUserInput();
    void sMovement();
    void sEnemySpawner();

    void SpawnPlayer();
    void SpawnEnemy();
    void SpawnBullet(const std::shared_ptr<Entity>& source, const Vec2& target);
};