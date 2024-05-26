#include "Font.h"
#include <pugixml.hpp>
#include <iostream>

Font::Font() : _height(12)
{
	// Load font as image. Use black to mask transparent area.
	sf::Image fontImage;
	fontImage.loadFromFile("Assets/Fonts/pmd_font.png");
	fontImage.createMaskFromColor(sf::Color(0x000000FF));

	// Store image as texture.
	_texture = new sf::Texture();
	_texture->loadFromImage(fontImage);
	_texture->setSmooth(false);

	// Initialise uv coordinates.
	for (int y = 0; y < 16; y++)
	{
		for (int x = 0; x < 16; x++)
		{
			// Calculate character index.
			int index = x + y * 16;

			// Initialise width.
			_width[index] = 12;

			// Initialise uv coordinates.
			_u[index] = _height * x;
			_v[index] = _height * y;
		}
	}

	// Load XML file containing character widths.
	pugi::xml_document fontTable;
	pugi::xml_parse_result result = fontTable.load_file("Assets/Fonts/pmd_font.xml");

	pugi::xml_node font = fontTable.child("Font");

	// Loop through each entry in the table, set character width from entry.
	for (pugi::xml_node table = font.child("Table"); table; table = table.next_sibling("Table"))
	{
		for (pugi::xml_node glyph = table.child("Char"); glyph; glyph = glyph.next_sibling("Char"))
		{
			_width[glyph.attribute("id").as_int()] = glyph.attribute("width").as_int();
		}
	}
}

Font::~Font()
{
	delete _texture;
	_texture = nullptr;
}

const int Font::GetCharWidth(const char& a) const
{
	// Convert ASCII char to integer using Windows - 1252
	int isochar = wchar_t(unsigned char(a));

	// Return the width of the current character, default to zero if a non-character.
	return (isochar < 256) ? _width[isochar] : 0;
}
const int Font::GetCharHeight() const
{
	return _height;
}

const sf::IntRect Font::GetTextureRect(const char& a) const
{
	// Convert ASCII char to integer using Windows-1252.
	int isochar = wchar_t(unsigned char(a));

	// Return the texture rect of the current character, default to zero if a non-character.
	int index =  (isochar < 256) ? isochar : 0;
	return sf::IntRect(_u[index], _v[index], _width[index], _height);
}
const sf::Texture* Font::GetTexture() const
{
	return _texture;
}