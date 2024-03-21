#include "InputManager.h"
#include <SFML/Graphics.hpp>

InputManager::InputManager()
{
	// Initials keys.
	for (int i = 0; i < 256; i++)
	{
		_keys[i] = false;
		_prevKeys[i] = false;
	}
}

void InputManager::Update()
{
	for (int i = 0; i < 256; i++)
	{
		_prevKeys[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i));
		//_keys[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i));
	}
}

const bool InputManager::GetKey(const sf::Keyboard::Key& key) const
{
	return _keys[int(key)];
}
const bool InputManager::GetKey(const int& key) const
{
	return _keys[key];
}
void InputManager::SetKey(const sf::Keyboard::Key& key, const bool& state)
{
	_keys[int(key)] = state;
}
void InputManager::SetKey(const int& key, const bool& state)
{
	_keys[key] = state;
}

const bool InputManager::GetKeyPressed(const sf::Keyboard::Key& key) const
{
	if (sf::Keyboard::isKeyPressed(key) && !_prevKeys[int(key)]) return true;
	else return false;
}
const bool InputManager::GetKeyReleased(const sf::Keyboard::Key& key) const
{
	if (!sf::Keyboard::isKeyPressed(key) && _prevKeys[int(key)]) return true;
	else return false;
}