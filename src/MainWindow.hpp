#pragma once
#include <gtkmm.h>
#include "Canvas.hpp"

namespace ganpatimkr {

class MainWindow : public Gtk::ApplicationWindow {
public:
    MainWindow();

private:
    Canvas area;
};
}