/*
 *      oceania.c
 *
 *      Copyright 2008 Shaji <djshaji@gmail.com>
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

#include "oceania.h"

void oceania_create_columns ( GtkTreeView * tree_view1 )
{
	GtkCellRenderer * cell1 = gtk_cell_renderer_pixbuf_new () ;
	GtkCellRenderer * cell2 = gtk_cell_renderer_text_new () ;
	
	gint x = 0, y = 0 ;
	
	gtk_cell_renderer_get_fixed_size ( cell1, & x, & y ) ;
	gtk_cell_renderer_set_fixed_size ( cell1, x, y + 36 ) ;
	
	gtk_cell_renderer_get_fixed_size ( cell2, & x, & y ) ;
	gtk_cell_renderer_set_fixed_size ( cell2, x, y + 36 ) ;
	
	GtkTreeViewColumn * column1 = gtk_tree_view_column_new_with_attributes ( "Name",
																			cell1,
																			"pixbuf",
																			0,
																			null ) ;
	GtkTreeViewColumn * column2 = gtk_tree_view_column_new_with_attributes ( "PID",
																			cell2,
																			"text",
																			1,
																			null ) ;

	gtk_tree_view_append_column ( tree_view1, column1 ) ;
	gtk_tree_view_append_column ( tree_view1, column2 ) ;
	
	/*
	gtk_tree_view_column_set_spacing ( column1, 10 ) ;
	gtk_tree_view_column_set_spacing ( column2, 10 ) ;
	
	gtk_tree_view_column_set_sizing ( column1, GTK_TREE_VIEW_COLUMN_GROW_ONLY ) ;
	gtk_tree_view_column_set_sizing ( column2, GTK_TREE_VIEW_COLUMN_GROW_ONLY ) ;
	*/
	
	return ;
}

void oceania_create_columns_2 ( GtkTreeView * tree_view1 )
{
	GtkCellRenderer * cell1 = gtk_cell_renderer_pixbuf_new () ;
	GtkCellRenderer * cell2 = gtk_cell_renderer_text_new () ;
	
	gint x = 0, y = 0 ;
	
	gtk_cell_renderer_get_fixed_size ( cell1, & x, & y ) ;
	gtk_cell_renderer_set_fixed_size ( cell1, x, y + 32 ) ;
	
	gtk_cell_renderer_get_fixed_size ( cell2, & x, & y ) ;
	gtk_cell_renderer_set_fixed_size ( cell2, x, y + 32 ) ;
	
	GtkTreeViewColumn * column1 = gtk_tree_view_column_new_with_attributes ( "Name",
																			cell1,
																			"pixbuf",
																			0,
																			null ) ;
	GtkTreeViewColumn * column2 = gtk_tree_view_column_new_with_attributes ( "PID",
																			cell2,
																			"text",
																			1,
																			null ) ;

	gtk_tree_view_append_column ( tree_view1, column1 ) ;
	gtk_tree_view_append_column ( tree_view1, column2 ) ;
	
	return ;
}

void oceania_append_column ( GtkTreeStore * store, gchar * icon, gchar * display_name, gchar * path, gboolean is_separator )
{
	GdkPixbuf * pixbuf = null ;
	if ( icon )
		pixbuf = oceania_find_image ( icon ) ;
	
	GtkTreeIter iter ;
	gtk_tree_store_append ( store, & iter, null ) ;
	
	gtk_tree_store_set ( store, & iter, 0, pixbuf, 1, display_name, 2, path, 3, is_separator, -1 ) ;

	if ( pixbuf )
		g_object_unref ( pixbuf ) ;
	
	return ;
}

void oceania_mouse_over_callback ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data )
{
	gchar * text = gtk_label_get_text ( data ) ;
	gchar * markup = g_markup_printf_escaped ( "<span foreground=\"black\">%s</span>", text ) ;
	
	gtk_label_set_label ( data, markup ) ;
	g_free ( markup ) ;
}

void oceania_mouse_over_callback_reset ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data )
{
	gchar * text = gtk_label_get_text ( data ) ;
	gchar * markup = g_markup_printf_escaped ( "<span foreground=\"white\">%s</span>", text ) ;
	
	gtk_label_set_label ( data, markup ) ;
	g_free ( markup ) ;
}

void oceania_mouse_over_callback_1 ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data )
{
	gchar * text = gtk_label_get_text ( data ) ;
	gchar * markup = g_markup_printf_escaped ( "<span foreground=\"black\" size=\"small\">%s</span>", text ) ;
	
	gtk_label_set_label ( data, markup ) ;
	g_free ( markup ) ;
}

void oceania_mouse_over_callback_1_reset ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data )
{
	gchar * text = gtk_label_get_text ( data ) ;
	gchar * markup = g_markup_printf_escaped ( "<span foreground=\"white\" size=\"small\">%s</span>", text ) ;
	
	gtk_label_set_label ( data, markup ) ;
	g_free ( markup ) ;
}

