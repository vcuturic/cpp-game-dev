#include <string>
#include <memory>
#include "../Components/CTransform.cpp"
#include "../Components/CShape.cpp"
#include "../Components/CInput.cpp"

#pragma once

class Entity
{
	friend class EntityManager;

	std::string m_tag = "default";
	bool m_active = true;
	size_t m_id = 0;

	Entity(const std::string &tag, size_t id);

public:
	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CShape> cShape;
	std::shared_ptr<CInput> cInput;
};
