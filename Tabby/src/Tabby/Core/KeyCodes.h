#pragma once

namespace Tabby
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space               = 32,
		Apostrophe          = 39, /* ' */
		Comma               = 44, /* , */
		Minus               = 45, /* - */
		Period              = 46, /* . */
		Slash               = 47, /* / */

		D0                  = 48, /* 0 */
		D1                  = 49, /* 1 */
		D2                  = 50, /* 2 */
		D3                  = 51, /* 3 */
		D4                  = 52, /* 4 */
		D5                  = 53, /* 5 */
		D6                  = 54, /* 6 */
		D7                  = 55, /* 7 */
		D8                  = 56, /* 8 */
		D9                  = 57, /* 9 */

		Semicolon           = 59, /* ; */
		Equal               = 61, /* = */

		A                   = 65,
		B                   = 66,
		C                   = 67,
		D                   = 68,
		E                   = 69,
		F                   = 70,
		G                   = 71,
		H                   = 72,
		I                   = 73,
		J                   = 74,
		K                   = 75,
		L                   = 76,
		M                   = 77,
		N                   = 78,
		O                   = 79,
		P                   = 80,
		Q                   = 81,
		R                   = 82,
		S                   = 83,
		T                   = 84,
		U                   = 85,
		V                   = 86,
		W                   = 87,
		X                   = 88,
		Y                   = 89,
		Z                   = 90,

		LeftBracket         = 91,  /* [ */
		Backslash           = 92,  /* \ */
		RightBracket        = 93,  /* ] */
		GraveAccent         = 96,  /* ` */

		World1              = 161, /* non-US #1 */
		World2              = 162, /* non-US #2 */

		/* Function keys */
		Escape              = 256,
		Enter               = 257,
		Tab                 = 258,
		Backspace           = 259,
		Insert              = 260,
		Delete              = 261,
		Right               = 262,
		Left                = 263,
		Down                = 264,
		Up                  = 265,
		PageUp              = 266,
		PageDown            = 267,
		Home                = 268,
		End                 = 269,
		CapsLock            = 280,
		ScrollLock          = 281,
		NumLock             = 282,
		PrintScreen         = 283,
		Pause               = 284,
		F1                  = 290,
		F2                  = 291,
		F3                  = 292,
		F4                  = 293,
		F5                  = 294,
		F6                  = 295,
		F7                  = 296,
		F8                  = 297,
		F9                  = 298,
		F10                 = 299,
		F11                 = 300,
		F12                 = 301,
		F13                 = 302,
		F14                 = 303,
		F15                 = 304,
		F16                 = 305,
		F17                 = 306,
		F18                 = 307,
		F19                 = 308,
		F20                 = 309,
		F21                 = 310,
		F22                 = 311,
		F23                 = 312,
		F24                 = 313,
		F25                 = 314,

		/* Keypad */
		KP0                 = 320,
		KP1                 = 321,
		KP2                 = 322,
		KP3                 = 323,
		KP4                 = 324,
		KP5                 = 325,
		KP6                 = 326,
		KP7                 = 327,
		KP8                 = 328,
		KP9                 = 329,
		KPDecimal           = 330,
		KPDivide            = 331,
		KPMultiply          = 332,
		KPSubtract          = 333,
		KPAdd               = 334,
		KPEnter             = 335,
		KPEqual             = 336,

		LeftShift           = 340,
		LeftControl         = 341,
		LeftAlt             = 342,
		LeftSuper           = 343,
		RightShift          = 344,
		RightControl        = 345,
		RightAlt            = 346,
		RightSuper          = 347,
		Menu                = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define TB_KEY_SPACE           ::Tabby::Key::Space