GtkWidget * oceania_create_menu ( void )
{
	GtkSettings * settings = gtk_settings_get_default () ;
	gtk_settings_set_long_property ( settings, "gtk-button-images", false, "XProperty" ) ;

	GtkWindow * window = gtk_window_new ( GTK_WINDOW_TOPLEVEL ) ;
	GtkVBox * master = gtk_vbox_new ( no, 0 ) ;
	
	gtk_window_set_skip_pager_hint ( window, true ) ;
	gtk_window_set_skip_taskbar_hint ( window, true ) ;
	
	gtk_container_add ( window, master ) ;
	gtk_window_set_type_hint ( window, GDK_WINDOW_TYPE_HINT_DIALOG ) ;
	
	gtk_window_set_decorated ( window, false ) ;
		
	default_color.red = 74 * 257 ;
	default_color.green = 134 * 257 ;
	default_color.blue = 230 * 257 ;
	
	/* 99, 195, 255 */
	/* 32, 117, 223 */
	/* 215, 231, 255 */
	GdkColor color ;
	
	//if ( ! oceania_get_color ( & color ))
	{
		color.red = default_color.red ;
		color.green = default_color.green ;
		color.blue = default_color.blue ;
	}
	
	gtk_widget_modify_bg ( window, GTK_STATE_NORMAL, & color ) ;
	
	GdkColor color1 ;
	color1.red = 65535 ;
	color1.green = 65535 ;
	color1.blue = 65535 ;
	
	GtkFrame * frame = gtk_button_new () ;
	gtk_widget_modify_bg ( frame, GTK_STATE_NORMAL, & color ) ;
	
	gtk_button_set_relief ( frame, GTK_RELIEF_NONE ) ;
	
	lt = gtk_layout_new ( null, null ) ;
	bg1 = gtk_image_new () ;
	
	gtk_widget_modify_bg ( lt, GTK_STATE_NORMAL, & color ) ;
	//gtk_widget_set_no_show_all ( bg1, true ) ;
	//if ( gdk_color_equal ( & color, & default_color ))
		gtk_widget_show ( bg1 ) ;
	
	GdkPixbuf * bg1_p = oceania_find_image ( "menu_up2.png" ) ;
	gtk_image_set_from_pixbuf ( bg1, bg1_p ) ;
	
	g_object_unref ( bg1_p ) ;
	gtk_layout_put ( lt, bg1, 0, 0 ) ;
	
	GtkWidget * header = gtk_hbox_new ( no, 2 ) ;
	
	//GtkWidget * from = gtk_button_new () ;
	//gtk_container_add ( from, header ) ;
	
	gtk_box_pack_start ( master, lt, yes, yes, 0 ) ;
	//gtk_frame_set_shadow_type ( from, GTK_SHADOW_ETCHED_OUT ) ;
	
	gtk_layout_put ( lt, header, 0, 0 ) ;
	GtkVBox * vb = gtk_vbox_new ( no, 0 ) ;
	
	GtkHBox * lbox = gtk_hbox_new ( no, 0 ) ;
	gtk_box_pack_start ( vb, lbox, no, no, 0 ) ;
	
	GtkImage * logo = gtk_image_new () ;
	gchar * logo_fp = oceania_get_logo () ;
	
	GdkPixbuf * logo_p = null ;
	if ( logo_fp )
		logo_p = gdk_pixbuf_new_from_file_at_scale ( logo_fp, 48, 48, false, null ) ;
	else
		logo_p = oceania_find_image ( "oceania_logo.png" ) ;
	
	g_free ( logo_fp ) ;
	
	gtk_image_set_from_pixbuf ( logo, logo_p ) ;
	g_object_unref ( logo_p ) ;
	
	g_signal_connect ( frame, "clicked", oceania_set_logo, logo ) ;
	
	struct utsname un ;
	uname ( & un ) ;
	
	GtkLabel * label = gtk_label_new ( null ) ;
	gchar * markup = g_markup_printf_escaped ( "<span size=\"large\" foreground=\"white\"><b>%s</b></span><span foreground=\"white\"size=\"small\">\n%s on an <b>%s</b></span>",
						getenv ( "USER" ),
						un.release,
						un.machine ) ;
	gtk_label_set_markup ( label, markup ) ;
	g_free ( markup ) ;
	
	gtk_label_set_line_wrap ( label, on ) ;
	
	GtkButton * change_color = gtk_button_new () ;
	GtkLabel * lb1 = gtk_label_new ( null ) ;
	
	gtk_label_set_markup ( lb1, "<span size=\"small\" foreground=\"white\">Change background color</span>" ) ;	
	
	gtk_container_add ( change_color, lb1 ) ;
	gtk_button_set_relief ( change_color, GTK_RELIEF_NONE ) ;
	
	gtk_container_add ( frame, logo ) ;
	gtk_box_pack_start ( header, frame, no, no, 2 ) ;
	
	gtk_box_pack_start ( header, label, no, no, 2 ) ;	
	
	///> TODO CHANGE COLOR
	//gtk_box_pack_end ( lbox, change_color, no, no, 2 ) ;
	
	gtk_box_pack_end ( header, vb, no, no, 0 ) ;
	g_signal_connect ( change_color, "clicked", oceania_change_color, window ) ;
	
	//g_signal_connect_after ( change_color, "enter-notify-event", oceania_mouse_over_callback_1, lb1 ) ;
	//g_signal_connect_after ( change_color, "leave-notify-event", oceania_mouse_over_callback_1_reset, lb1 ) ;

	gtk_widget_show_all ( header ) ;
	GtkRequisition qu1 ;
	
	gtk_widget_size_request ( header, & qu1 ) ;
	gtk_widget_set_size_request ( lt, qu1.width, qu1.height ) ;
	
	//gtk_widget_modify_bg ( lt, GTK_STATE_NORMAL, & default_color ) ;
	
	GtkWidget * box = gtk_hbox_new ( yes, 0 ) ;
	gtk_box_pack_start ( master, box, yes, yes, 0 ) ;
	
	GtkVBox * vbox1 = gtk_vbox_new ( no, 0 ) ;
	gtk_box_pack_start ( box, vbox1, yes, yes, 0 ) ;
	
	GtkTreeStore * store1 = gtk_tree_store_new ( 4, GDK_TYPE_PIXBUF, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_BOOLEAN ) ;
	GtkTreeStore * store2 = gtk_tree_store_new ( 4, GDK_TYPE_PIXBUF, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_BOOLEAN ) ;
	
	/* Get menu from rcfile */
	oceania_populate_menu ( store1, store2 ) ;

	GtkTreeView * tree_view1 = gtk_tree_view_new () ;
	gtk_widget_set_name ( tree_view1, "tree_view1" ) ;
	//gtk_widget_set_name ( tree_view1, "gtk-treeview1" ) ;
	
	gtk_box_pack_start ( vbox1, tree_view1, yes, yes, 0 ) ;
	gtk_tree_view_set_headers_visible ( tree_view1, no ) ;
	
	gtk_tree_view_set_model ( tree_view1, store1 ) ;
	gtk_tree_view_set_row_separator_func ( tree_view1, oceania_is_separator, null, null ) ;
	
	oceania_create_columns ( tree_view1 ) ;
	gtk_tree_view_set_hover_selection ( tree_view1, true ) ;
	
	/*
	oceania_append_column ( store1, "Terminal.png", "Terminal", "xterm", false ) ;
	oceania_append_column ( store1, "Run.png", "Run", "Run", false ) ;
	oceania_append_column ( store1, "gadu.png", "Gadu", "Gadu", true ) ;
	oceania_append_column ( store1, "Audacious.png", "Audacious", "audacious", false ) ;
	oceania_append_column ( store1, "MPlayer.png", "MPlayer", "gmplayer", false ) ;
	oceania_append_column ( store1, "gadu.png", "Gadu", "Gadu", true ) ;
	oceania_append_column ( store1, "bookmarks_list_add.png", "Virtual memory", "Swap", false ) ;
	oceania_append_column ( store1, "About April.png", "Assistant", "Assistant", false ) ;
	oceania_append_column ( store1, "gadu.png", "Gadu", "Gadu", true ) ;
	oceania_append_column ( store1, "Run.png", "Run", "Run", false ) ;
	*/
	//oceania_append_column ( store1, "gadu.png", "Gadu", "Gadu", true ) ;
		
	GtkVBox * vbox2 = gtk_vbox_new ( no, 2 ) ;
	gtk_box_pack_start ( box, vbox2, yes, yes, 2 ) ;
	
	GtkTreeView * tree_view2 = gtk_tree_view_new () ;
	gtk_widget_set_name ( tree_view2, "tree_view2" ) ;
	g_signal_connect ( tree_view2, "button-press-event", oceania_button_press_callback, null ) ;
	
	/* 215, 231, 255 */
	GdkColor colour ;
	colour.red = 215 * 257 ;
	colour.green = 231 * 257 ;
	colour.blue = 255 * 257 ;
	
	gtk_widget_show ( tree_view2 ) ;
	oceania_update_gui () ;
	
	gtk_widget_modify_base ( tree_view2, GTK_STATE_NORMAL, & colour ) ;
	gtk_widget_modify_fg ( tree_view2, GTK_STATE_NORMAL, & color1 ) ;
	
	g_signal_connect ( tree_view1, "enter-notify-event", oceania_grab_focus, null ) ;
	g_signal_connect ( tree_view2, "enter-notify-event", oceania_grab_focus, null ) ;

	gtk_tree_view_set_headers_visible ( tree_view2, no ) ;
	
	gtk_tree_view_set_model ( tree_view2, store2 ) ;
	gtk_tree_view_set_row_separator_func ( tree_view2, oceania_is_separator, null, null ) ;
	
	oceania_create_columns ( tree_view2 ) ;
	gtk_tree_view_set_hover_selection ( tree_view2, true ) ;

	/*
	oceania_append_column ( store2, "Local Hard Drives.png", "Local Hard Drives", "susie /local_hard_drives", false ) ;
	oceania_append_column ( store2, "Computer.png", "Computer", "susie /Computer", false ) ;
	oceania_append_column ( store2, "Unix System Root.png", "Unix System Root", "susie /", false ) ;
	oceania_append_column ( store2, "gadu.png", "Gadu", "Gadu", true ) ;
	oceania_append_column ( store2, "CD Recorder.png", "CD Recorder", "susie /CDRecorder", false ) ;
	//oceania_append_column ( store2, "gadu.png", "Gadu", "Gadu", true ) ;
	oceania_append_column ( store2, "Favorites.png", "Favorites", "susie Favorites", false ) ;
	oceania_append_column ( store2, "Documents.png", "Documents", "susie /home", false ) ;
	oceania_append_column ( store2, "gadu.png", "Gadu", "Gadu", true ) ;
	oceania_append_column ( store2, "Control Center.png", "Control Center", "susie /ControLCenter", false ) ;
	oceania_append_column ( store2, "gadu.png", "Gadu", "Gadu", true ) ;
	oceania_append_column ( store2, "Task Manager.png", "Task Manager", "taskmgr", false ) ;
	oceania_append_column ( store2, "Readme.png", "System Info", "ComputerProperties", false ) ;
	*/
	
	g_signal_connect ( tree_view1, "button-press-event", oceania_button_press_callback, null ) ;

	/// Recent files 
	{
	
	recent_menu = gtk_menu_new () ;

	GtkTreeStore * store5 = gtk_tree_store_new ( 3, GDK_TYPE_PIXBUF, G_TYPE_STRING, GDK_TYPE_PIXBUF ) ;
	GtkTreeView * tree_view5 = gtk_tree_view_new () ;
	
	gtk_box_pack_start ( vbox2, tree_view5, no, no, 0 ) ;
	gtk_box_pack_start ( vbox2, tree_view2, yes, yes, 0 ) ;

	gtk_tree_view_set_headers_visible ( tree_view5, no ) ;
	
	gtk_tree_view_set_model ( tree_view5, store5 ) ;
	
	
	GtkTreeSelection * select5 = gtk_tree_view_get_selection ( tree_view5 ) ;
	gtk_tree_selection_set_mode ( select5, GTK_SELECTION_MULTIPLE ) ;
	
	gtk_tree_view_set_hover_selection ( tree_view5, true ) ;
	
	GtkCellRenderer * cell5 = gtk_cell_renderer_pixbuf_new () ;
	oceania_create_columns ( tree_view5 ) ;

	GtkTreeViewColumn * column5 = gtk_tree_view_column_new_with_attributes ( "PID",
																			cell5,
																			"pixbuf",
																			2,
																			null ) ;

	

	gtk_tree_view_append_column ( tree_view5, column5 ) ;
	
	GdkPixbuf * pixbuf5 = oceania_find_image ( "folder_yellow.png" ) ;
	GdkPixbuf * pixbuf6 = oceania_find_image ( "forward1.png" ) ;
	
	GtkTreeIter iter ;
	gtk_tree_store_append ( store5, & iter, null ) ;
	
	gtk_tree_store_set ( store5, & iter, 0, pixbuf5, 1, "Recent files", 2, pixbuf6, -1 ) ;

	g_object_unref ( pixbuf5 ) ;
	g_object_unref ( pixbuf6 ) ;
	
	g_signal_connect ( tree_view5, "enter-notify-event", oceania_handle_recent, null ) ;
	g_signal_connect ( tree_view5, "leave-notify-event", oceania_handle_all_programs_reset, null ) ;

	g_signal_connect ( tree_view5, "row-activated", oceania_recent_menu, all_programs ) ;
	
	} ///> Recent files code fin.

	GtkHBox * hbox4 = gtk_hbox_new ( no, 0 ) ;
	gtk_box_pack_start ( vbox1, hbox4, no, no, 2 ) ;
	
	GtkFrame * frm = gtk_frame_new ( null ) ;
	gtk_box_pack_start ( hbox4, frm, yes, yes, 2 ) ;
	
	GtkLabel * dall = gtk_label_new ( null ) ;
	gtk_label_set_markup ( dall, "<span size=\"smaller\" foreground=\"white\">Run</span>" ) ;
	
	gtk_frame_set_label_widget ( frm, dall ) ;
	gtk_frame_set_shadow_type ( frm, GTK_SHADOW_NONE ) ;
	
	GtkEntry * entry = gtk_entry_new () ;
	gtk_container_add ( frm, entry ) ;
	
	GtkTreeStore * store = susie_open_with_get_programs () ;
	GtkEntryCompletion * completion = gtk_entry_completion_new () ;
	
	gtk_entry_completion_set_model ( completion, store ) ;
	gtk_entry_completion_set_text_column ( completion, 0 ) ;
	
	gtk_entry_completion_set_popup_completion ( completion, true ) ;
	gtk_entry_completion_set_inline_completion ( completion, true ) ;
	
	gtk_entry_completion_set_minimum_key_length ( completion, 1 ) ;
	gtk_entry_set_completion ( entry, completion ) ;
	
	g_signal_connect ( entry, "activate", susie_run, null ) ;
	g_signal_connect ( entry, "enter-notify-event", oceania_grab_focus, null ) ;

	GtkTreeStore * store3 = gtk_tree_store_new ( 3, GDK_TYPE_PIXBUF, G_TYPE_STRING, GDK_TYPE_PIXBUF ) ;
	GtkTreeView * tree_view3 = gtk_tree_view_new () ;
	
	gtk_box_pack_start ( vbox1, tree_view3, no, no, 2 ) ;
	gtk_tree_view_set_headers_visible ( tree_view3, no ) ;
	
	gtk_tree_view_set_model ( tree_view3, store3 ) ;
	
	
	GtkTreeSelection * select3 = gtk_tree_view_get_selection ( tree_view3 ) ;
	gtk_tree_selection_set_mode ( select3, GTK_SELECTION_MULTIPLE ) ;
	
	oceania_create_columns ( tree_view3 ) ;
	gtk_tree_view_set_hover_selection ( tree_view3, true ) ;
	
	GtkCellRenderer * cell2 = gtk_cell_renderer_pixbuf_new () ;
	GtkTreeViewColumn * column2 = gtk_tree_view_column_new_with_attributes ( "PID",
																			cell2,
																			"pixbuf",
																			2,
																			null ) ;

	

	gtk_tree_view_append_column ( tree_view3, column2 ) ;
	
	GdkPixbuf * pixbuf = oceania_find_image ( "folder_cool.png" ) ;
	GdkPixbuf * pixbuf1 = oceania_find_image ( "forward1.png" ) ;
	
	GtkTreeIter iter ;
	gtk_tree_store_append ( store3, & iter, null ) ;
	
	gtk_tree_store_set ( store3, & iter, 0, pixbuf, 1, "More programs", 2, pixbuf1, -1 ) ;

	g_object_unref ( pixbuf ) ;
	g_object_unref ( pixbuf1 ) ;

	all_programs = gtk_menu_new () ;
	jackie_create_menu ( all_programs ) ;
	
	gtk_widget_show_all ( all_programs ) ;
	
	//gtk_menu_attach_to_widget ( all_programs, tree_view3, gtk_widget_destroy ) ;
	//g_signal_connect_swapped ( all_programs, "selection-done", gtk_widget_hide, window ) ;
	
	g_signal_connect ( tree_view3, "enter-notify-event", oceania_handle_all_programs, null ) ;
	g_signal_connect ( tree_view3, "leave-notify-event", oceania_handle_all_programs_reset, null ) ;

	g_signal_connect_swapped ( tree_view3, "row-activated", oceania_all_programs_popup, all_programs ) ;
	
	lt2  = gtk_layout_new ( null, null ) ;
	bg2 = gtk_image_new () ;
	
	GdkPixbuf * pixbuf11 = oceania_find_image ( "menu_down.png" ) ;
	gtk_image_set_from_pixbuf ( bg2, pixbuf11 ) ;
	
	g_object_unref ( pixbuf11 ) ;
	
	GtkWidget * hbox2 = gtk_hbox_new ( no, 2 ) ;
	GtkFrame * fr = gtk_frame_new ( null ) ;
	
	gtk_frame_set_shadow_type ( fr, GTK_SHADOW_ETCHED_IN ) ;
	gtk_box_pack_start ( master, lt2, no, no, 0 ) ;
	
	//gtk_container_add ( fr, hbox2 ) ;
	gtk_widget_show ( bg2 ) ;
	
	gtk_layout_put ( lt2, bg2, 0, 0 ) ;
	gtk_layout_put ( lt2, hbox2, 0, 0 ) ;
	
	GtkButton * logoff = gtk_button_new () ;
	GdkPixbuf * logoff_p = oceania_find_image ( "Livraison.png" ) ;
	
	GtkWidget * bb1 = gtk_hbox_new ( no, 2 ) ;
	gtk_container_add ( logoff, bb1 ) ;
	
	GtkLabel * logoff_l = gtk_label_new ( "Logoff" ) ;
	gtk_label_set_markup ( logoff_l, "<span foreground=\"white\">Logoff</span>" ) ;
	
	gtk_box_pack_start ( bb1, gtk_image_new_from_pixbuf ( logoff_p ), no, no, 2 ) ;
	gtk_box_pack_start ( bb1, logoff_l, no, no, 2 ) ;
	
	GtkButton * shutdown = gtk_button_new () ;
	GdkPixbuf * shutdown_p = oceania_find_image ( "Auto Shutdown Timer.png" ) ;
	
	GtkWidget * bb2 = gtk_hbox_new ( no, 2 ) ;
	gtk_container_add ( shutdown, bb2 ) ;

	GtkLabel * shutdown_l = gtk_label_new ( "Shutdown" ) ;
	gtk_label_set_markup ( shutdown_l, "<span foreground=\"white\">Shutdown</span>" ) ;
	
	gtk_box_pack_start ( bb2, gtk_image_new_from_pixbuf ( shutdown_p ), no, no, 2 ) ;
	gtk_box_pack_start ( bb2, shutdown_l, no, no, 2 ) ;
	
	g_object_unref ( logoff_p ) ;
	g_object_unref ( shutdown_p ) ;
	
	gtk_box_pack_end ( hbox2, shutdown, no, no, 2 ) ;
	gtk_box_pack_end ( hbox2, logoff, no, no, 2 ) ;
	
	gtk_widget_modify_bg ( lt2, GTK_STATE_NORMAL, & color ) ;
	gtk_widget_modify_bg ( hbox2, GTK_STATE_NORMAL, & color ) ;

	gtk_button_set_relief ( logoff, GTK_RELIEF_NONE ) ;
	gtk_button_set_relief ( shutdown, GTK_RELIEF_NONE ) ;
	
	g_signal_connect_after ( logoff, "enter-notify-event", oceania_mouse_over_callback, logoff_l ) ;
	g_signal_connect_after ( logoff, "leave-notify-event", oceania_mouse_over_callback_reset, logoff_l ) ;

	g_signal_connect_after ( shutdown, "enter-notify-event", oceania_mouse_over_callback, shutdown_l ) ;
	g_signal_connect_after ( shutdown, "leave-notify-event", oceania_mouse_over_callback_reset, shutdown_l ) ;
	
	g_signal_connect_after ( window, "key-press-event", oceania_key_press_handler, null ) ;
	g_signal_connect ( window, "focus-out-event", oceania_hide_menu, null ) ;

	g_signal_connect ( logoff, "clicked", oceania_log_off_gui, null ) ;
	g_signal_connect ( shutdown, "clicked", oceania_shutdown_gui, null ) ;
	
	gtk_widget_show_all ( hbox2 ) ;
	gtk_widget_show_all ( master ) ;
	
	GtkRequisition qq, qw ;
	
	gtk_widget_size_request ( hbox2, & qq ) ;
	gtk_widget_size_request ( master, & qw ) ;
	
	gtk_widget_set_size_request ( lt2, qw.width, qq.height ) ;
	gtk_widget_set_size_request ( hbox2, qw.width, qq.height ) ;
	
	gtk_widget_show_all ( master ) ;
	oceania_update_gui () ;
		
	g_signal_connect ( tree_view1, "row-activated", oceania_row_activated, store1 ) ;
	g_signal_connect ( tree_view2, "row-activated", oceania_row_activated, store2 ) ;
	
	//gtk_tree_view_columns_autosize ( tree_view1 ) ;
	
	GtkRequisition qu ;
	gtk_widget_size_request ( master, & qu ) ;
	
	signal ( SIGUSR1, oceania_signal_handler ) ;
	
	/*
	GdkPixbuf * start = gdk_pixbuf_new_from_file ( START, null ) ;
	GdkPixbuf * start1 = gdk_pixbuf_new_from_file ( START1, null ) ;
	
	g_signal_connect ( window, "hide", oceania_start_pressed, start ) ;
	g_signal_connect ( window, "show", oceania_start_pressed, start1 ) ;
	
	*/
	
	gtk_window_move ( window, 0, gdk_screen_height () - qu.height - 32 ) ;	
	gtk_widget_hide ( change_color ) ;
	
	return window ;
}

