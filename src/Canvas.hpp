#pragma once
#include <gtkmm.h>
#include <gtkmm/drawingarea.h>
#include "Colors.hpp"
#include "Renderer.hpp"

class Canvas : public Gtk::DrawingArea {
public:
    Canvas(Renderer* renderer);
private:
    Renderer* renderer;
    void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
};
