#include "Renderer.hpp"

void Renderer::draw(
    const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
    this->width = width;
    this->height = height;

    cr->set_line_width(4.0);
    drawBackground(cr);

    drawD(cr);
    drawY(cr);
    drawP(cr);
    drawMukut(cr);
}

// Most of the points were obtained using a graph paper,
// some of the control points for curves were obtained
// via a bezier curve visualizer i found on desmos

void Renderer::drawD(const Cairo::RefPtr<Cairo::Context>& cr)
{
    colorScheme.d.setAsCurrent(cr);

    moveToCenter(cr);
    cr->rel_move_to(-160, -20);
    cr->rel_curve_to(40, -40, 108, 68, 20, 40);
    cr->rel_line_to(-20, -40);
    cr->stroke();
}

void Renderer::drawY(const Cairo::RefPtr<Cairo::Context>& cr)
{
    colorScheme.y.setAsCurrent(cr);

    moveToCenter(cr);
    cr->rel_move_to(-100.0, -50.0);
    cr->rel_line_to(88, 132);
    cr->rel_curve_to(10, 20, -20, 20, -20, 5);

    cr->rel_move_to(40, -137);
    cr->rel_line_to(-50, 88);

    cr->stroke();
}

void Renderer::drawP(const Cairo::RefPtr<Cairo::Context>& cr)
{
    colorScheme.p.setAsCurrent(cr);

    moveToCenter(cr);
    cr->rel_move_to(40, -40);
    cr->rel_line_to(-50, 88);
    cr->rel_move_to(50, -88);

    cr->rel_curve_to(40, -10, 80, 80, -35, 60);
    cr->stroke();
};

void Renderer::drawMukut(const Cairo::RefPtr<Cairo::Context>& cr)
{
    colorScheme.mukut.setAsCurrent(cr);

    moveToCenter(cr);
    cr->rel_move_to(-100, -80);
    cr->rel_line_to(100, 0);

    cr->rel_move_to(-90, -20);
    cr->rel_line_to(80, 0);

    cr->rel_move_to(-70, -20);
    cr->rel_line_to(60, 0);

    cr->rel_move_to(-10, -20);
    cr->rel_line_to(0, -20);

    cr->rel_curve_to(0, -30, -40, -30, -40, 0);
    cr->rel_line_to(0, 20);

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