void oceania_popup_menu ( void )
{
	oceania_create () ;
	gtk_window_set_keep_above ( oceania_menu, yes ) ;
	
	gtk_widget_show_all ( oceania_menu ) ;
	gtk_main () ;
}

GdkPixbuf * oceania_find_image ( gchar * filename )
{
	GError * error = null ;
	if ( g_file_test ( filename, G_FILE_TEST_EXISTS ))
	{
		GdkPixbuf * image = gdk_pixbuf_new_from_file ( filename, & error ) ;
		if ( error )
			g_critical ( "%s", error -> message ) ;
		
		return image ;
	}

	gchar * system_path = g_build_filename ( "/usr/share/icons", filename, null ) ;
	if ( g_file_test ( system_path, G_FILE_TEST_EXISTS ))
	{
		GdkPixbuf * image = gdk_pixbuf_new_from_file ( system_path, & error ) ;
		if ( error )
			g_critical ( "%s", error -> message ) ;

		g_free ( system_path ) ;
		return image ;
	}

	g_free ( system_path ) ;
	gchar * user_path = g_build_filename ( g_getenv ( "HOME" ), "/.icons/start-menu", filename, null ) ;
	if ( g_file_test ( user_path, G_FILE_TEST_EXISTS ))
	{
		GdkPixbuf * image = gdk_pixbuf_new_from_file ( user_path, & error ) ;
		if ( error )
			g_critical ( "%s", error -> message ) ;

		g_free ( user_path ) ;
		return image ;
	}

	g_free ( user_path ) ;
	
	g_debug ( "Cannot find icon: %s", filename ) ;
	return null ;
}

