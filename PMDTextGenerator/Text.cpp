#include "Text.h"
#include "Font.h"

#include <SFML/Graphics.hpp>

Text::Text()
{
	_string = "";
}
Text::~Text()
{
	// Default deconstructor.
}

void Text::Render(sf::RenderWindow* renderer, const sf::Vector2f& position, const sf::Color& color, const bool& specialText)
{
	// Set offset for current draw position.
	sf::Vector2f offset(0, 0);

	// Initialise the character sprite.
	sf::Sprite glyph;
	glyph.setTexture(*_font->GetTexture());
	glyph.setColor(color);

	int colorID = 0;

	// Loop through each letter in the string.
	for (int i = 0; i < _string.length(); i++)
	{
		// Check for special characters.
		if (_string[i] == '\t')
		{
			// New line character, add to y offset.
			offset.x = 0;
			offset.y += 13;
			continue;
		}
		else if ( _string[i] == '<')
		{
			// Special colour character, increment colour value.
			if (specialText) colorID++;
			continue;
		}
		else if (_string[i] == '>')
		{
			// Special colour character, decrement colour value.
			if (specialText) colorID--;
			continue;
		}

		// Get the texture rect for the character. Update position.
		glyph.setTextureRect(_font->GetTextureRect(_string[i]));
		glyph.setPosition(position + offset);

		// Set text colour based on colour ID.
		switch (colorID)
		{
		default:
			// Default colour.
			glyph.setColor(color); break;
		case 1:
			// Yellow text, speaker.
			glyph.setColor(sf::Color(0xFFFF00FF)); break;
		case 2:
			// Blue text, player name.
			glyph.setColor(sf::Color(0x009AFBFF)); break;
		}

		// Draw current glyph.
		renderer->draw(glyph);

		// Update x offset using character width.
		offset.x += glyph.getTextureRect().width;
	}
}

void Text::SetFont(Font* font)
{
	_font = font;
}

void Text::SetString(const std::string& string)
{
	_string = string;
}