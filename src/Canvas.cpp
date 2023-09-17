#include "Canvas.hpp"

namespace ganpatimkr {
Canvas::Canvas() { set_draw_func(sigc::mem_fun(*this, &Canvas::on_draw)); }

void Canvas::on_draw(
    const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
    cr->set_source_rgb(1., .5, .0);
    cr->set_line_width(3);

    cr->move_to(11, 11);
    cr->line_to(111, 111);
    cr->stroke();
}
}