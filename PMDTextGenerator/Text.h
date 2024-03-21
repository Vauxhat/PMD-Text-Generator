#ifndef _TEXT_H
#define _TEXT_H

#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

class Font;
namespace sf { class RenderWindow; }

class Text
{
private:
	std::string _string;
	Font* _font;

public:
	Text();
	~Text();

	void Render(sf::RenderWindow* renderer, const sf::Vector2f& position, const sf::Color& color = sf::Color::White, const bool& specialText = true);

	void SetFont(Font* font);
	void SetString(const std::string& string);
};

#endif
