// src: https://www.youtube.com/watch?v=ajNvsv1ka4I&list=LL&index=1
// THIS APP DOESN"T RUN WITH GTK4 so abandoning it!! ~ Sahil
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

// These are global variables
static GtkWidget *number1;
static GtkWidget *number2;
static GtkWidget *result;

void do_calculate(GtkWidget *calculate, gpointer data) {
  int num1 = atoi((char *)gtk_editable_get_text(GTK_ENTRY(number1)));
  int num2 = atoi((char *)gtk_editable_get_text(GTK_ENTRY(number2)));

  char buffer[32];
  snprintf(buffer, sizeof(buffer), "result: %d", num1 + num2);

  gtk_label_set_text(GTK_LABEL(result), buffer);
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window, *grid, *calculate;
  GtkWidget *box;

  window = gtk_application_window_new(app);

  grid = gtk_grid_new();

  // Now, put the grid inside the window
  ////deprecated gtk_container_add(GTK_CONTAINER(window), grid);
  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(box, GTK_ALIGN_CENTER);

  // add the `box` widget to the `window` widget using gtk_window_set_child()
  gtk_window_set_child(GTK_WINDOW(window), box);

  // Create instance of entry
  number1 = gtk_entry_new();
  // Attach number1 to grid
  gtk_grid_attach(GTK_GRID(grid), number1, 0, 0, 1, 1);

  number2 = gtk_entry_new();
  gtk_grid_attach(GTK_GRID(grid), number2, 1, 0, 1, 1);

  calculate = gtk_button_new_with_label("calculate");
  g_signal_connect(calculate, "clicked", G_CALLBACK(do_calculate), NULL);
  gtk_grid_attach(GTK_GRID(grid), calculate, 2, 0, 1, 1);

  result = gtk_label_new("result:");
  gtk_grid_attach(GTK_GRID(grid), result, 3, 0, 1, 1);
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
