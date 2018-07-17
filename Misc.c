/*
 *      Misc.c
 *
 *      Copyright 2008 DJ Shaji <djshaji@gmail.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/*		The classic Shaji misc.c */

void message_box_info ( gchar * message )
{
	GtkWidget * dialog = gtk_message_dialog_new ( 	null,
													GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
													GTK_MESSAGE_INFO,
													GTK_BUTTONS_OK,
													"%s",
													message ) ;

	gdk_beep () ;
	gtk_dialog_run ( dialog ) ;
	gtk_widget_destroy ( dialog ) ;

	return ;
}

void message_box_error ( gchar * message )
{
	GtkWidget * dialog = gtk_message_dialog_new ( 	null,
													GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
													GTK_MESSAGE_ERROR,
													GTK_BUTTONS_OK,
													"%s",
													message ) ;

	gdk_beep () ;
	gtk_dialog_run ( dialog ) ;
	gtk_widget_destroy ( dialog ) ;

	return ;
}

void message_box_warning ( gchar * message )
{
	GtkWidget * dialog = gtk_message_dialog_new ( 	null,
													GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
													GTK_MESSAGE_WARNING,
													GTK_BUTTONS_OK,
													"%s",
													message ) ;

	gdk_beep () ;
	gtk_dialog_run ( dialog ) ;
	gtk_widget_destroy ( dialog ) ;

	return ;
}

gboolean message_box_question ( gchar * message )
{
	GtkWidget * dialog = gtk_message_dialog_new ( 	null,
													GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
													GTK_MESSAGE_QUESTION,
													GTK_BUTTONS_YES_NO,
													"%s",
													message ) ;

	gdk_beep () ;
	GtkResponseType response = gtk_dialog_run ( dialog ) ;
	gtk_widget_destroy ( dialog ) ;

	gboolean result ;
	if ( response == GTK_RESPONSE_YES )
		result = true ;
	else
		result = false ;

	return result ;
}

void nina_startup ( void )
{
	home = g_strdup ( g_getenv ( "HOME" )) ;
	april_menu = g_build_filename ( home, ".april_menu", null ) ;

	if ( g_file_test ( "/etc/X11/xdg/april", G_FILE_TEST_IS_DIR ))
		DEFAULT_MENU_ROOT_DIR = g_strdup ( "/etc/X11/xdg/april" ) ;
	else
	{
		gchar * path = g_build_filename ( home, "april", null ) ;
		if ( g_file_test ( path, G_FILE_TEST_IS_DIR ))
			DEFAULT_MENU_ROOT_DIR = g_strdup ( path ) ;
		else
			message_box_error ( "Cannot find menu hierarchy !" ) ;

		g_free ( path ) ;
	}

	g_printf ( "Debug: Using %s as root for menu hierarchy.\n", DEFAULT_MENU_ROOT_DIR ) ;
}

void nina_spawn_async_old ( GtkWidget * widget, gchar * command )
{
	gchar * command2 = g_strconcat ( "\"", command, "\" &", null ) ;
	system ( command2 ) ;

	g_free ( command2 ) ;
}

void nina_spawn_async ( GtkWidget * widget, gchar * command )
{
	oceania_spawn_async ( command ) ;
	return ;
	
	GError * error = null ;
	g_spawn_command_line_async ( command, & error ) ;
	
	if ( error )
		message_box_error ( error -> message ) ;
	
	gtk_widget_hide ( oceania_menu ) ;
}
