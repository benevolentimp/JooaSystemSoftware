/* coding: utf-8
 * TITLE		: MainGtkApp.c
 * AUTHOR		: Jooa Jaakkola (@benevolentimp)
 * DESCRIPTION	: 
*/
#include <gtk/gtk.h>
#include "ActivateWindow.h"

void activate(GtkApplication *app, gpointer userData);

int main(int argc, char *argv[])
{	
	int appReturn = 0;
	
	// Declare a pointer for application
	GtkApplication *app;
	app = gtk_application_new("fi.jooas", G_APPLICATION_FLAGS_NONE);
	
	// Use the app - function calls & other setups
	g_signal_connect(app, "activate", G_CALLBACK(activateWindow1), NULL);
	appReturn = g_application_run(G_APPLICATION(app), argc, argv);

	// Free pointer of type GtkApplication
	g_object_unref(app);
	
	return 0;
}

