/*
 *      april.c
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

#include <gtk/gtk.h>

GtkMenuItem * nina_create_submenu ( GtkMenu * menu, gchar * text ) ;

void nina_test ( void )
{
	GtkWidget * window = gtk_window_new ( GTK_WINDOW_TOPLEVEL ) ;
	GtkLayout * lt = gtk_layout_new ( null, null ) ;
	gtk_container_add ( window, lt ) ;
	GtkBox * box = gtk_vbox_new ( 1, 1 ) ;
	gtk_layout_put ( lt, box, 10, 10 ) ;

	GtkMenu * menu = gtk_menu_new () ;

	gint i ;
	for ( i = 0 ; i < 10 ; i ++ )
	{
		GtkMenuItem * item = gtk_menu_item_new_with_label ( "Hello" ) ;

		//gtk_menu_attach ( menu, item, 0, 60, 0, 10 ) ;
		//gtk_menu_shell_append ( menu,item ) ;
		gtk_box_pack_end ( box, item, 1, 1, 1 ) ;
		gtk_widget_show ( item ) ;
	}

	//gtk_menu_popup ( menu, null, null, null, null, null, null ) ;
	gtk_widget_show_all ( window ) ;
	gtk_main () ;
}

GtkImage * nina_find_image ( gchar * filename )
{
	if ( g_file_test ( filename, G_FILE_TEST_EXISTS ))
	{
		GtkImage * image = gtk_image_new_from_file ( filename ) ;
		return image ;
	}

	gchar * system_path = g_build_filename ( "/usr/share/icons", filename, null ) ;
	if ( g_file_test ( system_path, G_FILE_TEST_EXISTS ))
	{
		GtkImage * image = gtk_image_new_from_file ( system_path ) ;
		g_free ( system_path ) ;

		return image ;
	}

	g_free ( system_path ) ;
	gchar * user_path = g_build_filename ( home, "icons", filename, null ) ;
	if ( g_file_test ( user_path, G_FILE_TEST_EXISTS ))
	{
		GtkImage * image = gtk_image_new_from_file ( user_path ) ;
		g_free ( user_path ) ;

		return image ;
	}

	g_free ( user_path ) ;
	return null ;
}

void nina_parse_subtext ( GtkMenu * menu, gchar * text )
{
	gchar ** vector = g_strsplit ( text, " ", MinusOne ) ;
	if ( ! vector )
		return ;

	if ( strcmp ( vector [0], "<command>" ) != 0 )
	{
		g_strfreev ( vector ) ;
		return ;
	}

	GtkWidget * item ;
	GtkImage * image = nina_find_image ( vector [3] ) ;
	if ( image )
	{
		item = gtk_image_menu_item_new_with_label ( vector [1] ) ;
		gtk_image_menu_item_set_image ( item, image ) ;
	}
	else
		item = gtk_menu_item_new_with_label ( vector [1] ) ;

	g_signal_connect ( item, "activate", nina_spawn_async, g_strdup ( vector[2] )) ;
	/* DEBUG */
	g_signal_connect ( item, "activate", nina_test, g_strdup ( vector[2] )) ;

	gint x = 0, y = 0 ;
	gtk_widget_get_size_request ( item, & x, & y ) ;
	gtk_widget_set_size_request ( item, x, 32 ) ;

	g_strfreev ( vector ) ;
	gtk_menu_shell_append ( menu, item ) ;
}

