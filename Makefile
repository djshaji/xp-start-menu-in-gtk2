GTK_CFLAGS=`pkg-config gtk+-2.0 --cflags`
GTK_LIBS=`pkg-config gtk+-2.0 --libs`

all:
	cc main.c $(GTK_CFLAGS) $(GTK_LIBS) -o start-menu -w
	
	xkbbell

install:
	if ! test -d ~/.icons/start-menu ; then mkdir -v ~/.icons/start-menu ; fi
	cp -vr icons/* ~/.icons/start-menu
	cp -v oceaniarc ~/.oceaniarc

	if ! test -d ~/bin ; then mkdir -v ~/bin ; fi
	cp -v start-menu ~/bin/
