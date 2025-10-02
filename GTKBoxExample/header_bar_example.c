#include <adwaita.h> // Изменили включение заголовочного файла
#include <gtk/gtk.h>

// Обработчик нажатия кнопки
static void on_button_clicked(GtkButton *button, gpointer user_data) {
  g_print("Кнопка нажата!\n");
}

// Функция активации приложения
static void activate(GtkApplication *app, gpointer user_data) {
  // Создаем главное окно
  AdwApplicationWindow *window =
      ADW_APPLICATION_WINDOW(adw_application_window_new(app));
  gtk_window_set_title(GTK_WINDOW(window), "Пример приложения");
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

  // Создаем заголовок окна
  AdwHeaderBar *headerbar = ADW_HEADER_BAR(adw_header_bar_new());

  // Добавляем кнопки в заголовок
  GtkButton *button1 = GTK_BUTTON(gtk_button_new_with_label("Кнопка 1"));
  g_signal_connect(button1, "clicked", G_CALLBACK(on_button_clicked), NULL);
  adw_header_bar_pack_end(headerbar, GTK_WIDGET(button1));

  GtkButton *button2 = GTK_BUTTON(gtk_button_new_with_label("Кнопка 2"));
  g_signal_connect(button2, "clicked", G_CALLBACK(on_button_clicked), NULL);
  adw_header_bar_pack_end(headerbar, GTK_WIDGET(button2));

  // Устанавливаем заголовок через специальное свойство
  adw_application_window_set_header_bar(window, headerbar);

  // Создаем основной контент
  GtkBox *content = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 12));
  gtk_window_set_child(GTK_WINDOW(window), GTK_WIDGET(content));

  // Добавляем метку
  GtkLabel *label = GTK_LABEL(gtk_label_new("Добро пожаловать в приложение!"));
  gtk_box_append(GTK_BOX(content), GTK_WIDGET(label));

  // Показываем окно
  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
  // Создаем GtkApplication
  GtkApplication *app = gtk_application_new("com.example.libadwaita.app",
                                            G_APPLICATION_DEFAULT_FLAGS);

  // Подключаем функцию активации
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  // Запускаем приложение
  return g_application_run(G_APPLICATION(app), argc, argv);
}
