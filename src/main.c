#include <gtk/gtk.h>
#include "calculator.h"
#include "ui.h"

int main(int argc, char *argv[])
{
    // Inicializa o GTK
    gtk_init(&argc, &argv);

    // Cria a interface
    GtkWidget *window = create_calculator_ui();
    
    // Mostra todos os widgets
    gtk_widget_show_all(window);

    // Inicia o loop principal do GTK
    gtk_main();

    return 0;
}