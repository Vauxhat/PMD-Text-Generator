#include "Dialogue.h"

// Function declarations.
void RenderBox(sf::RenderWindow* renderer, sf::Texture* texture, const sf::Vector2f& position, const sf::Vector2f& size, const int& offset);

Dialogue::Dialogue()
{
	// Create texture.
	_dialogueTexture = new sf::Texture();
	_portraitTexture = new sf::Texture();

	// Initialise target string.
	_targetString = "<Cinderace>: Let's try our best today, \tlike always!";
	_currentString = "<Cinderace>: ";

	// Initialise text.
	_text.SetFont(&_font);
	_text.SetString(_currentString);

	// Initialise portrait UVs.
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			_portraitRect[x + y * 5] = sf::IntRect(x * 40, y * 40, 40, 40);
		}
	}
}
Dialogue::~Dialogue()
{
	delete _dialogueTexture;
	_dialogueTexture = nullptr;

	delete _portraitTexture;
	_portraitTexture = nullptr;
}

void Dialogue::Init()
{
	// Load UI elements. Use colour mask to hide transparent elements.
	sf::Image frame;
	frame.loadFromFile("Assets/Textures/frame_b0.png");
	frame.createMaskFromColor(sf::Color(0, 120, 144));

	// Set texture using masked image.
	_dialogueTexture->loadFromImage(frame);
	_dialogueTexture->setSmooth(false);

	// Load portrait texture.
	_portraitTexture->loadFromFile("Assets/Textures/portrait-0815.png");
}

void Dialogue::FixedUpdate(const float& fixedTime)
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
		} 
		while (currentChar == '<' || currentChar == '>' || currentChar == '\t');

		// Update text from string.
		_text.SetString(_currentString);
	}
}

void Dialogue::Render(sf::RenderWindow* renderer)
{
	// Render Dialogue box.
	RenderBox(renderer, _dialogueTexture, sf::Vector2f(8, 128), sf::Vector2f(240, 56), 16);

	// Render Portrait box.
	RenderBox(renderer, _dialogueTexture, sf::Vector2f(8, 64), sf::Vector2f(56, 56), 80);

	// Render text shadow.
	_text.Render(renderer, sf::Vector2f(21, 138), sf::Color::Black, false);
	_text.Render(renderer, sf::Vector2f(20, 139), sf::Color::Black, false);

	// Render text.
	_text.Render(renderer, sf::Vector2f(20, 138));

	// Create sprite for portrait. Set frame based on desired emotion.
	sf::Sprite portrait;
	portrait.setTexture(*_portraitTexture);
	portrait.setTextureRect(_portraitRect[Portrait::HAPPY]);
	portrait.setPosition(16, 72);

	// Render portrait.
	renderer->draw(portrait);
}

// Useful function for rendering UI boxes. Frame type is modified using offset.
void RenderBox(sf::RenderWindow* renderer, sf::Texture* texture, const sf::Vector2f& position, const sf::Vector2f& size, const int& offset)
{
	// Create sprites
	sf::Sprite borderTopLeft(*texture, sf::IntRect(offset, 0, 8, 8));
	sf::Sprite borderTopRight(*texture, sf::IntRect(offset + 16, 0, 8, 8));
	sf::Sprite borderBottomLeft(*texture, sf::IntRect(offset + 40, 0, 8, 8));
	sf::Sprite borderBottomRight(*texture, sf::IntRect(offset + 56, 0, 8, 8));

	sf::Sprite borderTop(*texture, sf::IntRect(offset + 8, 0, 8, 8));
	sf::Sprite borderBottom(*texture, sf::IntRect(offset + 48, 0, 8, 8));
	sf::Sprite borderLeft(*texture, sf::IntRect(offset + 24, 0, 8, 8));
	sf::Sprite borderRight(*texture, sf::IntRect(offset + 32, 0, 8, 8));

	sf::Sprite background(*texture, sf::IntRect(8, 0, 8, 8));

	// Draw first top.
	borderTopLeft.setPosition(position);
	renderer->draw(borderTopLeft);

	borderTop.setPosition(position + sf::Vector2f(8.f, 0.f));
	borderTop.setScale((size.x - 16) / 8.f, 1.f);
	renderer->draw(borderTop);

	borderTopRight.setPosition(position + sf::Vector2f(size.x - 8.f, 0.f));
	renderer->draw(borderTopRight);

	// Draw middle row.
	borderLeft.setPosition(position + sf::Vector2f(0.f, 8.f));
	borderLeft.setScale(1.f, (size.y - 16) / 8.f);
	renderer->draw(borderLeft);

	background.setPosition(position + sf::Vector2f(8.f, 8.f));
	background.setScale((size.x - 16) / 8.f, (size.y - 16) / 8.f);
	renderer->draw(background);

	borderRight.setPosition(position + sf::Vector2f(size.x - 8.f, 8.f));
	borderRight.setScale(1.f, (size.y - 16) / 8.f);
	renderer->draw(borderRight);

	// Draw bottom row.
	borderBottomLeft.setPosition(position + sf::Vector2f(0.f, size.y - 8.f));
	renderer->draw(borderBottomLeft);

	borderBottom.setPosition(position + sf::Vector2f(8.f, size.y - 8.f));
	borderBottom.setScale((size.x - 16) / 8.f, 1.f);
	renderer->draw(borderBottom);

	borderBottomRight.setPosition(position + sf::Vector2f(size.x - 8.f, size.y - 8.f));
	renderer->draw(borderBottomRight);
}