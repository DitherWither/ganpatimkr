# GanpatiMkr

A project I made for the pratham code competition conducted in DYP collage, Kasaba Bawada in 2023

This won the 1st prize for the C/C++ cluster

It uses gtkmm for the UI, and cairo for the graphics

It is using meson as the build system.

The entire project is written in C++

While it has libadwaita as a dependency, it is only used for the theme,
and you can easily comment this line out form main.cpp to remove the dependency:
```diff
-#define USE_LIBADWAITA
+// #define USE_LIBADWAITA
```

And then, simply edit `meson.build` to stop linking to it 

## Cut content

Here are some features I wanted to add, but couldn't due to time constraints

 - Export as svg
 - Scaling
 - Configurable border around the entire image
 - Background Patterns

## How to build

Install gtk, gtkmm, and libadwaita using your package manager.

Then, with the working directory set as the root of this project,
run 

```sh
meson setup build
cd build
meson compile
```

Now, it should have generated a `ganpatimkr` executable

Now, run it with
```sh
./ganpatimkr
```