#define TB_KEY_APOSTROPHE      ::Tabby::Key::Apostrophe    /* ' */
#define TB_KEY_COMMA           ::Tabby::Key::Comma         /* , */
#define TB_KEY_MINUS           ::Tabby::Key::Minus         /* - */
#define TB_KEY_PERIOD          ::Tabby::Key::Period        /* . */
#define TB_KEY_SLASH           ::Tabby::Key::Slash         /* / */
#define TB_KEY_0               ::Tabby::Key::D0
#define TB_KEY_1               ::Tabby::Key::D1
#define TB_KEY_2               ::Tabby::Key::D2
#define TB_KEY_3               ::Tabby::Key::D3
#define TB_KEY_4               ::Tabby::Key::D4
#define TB_KEY_5               ::Tabby::Key::D5
#define TB_KEY_6               ::Tabby::Key::D6
#define TB_KEY_7               ::Tabby::Key::D7
#define TB_KEY_8               ::Tabby::Key::D8
#define TB_KEY_9               ::Tabby::Key::D9
#define TB_KEY_SEMICOLON       ::Tabby::Key::Semicolon     /* ; */
#define TB_KEY_EQUAL           ::Tabby::Key::Equal         /* = */
#define TB_KEY_A               ::Tabby::Key::A
#define TB_KEY_B               ::Tabby::Key::B
#define TB_KEY_C               ::Tabby::Key::C
#define TB_KEY_D               ::Tabby::Key::D
#define TB_KEY_E               ::Tabby::Key::E
#define TB_KEY_F               ::Tabby::Key::F
#define TB_KEY_G               ::Tabby::Key::G
#define TB_KEY_H               ::Tabby::Key::H
#define TB_KEY_I               ::Tabby::Key::I
#define TB_KEY_J               ::Tabby::Key::J
#define TB_KEY_K               ::Tabby::Key::K
#define TB_KEY_L               ::Tabby::Key::L
#define TB_KEY_M               ::Tabby::Key::M
#define TB_KEY_N               ::Tabby::Key::N
#define TB_KEY_O               ::Tabby::Key::O
#define TB_KEY_P               ::Tabby::Key::P
#define TB_KEY_Q               ::Tabby::Key::Q
#define TB_KEY_R               ::Tabby::Key::R
#define TB_KEY_S               ::Tabby::Key::S
#define TB_KEY_T               ::Tabby::Key::T
#define TB_KEY_U               ::Tabby::Key::U
#define TB_KEY_V               ::Tabby::Key::V
#define TB_KEY_W               ::Tabby::Key::W
#define TB_KEY_X               ::Tabby::Key::X
#define TB_KEY_Y               ::Tabby::Key::Y
#define TB_KEY_Z               ::Tabby::Key::Z
#define TB_KEY_LEFT_BRACKET    ::Tabby::Key::LeftBracket   /* [ */
#define TB_KEY_BACKSLASH       ::Tabby::Key::Backslash     /* \ */
#define TB_KEY_RIGHT_BRACKET   ::Tabby::Key::RightBracket  /* ] */
#define TB_KEY_GRAVE_ACCENT    ::Tabby::Key::GraveAccent   /* ` */
#define TB_KEY_WORLD_1         ::Tabby::Key::World1        /* non-US #1 */
#define TB_KEY_WORLD_2         ::Tabby::Key::World2        /* non-US #2 */

/* Function keys */
#define TB_KEY_ESCAPE          ::Tabby::Key::Escape
#define TB_KEY_ENTER           ::Tabby::Key::Enter
#define TB_KEY_TAB             ::Tabby::Key::Tab
#define TB_KEY_BACKSPACE       ::Tabby::Key::Backspace
#define TB_KEY_INSERT          ::Tabby::Key::Insert
#define TB_KEY_DELETE          ::Tabby::Key::Delete
#define TB_KEY_RIGHT           ::Tabby::Key::Right
#define TB_KEY_LEFT            ::Tabby::Key::Left
#define TB_KEY_DOWN            ::Tabby::Key::Down
#define TB_KEY_UP              ::Tabby::Key::Up
#define TB_KEY_PAGE_UP         ::Tabby::Key::PageUp
#define TB_KEY_PAGE_DOWN       ::Tabby::Key::PageDown
#define TB_KEY_HOME            ::Tabby::Key::Home
#define TB_KEY_END             ::Tabby::Key::End
#define TB_KEY_CAPS_LOCK       ::Tabby::Key::CapsLock
#define TB_KEY_SCROLL_LOCK     ::Tabby::Key::ScrollLock
#define TB_KEY_NUM_LOCK        ::Tabby::Key::NumLock
#define TB_KEY_PRINT_SCREEN    ::Tabby::Key::PrintScreen
#define TB_KEY_PAUSE           ::Tabby::Key::Pause
#define TB_KEY_F1              ::Tabby::Key::F1
#define TB_KEY_F2              ::Tabby::Key::F2
#define TB_KEY_F3              ::Tabby::Key::F3
#define TB_KEY_F4              ::Tabby::Key::F4
#define TB_KEY_F5              ::Tabby::Key::F5
#define TB_KEY_F6              ::Tabby::Key::F6
#define TB_KEY_F7              ::Tabby::Key::F7
#define TB_KEY_F8              ::Tabby::Key::F8
#define TB_KEY_F9              ::Tabby::Key::F9
#define TB_KEY_F10             ::Tabby::Key::F10
#define TB_KEY_F11             ::Tabby::Key::F11
#define TB_KEY_F12             ::Tabby::Key::F12
#define TB_KEY_F13             ::Tabby::Key::F13
#define TB_KEY_F14             ::Tabby::Key::F14
#define TB_KEY_F15             ::Tabby::Key::F15
#define TB_KEY_F16             ::Tabby::Key::F16
#define TB_KEY_F17             ::Tabby::Key::F17
#define TB_KEY_F18             ::Tabby::Key::F18
#define TB_KEY_F19             ::Tabby::Key::F19
#define TB_KEY_F20             ::Tabby::Key::F20
#define TB_KEY_F21             ::Tabby::Key::F21
#define TB_KEY_F22             ::Tabby::Key::F22
#define TB_KEY_F23             ::Tabby::Key::F23
#define TB_KEY_F24             ::Tabby::Key::F24
#define TB_KEY_F25             ::Tabby::Key::F25

