# Learn Gtk

Source: [Gtk - Getting Started](https://docs.gtk.org/gtk4/getting_started.html)

**Install `gtk4`**

- In archlinux: `sudo pacman -S gtk4`

**_Read to start again?_**

- Start reading from [here](https://docs.gtk.org/gtk4/*getting_started.html#custom-drawing) in _Getting Started_ guide of gtk.
- [Beautiful Buttons with GTK Guide](https://wiki.gnome.org/HowDoI/Buttons)
- [Video from distrotube](https://youtu.be/gkyd7Uv6uJ8)
- [Gtk3 to Gtk4 Migration Guide](https://docs.gtk.org/gtk4/migrating-3to4.html)

**Formatting C code**

- Use `clangFormatWatchAll` to watch for formatting of all `.c` files in the project and run the resulting gtk app build.

**Running files**:

- Watch for files while building gtk app -

  ```bash
    # Use gmon to watch for gtk building
    gmon filename.c

    #type gmon
    #Output
    gtkmon ()
    {
      nodemon - w "$@" - x "gcc -o .binary $@ `pkg-config --cflags --libs gtk4` && ./.binary"
    }
  ```
