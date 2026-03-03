#include <vector>
#include <unordered_map>
#include <string>

#include "Entity.h"

#pragma once

class EntityManager
{
	std::vector<Entity> m_entities;
	std::unordered_map<std::string, Entity> m_entityMap;
	std::vector<Entity> m_toAdd;

	size_t m_totalEntities = 0;

public:
	EntityManager();
	Entity& addEntity(const std::string &tag);
	std::vector<Entity>& getEntities();
	void update();
};