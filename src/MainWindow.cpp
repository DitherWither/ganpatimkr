#include "MainWindow.hpp"
#include "ColorPickerColumn.hpp"

MainWindow::MainWindow()
{
    colorScheme.background.r = 0.141;
    colorScheme.background.g = 0.122;
    colorScheme.background.b = 0.192;

    colorScheme.d.r = 0.753;
    colorScheme.d.g = 0.11;
    colorScheme.d.b = 0.157;

    colorScheme.y.r = 0.18;
    colorScheme.y.g = 0.761;
    colorScheme.y.b = 0.494;

    colorScheme.p.r = 0.208;
    colorScheme.p.g = 0.518;
    colorScheme.p.b = 0.894;

    colorScheme.mukut.r = 0.965;
    colorScheme.mukut.g = 0.827;
    colorScheme.mukut.b = 0.176;

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

    // This causes a "memory leak", but the instances are needed until the
    // window closes so there is no point in writing code to free their memory,
    // and it adds a bunch of additional complexity i'd rather avoid

    ColorPickerColumn* bgPicker = new ColorPickerColumn(
        "Background Color", &colorScheme.background, area);
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

MainWindow::~MainWindow() { }