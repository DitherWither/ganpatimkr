#pragma once
#include <gtkmm/drawingarea.h>

struct ColorRGBA {
    double r = 0.0;
    double g = 0.0;
    double b = 0.0;
    double a = 1.0;

    inline void setAsCurrent(const Cairo::RefPtr<Cairo::Context>& cr)
    {
        cr->set_source_rgba(r, g, b, a);
    }

    inline Gdk::RGBA toGdkRGBA()
    {
        Gdk::RGBA col;
        col.set_red(r);
        col.set_green(g);
        col.set_blue(b);
        col.set_alpha(a);
        return col;
    }
};

class ColorScheme {
public:
    ColorRGBA background;
    ColorRGBA d;
    ColorRGBA y;
    ColorRGBA p;
    ColorRGBA mukut;
};
