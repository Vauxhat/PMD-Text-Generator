#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

#include <SFML/Window/Keyboard.hpp>

//enum class KeyboardKey
//{
//	BACKSPACE = 8,
//	TAB,
//	NUMPAD_5 = 12,
//	ENTER,
//	SHIFT = 16,
//	CTRL,
//	ALT,
//	PAUSE,
//	CAPS_LOCK,
//	ESCAPE = 27,
//	SPACE = 32,
//	PAGE_UP,
//	PAGER_DOWN,
//	END,
//	HOME,
//	LEFT,
//	UP,
//	RIGHT,
//	DOWN,
//	PRINT_SCREEN = 44,
//	INSERT,
//	DELETE,
//	ZERO = 48,
//	ONE,
//	TWO,
//	THREE,
//	FOUR,
//	FIVE,
//	SIX,
//	SEVEN,
//	EIGHT,
//	NINE,
//	A = 65,
//	B,
//	C,
//	D,
//	E,
//	F,
//	G,
//	H,
//	I,
//	J,
//	K,
//	L,
//	M,
//	N,
//	O,
//	P,
//	Q,
//	R,
//	S,
//	T,
//	U,
//	V,
//	W,
//	X,
//	Y,
//	Z,
//	LEFT_WIN,
//	RIGHT_WIN,
//	POPUP,
//	NUMPAD_ZERO = 96,
//	NUMPAD_ONE,
//	NUMPAD_TWO,
//	NUMPAD_THREE,
//	NUMPAD_FOUR,
//	NUMPAD_FIVE,
//	NUMPAD_SIX,
//	NUMPAD_SEVEN,
//	NUMPAD_EIGHT,
//	NUMPAD_NINE,
//	NUMPAD_STAR,
//	NUMPAD_PLUS,
//	NUMPAD_MINUS = 109,
//	NUMPAD_DOT,
//	NUMPAD_SLASH,
//	F1,
//	F2,
//	F3,
//	F4,
//	F5,
//	F6,
//	F7,
//	F8,
//	F9,
//	F10,
//	F11,
//	F12,
//	NUM_LOCK = 144,
//	SCROLL_LOCK,
//	LEFT_SHIFT = 160,
//	RIGHT_SHIFT,
//	LEFT_CTRL,
//	RIGHT_CTRL
//};

class InputManager
{
private:
	bool _keys[256];
	bool _prevKeys[256];

public:
	InputManager();

	void Update();

	const bool GetKey(const sf::Keyboard::Key& key) const;
	const bool GetKey(const int& key) const;
	void SetKey(const sf::Keyboard::Key& key, const bool& state);
	void SetKey(const int& key, const bool& state);

	const bool GetKeyPressed(const sf::Keyboard::Key& key) const;
	const bool GetKeyReleased(const sf::Keyboard::Key& key) const;
};

#endif
