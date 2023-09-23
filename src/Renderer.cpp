#include "Renderer.hpp"

void Renderer::draw(
    const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
    this->width = width;
    this->height = height;

    drawBackground(cr);

    drawD(cr);

    drawY(cr);
}

void Renderer::drawD(const Cairo::RefPtr<Cairo::Context>& cr)
{
    moveToCenter(cr);
    cr->rel_move_to(-160.0, -20.0);
    colorScheme.d.setAsCurrent(cr);
    cr->rel_line_to(60, 40);
    // cr->rel_curve_to(10, -10, 40, -10, 60, 40);
    cr->rel_curve_to(20, -80, -80, -90, -60, -40);
    cr->stroke();
}

void Renderer::drawY(const Cairo::RefPtr<Cairo::Context>& cr)
{
    moveToCenter(cr);
    cr->rel_move_to(-130.0, -60.0);
    colorScheme.y.setAsCurrent(cr);
    cr->rel_curve_to(110, 30, 40, 180, 10, 210);
    cr->stroke();

    // back to src
    moveToCenter(cr);
    cr->rel_move_to(10, -80);
    cr->rel_curve_to(-90, 60, 0, 100, -120, 250);
    cr->stroke();
}

void Renderer::drawBackground(const Cairo::RefPtr<Cairo::Context>& cr)
{
    colorScheme.background.setAsCurrent(cr);
    cr->rectangle(0, 0, width, height);
    cr->fill();
}

void Renderer::moveToCenter(const Cairo::RefPtr<Cairo::Context>& cr)
{
    cr->move_to(width / 2, height / 2);
}