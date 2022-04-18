/* -¤- coding: utf-8 -¤-
 * TITLE		: ActivateWindow.c
 * AUTHOR		: Jooa Jaakkola (@benevolentimp)
 * DESCRIPTION	: Implementation-file for activating windows.
*/
#include <gtk/gtk.h>
#include "ActivateWindow.h"

void activateWindow1(GtkApplication *app, gpointer userData)
{
	GtkWidget *window = NULL;
	window = gtk_application_window_new(app);

	gtk_widget_show_all(window);
}
