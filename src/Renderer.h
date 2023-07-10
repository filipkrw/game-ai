#include <SFML/Graphics.hpp>
#include <mutex>

class Renderer
{
private:
    static Renderer *instance;
    static std::mutex mtx;
    sf::RenderWindow *window;

    // Private constructor so that no objects can be created
    Renderer();

public:
    // Delete copy constructor and assignment operator
    Renderer(Renderer &other) = delete;
    void operator=(const Renderer &) = delete;

    static Renderer *getInstance();

    sf::RenderWindow *GetWindow();

    // Remember to delete the window when done
    ~Renderer();
};
