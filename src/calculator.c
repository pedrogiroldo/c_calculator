#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicialização das variáveis globais
GtkWidget *entry;
float num1 = 0, num2 = 0, result = 0;
char operation = ' ';

void numeric_button(GtkWidget *widget, gpointer data)
{
    const char *number = (const char *)data;
    const char *current_text = gtk_entry_get_text(GTK_ENTRY(entry));

    // Se o texto atual é "0", substitua-o
    if (strcmp(current_text, "0") == 0)
    {
        gtk_entry_set_text(GTK_ENTRY(entry), number);
    }
    else
    {
        // Senão, adicione o número ao final
        char novo_texto[100];
        sprintf(novo_texto, "%s%s", current_text, number);
        gtk_entry_set_text(GTK_ENTRY(entry), novo_texto);
    }
}

void operation_button(GtkWidget *widget, gpointer data)
{
    // Guarda o primeiro número
    num1 = atof(gtk_entry_get_text(GTK_ENTRY(entry)));

    // Guarda a operação
    operation = *((const char *)data);

    // Limpa a entrada para o próximo número
    gtk_entry_set_text(GTK_ENTRY(entry), "0");
}

void equal_button(GtkWidget *widget, gpointer data)
{
    // Guarda o segundo número
    num2 = atof(gtk_entry_get_text(GTK_ENTRY(entry)));

    // Realiza a operação
    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
        {
            gtk_entry_set_text(GTK_ENTRY(entry), "Erro: divisão por zero");
            return;
        }
        break;
    }

    char result_text[50];
    sprintf(result_text, "%.2f", result);
    gtk_entry_set_text(GTK_ENTRY(entry), result_text);
}

void clean_button(GtkWidget *widget, gpointer data)
{
    num1 = 0;
    num2 = 0;
    result = 0;
    operation = ' ';
    gtk_entry_set_text(GTK_ENTRY(entry), "0");
}