/* Keypad */
#define TB_KEY_KP_0            ::Tabby::Key::KP0
#define TB_KEY_KP_1            ::Tabby::Key::KP1
#define TB_KEY_KP_2            ::Tabby::Key::KP2
#define TB_KEY_KP_3            ::Tabby::Key::KP3
#define TB_KEY_KP_4            ::Tabby::Key::KP4
#define TB_KEY_KP_5            ::Tabby::Key::KP5
#define TB_KEY_KP_6            ::Tabby::Key::KP6
#define TB_KEY_KP_7            ::Tabby::Key::KP7
#define TB_KEY_KP_8            ::Tabby::Key::KP8
#define TB_KEY_KP_9            ::Tabby::Key::KP9
#define TB_KEY_KP_DECIMAL      ::Tabby::Key::KPDecimal
#define TB_KEY_KP_DIVIDE       ::Tabby::Key::KPDivide
#define TB_KEY_KP_MULTIPLY     ::Tabby::Key::KPMultiply
#define TB_KEY_KP_SUBTRACT     ::Tabby::Key::KPSubtract
#define TB_KEY_KP_ADD          ::Tabby::Key::KPAdd
#define TB_KEY_KP_ENTER        ::Tabby::Key::KPEnter
#define TB_KEY_KP_EQUAL        ::Tabby::Key::KPEqual

#define TB_KEY_LEFT_SHIFT      ::Tabby::Key::LeftShift
#define TB_KEY_LEFT_CONTROL    ::Tabby::Key::LeftControl
#define TB_KEY_LEFT_ALT        ::Tabby::Key::LeftAlt
#define TB_KEY_LEFT_SUPER      ::Tabby::Key::LeftSuper
#define TB_KEY_RIGHT_SHIFT     ::Tabby::Key::RightShift
#define TB_KEY_RIGHT_CONTROL   ::Tabby::Key::RightControl
#define TB_KEY_RIGHT_ALT       ::Tabby::Key::RightAlt
#define TB_KEY_RIGHT_SUPER     ::Tabby::Key::RightSuper
#define TB_KEY_MENU            ::Tabby::Key::Menu

// #pragma once