void oceania_update_gui ( void )
{
	while ( gtk_events_pending ())
		gtk_main_iteration_do ( true ) ;
}

gboolean oceania_is_separator ( GtkTreeModel * model, GtkTreeIter * iter, shagpointer data )
{
	gboolean value ;
	gtk_tree_model_get ( model, iter, 3, & value, -1 ) ;
	
	return value ;
}

void oceania_handle_all_programs ( GtkTreeView * tree_view, GdkEventCrossing * event, shagpointer data )
{
	gtk_widget_grab_focus ( tree_view ) ;
	gint i = 0 ;
	
	GtkTreeSelection * select = gtk_tree_view_get_selection ( tree_view ) ;
	gtk_tree_selection_select_all ( select ) ;
	
	for ( i = 0 ; i < 50 ; i ++ )
	{
		if ( gtk_tree_selection_count_selected_rows ( select ) == 0 )
			return ;
		
		g_usleep ( 10000 ) ;
		oceania_update_gui () ;
		
	}
	
	gtk_menu_popup ( all_programs, null, null, null, null, null, gtk_get_current_event_time ()) ;
	gtk_widget_show ( gtk_widget_get_toplevel ( tree_view )) ;
}

void oceania_handle_all_programs_reset ( GtkTreeView * tree_view, GdkEventCrossing * event, shagpointer data )
{
	GtkTreeSelection * select = gtk_tree_view_get_selection ( tree_view ) ;
	gtk_tree_selection_unselect_all ( select ) ;
}

void oceania_all_programs_popup ( void )
{
	gtk_menu_popup ( all_programs, null, null, null, null, null, gtk_get_current_event_time ()) ;
}
	
void oceania_menu_run ( GtkTreeView * view, GtkTreePath * path, GtkTreeViewColumn * column, shagpointer data )
{
	GtkTreeIter iter ;
	GtkTreeModel * model = gtk_tree_view_get_model ( view ) ;
	
	gtk_tree_model_get_iter ( model, & iter, path ) ;
	
	gchar * filename = null ;
	gtk_tree_model_get ( model, & iter, 2, & filename, -1 ) ;
	
	if ( filename != null )
	{
		gchar * command = g_strdup_printf ( "%s &", filename ) ;
		system ( command ) ;
		
		g_free ( command ) ;
	}
	
	g_free ( filename ) ;
}

gboolean oceania_button_press_callback ( GtkWidget * widget, GdkEventButton * event, shagpointer data )
{
	if ( event -> button == 3 )
	{
		oceania_secondary_menu_popup ( widget ) ;
		return ;
	}
	
	if ( ! event -> button == 3 )
		return ;
	
	GtkTreeSelection * select = gtk_tree_view_get_selection ( widget ) ;
	GtkTreeModel * model = gtk_tree_view_get_model ( widget ) ;
	GtkTreeIter iter ;
	
	if ( ! gtk_tree_selection_get_selected ( select, null, & iter ))
		return false ;
	
	gchar * filename = null ;
	gtk_tree_model_get ( model, & iter, 2, & filename, -1 ) ;
	
	if ( filename != null )
	{
		GError * error = null ;
		g_spawn_command_line_async ( filename, & error ) ;
		
		if ( error )
			message_box_error ( error -> message ) ;
	}
	
	g_free ( filename ) ;
	gtk_widget_hide ( oceania_menu ) ;
}

void oceania_key_press_handler ( GtkWidget * widget, GdkEventKey * event, shagpointer data )
{
	switch ( event -> keyval )
	{
		case GDK_Escape:
			gtk_widget_hide ( widget ) ;
			break ;
		default:
			break ;
	}
}

void oceania_hide_menu ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data )
{
	if ( GTK_WIDGET_VISIBLE ( all_programs ))
		return ;

	else if ( GTK_WIDGET_VISIBLE ( recent_menu ))
		return ;
	else if ( a_menu_is_up )
		return ;
	
	gtk_widget_hide ( widget ) ;
}


void oceania_log_off ( void )
{
	GtkDialog * dialog = gtk_dialog_new_with_buttons (	"Log off ?",
														null,
														GTK_DIALOG_MODAL,
														"Log off",
														GTK_RESPONSE_ACCEPT,
														"Cancel",
														GTK_RESPONSE_CANCEL,
														null ) ;
	
	GtkLabel * label = gtk_label_new ( 	"Are you sure you want to log off ?\n\n"
										"Your X Session will be closed, and you will\n"
										"be taken to the terminal console. If you do\n"
										"not know what that is, please don\'t log off.\n\n"
										"If you get stuck anywhere, press the power \n"
										"button to power off the system." ) ;
	
	GdkPixbuf * pixbuf = oceania_find_image ( "Livraison.png" ) ;
	GtkImage * image = gtk_image_new_from_pixbuf ( pixbuf ) ;
	
	g_object_unref ( pixbuf ) ;
	
	GtkWidget * box = gtk_hbox_new ( no, 2 ) ;
	gtk_box_pack_start ( dialog -> vbox, box, no, no, 5 ) ;
	
	gtk_box_pack_start ( box, image, no, no, 5 ) ;
	gtk_box_pack_start ( box, label, no, no, 5 ) ;
	
	gtk_widget_show_all ( dialog ) ;
	
	if ( gtk_dialog_run ( dialog ) == GTK_RESPONSE_ACCEPT )
		system ( "killall Xorg" ) ;
	
	gtk_widget_destroy ( dialog ) ;
}

void oceania_shutdown ( void )
{
	GError * error = null ;
	g_spawn_command_line_async ( "Logoff", & error ) ;
	
	if ( error )
		message_box_error ( error -> message ) ;
	
	gtk_widget_hide ( oceania_menu ) ;
}

gboolean oceania_grab_focus ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data )
{
	gtk_widget_grab_focus ( widget ) ;
}	
	
void oceania_popup ( void )
{
	g_debug ( "Caught signal" ) ;

	if ( GTK_WIDGET_VISIBLE ( oceania_menu ))
		gtk_widget_hide ( oceania_menu ) ;
	else
	{
		gtk_widget_show_all ( oceania_menu ) ;
	}
	
	//oceania_update_gui () ;
}

void oceania_create ( void )
{
	oceania_menu = oceania_create_menu () ;
}

void oceania_signal_handler ( gint signum )
{
	switch ( signum )
	{
		case SIGUSR1:
			oceania_popup () ;
			break ;
		default:
			break ;
	}
}

void oceania_populate_menu ( GtkTreeStore * store1, GtkTreeStore * store2 )
{
	//gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".config", "lxpanel", "default", "oceaniarc", null ) ;
	gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".oceaniarc", null ) ;
	if ( ! g_file_test ( oceaniarc, G_FILE_TEST_EXISTS ))
	{
		gchar * message = g_strdup_printf ( "Configuration file not found:\n%s", oceaniarc ) ;
		message_box_error ( message ) ;
		
		g_free ( message ) ;
		g_free ( oceaniarc ) ;
		
		return ;
	}

	GKeyFile * file = g_key_file_new () ;
	GError * error = null ;
	
	g_key_file_load_from_file ( file, oceaniarc, G_KEY_FILE_NONE, & error ) ;
	if ( error )
	{
		message_box_error ( error -> message ) ;
		g_free ( oceaniarc ) ;
		
		g_key_file_free ( file ) ;
		return ;
	}
	
	gsize length = 0 ;
	gchar ** keys = g_key_file_get_groups ( file, & length ) ;
	
	gint i = 0 ;
	for ( i = 0 ; i < length ; i ++ )
	{
		gchar * icon = g_key_file_get_string ( file, keys [i], "icon", null ) ;
		gchar * name = g_key_file_get_string ( file, keys [i], "name", null ) ;
		gchar * command = g_key_file_get_string ( file, keys [i], "command", null ) ;
		gint column = g_key_file_get_integer ( file, keys [i], "column", null ) ;
		gboolean is_separator = g_key_file_get_boolean ( file, keys [i], "is_separator", null ) ;
		
		switch ( column )
		{
			case 1:
				oceania_append_column ( store1, icon, name, command, is_separator ) ;
				break ;
			case 2:
				oceania_append_column ( store2, icon, name, command, is_separator ) ;
				break ;
			default:
				g_debug ( "Invalid coloumn %d requested.", column ) ;
				break ;
		}
		
		g_free ( icon ) ;
		g_free ( name ) ;
		g_free ( command ) ;
	}
	
	g_strfreev ( keys ) ;
	g_key_file_free ( file ) ;

	g_free ( oceaniarc ) ;	
}

