#include "Canvas.hpp"

Canvas::Canvas(Renderer* renderer)
    : renderer(renderer)
{
    set_draw_func(sigc::mem_fun(*this, &Canvas::on_draw));
}

void Canvas::on_draw(
    const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{

    renderer->draw(cr, width, height);
}