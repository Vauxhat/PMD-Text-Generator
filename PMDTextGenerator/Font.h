#ifndef _FONT_LOADER_H
#define _FONT_LOADER_H

#include <SFML/Graphics.hpp>

class Font
{
private:
	sf::Texture* _texture;

	int _height;
	int _width[256];

	int _u[256];
	int _v[256];

public:
	Font();
	~Font();

	const int GetCharWidth(const char& a) const;
	const int GetCharHeight() const;

	const sf::IntRect GetTextureRect(const char& a) const;
	const sf::Texture* GetTexture() const;
};

#endif