void oceania_change_color ( GtkWidget * widget, shagpointer data )
{
	GtkColorSelectionDialog * select = gtk_color_selection_dialog_new ( "Select color" ) ;
	gtk_dialog_add_button ( select, "Default", 2 ) ;
	
	GtkResponseType type = gtk_dialog_run ( select )  ;
	
	GdkColor color ;
	if ( type == -6 )
	{
		gtk_widget_destroy ( select ) ;
		return ;
	}
	else if ( type == -5 )
	{
		gtk_color_selection_get_current_color ( select -> colorsel, & color ) ;
	}
	else
	{
		color.red = default_color.red ;
		color.green = default_color.green ;
		color.blue = default_color.blue ;
	}
	
	if ( gdk_color_equal ( & color, & default_color ))
	{
		gtk_widget_show ( bg1 ) ;
		gtk_widget_show ( bg2 ) ;
	}
	else
	{
		gtk_widget_hide ( bg1 ) ;
		gtk_widget_hide ( bg2 ) ;
	}
	
	gtk_widget_destroy ( select ) ;
	
	//gtk_widget_modify_bg ( data, GTK_STATE_NORMAL, & color ) ;
	//gtk_widget_modify_bg ( lt, GTK_STATE_NORMAL, & color ) ;
	//gtk_widget_modify_bg ( lt2, GTK_STATE_NORMAL, & color ) ;
	
	oceania_save_color ( & color ) ;
	oceania_update_gui () ;
}

vodi oceania_change_color_reset ( GtkWidget * widget, shagpointer data )
{
	GdkColor color ;
	color.red = default_color.red ;
	color.green = default_color.green ;
	color.blue = default_color.blue ;

	gtk_color_selection_set_color ( data, & color ) ;
}

void oceania_save_color ( const GdkColor * color )
{
	gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".oceaniarc", null ) ;	
	
	GKeyFile * file = g_key_file_new () ;
	GError * error = null ;
	
	g_key_file_load_from_file ( file, oceaniarc, G_KEY_FILE_NONE, & error ) ;
	if ( error )
		g_warning ( "%s", error -> message ) ;
	
	g_key_file_set_integer ( file, "BackgroundColor", "red", color -> red ) ;
	g_key_file_set_integer ( file, "BackgroundColor", "blue", color -> blue ) ;
	g_key_file_set_integer ( file, "BackgroundColor", "green", color -> green ) ;
	
	gchar * data = g_key_file_to_data ( file, null, null ) ;
	FILE * fp = fopen ( oceaniarc, "w" ) ;
	
	fprintf ( fp, "%s", data ) ;
	fclose ( fp ) ;
	
	g_free ( oceaniarc ) ;
	g_key_file_free ( file ) ;
	
	g_free ( data ) ;
}

gboolean oceania_get_color ( GdkColor * color )
{
	gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".oceaniarc", null ) ;	

	GKeyFile * file = g_key_file_new () ;
	GError * error = null ;
	
	g_key_file_load_from_file ( file, oceaniarc, G_KEY_FILE_NONE, & error ) ;
	if ( error )
		g_warning ( "%s", error -> message ) ;
	
	gint red = 0, green = 0, blue = 0 ;
	GError * error1 = null, * error2 = null, * error3 = null ;
	
	red = g_key_file_get_integer ( file, "BackgroundColor", "red", & error1 ) ;
	blue = g_key_file_get_integer ( file, "BackgroundColor", "blue", & error2 ) ;
	green = g_key_file_get_integer ( file, "BackgroundColor", "green", & error3 ) ;
	
	gboolean result = false ;
	
	if ( error1 == null && error2 == null && error3 == null )
	{
		color -> red = red ;
		color -> green = green ;
		color -> blue = blue ;
		
		result = true ;
	}
	
	g_key_file_free ( file ) ;
	g_free ( oceaniarc ) ;
	
	return result ;
}

void oceania_set_logo ( GtkWidget * widget, shagpointer data )
{
	GtkFileChooserDialog * dialog = gtk_file_chooser_dialog_new ( 	"Open image",
																	null,
																	GTK_FILE_CHOOSER_ACTION_OPEN,
																	"Default",
																	2,
																	GTK_STOCK_CANCEL,
																	GTK_RESPONSE_REJECT,
																	GTK_STOCK_OK,
																	GTK_RESPONSE_ACCEPT,
																	null ) ;
	
	GtkFileFilter * filter = gtk_file_filter_new () ;
	gtk_file_filter_add_mime_type ( filter, "image/*" ) ;
	
	gtk_file_filter_set_name ( filter, "Images" ) ;
	gtk_file_chooser_add_filter ( dialog, filter ) ;
	
	GtkFileFilter * filter1 = gtk_file_filter_new () ;
	gtk_file_filter_add_pattern ( filter1, "*" ) ;
	
	gtk_file_filter_set_name ( filter1, "All files" ) ;
	gtk_file_chooser_add_filter ( dialog, filter1 ) ;
	
	GtkResponseType type = gtk_dialog_run ( dialog ) ;
	if ( type == GTK_RESPONSE_REJECT )
	{
		gtk_widget_destroy ( dialog ) ;
		return ;
	}
	else if ( type == 2 )
	{
		GdkPixbuf * pixbuf = oceania_find_image ( "oceania_logo.png" ) ;
		gtk_image_set_from_pixbuf ( data, pixbuf ) ;
		
		g_object_unref ( pixbuf ) ;
		oceania_update_gui () ;
		
		oceania_save_logo ( null ) ;
		
		gtk_widget_destroy ( dialog ) ;
		return ;
	}
	
	
	gchar * filename = gtk_file_chooser_get_filename ( dialog ) ;
	gtk_widget_destroy ( dialog ) ;
	
	GError * error = null ;
	GdkPixbuf * pixbuf = gdk_pixbuf_new_from_file_at_scale ( filename, 48, 48, false, & error ) ;
	
	if ( error )
		message_box_error ( error -> message ) ;
	else
	{
		gtk_image_set_from_pixbuf ( data, pixbuf ) ;
	}
	
	oceania_save_logo ( filename ) ;
	
	g_object_unref ( pixbuf ) ;
	g_free ( filename ) ;
	
	oceania_update_gui () ;
}
	
void oceania_save_logo ( const gchar * logo )
{
	gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".oceaniarc", null ) ;	
	
	GKeyFile * file = g_key_file_new () ;
	GError * error = null ;
	
	g_key_file_load_from_file ( file, oceaniarc, G_KEY_FILE_NONE, & error ) ;
	if ( error )
		g_warning ( "%s", error -> message ) ;

	if ( logo )
		g_key_file_set_string ( file, "logo", "filename", logo ) ;
	else
		g_key_file_remove_key ( file, "logo", "filename", null ) ;

	gchar * data = g_key_file_to_data ( file, null, null ) ;
	FILE * fp = fopen ( oceaniarc, "w" ) ;
	
	fprintf ( fp, "%s", data ) ;
	fclose ( fp ) ;
	
	g_free ( oceaniarc ) ;
	g_key_file_free ( file ) ;
	
	g_free ( data ) ;
}

gchar * oceania_get_logo ( void )
{
	gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".oceaniarc", null ) ;	

	GKeyFile * file = g_key_file_new () ;
	GError * error = null, * error1 = null ;
	
	g_key_file_load_from_file ( file, oceaniarc, G_KEY_FILE_NONE, & error ) ;
	if ( error )
		g_warning ( "%s", error -> message ) ;
	
	
	gchar * logo = g_key_file_get_string ( file, "logo", "filename", & error1 ) ;
	
	g_key_file_free ( file ) ;
	g_free ( oceaniarc ) ;
	
	if ( error1 )
	{
		if ( logo )
			g_free ( logo ) ;
		
		g_debug ( "%s", error1 -> message ) ;
		return null ;
	}
	else
		return logo ;
}

gboolean oceania_tree_view_is_selected ( GtkTreeView * view )
{
	GtkTreeSelection * select = gtk_tree_view_get_selection ( view ) ;
	return gtk_tree_selection_get_selected ( select, null, null ) ;
}

gchar * oceania_tree_view_run ( GtkTreeView * view )
{
	GtkTreeSelection * select = gtk_tree_view_get_selection ( view ) ;
	GtkTreeModel * model = gtk_tree_view_get_model ( view ) ;
	GtkTreeIter iter ;
	
	if ( ! gtk_tree_selection_get_selected ( select, null, & iter ))
		return false ;
	
	gchar * filename = null ;
	gtk_tree_model_get ( model, & iter, 2, & filename, -1 ) ;
	
	if ( filename != null )
	{
		oceania_spawn_async ( filename ) ;
	}
	
	g_free ( filename ) ;
	gtk_widget_hide ( oceania_menu ) ;
}

