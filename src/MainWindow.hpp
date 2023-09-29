#pragma once
#include <gtkmm.h>
#include "Canvas.hpp"

class MainWindow : public Gtk::ApplicationWindow {
public:
    MainWindow();
    ~MainWindow();
private:
    Canvas* area = nullptr;
    Renderer* renderer = nullptr;
    ColorScheme colorScheme;
    Gtk::Box PropertiesMenu();
    // Gtk::Box ColorPickerColumn(std::string title, ColorRGBA& color);
};