// // From glfw3.h
// #define TB_KEY_SPACE              32
// #define TB_KEY_APOSTROPHE         39  /* ' */
// #define TB_KEY_COMMA              44  /* , */
// #define TB_KEY_MINUS              45  /* - */
// #define TB_KEY_PERIOD             46  /* . */
// #define TB_KEY_SLASH              47  /* / */
// #define TB_KEY_0                  48
// #define TB_KEY_1                  49
// #define TB_KEY_2                  50
// #define TB_KEY_3                  51
// #define TB_KEY_4                  52
// #define TB_KEY_5                  53
// #define TB_KEY_6                  54
// #define TB_KEY_7                  55
// #define TB_KEY_8                  56
// #define TB_KEY_9                  57
// #define TB_KEY_SEMICOLON          59  /* ; */
// #define TB_KEY_EQUAL              61  /* = */
// #define TB_KEY_A                  65
// #define TB_KEY_B                  66
// #define TB_KEY_C                  67
// #define TB_KEY_D                  68
// #define TB_KEY_E                  69
// #define TB_KEY_F                  70
// #define TB_KEY_G                  71
// #define TB_KEY_H                  72
// #define TB_KEY_I                  73
// #define TB_KEY_J                  74
// #define TB_KEY_K                  75
// #define TB_KEY_L                  76
// #define TB_KEY_M                  77
// #define TB_KEY_N                  78
// #define TB_KEY_O                  79
// #define TB_KEY_P                  80
// #define TB_KEY_Q                  81
// #define TB_KEY_R                  82
// #define TB_KEY_S                  83
// #define TB_KEY_T                  84
// #define TB_KEY_U                  85
// #define TB_KEY_V                  86
// #define TB_KEY_W                  87
// #define TB_KEY_X                  88
// #define TB_KEY_Y                  89
// #define TB_KEY_Z                  90
// #define TB_KEY_LEFT_BRACKET       91  /* [ */
// #define TB_KEY_BACKSLASH          92  /* \ */
// #define TB_KEY_RIGHT_BRACKET      93  /* ] */
// #define TB_KEY_GRAVE_ACCENT       96  /* ` */
// #define TB_KEY_WORLD_1            161 /* non-US #1 */
// #define TB_KEY_WORLD_2            162 /* non-US #2 */

// /* Function keys */
// #define TB_KEY_ESCAPE             256
// #define TB_KEY_ENTER              257
// #define TB_KEY_TAB                258
// #define TB_KEY_BACKSPACE          259
// #define TB_KEY_INSERT             260
// #define TB_KEY_DELETE             261
// #define TB_KEY_RIGHT              262
// #define TB_KEY_LEFT               263
// #define TB_KEY_DOWN               264
// #define TB_KEY_UP                 265
// #define TB_KEY_PAGE_UP            266
// #define TB_KEY_PAGE_DOWN          267
// #define TB_KEY_HOME               268
// #define TB_KEY_END                269
// #define TB_KEY_CAPS_LOCK          280
// #define TB_KEY_SCROLL_LOCK        281
// #define TB_KEY_NUM_LOCK           282
// #define TB_KEY_PRINT_SCREEN       283
// #define TB_KEY_PAUSE              284
// #define TB_KEY_F1                 290
// #define TB_KEY_F2                 291
// #define TB_KEY_F3                 292
// #define TB_KEY_F4                 293
// #define TB_KEY_F5                 294
// #define TB_KEY_F6                 295
// #define TB_KEY_F7                 296
// #define TB_KEY_F8                 297
// #define TB_KEY_F9                 298
// #define TB_KEY_F10                299
// #define TB_KEY_F11                300
// #define TB_KEY_F12                301
// #define TB_KEY_F13                302
// #define TB_KEY_F14                303
// #define TB_KEY_F15                304
// #define TB_KEY_F16                305
// #define TB_KEY_F17                306
// #define TB_KEY_F18                307
// #define TB_KEY_F19                308
// #define TB_KEY_F20                309
// #define TB_KEY_F21                310
// #define TB_KEY_F22                311
// #define TB_KEY_F23                312
// #define TB_KEY_F24                313
// #define TB_KEY_F25                314
// #define TB_KEY_KP_0               320
// #define TB_KEY_KP_1               321
// #define TB_KEY_KP_2               322
// #define TB_KEY_KP_3               323
// #define TB_KEY_KP_4               324
// #define TB_KEY_KP_5               325
// #define TB_KEY_KP_6               326
// #define TB_KEY_KP_7               327
// #define TB_KEY_KP_8               328
// #define TB_KEY_KP_9               329
// #define TB_KEY_KP_DECIMAL         330
// #define TB_KEY_KP_DIVIDE          331
// #define TB_KEY_KP_MULTIPLY        332
// #define TB_KEY_KP_SUBTRACT        333
// #define TB_KEY_KP_ADD             334
// #define TB_KEY_KP_ENTER           335
// #define TB_KEY_KP_EQUAL           336
// #define TB_KEY_LEFT_SHIFT         340
// #define TB_KEY_LEFT_CONTROL       341
// #define TB_KEY_LEFT_ALT           342
// #define TB_KEY_LEFT_SUPER         343
// #define TB_KEY_RIGHT_SHIFT        344
// #define TB_KEY_RIGHT_CONTROL      345
// #define TB_KEY_RIGHT_ALT          346
// #define TB_KEY_RIGHT_SUPER        347
// #define TB_KEY_MENU               348