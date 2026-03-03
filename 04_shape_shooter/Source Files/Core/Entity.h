#include <string>
#include <memory>
#include "../Components/CTransform.cpp"
#include "../Components/CShape.cpp"

#pragma once

class Entity
{
	std::string m_tag;
	bool m_active;
	size_t m_id;

public:
	Entity(std::string tag, bool active, size_t id);

	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CShape> cShape;
};
