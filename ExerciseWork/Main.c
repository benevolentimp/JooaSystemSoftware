/* ~*~ coding: utf-8 ~*~
 * TITLE	: Main.c
 * AUTHOR	: Jooa Jaakkola (@benevolentimp)
 * DESCRIPTION	: GUIs with Gtk.
*/
#include <gtk/gtk.h>
#include "Setup.h"

// Global variables 
GtkWidget *number1 = NULL;
GtkWidget *number2 = NULL;
GtkWidget *calc   = NULL;
GtkWidget *result  = NULL;

int main(int argc, char *argv[])
{	
	GtkWidget *window = NULL;
	GtkWidget *grid   = NULL;

	gtk_init(&argc, &argv); // Begin GTK-code

	// Create the widgets defined above :
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	windowSetup(window);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); // To make upper-right close-button also end process
	
	gridSetupRow0(grid, window);
	/*
	gridSetupRow1(grid, window);
	gridSetupRow2(grid, window);
	gridSetupRow3(grid, window);
	*/
	// Mandatory commands at the end for rendering the window
	// :
	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}
