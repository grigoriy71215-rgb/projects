#include <adwaita.h>
#include <gtk/gtk.h>

static void activate_cb(GtkApplication *app, gpointer user_data) {
  // Создаем главное окно
  GtkWidget *window = adw_application_window_new(GTK_APPLICATION(app));
  gtk_window_set_title(GTK_WINDOW(window), "LibAdwaita Example");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

  // Создаем кнопку
  GtkWidget *button = gtk_button_new_with_label("Нажми меня!");
  g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy),
                           window);

  // Создаем основной контейнер
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
  gtk_box_append(GTK_BOX(box), button);

  // Устанавливаем отступы
  gtk_widget_set_margin_top(box, 12);
  gtk_widget_set_margin_bottom(box, 12);
  gtk_widget_set_margin_start(box, 12);
  gtk_widget_set_margin_end(box, 12);

  // Правильный метод для AdwApplicationWindow!
  adw_application_window_set_content(ADW_APPLICATION_WINDOW(window), box);

  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
  AdwApplication *app =
      adw_application_new("com.example.AdwApp", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate_cb), NULL);

  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  return status;
}
