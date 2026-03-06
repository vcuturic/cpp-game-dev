#include <vector>
#include <unordered_map>
#include <string>

#include "Entity.h"

#pragma once

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::unordered_map<std::string, std::shared_ptr<Entity>> EntityMap;

class EntityManager
{
	EntityVec m_entities;
	EntityMap m_entityMap;
	EntityVec m_toAdd;

	size_t m_totalEntities = 0;

public:
	EntityManager();
	void update();

	std::shared_ptr<Entity> addEntity(const std::string &tag);

	EntityVec & getEntities();
};