gint nina_create_submenu1 ( GtkMenu * menu, gchar ** vector, gint i )
{
	if ( ! nina_probe ( vector [i], NINA_SUBMENU ))
		reutern i ;

	gchar ** hector = g_strsplit ( vector [i], " ", -1 ) ;
	if ( hector == null )
		return i ;

	GtkMenu * menu2 = gtk_menu_new () ;
	GtkWidget * item ;
	GtkImage * image = nina_find_image ( hector [2] ) ;
	if ( image )
	{
		item = gtk_image_menu_item_new_with_label ( hector [1] ) ;
		gtk_image_menu_item_set_image ( item, image ) ;
	}
	else
		item = gtk_menu_item_new_with_label ( hector [1] ) ;
	g_strfreev ( hector ) ;

	gtk_menu_item_set_submenu ( item, menu2 ) ;
	gtk_menu_shell_append ( menu, item ) ;

	gint x = 0, y = 0 ;
	gtk_widget_get_size_request ( item, & x, & y ) ;
	gtk_widget_set_size_request ( item, x, 32 ) ;

	i ++ ;

	while ( strcmp ( vector [i], "</submenu>" ))
	{
		g_printf ( "%d %s\n", i, vector [i] ) ;
		if ( nina_probe ( vector [i], NINA_MENUITEM ))
			nina_parse_subtext ( menu2, vector[i] ) ;
		else if ( nina_probe ( vector [i], NINA_SUBMENU ))
			i = nina_create_submenu1 ( menu2, vector, i ) ;
		else if ( nina_probe ( vector [i], NINA_SEPARATOR ))
			nina_add_separator ( menu2 ) ;
		else if ( nina_probe ( vector [i], NINA_EOF ))
			return i ;

		i ++ ;
	}

	return i ;
}

GtkMenuItem * nina_create_submenu ( GtkMenu * menu, gchar * text )
{
	GtkMenuItem * item = gtk_menu_item_new_with_label ( text ) ;
	gtk_menu_shell_append ( menu, item ) ;

	gint x = 0, y = 0 ;
	gtk_widget_get_size_request ( item, & x, & y ) ;
	gtk_widget_set_size_request ( item, x, 32 ) ;

	return item ;
}

gboolean nina_probe ( gchar * text, NinaMenuItem type )
{
	gchar ** vector = g_strsplit ( text, " ", MinusOne ) ;
	if ( ! vector )
		return false ;

	gboolean result = false ;
	switch ( type )
	{
		case NINA_MENUITEM:
			result = ! strcmp ( vector [0], "<command>" ) ;
			break ;
		case NINA_SEPARATOR:
			result = ! strcmp ( vector [0], "<separator>" ) ;
			break ;
		case NINA_SUBMENU:
			result = ! strcmp ( vector [0], "<submenu>" ) ;
			break ;
		case NINA_EOF:
			result = ! strcmp ( vector[0], "</menu>" ) ;
			break ;
		default:
			result = false ;
			break ;
	}

	g_strfreev ( vector ) ;
	return result ;
}


void nina_add_separator ( GtkMenu * menu )
{
	GtkSeparatorMenuItem * item = gtk_separator_menu_item_new () ;
	gtk_menu_shell_append ( menu, item ) ;
}

void nina_parse_text ( GtkMenu * menu, gchar * text )
{
	gchar ** vector = g_strsplit ( text, "\n", MinusOne ) ;
	gint i = 0 ;
	while ( vector [i] != null )
	{
		g_printf ( "%d %s\n", i, vector [i] ) ;
		if ( nina_probe ( vector [i], NINA_MENUITEM ))
		{
			nina_parse_subtext ( menu, vector [i] ) ;
		}
		else if ( nina_probe ( vector [i], NINA_SUBMENU ))
		{
			i = nina_create_submenu1 ( menu, vector, i ) ;
		}
		else if ( nina_probe ( vector [i], NINA_SEPARATOR ))
		{
			nina_add_separator ( menu ) ;
		}
		else
			g_printf ( "Nina: Unknown menu entry %s in file %s!\n", vector [i], april_menu ) ;

		if ( nina_probe ( vector [i], NINA_EOF ))
			break ;
		i ++ ;
	}

	g_strfreev ( vector ) ;
}


vodi nina_parse_menu ( GtkMenu * menu )
{
	/* Do this only once, or memory corruption, and condemnation to the
	* darkest corners of hell. */
	if ( ! april_menu )
		nina_startup () ;

	gchar * text ;
	GError * error = null ;
	g_file_get_contents ( april_menu, & text, null, & error ) ;
	if ( error )
	{
		message_box_error ( error -> message ) ;
		return ;
	}

	nina_parse_text ( menu, text ) ;
	gtk_widget_show_all ( menu ) ;
	g_free ( text ) ;
}


