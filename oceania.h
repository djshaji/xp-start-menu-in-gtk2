/*
 *      oceania.h
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

//#include "misc.h"

#include <gtk/gtk.h>

void oceania_create_columns ( GtkTreeView * tree_view1 ) ;
void oceania_create_columns_2 ( GtkTreeView * tree_view1 ) ;
void oceania_append_column ( GtkTreeStore * store, gchar * icon, gchar * display_name, gchar * path, gboolean is_separator ) ;
void oceania_mouse_over_callback ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data ) ;
void oceania_mouse_over_callback_reset ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data ) ;
void oceania_mouse_over_callback_1 ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data ) ;
void oceania_mouse_over_callback_1_reset ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data ) ;
GtkWidget * oceania_create_menu ( void ) ;
GdkPixbuf * oceania_find_image ( gchar * filename ) ;
gboolean oceania_is_separator ( GtkTreeModel * model, GtkTreeIter * iter, shagpointer data ) ;

void oceania_handle_all_programs ( GtkTreeView * tree_view, GdkEventCrossing * event, shagpointer data ) ;
void oceania_handle_all_programs_reset ( GtkTreeView * tree_view, GdkEventCrossing * event, shagpointer data ) ;

GtkMenu * all_programs ;
gboolean menu_is_up = false ;
void oceania_popup_menu ( void ) ;
void oceania_all_programs_popup ( void ) ;

void oceania_menu_run ( GtkTreeView * view, GtkTreePath * path, GtkTreeViewColumn * column, shagpointer data ) ;
gboolean oceania_button_press_callback ( GtkWidget * widget, GdkEventButton * event, shagpointer data ) ;

void oceania_key_press_handler ( GtkWidget * widget, GdkEventKey * event, shagpointer data ) ;
void oceania_hide_menu ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data ) ;
void oceania_log_off ( void ) ;
void oceania_shutdown ( void ) ;

gboolean oceania_grab_focus ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data ) ;

void oceania_signal_handler ( gint signum ) ;
void oceania_change_color ( GtkWidget * widget, shagpointer data ) ;
vodi oceania_change_color_reset ( GtkWidget * widget, shagpointer data ) ;

void oceania_set_logo ( GtkWidget * widget, shagpointer data ) ;
gchar * oceania_get_logo ( void ) ;

//GtkTreeView * tree_view1, * tree_view2  ;
gchar * oceania_tree_view_run ( GtkTreeView * view ) ;

GtkTreeStore * susie_open_with_get_programs ( void ) ;
void susie_run ( GtkWidget * widget, shagpointer data ) ;
gboolean susie_hash_probe ( gchar * filename ) ;

GtkImage * bg1, * bg2 ;
GdkColor default_color ;
GtkLayout * lt, * lt2  ;

void nina_spawn_async ( GtkWidget * widget, gchar * command ) ;
void oceania_start_pressed ( GtkWidget * widget, gpointer data ) ;
void oceania_spawn_async ( gchar * command ) ;

void oceania_row_activated ( GtkWidget * widget, GtkTreePath * tree_path, GtkTreeViewColumn * column, gpointer data ) ;

void oceania_recent_run ( GtkWidget * widget, gchar * data ) ;
GtkMenu * oceania_recent_create ( GList * list_for_pointers ) ;
void oceania_recent_menu ( GtkWidget * tree_view ) ;
void oceania_handle_recent ( GtkTreeView * tree_view, GdkEventCrossing * event, shagpointer data ) ;

GtkMenu * recent_menu = null ;
void oceania_recent_clear ( void ) ;
void oceania_update_gui ( void ) ;
void oceania_handle_all_programs ( GtkTreeView * tree_view, GdkEventCrossing * event, shagpointer data ) ;
void oceania_hide_menu ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data ) ;

GtkWidget * oceania_menu ;
GtkWidget * image ;
void oceania_add_program ( GtkTreeView * view ) ;
void oceania_remove_program ( GtkTreeView * view ) ;
GtkMenu * oceania_secondary_menu_create ( GtkTreeView * view ) ;
void oceania_secondary_menu_popup ( GtkTreeView * view ) ;

gboolean a_menu_is_up = false ;
void oceania_menu_item_properties ( GtkTreeView * view ) ;
void oceania_add_separator ( GtkTreeView * view ) ;
void oceania_remove_separator ( GtkTreeView * view ) ;
void oceania_shutdown_gui ( void ) ;
void oceania_log_off_gui ( void ) ;
