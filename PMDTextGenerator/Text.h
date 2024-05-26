#ifndef _TEXT_H
#define _TEXT_H

#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

class Font;
namespace sf { class RenderWindow; }

enum class Alignment
{
	LEFT,
	CENTRE,
	RIGHT
};

class Text
{
private:
	std::string _currentString;
	std::string _targetString;
	Font* _font;
	Alignment _alignment;

public:
	Text();
	~Text();

	void FixedUpdate();
	void Render(sf::RenderWindow* renderer, const sf::Vector2f& position, const sf::Color& color = sf::Color::White, const bool& specialText = true);

	void SetFont(Font* font);
	void SetString(const std::string& string);
	void SetString(const std::string& current, const std::string& target);

	const int GetLineWidth(const int& start);

	void SetAlignment(const Alignment& alignment);
};

#endif
