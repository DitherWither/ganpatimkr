#include "MainWindow.hpp"
#include <gtkmm.h>

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("io.github.ditherwither.ganpatimkr");

    return app->make_window_and_run<ganpatimkr::MainWindow>(argc, argv);
}