GtkTreeStore * susie_open_with_get_programs ( void )
{
	GDir * dir ;
	GError * error = null ;
	
	dir = g_dir_open ( "/usr/bin", 0, & error ) ;
	if ( error )
	{
		message_box_warning ( error -> message ) ;
		return null ;
	}
	
	gchar * name = g_dir_read_name ( dir ) ;
	GtkTreeStore * store = gtk_tree_store_new ( 1, G_TYPE_STRING ) ;
	
	while ( name )
	{
		GtkTreeIter iter ;
		gtk_tree_store_append ( store, & iter, null ) ;
		
		gtk_tree_store_set ( store, & iter, 0, name, -1 ) ;
		name = g_dir_read_name ( dir ) ;
	}
	
	g_dir_close ( dir ) ;
	error = null ;
	
	dir = g_dir_open ( "/usr/local/bin", 0, & error ) ;
	if ( error )
	{
		message_box_warning ( error -> message ) ;
		return null ;
	}
	
	name = g_dir_read_name ( dir ) ;
	
	while ( name )
	{
		GtkTreeIter iter ;
		gtk_tree_store_append ( store, & iter, null ) ;
		
		gtk_tree_store_set ( store, & iter, 0, name, -1 ) ;
		name = g_dir_read_name ( dir ) ;
	}
	
	g_dir_close ( dir ) ;
	return store ;
}

void susie_run ( GtkWidget * widget, shagpointer data )
{
	gchar * filename = gtk_entry_get_text ( widget ) ;
	if ( filename == null )
		return ;
	
	/*
	if ( susie_hash_probe ( filename ))
	{
		gchar * command = g_strdup_printf ( "susie \\#%s", filename ) ;
		
		GError * error = null ;
		g_spawn_command_line_async ( command, & error ) ;
		
		if ( error )
		{
			g_warning ( "lxpanel: %s", error -> message ) ;
			gdk_beep () ;
			
		}
		
		g_free ( command ) ;
	}
	
	else
	*/
	
	if ( g_file_test ( filename, G_FILE_TEST_IS_DIR ))
	{
		gchar * command = g_strdup_printf ( "susie \"%s\"", filename ) ;
		
		GError * error = null ;
		g_spawn_command_line_async ( command, & error ) ;
		
		if ( error )
		{
			g_warning ( "lxpanel: %s", error -> message ) ;
			gdk_beep () ;
			
		}
		
		g_free ( command ) ;
	}
	else
	{
		GError * error = null ;
		g_spawn_command_line_async ( filename, & error ) ;
		
		if ( error )
		{
			g_warning ( "lxpanel: %s", error -> message ) ;
			gdk_beep () ;
			
			return ;
		}
	}
		
	gtk_editable_delete_text ( widget, 0, -1 ) ;
	
	gtk_widget_hide ( oceania_menu ) ;
	oceania_update_gui () ;
	
	return ;
}

gboolean susie_hash_probe ( gchar * filename )
{
	if ( filename == null )
		return false ;
	
	if ( filename [0] == '#' )
		return true ;
	else
		return false ;
}

void oceania_start_pressed ( GtkWidget * widget, gpointer data )
{
	gtk_image_set_from_pixbuf ( image, data ) ;
}

void oceania_spawn_async ( gchar * command )
{
	gchar * command1 = g_strdup_printf ( "\"%s\"", command ) ;
	GError * error = null ;
	
	g_spawn_command_line_async ( command1, & error ) ;
	if ( error )
	{
		gchar * message = g_strdup_printf ( "Command failed: %s\n\n%s", command, error -> message ) ;
		message_box_error ( message ) ;
		
		g_free ( message ) ;
	}
	
	g_free ( command1 ) ;
	gtk_widget_hide ( oceania_menu ) ;
}

void oceania_row_activated ( GtkWidget * widget, GtkTreePath * tree_path, GtkTreeViewColumn * column, gpointer data )
{
	gchar * path = null ;
	GtkTreeIter iter ;
	
	gtk_tree_model_get_iter ( data, & iter, tree_path ) ;
	gtk_tree_model_get ( data, & iter, 2, & path, -1 ) ;
	
	GError * error = null ;
	g_spawn_command_line_async ( path, & error ) ;
	
	if ( error )
		message_box_error ( error -> message ) ;
	
	g_free ( path ) ;
	gtk_widget_hide ( oceania_menu ) ;
}

void oceania_recent_run ( GtkWidget * widget, gchar * data )
{
	gchar * command = g_strdup_printf ( "Open \"%s\" &", data ) ;
	system ( command ) ;
	
	g_free ( command ) ;
}

GtkMenu * oceania_recent_create ( GList * list )
{
	///> TODO
	/* 	 have to find out where gnome keeps it's recent files
	* 	 no one's runnin' april yet :)
	*/
	
	GtkMenu * mn = gtk_menu_new () ;
	GtkMenuItem * tem = gtk_menu_item_new_with_label ( "Empty" ) ;
	
	gtk_widget_set_sensitive ( tem, no ) ;
	
	gtk_menu_shell_append ( mn, tem ) ;
	gtk_widget_show_all ( mn ) ;
	
	return mn ;
	

	gchar * recent = g_build_filename ( g_getenv ( "HOME" ), ".susie", "recent", null ) ;
	if ( ! g_file_test ( recent, G_FILE_TEST_EXISTS ))
	{
		g_free ( recent ) ;
		return null ;
	}
	
	GDir * dir = g_dir_open ( recent, 0, null ) ;
	GtkMenu * menu = gtk_menu_new () ;

	GtkTooltips * tooltips = gtk_tooltips_new () ;
	
	gchar * name = g_dir_read_name ( dir ) ;
	while ( name )
	{
		GtkMenuItem * item = gtk_menu_item_new_with_label ( name ) ;
		gchar * path = g_build_filename ( recent, name, null ) ;
		
		g_signal_connect ( item, "activate", oceania_recent_run, path ) ;
		gtk_menu_shell_append ( menu, item ) ;				

		gchar * link = g_file_read_link ( path, null ) ;
		gtk_tooltips_set_tip ( tooltips, item, link, path ) ;
		
		g_free ( link ) ;

		list = g_list_append ( list, path ) ;
		name = g_dir_read_name ( dir ) ;
	}
	
	GtkMenuItem * item = gtk_menu_item_new_with_label ( "Clear recent files" ) ;
	g_signal_connect ( item, "activate", oceania_recent_clear, null ) ;
	
	gtk_menu_shell_append ( menu, gtk_separator_menu_item_new ()) ;
	gtk_menu_shell_append ( menu, item ) ;

	g_dir_close ( dir ) ;
	gtk_widget_show_all ( menu ) ;
	
	g_free ( recent ) ;
	return menu ;
}

void oceania_recent_free ( GList * list )
{
	g_list_foreach ( list, g_free, null ) ;
	g_list_free ( list ) ;
}	

void oceania_recent_menu ( GtkWidget * tree_view )
{
	GList * list = null ;
	gtk_widget_destroy ( recent_menu ) ;
	
	recent_menu = oceania_recent_create ( list ) ;

	//g_signal_connect ( menu, "selection-done", gtk_widget_destroy, null ) ;
	g_signal_connect_swapped ( recent_menu, "selection-done", oceania_recent_free, list ) ;
	
	gtk_menu_popup ( recent_menu, null, null, null, null, null, gtk_get_current_event_time ()) ;
	gtk_widget_show ( gtk_widget_get_toplevel ( tree_view )) ;
}

void oceania_handle_recent ( GtkTreeView * tree_view, GdkEventCrossing * event, shagpointer data )
{
	gtk_widget_grab_focus ( tree_view ) ;
	gint i = 0 ;
	
	GtkTreeSelection * select = gtk_tree_view_get_selection ( tree_view ) ;
	gtk_tree_selection_select_all ( select ) ;
	
	for ( i = 0 ; i < 50 ; i ++ )
	{
		if ( gtk_tree_selection_count_selected_rows ( select ) == 0 )
			return ;
		
		g_usleep ( 10000 ) ;
		oceania_update_gui () ;
		
	}
	
	oceania_recent_menu ( tree_view ) ;
}

void oceania_purge_dir ( gchar * recent )
{
	GDir * dir = g_dir_open ( recent, 0, null ) ;
	gchar * name = g_dir_read_name ( dir ) ;
	
	while ( name )
	{
		gchar * path = g_build_filename ( recent, name, null ) ;
		if ( g_file_test ( path, G_FILE_TEST_IS_DIR ))
			oceania_purge_dir ( path ) ;
		
		g_remove ( path ) ;
		
		g_free ( path ) ;
		name = g_dir_read_name ( dir ) ;
	}
	
	g_dir_close ( dir ) ;	
}

