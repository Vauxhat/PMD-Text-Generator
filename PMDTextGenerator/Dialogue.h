#ifndef _DIALOGUE_H
#define _DIALOGUE_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Text.h"
#include "Font.h"

class Dialogue
{
private:
	enum Portrait
	{
		NORMAL,
		HAPPY,
		PAIN,
		ANGRY,
		WORRIED,
		SAD,
		CRYING,
		SHOUTING,
		TEARY_EYED,
		DETERMINED,
		JOYOUS,
		INSPIRED,
		SURPRISED,
		DIZZY,
		SIGH = 16,
		STUNNED
	};

private:
	Font _font;
	Text _text;

	std::string _currentString;
	std::string _targetString;

	sf::Texture* _dialogueTexture;
	sf::Texture* _portraitTexture;

	sf::IntRect _portraitRect[5 * 8];

public:
	Dialogue();
	~Dialogue();

	void Init();

	void Render(sf::RenderWindow* renderer);
	void Update(const float& deltaTime);
	void FixedUpdate(const float& fixedTime);
};

#endif
