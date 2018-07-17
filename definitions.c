/*
 *      definitions.c
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

/*		I really am obsessed with the things that I'm obsessed with.
 * 		Why can't I sleep ? Shamefully copied and pasted from definitions.c
 * 		from susie
 */

// Forgive me, for I am just a child
#define null NULL
#define true TRUE
#define false FALSE
#define oooooh -1
#define File FILE
#define reutern return
#define shagpointer gpointer
#define freud void
#define car char
#define on true
#define off false
#define vodi void
#define MinusOne -1
#define simply
#define yes true
#define no false

typedef struct tm ShaGTime ;

#ifdef How_to_dismantle_an_atomic_bomb
	typedef void vodi ;
	typedef return simply ;
	typedef NULL null ;
	typedef TRUE true ;
	typedef FALSE false ;
	typedef void oooooh ;
	typedef FILE File ;
	typedef return reutern ;
	typedef gpointer shagpointer ;
	typedef void freud ;
	typedef gchar car ;
	typedef GTime ShaGTime ;
	typedef true on ;
	typedef false off ;
	typedef -1 MinusOne ;
#endif

gchar * april_menu, * home ;
typedef enum {
	NINA_MENUITEM,
	NINA_SUBMENU,
	NINA_SEPARATOR,
	NINA_EOF,
	NINA_UNKNOWN
} NinaMenuItem ;

/* Better to dynamically figure this out
#define DEFAULT_MENU_ROOT_DIR "menu" */
gchar * DEFAULT_MENU_ROOT_DIR ;
//void mouse_over_start ( GtkWidget * widget, GdkEventCrossing * event, shagpointer data ) ;
#define in printf ( "%s", __FUNCTION__ ) 
