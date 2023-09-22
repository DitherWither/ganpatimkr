#include "MainWindow.hpp"

MainWindow::MainWindow()
{
    // colorScheme.background.r = 1.0;
    colorScheme.d.r = 1.0;
    colorScheme.y.g = 1.0;
    colorScheme.y.b = 1.0;

    renderer = new Renderer(colorScheme);
    area = new Canvas(renderer);
    
    set_title("GanpatiMkr"); 
    set_default_size(800, 600);

    set_child(*area);
    area->show();
}

MainWindow::~MainWindow() {

}