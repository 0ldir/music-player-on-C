#include <gtk/gtk.h>

static void activate(GApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(window), "GTK4 Application");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 500);

    GtkWidget *fix = gtk_fixed_new();
    gtk_window_set_child(GTK_WINDOW(window), fix);

    GtkWidget *play_button = gtk_toggle_button_new_with_label(">");
    gtk_widget_set_size_request(play_button, 30, 40);
    gtk_fixed_put(GTK_FIXED(fix), play_button, 400, 400);

    GtkWidget *next_button = gtk_button_new_with_label("->");
    gtk_widget_set_size_request(next_button, 30, 40);
    gtk_fixed_put(GTK_FIXED(fix), next_button, 500, 400);

    GtkWidget *prev_button = gtk_button_new_with_label("<-");
    gtk_widget_set_size_request(prev_button, 30, 40);
    gtk_fixed_put(GTK_FIXED(fix), prev_button, 300, 400);

    
    gtk_widget_show(window);
}

int main(int argc, char **argv) {
    // Создаем приложение с уникальным идентификатором
    GtkApplication *app = gtk_application_new("com.example.gtkapp", G_APPLICATION_DEFAULT_FLAGS);
    
    // Подключаем сигнал activate
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    
    // Запускаем приложение
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    
    // Освобождаем ресурсы
    g_object_unref(app);
    
    return status;
}