/*
 *      april2.c
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
void * jackie_menu_pos ( GtkMenu * menu, gint * x, gint * y, gboolean push_in, gpointer data ) ;

void susie_menu_destroy ( GtkWidget * widget, gpointer user_data )
{
	gtk_widget_destroy ( widget ) ;
	gtk_main_quit () ;
}

void jackie_create_menu_item ( GtkMenu * menu, gchar * filename )
{
	gchar * basename = g_path_get_basename ( filename ) ;
	GtkWidget * item ;

	gchar * icon = g_strconcat ( basename, ".png", null ) ;
	
	GdkPixbuf * pixbuf1 = oceania_find_image ( icon ) ;
	GdkPixbuf * pixbuf = gdk_pixbuf_scale_simple ( pixbuf1, 22, 22, GDK_INTERP_BILINEAR ) ;
	GtkImage * image = gtk_image_new_from_pixbuf ( pixbuf ) ;

	g_free ( icon ) ;
	g_object_unref ( pixbuf ) ;
	
	g_object_unref ( pixbuf1 ) ;
	
	if ( image )
	{
		item = gtk_image_menu_item_new_with_label ( basename ) ;
		gtk_image_menu_item_set_image ( item, image ) ;
	}
	else
		item = gtk_menu_item_new_with_label ( basename ) ;

	gtk_menu_shell_append ( menu, item ) ;
	g_signal_connect ( item, "activate", nina_spawn_async, g_strdup ( filename )) ;

	gint x = 0, y = 0 ;
	gtk_widget_get_size_request ( item, & x, & y ) ;
	gtk_widget_set_size_request ( item, x, 32 ) ;

	g_free ( basename ) ;
	return ;
}

void jackie_recurse_dir ( GtkMenu * menu, gchar * folder )
{
	GDir * dir ;
	GError * error = null ;
	dir = g_dir_open ( folder, 0, & error ) ;
	if ( error )
	{
		message_box_error ( error -> message ) ;

		g_dir_close ( dir ) ;
		return ;
	}

	gchar * basename = g_path_get_basename ( folder ) ;
	GtkWidget * item ;
	GtkMenu * menu2 = gtk_menu_new () ;

	gchar * icon = g_strconcat ( basename, ".png", null ) ;
	GdkPixbuf * pixbuf1 = oceania_find_image ( icon ) ;
	GdkPixbuf * pixbuf = gdk_pixbuf_scale_simple ( pixbuf1, 22, 22, GDK_INTERP_BILINEAR ) ;
	GtkImage * image = gtk_image_new_from_pixbuf ( pixbuf ) ;

	g_free ( icon ) ;
	g_object_unref ( pixbuf ) ;
	
	g_object_unref ( pixbuf1 ) ;
	if ( image )
	{
		item = gtk_image_menu_item_new_with_label ( basename ) ;
		gtk_image_menu_item_set_image ( item, image ) ;
	}
	else
		item = gtk_menu_item_new_with_label ( basename ) ;

	gtk_menu_shell_append ( menu, item ) ;
	gtk_menu_item_set_submenu ( item, menu2 ) ;

	gint x = 0, y = 0 ;
	gtk_widget_get_size_request ( item, & x, & y ) ;
	gtk_widget_set_size_request ( item, x, 32 ) ;

	g_free ( basename ) ;


	gchar * filename = g_dir_read_name ( dir ) ;
	while ( filename )
	{
		gchar * full_filename = g_build_filename ( folder, filename, null ) ;
		if ( g_file_test ( full_filename, G_FILE_TEST_IS_DIR ))
			jackie_recurse_dir ( menu2, full_filename ) ;
		else if ( g_file_test ( full_filename, G_FILE_TEST_IS_EXECUTABLE ))
			jackie_create_menu_item ( menu2, full_filename ) ;
		else
			g_printf ( "Unknown file format %s\n", filename ) ;

		filename = g_dir_read_name ( dir ) ;
		g_free ( full_filename ) ;
	}

	g_dir_close ( dir ) ;
	return ;
}


void jackie_create_menu1 ( GtkMenu * menu )
{
	nina_startup () ;

	GDir * dir ;
	GError * error = null ;
	dir = g_dir_open ( DEFAULT_MENU_ROOT_DIR, 0, & error ) ;
	if ( error )
	{
		message_box_error ( error -> message ) ;

		g_dir_close ( dir ) ;
		return ;
	}

	gchar * filename = g_dir_read_name ( dir ) ;
	while ( filename )
	{
		gchar * full_filename = g_build_filename ( DEFAULT_MENU_ROOT_DIR, filename, null ) ;
		if ( g_file_test ( full_filename, G_FILE_TEST_IS_DIR ))
			jackie_recurse_dir ( menu, full_filename ) ;
		else if ( g_file_test ( full_filename, G_FILE_TEST_IS_EXECUTABLE ))
			jackie_create_menu_item ( menu, full_filename ) ;

		filename = g_dir_read_name ( dir ) ;
		g_free ( full_filename ) ;
	}

	gtk_widget_show_all ( menu ) ;
	g_dir_close ( dir ) ;
}

void * jackie_menu_pos ( GtkMenu * menu, gint * x, gint * y, gboolean push_in, gpointer data )
{
	x = 0 ;
	y = gdk_screen_width () - 12 ;
}

void jackie_popup_menu ( void )
{
	g_usleep ( 150000 ) ;
	GtkMenu * menu = gtk_menu_new () ;
	jackie_create_menu ( menu ) ;

	g_signal_connect ( menu, "selection-done", susie_menu_destroy, menu ) ;
	//g_signal_connect_swapped ( menu, "selection-done", gtk_widget_hide, oceania_menu ) ;

	gtk_menu_popup ( menu, NULL, NULL, NULL, NULL, NULL, gtk_get_current_event_time () ) ;
	gtk_main () ;
}

void jackie_create_menu ( GtkMenu * menu )
{
	GDir * dir = g_dir_open ( "/usr/share/applications", 0, null ) ;
	gchar * name = g_dir_read_name ( dir ) ;
	
	GList * list = null, * list1 = null ;
	
	while ( name )
	{
		gchar * filename = g_build_filename ( "/usr/share/applications", name, null ) ;
		GKeyFile * file = g_key_file_new () ;
		
		if ( ! g_key_file_load_from_file ( file, filename, G_KEY_FILE_NONE, null ))
		{
			g_free ( filename ) ;
			g_key_file_free ( file ) ;
			
			name = g_dir_read_name ( dir ) ;
			continue ;
		}
		
		gchar * app1 = g_key_file_get_string ( file, "Desktop Entry", "Exec", null ) ;
		gchar * dis = g_key_file_get_string ( file, "Desktop Entry", "Name", null ) ;

		gchar ** cat = g_key_file_get_string_list ( file, "Desktop Entry", "Categories", null, null ) ;
		gchar * app = null ;

		if ( app1 )
		{
			gchar ** vector = g_strsplit ( app1, " ", -1 ) ;
			app = g_strdup ( vector [0] ) ;
			
			g_free ( app1 ) ;
			g_strfreev ( vector ) ;
		}
		
		GtkMenuItem * item ;
		
		if ( dis )
			item = gtk_menu_item_new_with_label ( dis ) ;

		else
			item = gtk_menu_item_new_with_label ( name ) ;
		
		/*
		gchar * ico = g_key_file_get_string ( file, "Desktop Entry", "Icon", null ) ;
		gchar * dis = g_key_file_get_string ( file, "Desktop Entry", "Name", null ) ;
		
		GtkMenuItem * item = gtk_menu_item_new () ;
		GtkVBox * box = gtk_vbox_new ( no, 2 ) ;
		
		GtkImage * image = nina_find_image ( ico ) ;
		if ( image )
		{
			gtk_box_pack_start ( box, image, no, no, 2 ) ;
		}
		
		gtk_box_pack_start ( box, gtk_label_new ( dis ), no, no, 2 ) ;
		g_free ( ico ) ;
		*/

		g_signal_connect ( item, "activate", nina_spawn_async, app ) ;
		
		if ( cat ) {
		GList * search = g_list_find_custom ( list, cat[0], strcmp ) ;
		if ( search )
		{
			gint pos = g_list_position ( list, search ) ;
			gtk_menu_shell_append ( g_list_nth_data ( list1, pos ), item ) ;
		}
		else if ( cat )
		{
			GtkMenu * imenu = gtk_menu_new () ;
			GtkMenuItem * i = gtk_menu_item_new_with_label ( cat[0] ) ;
			
			gtk_menu_item_set_submenu ( i, imenu ) ;
			gtk_menu_shell_append ( imenu, item ) ;
			
			gtk_menu_shell_append ( menu, i ) ;
			
			list = g_list_append ( list, g_strdup ( cat[0] )) ;
			list1 = g_list_append ( list1, imenu ) ;
		}
		}
		//else
			//gtk_menu_shell_append ( menu, item ) ;
		
		g_free ( dis ) ;
		name = g_dir_read_name ( dir ) ;
		
		g_free ( filename ) ;
		g_key_file_free ( file ) ;
		
		g_strfreev ( cat ) ;
	}
		
	g_dir_close ( dir ) ;
}

