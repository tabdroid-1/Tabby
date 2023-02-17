#include <Tabby.h>
#include <Tabby/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Tabby {

	class TabbyEngine : public Application
	{
	public:
		TabbyEngine()
			: Application("Tabby Engine")
		{
			PushLayer(new EditorLayer());
		}

		~TabbyEngine()
		{
		}
	};

	Application* CreateApplication()
	{
		return new TabbyEngine();
	}

}