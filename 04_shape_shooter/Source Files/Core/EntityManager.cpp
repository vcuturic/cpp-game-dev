#include "EntityManager.h"

EntityManager::EntityManager()
{
}

Entity& EntityManager::addEntity(const std::string& tag)
{
	Entity e(tag, true, m_totalEntities++);
	m_toAdd.push_back(e);

	return m_toAdd.back();
}

std::vector<Entity>& EntityManager::getEntities()
{
    return m_entities;
}

void EntityManager::update()
{
    for (auto& e : m_toAdd)
    {
        m_entities.push_back(e);
    }

    m_toAdd.clear();
}
