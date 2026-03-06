#include "EntityManager.h"

EntityManager::EntityManager()
{
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto entity = std::shared_ptr<Entity>(new Entity(tag, m_totalEntities++));

	m_toAdd.push_back(entity);

	return entity;
}


EntityVec & EntityManager::getEntities()
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
