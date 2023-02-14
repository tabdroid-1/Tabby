#pragma once

namespace Tabby
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0                = 0,
		Button1                = 1,
		Button2                = 2,
		Button3                = 3,
		Button4                = 4,
		Button5                = 5,
		Button6                = 6,
		Button7                = 7,

		ButtonLast             = Button7,
		ButtonLeft             = Button0,
		ButtonRight            = Button1,
		ButtonMiddle           = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define TB_MOUSE_BUTTON_0      ::Tabby::Mouse::Button0
#define TB_MOUSE_BUTTON_1      ::Tabby::Mouse::Button1
#define TB_MOUSE_BUTTON_2      ::Tabby::Mouse::Button2
#define TB_MOUSE_BUTTON_3      ::Tabby::Mouse::Button3
#define TB_MOUSE_BUTTON_4      ::Tabby::Mouse::Button4
#define TB_MOUSE_BUTTON_5      ::Tabby::Mouse::Button5
#define TB_MOUSE_BUTTON_6      ::Tabby::Mouse::Button6
#define TB_MOUSE_BUTTON_7      ::Tabby::Mouse::Button7
#define TB_MOUSE_BUTTON_LAST   ::Tabby::Mouse::ButtonLast
#define TB_MOUSE_BUTTON_LEFT   ::Tabby::Mouse::ButtonLeft
#define TB_MOUSE_BUTTON_RIGHT  ::Tabby::Mouse::ButtonRight
#define TB_MOUSE_BUTTON_MIDDLE ::Tabby::Mouse::ButtonMiddle