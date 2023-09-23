#pragma once
#include <cairomm/cairomm.h>
#include "Colors.hpp"

class Renderer {
public:
    inline Renderer(ColorScheme& colorScheme) : colorScheme(colorScheme) {}
    void draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height);
private:
    int width;
    int height;
    ColorScheme& colorScheme;

    void drawBackground(const Cairo::RefPtr<Cairo::Context>& cr);
    void drawD(const Cairo::RefPtr<Cairo::Context>& cr);
    void drawY(const Cairo::RefPtr<Cairo::Context>& cr);
    void moveToCenter(const Cairo::RefPtr<Cairo::Context>& cr);
};