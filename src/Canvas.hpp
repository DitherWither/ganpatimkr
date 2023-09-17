#pragma once
#include <gtkmm.h>
#include <gtkmm/drawingarea.h>

namespace ganpatimkr {

class Canvas : public Gtk::DrawingArea {
public:
    Canvas();
protected:
    void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
};

};