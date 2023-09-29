#include "MainWindow.hpp"
#include <adwaita.h>
#include <gtkmm.h>

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("io.github.ditherwither.ganpatimkr");

    // Makes the application use libadwaita theme instead of the default one
    // we are not using libadwaita in the main application, but this is needed
    // for dark mode support.
    adw_style_manager_set_color_scheme(
        adw_style_manager_get_default(), ADW_COLOR_SCHEME_DEFAULT);

    return app->make_window_and_run<MainWindow>(argc, argv);
}