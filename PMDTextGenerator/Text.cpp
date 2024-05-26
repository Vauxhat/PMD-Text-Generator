#include "Text.h"
#include "Font.h"

#include <SFML/Graphics.hpp>

Text::Text()
{
	_currentString = "";
	_targetString = "";
	_alignment = Alignment::LEFT;
}
Text::~Text()
{
	// Default deconstructor.
}

void Text::FixedUpdate()
{
	// Check if current string matches target string.
	if (_currentString.size() < _targetString.size())
	{
		char currentChar;

		do // Keep adding characters to string until a non-special character is found.
		{
			// Add current character to string.
			currentChar = _targetString[_currentString.size()];
			_currentString.push_back(currentChar);
		} while (currentChar == '<' || currentChar == '>' || currentChar == '\t');
	}
}

void Text::Render(sf::RenderWindow* renderer, const sf::Vector2f& position, const sf::Color& color, const bool& specialText)
{
	// Set offset for current draw position.
	sf::Vector2f offset(0, 0);
	offset.x = GetLineWidth(0);

	// Initialise the character sprite.
	sf::Sprite glyph;
	glyph.setTexture(*_font->GetTexture());
	glyph.setColor(color);

	int colorID = 0;

	// Loop through each letter in the string.
	for (int i = 0; i < _currentString.length(); i++)
	{
		// Check for special characters.
		if (_currentString[i] == '\t')
		{
			// New line character, add to y offset.
			offset.x = GetLineWidth(i + 1);
			offset.y += 13;
			continue;
		}
		else if (_currentString[i] == '<')
		{
			// Special colour character, increment colour value.
			if (specialText) colorID++;
			continue;
		}
		else if (_currentString[i] == '>')
		{
			// Special colour character, decrement colour value.
			if (specialText) colorID--;
			continue;
		}

		// Get the texture rect for the character. Update position.
		glyph.setTextureRect(_font->GetTextureRect(_currentString[i]));
		glyph.setPosition(position + offset);

		// Set text colour based on colour ID.
		switch (colorID)
		{
		default:
			// Default colour.
			glyph.setColor(color); break;
		case 1:
			// Yellow text, partner.
			glyph.setColor(sf::Color(0xFFFF00FF)); break;
		case 2:
			// Blue text, player name.
			glyph.setColor(sf::Color(0x009AFBFF)); break;
		case 3:
			// Blue text, non-player name.
			glyph.setColor(sf::Color(0x00FBFBFF)); break;
		case 4:
			// Orange text, location.
			glyph.setColor(sf::Color(0xFBC361FF)); break;
		case 5:
			// Light pink text, items.
			glyph.setColor(sf::Color(0xFBCBCBFF)); break;
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
	_currentString = string;
	_targetString = string;
}
void Text::SetString(const std::string& current, const std::string& target)
{
	_currentString = current;
	_targetString = target;
}

const int Text::GetLineWidth(const int& start)
{
	int width = 0;

	// Check if text is left aligned.
	if (_alignment == Alignment::LEFT)
	{
		// Offset is always zero for left alignemnt text.
		return width;
	}
	else
	{
		// Loop through each character.
		for (int i = start; i < _targetString.length(); i++)
		{
			// Check for special characters.
			if (_targetString[i] == '\t')
			{
				// New line, stop counting.
				break;
			}
			else if (_targetString[i] == '<' || _targetString[i] == '>')
			{
				// Colour characters, ignore.
				continue;
			}
			else
			{
				// Add character length to total width.
				width += _font->GetCharWidth(_targetString[i]);
			}
		}

		// Calculate final offset based on alignment.
		if (_alignment == Alignment::CENTRE)
		{
			// Centre alignment.
			width = 0 - width / 2;
		}
		else
		{
			// Right alignment.
			width = 0 - width;
		}
	}

	// Return output.
	return width;
}

void Text::SetAlignment(const Alignment& alignment)
{
	_alignment = alignment;
}