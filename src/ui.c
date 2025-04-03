#include "ui.h"
#include "calculator.h"
#include <string.h>

GtkWidget *create_calculator_ui(void)
{
    // Cria a janela principal
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculadora do Giroldo");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 700);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    GtkCssProvider *provider = gtk_css_provider_new();
    const char *css =
        "button {\n"
        "    font-size: 28pt;\n"
        "}\n"
        "button.number-button {\n"
        "    color: black;\n"
        "}\n"
        "button.operation-button {\n"
        "    color: blue;\n"
        "}\n"
        "button.function-button {\n"
        "    color: red;\n"
        "}\n"
        "button.equal-button {\n"
        "    color: green;\n"
        "}\n"
        "entry {\n"
        "    font-size: 32pt;\n"
        "}";
    gtk_css_provider_load_from_data(provider, css, -1, NULL);

    // Aplicar o CSS a toda a aplicação
    GdkDisplay *display = gdk_display_get_default();
    GdkScreen *screen = gdk_display_get_default_screen(display);
    gtk_style_context_add_provider_for_screen(screen,
                                              GTK_STYLE_PROVIDER(provider),
                                              GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref(provider);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry), "0");
    gtk_entry_set_alignment(GTK_ENTRY(entry), 1);
    gtk_widget_set_size_request(entry, -1, 80);
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 5);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);

    const char *botoes[4][4] = {
        {"7", "8", "9", "/"},
        {"4", "5", "6", "*"},
        {"1", "2", "3", "-"},
        {"0", "C", "=", "+"}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            GtkWidget *button = gtk_button_new_with_label(botoes[i][j]);
            gtk_widget_set_hexpand(button, TRUE); // Permite expansão horizontal
            gtk_widget_set_vexpand(button, TRUE); // Permite expansão vertical
            GtkStyleContext *context = gtk_widget_get_style_context(button);
            gtk_grid_attach(GTK_GRID(grid), button, j, i, 1, 1);

            // Configura o que acontece quando o botão é clicado
            if (strcmp(botoes[i][j], "C") == 0)
            {
                g_signal_connect(button, "clicked", G_CALLBACK(clean_button), NULL);
                gtk_style_context_add_class(context, "function-button");
            }
            else if (strcmp(botoes[i][j], "=") == 0)
            {
                g_signal_connect(button, "clicked", G_CALLBACK(equal_button), NULL);
                gtk_style_context_add_class(context, "equal-button");
            }
            else if (strcmp(botoes[i][j], "+") == 0 ||
                     strcmp(botoes[i][j], "-") == 0 ||
                     strcmp(botoes[i][j], "*") == 0 ||
                     strcmp(botoes[i][j], "/") == 0)
            {
                g_signal_connect(button, "clicked", G_CALLBACK(operation_button), (gpointer)botoes[i][j]);
                gtk_style_context_add_class(context, "operation-button");
            }
            else
            {
                g_signal_connect(button, "clicked", G_CALLBACK(numeric_button), (gpointer)botoes[i][j]);
                gtk_style_context_add_class(context, "number-button");
            }
        }
    }

    return window;
}