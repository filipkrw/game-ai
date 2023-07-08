#ifndef RENDERER_H
#define RENDERER_H

class Renderer
{
protected:
    Renderer();

public:
    static Renderer *renderer_;
    static Renderer *GetInstance();

    Renderer(Renderer &other) = delete;
    void operator=(const Renderer &) = delete;

    Renderer *GetPointerAddress()
    {
        return renderer_;
    }
};

// Renderer *Renderer::renderer_ = nullptr;

#endif // RENDERER_H