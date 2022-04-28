/* coding: utf-8
 * TITLE	: Setup.c
 * AUTHOR	: Jooa Jaakkola (@benevolentimp)
 * DESCRIPTION	: Implementation for set-ups - windows and box-containers mainly.
*/
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "Setup.h"
#include "Calc.h"

extern GtkWidget *number1;
extern GtkWidget *number2;
extern GtkWidget *calc;
extern GtkWidget *result;

void windowSetup(GtkWidget *wnd)
{
	gtk_window_set_title(GTK_WINDOW(wnd), "Program");
	gtk_window_set_default_size(GTK_WINDOW(wnd), 666, 420);
	gtk_window_set_position(GTK_WINDOW(wnd), GTK_WIN_POS_CENTER);
	gtk_window_set_resizable(GTK_WINDOW(wnd), FALSE);
}

void gridSetupRow0(GtkWidget *grid, GtkWidget *window)
{
	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);

	number1 = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number1, 	0, 0, 1, 1);

	number2 = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number2, 	1, 0, 1, 1);

	calc = gtk_button_new_with_label("Sum");
	g_signal_connect(calc, "clicked", G_CALLBACK(doSum), result);
	
	gtk_grid_attach(GTK_GRID(grid), calc, 	2, 0, 1, 1);
		
	result = gtk_label_new("");
	gtk_grid_attach(GTK_GRID(grid), result, 	3, 0, 1, 1);
	
	gtk_widget_show_all(window);
}
/*
void gridSetupRow1(GtkWidget *grid, GtkWidget *window)
{
	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);

	number1 = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number1, 	0, 1, 1, 1);

	number2 = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number2, 	1, 1, 1, 1);

	calc = gtk_button_new_with_label("Diff");
	g_signal_connect(calc, "clicked", G_CALLBACK(doDiff), result);
	
	gtk_grid_attach(GTK_GRID(grid), calc, 	2, 1, 1, 1);
		
	result = gtk_label_new("");
	gtk_grid_attach(GTK_GRID(grid), result, 	3, 1, 1, 1);
	
	gtk_widget_show_all(window);
}

void gridSetupRow2(GtkWidget *grid, GtkWidget *window)
{
	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);

	number1 = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number1, 	0, 2, 1, 1);

	number2 = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number2, 	1, 2, 1, 1);

	calc = gtk_button_new_with_label("Prod");
	g_signal_connect(calc, "clicked", G_CALLBACK(doProd), result);
	
	gtk_grid_attach(GTK_GRID(grid), calc, 	2, 2, 1, 1);
		
	result = gtk_label_new("");
	gtk_grid_attach(GTK_GRID(grid), result, 	3, 2, 1, 1);
	
	gtk_widget_show_all(window);
}

void gridSetupRow3(GtkWidget *grid, GtkWidget *window)
{
	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window), grid);

	number1 = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number1, 	0, 3, 1, 1);

	number2 = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number2, 	1, 3, 1, 1);

	calc = gtk_button_new_with_label("Powr");
	g_signal_connect(calc, "clicked", G_CALLBACK(doPowr), result);
	
	gtk_grid_attach(GTK_GRID(grid), calc, 	2, 3, 1, 1);
		
	result = gtk_label_new("");
	gtk_grid_attach(GTK_GRID(grid), result, 	3, 3, 1, 1);
	
	gtk_widget_show_all(window);
}
*/
