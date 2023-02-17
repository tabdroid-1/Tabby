#include "tbpch.h"
#include "Tabby/Scene/Entity.h"

namespace Tabby {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}