#pragma once

#include "Tabby/Core/Base.h"
#include "Tabby/Core/KeyCodes.h"
#include "Tabby/Core/MouseCodes.h"

namespace Tabby {

    class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}