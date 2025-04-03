#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <gtk/gtk.h>

// Variáveis globais
extern GtkWidget *entry;
extern float num1, num2, result;
extern char operation;

// Funções da calculadora
void numeric_button(GtkWidget *widget, gpointer data);
void operation_button(GtkWidget *widget, gpointer data);
void equal_button(GtkWidget *widget, gpointer data);
void clean_button(GtkWidget *widget, gpointer data);

#endif // CALCULATOR_H