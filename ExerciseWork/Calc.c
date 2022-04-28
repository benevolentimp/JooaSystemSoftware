/* coding: utf-8
 * TITLE	: Setup.c
 * AUTHOR	: Jooa Jaakkola (@benevolentimp)
 * DESCRIPTION	: Implementation for set-ups - windows and box-containers mainly.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>

#include "Calc.h"

extern GtkWidget *number1;
extern GtkWidget *number2;
extern GtkWidget *result;

void doSum(GtkWidget *clc, gpointer userData)
{
	int num1 = atoi( (char*) gtk_entry_get_text(GTK_ENTRY(number1)) );
	int num2 = atoi( (char*) gtk_entry_get_text(GTK_ENTRY(number2)) );

	char charBuffer[32];

	snprintf(charBuffer, sizeof(charBuffer), "=> %d", num1 + num2);

	gtk_label_set_text(GTK_LABEL(result), charBuffer);
}
/*
void doDiff(GtkWidget *clc, gpointer userData)
{
	int num1 = atoi( (char*) gtk_entry_get_text(GTK_ENTRY(number1)) );
	int num2 = atoi( (char*) gtk_entry_get_text(GTK_ENTRY(number2)) );

	char charBuffer[32];

	snprintf(charBuffer, sizeof(charBuffer), "=> %d", num1 - num2);

	gtk_label_set_text(GTK_LABEL(result), charBuffer);
}

void doProd(GtkWidget *clc, gpointer userData)
{
	int num1 = atoi( (char*) gtk_entry_get_text(GTK_ENTRY(number1)) );
	int num2 = atoi( (char*) gtk_entry_get_text(GTK_ENTRY(number2)) );

	char charBuffer[32];

	snprintf(charBuffer, sizeof(charBuffer), "=> %d", num1 * num2);

	gtk_label_set_text(GTK_LABEL(result), charBuffer);
}

void doPowr(GtkWidget *clc, gpointer userData)
{
	int num1 = atoi( (char*) gtk_entry_get_text(GTK_ENTRY(number1)) );
	int num2 = atoi( (char*) gtk_entry_get_text(GTK_ENTRY(number2)) );

	char charBuffer[32];

	snprintf(charBuffer, sizeof(charBuffer), "=> %f", pow(num1, num2));

	gtk_label_set_text(GTK_LABEL(result), charBuffer);
}
*/
