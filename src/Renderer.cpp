#include "Renderer.h"

Renderer *Renderer::renderer_ = nullptr;

Renderer *Renderer::GetInstance()
{
    if (renderer_ == nullptr)
    {
        renderer_ = new Renderer();
    }
    return renderer_;
}

Renderer::Renderer()
{
}
