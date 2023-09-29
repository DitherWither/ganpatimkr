#pragma once
#include "Colors.hpp"
#include "Renderer.hpp"
#include <gtkmm.h>
#include <gtkmm/drawingarea.h>

class Canvas : public Gtk::DrawingArea {
public:
    Canvas(Renderer* renderer);

private:
    Renderer* renderer;
    void on_draw(
        const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
};
