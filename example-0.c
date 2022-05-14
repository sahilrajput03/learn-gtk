#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data) {
  g_print("I am eternal!!\n");
  // Learn1: executing a shell command, src: https://stackoverflow.com/a/19209148/10012446
  system("ls");
  // To run a sudo required command you must run binary as `sudo ./.binary`, yo!
  // system("ls /root");

  // This wont work unless you run the binary with sudo, `sudo ./.binary`
  // system("sudo ls /root");

  // notificationa and sound play works really good!
  // system("paplay /usr/share/sounds/freedesktop/stereo/bell.oga");
  // system("notify-send 'carl' 'cool'");

  // Learn:2 executing a shell command
  // execl("/bin/pwd", "pwd", NULL);
}

static void activate(GtkApplication *app, gpointer user_data) {
  // When activate function is called, we construct our GTK window
  GtkWidget *window;
  GtkWidget *button;

  // LEARN: window widget is main container for gtk application
  // The call to gtk_application_window_new() will create a new GtkApplicationWindow and store it inside the window pointer.
  window = gtk_application_window_new(app);
  // The window will have a frame, a title bar, and window controls depending on the platform, so we use gtk_window_set_title to set title.
  // gtk_window_set_title takes GtkWindow pointer and a string as input.
  // As our window pointer is a GtkWidget pointer, we need to cast it to GtkWindow. Window can be cast using the macro GTK_WINDOW()
  gtk_window_set_title(GTK_WINDOW(window), "Window");
  // window size is set using gtk_window_set_default_size() and the window is then shown by GTK via gtk_widget_show().
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

  // Creat a button
  button = gtk_button_new_with_label("I am a button!");

  // Bind print_hello function to 'clicked' event
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
  gtk_window_set_child(GTK_WINDOW(window), button);
  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  // "org.gtk.example" is application identifier
  app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);

  // We connect activate signal to activate fn
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  // "activate" signal is emitted when application is launched by "g_application_run" fn
  status = g_application_run(G_APPLICATION(app), argc, argv);
  //^^ in above statement, argc is argument count and argv are the arguments - imo ~sahil

  // When you close the window, by (for example) pressing the X button, the g_application_run() call returns with a number which is saved inside an integer variable named status. Afterwards, the GtkApplication object is freed from memory with g_object_unref().
  // Finally the status integer is returned and the application exits.
  g_object_unref(app);
  printf("program over..! Yipe!!");
  return (status);
}

// While the program is running, GTK is receiving events. These are typically input events caused by the user interacting with your program, but also things like messages from the window manager or other applications.
// GTK processes these and as a result, signals may be emitted on your widgets.
// Connecting handlers for these signals is how you normally make your program do something in response to user input.