void oceania_recent_clear ( void )
{
	GtkDialog * dialog = gtk_message_dialog_new_with_markup (
						 
						 null,
						 GTK_DIALOG_MODAL,
						 GTK_MESSAGE_QUESTION,
						 GTK_BUTTONS_YES_NO,
						 "<span size=\"medium\"><b>Clear recent documents ?</b></span>\n\n"
						 "If you clear the recent documents list, you will clear the following:\n"
						 "» All items from the Start > Recent documents menu item.\n"
						 "» All items in the Susie library recent files.",
						 null ) ;
															
	gint result = gtk_dialog_run ( dialog ) ;
	gtk_widget_destroy ( dialog ) ;
	
	if ( result == GTK_RESPONSE_NO )
		return ;
	

	gchar * recent = g_build_filename ( g_getenv ( "HOME" ), ".susie", "recent", null ) ;
	if ( ! g_file_test ( recent, G_FILE_TEST_EXISTS ))
	{
		g_free ( recent ) ;
		return null ;
	}
	
	oceania_purge_dir ( recent ) ;
	g_free ( recent ) ;
	
	recent = g_build_filename ( g_getenv ( "HOME" ), ".susie/library/recent", null ) ;

	oceania_purge_dir ( recent ) ;
	g_free ( recent ) ;
	
	recent = g_build_filename ( g_getenv ( "HOME" ), ".susie/library/audio", null ) ;

	oceania_purge_dir ( recent ) ;
	g_free ( recent ) ;
	recent = g_build_filename ( g_getenv ( "HOME" ), ".susie/library/video", null ) ;

	oceania_purge_dir ( recent ) ;
	g_free ( recent ) ;
	recent = g_build_filename ( g_getenv ( "HOME" ), ".susie/library/images", null ) ;

	oceania_purge_dir ( recent ) ;
	g_free ( recent ) ;
	
}

void oceania_add_program ( GtkTreeView * view )
{
	GtkTreeStore * store = gtk_tree_view_get_model ( view ) ;
	GtkDialog * dialog = gtk_dialog_new_with_buttons ( "Add program",
														null,
														GTK_DIALOG_MODAL,
														"Add",
														1,
														"Cancel",
														0,
														null ) ;

	GtkTable * table = gtk_table_new ( 1, 1, no ) ;
	
	GtkEntry * entry1 = gtk_entry_new (),
			
			* entry3 = gtk_entry_new () ;
	
	GtkFileChooserButton * chooser = gtk_file_chooser_button_new ( "Choose icon", GTK_FILE_CHOOSER_ACTION_OPEN ) ;
	
	//GtkSpinButton * spin = gtk_spin_button_new_with_range ( 1.0, 2.0, 1.0 ) ;
	gtk_table_attach ( table, gtk_label_new ( "Name" ), 0, 1, 0, 1, GTK_SHRINK, GTK_SHRINK, 2, 2 ) ;
	gtk_table_attach ( table, entry1, 2, 3, 0, 1, GTK_FILL, GTK_FILL, 2, 2 ) ;

	gtk_table_attach ( table, gtk_label_new ( "Icon" ), 0, 1, 2, 3, GTK_SHRINK, GTK_SHRINK, 2, 2 ) ;
	gtk_table_attach ( table, chooser, 2, 3, 2, 3, GTK_FILL, GTK_FILL, 2, 2 ) ;

	gtk_table_attach ( table, gtk_label_new ( "Exec" ), 0, 1, 4, 5, GTK_SHRINK, GTK_SHRINK, 2, 2 ) ;
	gtk_table_attach ( table, entry3, 2, 3, 4, 5, GTK_FILL, GTK_FILL, 2, 2 ) ;

	//gtk_table_attach ( table, gtk_label_new ( "Column" ), 6, 7, 0, 1, GTK_SHRINK, GTK_SHRINK, 2, 2 ) ;
	//gtk_table_attach ( table, spin, 6, 7, 2, 3, GTK_SHRINK, GTK_SHRINK, 2, 2 ) ;

	gtk_box_pack_start ( dialog -> vbox, table, yes, yes, 2 ) ;
	
	gtk_widget_show_all ( dialog ) ;
	if ( ! gtk_dialog_run ( dialog ))
	{
		gtk_widget_destroy ( dialog ) ;
		return ;
	}
	
	gchar * name = gtk_entry_get_text ( entry1 ) ;
	gchar * icon = gtk_file_chooser_get_filename ( chooser ) ;
	
	gchar * exec = gtk_entry_get_text ( entry3 ) ;
	GdkPixbuf * pixbuf = oceania_find_image ( icon ) ;
	
	GtkTreeIter iter ;
	gtk_tree_store_append ( store, & iter, null ) ;
	
	gtk_tree_store_set ( store, & iter, 0, pixbuf, 1, name, 2, exec, 3, no, -1 ) ;
	
	gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".oceaniarc", null ) ;	
	
	GKeyFile * file = g_key_file_new () ;
	GError * error = null ;
	
	g_key_file_load_from_file ( file, oceaniarc, G_KEY_FILE_NONE, & error ) ;
	if ( error )
		g_warning ( "%s", error -> message ) ;
	
	g_key_file_set_string ( file, name, "name", name ) ;
	g_key_file_set_string ( file, name, "icon", icon ) ;
	
	g_key_file_set_string ( file, name, "command", exec ) ;
	g_key_file_set_boolean ( file, name, "is_separator", false ) ;
	
	gchar * tree = gtk_widget_get_name ( view ) ;
	if ( strcmp ( tree, "tree_view1" ) == 0 )
		g_key_file_set_integer ( file, name, "column", 1 ) ;
	else
		g_key_file_set_integer ( file, name, "column", 2 ) ;
	
	gchar * data = g_key_file_to_data ( file, null, null ) ;
	
	if ( data )
	{
		FILE * fp = fopen ( oceaniarc, "w" ) ;
		
		fprintf ( fp, "%s", data ) ;
		fclose ( fp ) ;
	}
	
	g_free ( data ) ;
	g_key_file_free ( file ) ;
	
	g_free ( oceaniarc ) ;
	
	g_free ( icon ) ;
	g_object_unref ( pixbuf ) ;
	
	gtk_widget_destroy ( dialog ) ;
}

void oceania_remove_program ( GtkTreeView * view )
{
	GtkTreeIter iter ;
	if ( ! gtk_tree_selection_get_selected ( gtk_tree_view_get_selection ( view ), null, & iter ))
		return ;

	gchar * name = null ;
	gtk_tree_model_get ( gtk_tree_view_get_model ( view ), & iter, 1, & name, -1 ) ;
	
	gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".oceaniarc", null ) ;	
	
	GKeyFile * file = g_key_file_new () ;
	GError * error = null ;
	
	g_key_file_load_from_file ( file, oceaniarc, G_KEY_FILE_NONE, & error ) ;
	if ( error )
		g_warning ( "%s", error -> message ) ;
	
	gsize length = 0, i = 0, count = -1 ;
	gchar ** groups = g_key_file_get_groups ( file, & length ) ;
	
	for ( i = 0 ; i < length ; i ++ )
	{
		gchar * app = g_key_file_get_string ( file, groups [i], "name", null ) ;
		if ( app == null )
			continue ;
		
		if ( strcmp ( app, name ) == 0 )
		{
			g_free ( app ) ;
			
			count = i ;
			break ;
		}
		
		g_free ( app ) ;
	}
	
	if ( count == -1 )
	{
		g_free ( name ) ;
		g_free ( oceaniarc ) ;
	
		g_strfreev ( groups ) ;
		g_key_file_free ( file ) ;
		return ;
	}
	
	g_key_file_remove_group ( file, groups [count], null ) ;
	gchar * data = g_key_file_to_data ( file, null, null ) ;
	
	FILE * fp = fopen ( oceaniarc, "w" ) ;
	
	fprintf ( fp, "%s", data ) ;
	fclose ( fp ) ;
	
	g_free ( oceaniarc ) ;
	g_key_file_free ( file ) ;
	
	g_free ( data ) ;
	gtk_tree_store_remove ( gtk_tree_view_get_model ( view ), & iter ) ;

	g_free ( name ) ;
	g_strfreev ( groups ) ;
}

GtkMenu * oceania_secondary_menu_create ( GtkTreeView * view )
{
	GtkMenu * menu = gtk_menu_new () ;
	GtkMenuItem * add = gtk_menu_item_new_with_label ( "Add programs" ),
				* del = gtk_menu_item_new_with_label ( "Remove from list" ),
				* properties = gtk_menu_item_new_with_label ( "Properties" ),
				* sep = gtk_menu_item_new_with_label ( "Add separator" ),
				* del_sep = gtk_menu_item_new_with_label ( "Remove separator" ) ;
	
	gtk_menu_shell_append ( menu, add ) ;
	gtk_menu_shell_append ( menu, sep ) ;
	
	gtk_menu_shell_append ( menu, gtk_separator_menu_item_new ()) ;
	gtk_menu_shell_append ( menu, del ) ;
	gtk_menu_shell_append ( menu, del_sep ) ;
	gtk_menu_shell_append ( menu, gtk_separator_menu_item_new ()) ;
	gtk_menu_shell_append ( menu, properties ) ;
	
	g_signal_connect_swapped ( sep, "activate", oceania_add_separator, view ) ;
	g_signal_connect_swapped ( del_sep, "activate", oceania_remove_separator, view ) ;
	
	g_signal_connect_swapped ( add, "activate", oceania_add_program, view ) ;
	g_signal_connect_swapped ( del, "activate", oceania_remove_program, view ) ;
	
	g_signal_connect_swapped ( properties, "activate", oceania_menu_item_properties, view ) ;
	
	gtk_widget_show_all ( menu ) ;
	return menu ;
}

