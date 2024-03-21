#include <SFML/Graphics.hpp>

#include "Dialogue.h"
#include "InputManager.h"

#include <iostream>
#include <sstream>

// Function declarations.
void ResizeEvent(sf::RenderWindow* window, const int& width, const int& height);

int main()
{
    sf::RenderWindow window(sf::VideoMode(256, 192), "Mystery Dungeon Text Generator");
    //window.setFramerateLimit(60);

    InputManager inputManager;
    sf::Clock clock;

    // Create dialogue window, initialise.
    Dialogue dialogue;
    dialogue.Init();

    // Initialise global variables.
    float elapsedTime = 0.0f;
    bool captureFrame = false;
    int frameCount = 0;
    float fixedTime = 1.f / 60.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::Resized:
                ResizeEvent(&window, event.size.width, event.size.height);
                break;
            }
        }

        // Calculate current frame time, updated elapsed time.
        float deltaTime = clock.getElapsedTime().asSeconds();
        elapsedTime += deltaTime;
        clock.restart();

        // Update inpute manager.
        inputManager.Update();

        // Check if elapsed time is greater than fixed time.
        if (elapsedTime >= fixedTime)
        {
            // Perform fixed update
            dialogue.FixedUpdate(fixedTime);
            //captureFrame = true;
            frameCount++;

            // Reset elapsed time.
            elapsedTime = 0.0f;
        }

        // Clear window from previous frame.
        window.clear(sf::Color(0xFF0000FF));

        // Render current frame.
        dialogue.Render(&window);

        //Send current frame to display.
        window.display();

        // Check if frame should be captured.
        if (captureFrame && frameCount <= std::string(" Let's try our best today, like always!").size())
        {
            // Get screen texture from window, copy to image.
            sf::Texture screenTexture;
            screenTexture.create(window.getSize().x, window.getSize().y);
            screenTexture.update(window);
            screenTexture.setSmooth(false);
            sf::Image image = screenTexture.copyToImage();

            // Create numbered string for current frame.
            std::ostringstream string;
            string.width(3);
            string.fill('0');
            string << frameCount;

            // Save image to file.
            image.saveToFile(std::string("Capture/" + string.str() + ".png"));

            // Reset frame capture.
            captureFrame = false;
        }
    }

    return 0;
}

void ResizeEvent(sf::RenderWindow* window, const int& width, const int& height)
{
    // Calculate new and old aspect ratios.
    float newAspectRatio = (float)width / (float)height;
    float oldAspectRatio = 256.f / 192.f;

    sf::Vector2f viewSize;

    // Determine if new aspect ratio is greater or less than old aspect ratio.
    if (newAspectRatio > oldAspectRatio)
    {
        // Width is greater than height, scale by height.
        viewSize = sf::Vector2f(192.f * newAspectRatio, 192.f);
    }
    else
    {
        // Height is greater than width, scale by width.
        viewSize = sf::Vector2f(256.f, 256.f / newAspectRatio);
    }

    // Update render view.
    window->setView(sf::View(sf::Vector2f(128.f, 96.f), viewSize));
}