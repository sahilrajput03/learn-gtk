#include <glib/gstdio.h>
#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data) { g_print("Hello World\n"); }

static void quit_cb(GtkWindow *window) { gtk_window_close(window); }

static void activate(GtkApplication *app, gpointer user_data) {
  /* Construct a GtkBuilder instance and load our UI description */
  GtkBuilder *builder = gtk_builder_new();

  //? GTK supports the separation of user interface layout from your business logic, by using UI descriptions in an XML format that can be parsed by the GtkBuilder class.
  //?  Keeping the UI description in a separate file has several advantages: It is then possible to make minor adjustments to the UI without recompiling your program, and, more importantly, graphical UI editors such as Glade can load the file and allow you to create and modify your UI by point-and-click.
  gtk_builder_add_from_file(builder, "example-3-builder.ui", NULL);

  /* Connect signal handlers to the constructed widgets. */
  //? GtkBuilder can also be used to construct objects that are not widgets, such as tree models, adjustments, etc. That is the reason the method we use here is called gtk_builder_get_object() and returns a GObject instead of a GtkWidget.
  GObject *window = gtk_builder_get_object(builder, "window");
  gtk_window_set_application(GTK_WINDOW(window), app);

  GObject *button = gtk_builder_get_object(builder, "button1");
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

  button = gtk_builder_get_object(builder, "button2");
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

  button = gtk_builder_get_object(builder, "quit");
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(quit_cb), window);

  gtk_widget_show(GTK_WIDGET(window));

  /* We do not need the builder any more */
  g_object_unref(builder);
}

int main(int argc, char *argv[]) {
#ifdef GTK_SRCDIR
  g_chdir(GTK_SRCDIR);
#endif

  GtkApplication *app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
