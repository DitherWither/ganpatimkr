#pragma once
#include "Canvas.hpp"
#include "Colors.hpp"
#include "gtkmm/widget.h"
#include "sigc++/functors/mem_fun.h"
#include <gtkmm.h>
#include <iostream>

class ColorPickerColumn : public Gtk::Box {
    Gtk::ColorButton colorButton;
    Gtk::Label label;
    ColorRGBA* color;
    Gtk::Widget* drawArea;

public:
    inline ColorPickerColumn(std::string title, ColorRGBA* color, Gtk::Widget* drawArea)
        : label(Gtk::Label(title))
        , color(color)
        , drawArea(drawArea)
    {
        label.set_hexpand(true);
        label.set_halign(Gtk::Align::START);

        Gdk::RGBA rgba = color->toGdkRGBA();
        colorButton.set_rgba(rgba);
        colorButton.signal_color_set().connect(
            sigc::mem_fun(*this, &ColorPickerColumn::onColorChange));

        append(label);
        append(colorButton);
    }

private:
    void onColorChange()
    {
        auto newColor = colorButton.get_rgba();
        color->r = newColor.get_red();
        color->g = newColor.get_green();
        color->b = newColor.get_blue();
        color->a = newColor.get_alpha();
        drawArea->queue_draw();
    }
};