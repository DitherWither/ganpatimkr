#include "MainWindow.hpp"
#include "ColorPickerColumn.hpp"

MainWindow::MainWindow()
{
    // colorScheme.background.r = 1.0;
    colorScheme.d.r = 1.0;
    colorScheme.y.g = 1.0;
    colorScheme.p.b = 1.0;

    colorScheme.mukut.r = 1.0;
    colorScheme.mukut.g = 1.0;

    renderer = new Renderer(colorScheme);
    area = new Canvas(renderer);

    set_title("GanpatiMkr");
    set_default_size(800, 600);

    Gtk::Box main_box;
    main_box.set_orientation(Gtk::Orientation::HORIZONTAL);
    main_box.append(*area);

    Gtk::Box properties_box = PropertiesMenu();
    main_box.append(properties_box);

    set_child(main_box);
    area->show();
}

Gtk::Box MainWindow::PropertiesMenu()
{
    // Outer box
    Gtk::Box box;
    box.set_orientation(Gtk::Orientation::VERTICAL);
    box.set_margin(8);

    Gtk::Label titleLabel("<span size=\"xx-large\"><b>Properties</b></span>");
    titleLabel.set_use_markup(true);
    box.append(titleLabel);

    ColorPickerColumn* bgPicker
        = new ColorPickerColumn("Background Color", &colorScheme.background, area);
    box.append(*bgPicker);

    ColorPickerColumn* mukutPicker
        = new ColorPickerColumn("Mukut Color", &colorScheme.mukut, area);
    box.append(*mukutPicker);

    ColorPickerColumn* dPicker
        = new ColorPickerColumn("Color 1", &colorScheme.d, area);
    box.append(*dPicker);

    ColorPickerColumn* yPicker
        = new ColorPickerColumn("Color 2", &colorScheme.y, area);
    box.append(*yPicker);

    ColorPickerColumn* pPicker
        = new ColorPickerColumn("Color 3", &colorScheme.p, area);
    box.append(*pPicker);

    return box;
}

// Gtk::Box MainWindow::ColorPickerColumn(std::string title, ColorRGBA& color)
// {
//     Gtk::Box box;
//     box.set_orientation(Gtk::Orientation::HORIZONTAL);

//     Gtk::Label label(title);
//     label.set_hexpand(true);
//     label.set_halign(Gtk::Align::START);
//     box.append(label);

//     Gtk::ColorButton colorButton;
//     Gdk::RGBA rgba = color.toGdkRGBA();
//     colorButton.set_rgba(rgba);
//     // colorButton.signal_color_activated().connect([](const Gdk::RGBA&
//     newColor){
//     //     color.r = newColor.get_red();
//     //     color.g =
//     // });

//     box.append(colorButton);

//     return box;
// }

MainWindow::~MainWindow() { }