#include "MainWindow.hpp"

namespace ganpatimkr {
MainWindow::MainWindow()
{
    set_title("GanpatiMkr");
    set_default_size(800, 600);

    set_child(area);
    area.show();
}
}