void menu_destroy ( GtkMenu * menu )
{
	gtk_widget_destroy ( menu ) ;
	a_menu_is_up = false ;
}

void oceania_secondary_menu_popup ( GtkTreeView * view )
{
	a_menu_is_up = true ;
	
	GtkMenu * menu = oceania_secondary_menu_create ( view ) ;
	g_signal_connect_swapped ( menu, "selection-done", menu_destroy, menu ) ;
	
	gtk_menu_popup ( menu, null, null, null, null, null, gtk_get_current_event_time ()) ;
}	

void oceania_menu_item_properties ( GtkTreeView * view )
{
	GtkTreeIter iter ;
	if ( ! gtk_tree_selection_get_selected ( gtk_tree_view_get_selection ( view ), null, & iter ))
		return ;

	gchar * name = null ;
	gchar * exec = null ;
	
	gtk_tree_model_get ( gtk_tree_view_get_model ( view ), & iter, 1, & name, 2, & exec, -1 ) ;
	
	gchar * message = g_strdup_printf ( "Name: %s\nExec: %s", name, exec ) ;
	message_box_info ( message ) ;
	
	g_free ( message ) ;
	g_free ( name ) ;
	
	g_free ( exec ) ;
}

void oceania_add_separator ( GtkTreeView * view )
{
	GtkTreeModel * store = gtk_tree_view_get_model ( view ) ;
	
	GtkTreeIter iter ;
	gtk_tree_store_append ( store, & iter, null ) ;
	
	gtk_tree_store_set ( store, & iter, 3, yes, -1 ) ;
	
	gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".oceaniarc", null ) ;	
	
	GKeyFile * file = g_key_file_new () ;
	GError * error = null ;
	
	g_key_file_load_from_file ( file, oceaniarc, G_KEY_FILE_NONE, & error ) ;
	if ( error )
		g_warning ( "%s", error -> message ) ;
	
	gchar * name = g_strdup_printf ( "%d", gtk_get_current_event_time ()) ;
	
	g_key_file_set_string ( file, name, "name", "Eliz" ) ;
	g_key_file_set_boolean ( file, name, "is_separator", true ) ;
	
	gchar * tree = gtk_widget_get_name ( view ) ;
	if ( strcmp ( tree, "tree_view1" ) == 0 )
		g_key_file_set_integer ( file, name, "column", 1 ) ;
	else
		g_key_file_set_integer ( file, name, "column", 2 ) ;
	
	gchar * data = g_key_file_to_data ( file, null, null ) ;
	
	if ( data )
	{
		FILE * fp = fopen ( oceaniarc, "w" ) ;
		
		fprintf ( fp, "%s", data ) ;
		fclose ( fp ) ;
	}
	
	g_free ( data ) ;
	g_key_file_free ( file ) ;
	
	g_free ( oceaniarc ) ;
	g_free ( name ) ;
}

void oceania_remove_separator ( GtkTreeView * view )
{
	gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".oceaniarc", null ) ;	
	
	GKeyFile * file = g_key_file_new () ;
	GError * error = null ;
	
	g_key_file_load_from_file ( file, oceaniarc, G_KEY_FILE_NONE, & error ) ;
	if ( error )
		g_warning ( "%s", error -> message ) ;
	
	gsize length = 0, i = 0, count = -1 ;
	gchar ** groups = g_key_file_get_groups ( file, & length ) ;
	
	for ( i = 0 ; i < length ; i ++ )
	{
		gboolean is_separator = g_key_file_get_boolean ( file, groups [i], "is_separator", null ) ;
		if ( is_separator )
		{
			g_key_file_remove_group ( file, groups [i], null ) ;
			break ;
		}
	}
	
	gchar * data = g_key_file_to_data ( file, null, null ) ;
	FILE * fp = fopen ( oceaniarc, "w" ) ;
	
	fprintf ( fp, "%s", data ) ;
	fclose ( fp ) ;
	
	g_free ( oceaniarc ) ;
	g_key_file_free ( file ) ;
	
	g_free ( data ) ;
	g_strfreev ( groups ) ;

	GtkTreeModel * store = gtk_tree_view_get_model ( view ) ;
	gint num = gtk_tree_model_iter_n_children ( store, null ) ;
	
	for ( i = 0 ; i < num ; i ++ )
	{
		GtkTreeIter iter ;
		gtk_tree_model_iter_nth_child ( store, & iter, null, i ) ;
		
		gboolean is = false ;
		gtk_tree_model_get ( store, & iter, 3, & is, -1 ) ;
		
		if ( is )
		{
			gtk_tree_store_remove ( store, & iter ) ;
			break ;
		}
	}
}

gchar * april_key_file_get_string ( gchar * filename, gchar * section, gchar * key )
{
	GKeyFile * key_file = g_key_file_new () ;
	GError * error = null ;
	
	if ( ! g_key_file_load_from_file ( key_file, filename, G_KEY_FILE_NONE, & error ))
	{
		g_warning ( "Cannot open rcfile: %s",error -> message ) ;
		g_key_file_free ( key_file ) ;
		
		return ;
	
	}
	
	gchar * string = g_key_file_get_string ( key_file, section, key, null ) ;
	g_key_file_free ( key_file ) ;
	
	return string ;
}

void april_key_file_set_string ( gchar * filename, gchar * section, gchar * key, gchar * string )
{
	GKeyFile * key_file = g_key_file_new () ;
	GError * error = null ;
	
	if ( ! g_key_file_load_from_file ( key_file, filename, G_KEY_FILE_NONE, & error ))
	{
		g_warning ( "Cannot open rcfile: %s",error -> message ) ;
		g_key_file_free ( key_file ) ;
		
		return ;
	
	}
	
	g_key_file_set_string ( key_file, section, key, string ) ;
	april_key_file_write ( filename, key_file ) ;
	
	g_key_file_free ( key_file ) ;
}


void april_key_file_write ( gchar * filename, GKeyFile * file )
{
	gchar * data = g_key_file_to_data ( file, null, null ) ;
	FILE * fp = fopen ( filename, "w" ) ;
	
	if ( fp == null )
	{
		g_warning ( "Cannot open file: %s", strerror ( errno )) ;
		g_free ( data ) ;
		
		return ;
	}
	
	fprintf ( fp, "%s\n", data ) ;
	g_free ( data ) ;
	
	fclose ( fp ) ;
}

void oceania_shutdown_gui ( void )
{
	GtkDialog * dialog = gtk_dialog_new_with_buttons ( "Shutdown",
														null,
														GTK_DIALOG_MODAL,
														"Shutdown",
														1,
														"Cancel",
														0,
														null ) ;
	
	GtkEntry * entry = gtk_entry_new () ;
	gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".oceaniarc", null ) ;	
	
	gchar * cmd = april_key_file_get_string ( oceaniarc, "shutdown", "command" ) ;
	if ( cmd == null )
		gtk_entry_set_text ( entry, "shutdown" ) ;
	else
		gtk_entry_set_text ( entry, cmd ) ;
	
	g_free ( cmd ) ;

	gtk_box_pack_start ( dialog -> vbox, entry, yes, yes, 2 ) ;
	gtk_widget_show_all ( dialog ) ;
	
	if ( ! gtk_dialog_run ( dialog ))
	{
		g_free ( oceaniarc ) ;
		gtk_widget_destroy ( dialog ) ;
		
		return ;
	}

	gchar * command = gtk_entry_get_text ( entry ) ;
	
	if ( command )
		april_key_file_set_string ( oceaniarc, "shutdown", "command", command ) ;
	
	g_free ( oceaniarc ) ;
	
	GError * error = null ;
	g_spawn_command_line_async ( command, & error ) ;
	
	if ( error )
		message_box_error ( error -> message ) ;
	
	gtk_widget_destroy ( dialog ) ;
}

void oceania_log_off_gui ( void )
{
	GtkDialog * dialog = gtk_dialog_new_with_buttons ( "Log off",
														null,
														GTK_DIALOG_MODAL,
														"Log off",
														1,
														"Cancel",
														0,
														null ) ;
	
	GtkEntry * entry = gtk_entry_new () ;
	gchar * oceaniarc = g_build_filename ( g_getenv ( "HOME" ), ".oceaniarc", null ) ;	
	
	gchar * cmd = april_key_file_get_string ( oceaniarc, "logoff", "command" ) ;
	if ( cmd == null )
		gtk_entry_set_text ( entry, "killall gnome-session" ) ;
	else
		gtk_entry_set_text ( entry, cmd ) ;
	
	g_free ( cmd ) ;

	gtk_box_pack_start ( dialog -> vbox, entry, yes, yes, 2 ) ;
	gtk_widget_show_all ( dialog ) ;
	
	if ( ! gtk_dialog_run ( dialog ))
	{
		g_free ( oceaniarc ) ;
		gtk_widget_destroy ( dialog ) ;
		
		return ;
	}

	gchar * command = gtk_entry_get_text ( entry ) ;
	
	if ( command )
		april_key_file_set_string ( oceaniarc, "logoff", "command", command ) ;
	
	g_free ( oceaniarc ) ;
	
	GError * error = null ;
	g_spawn_command_line_async ( command, & error ) ;
	
	if ( error )
		message_box_error ( error -> message ) ;
	
	gtk_widget_destroy ( dialog ) ;
}
