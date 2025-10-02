#include <adwaita.h>

// Функция для простого toast
static void show_simple_toast(GtkButton *button, gpointer user_data) {
  AdwToastOverlay *overlay = ADW_TOAST_OVERLAY(user_data);
  AdwToast *toast = adw_toast_new("Уведомление показано! 🎉");
  adw_toast_overlay_add_toast(overlay, toast);
}

// Функция для кастомного toast
static void show_custom_toast(GtkButton *button, gpointer user_data) {
  AdwToastOverlay *overlay = ADW_TOAST_OVERLAY(user_data);
  AdwToast *toast = adw_toast_new("Это кастомное уведомление с текстом");
  adw_toast_set_timeout(toast, 3000); // 3 секунды
  adw_toast_overlay_add_toast(overlay, toast);
}

// Функция для нескольких toast
static void show_multiple_toasts(GtkButton *button, gpointer user_data) {
  AdwToastOverlay *overlay = ADW_TOAST_OVERLAY(user_data);

  for (int i = 1; i <= 3; i++) {
    char message[50];
    snprintf(message, sizeof(message), "Уведомление #%d", i);
    AdwToast *toast = adw_toast_new(message);
    adw_toast_set_timeout(toast, 1000 + i * 500);
    adw_toast_overlay_add_toast(overlay, toast);
  }
}

static void activate_cb(GtkApplication *app, gpointer user_data) {
  // Главное окно
  GtkWidget *window = adw_application_window_new(GTK_APPLICATION(app));
  gtk_window_set_title(GTK_WINDOW(window), "Toast Example");
  gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

  // Создание основного контейнера
  AdwToolbarView *toolbar_view = adw_toolbar_view_new();
  gtk_window_set_child(GTK_WINDOW(window), GTK_WIDGET(toolbar_view));

  // Создание заголовка
  AdwHeaderBar *header_bar = adw_header_bar_new();
  adw_toolbar_view_add_top_bar(toolbar_view, GTK_WIDGET(header_bar));

  // AdwToastOverlay для уведомлений
  AdwToastOverlay *overlay = adw_toast_overlay_new();

  // Основной контент
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
  gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(box, GTK_ALIGN_CENTER);
  gtk_widget_set_margin_all(box, 12);

  // Заголовок
  GtkWidget *title = gtk_label_new("Демонстрация Toast уведомлений");
  gtk_widget_add_css_class(title, "title-1");
  gtk_box_append(GTK_BOX(box), title);

  // Кнопки
  GtkWidget *button1 = gtk_button_new_with_label("Простое уведомление");
  GtkWidget *button2 = gtk_button_new_with_label("Кастомное уведомление");
  GtkWidget *button3 = gtk_button_new_with_label("Несколько уведомлений");

  // Подключаем обработчики
  g_signal_connect(button1, "clicked", G_CALLBACK(show_simple_toast), overlay);
  g_signal_connect(button2, "clicked", G_CALLBACK(show_custom_toast), overlay);
  g_signal_connect(button3, "clicked", G_CALLBACK(show_multiple_toasts),
                   overlay);

  gtk_box_append(GTK_BOX(box), button1);
  gtk_box_append(GTK_BOX(box), button2);
  gtk_box_append(GTK_BOX(box), button3);

  // Устанавливаем child для overlay
  adw_toast_overlay_set_child(overlay, box);

  // Устанавливаем content для toolbar_view (ПРАВИЛЬНЫЙ способ)
  adw_toolbar_view_set_content(toolbar_view, GTK_WIDGET(overlay));

  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char *argv[]) {
  AdwApplication *app =
      adw_application_new("com.example.ToastApp", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate_cb), NULL);

  int status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  return status;
}
