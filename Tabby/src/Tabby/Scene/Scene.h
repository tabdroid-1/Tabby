
#pragma once


#include "Tabby/Core/Timestep.h"
#include "Tabby/Renderer/EditorCamera.h"

#include <entt/include/entt.hpp>

namespace Tabby {

    class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());
        void DestroyEntity(Entity entity);

		void OnUpdateRuntime(Timestep ts);
		void OnUpdateEditor(Timestep ts, EditorCamera& camera);
        void OnViewportResize(uint32_t width, uint32_t height);

        Entity GetPrimaryCameraEntity();

        entt::registry m_Registry;
    private:
		template<typename T>
		void OnComponentAdded(Entity entity, T& component);
	private:
		
        uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;

        friend class Entity;
        friend class SceneSerializer;
        friend class SceneHierarchyPanel;
	};

}