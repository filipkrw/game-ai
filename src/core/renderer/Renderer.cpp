#include "Renderer.h"

// Define the static members
Renderer *Renderer::instance = nullptr;
std::mutex Renderer::mtx;

Renderer::Renderer()
{
    window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game AI");
    window->setFramerateLimit(144);
}

Renderer *Renderer::getInstance()
{
    if (instance == nullptr)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance == nullptr)
        {
            instance = new Renderer();
        }
    }
    return instance;
}

sf::RenderWindow *Renderer::GetWindow()
{
    return window;
}

// Remember to delete the window when done
Renderer::~Renderer()
{
    delete window;
}
