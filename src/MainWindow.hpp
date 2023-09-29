#pragma once
#include "Canvas.hpp"
#include <gtkmm.h>

class MainWindow : public Gtk::ApplicationWindow {
public:
    MainWindow();
    ~MainWindow();

private:
    Canvas* area = nullptr;
    Renderer* renderer = nullptr;
    ColorScheme colorScheme;
    Gtk::Box PropertiesMenu();
};
