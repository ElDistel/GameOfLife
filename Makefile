
# variables associees aux dossiers 

SDIR = src
ODIR = obj
BDIR = bin
IDIR = include
MODE = CAIRO

# compile flags

CPPFLAGS = -Iinclude -I/usr/include/cairo
LDFLAGS = -lcairo -lm -lX11

CFLAGS = $(CPPFLAGS) -Wall -g

vpath %.h $(IDIR)
vpath %.c $(SDIR)
vpath %.o $(ODIR)


main: main.o grille.o jeu.o io.o
	@mkdir -p $(BDIR)
	gcc -D $(MODE) $(CFLAGS) -o $(BDIR)/$@ $(ODIR)/main.o $(ODIR)/grille.o $(ODIR)/jeu.o $(ODIR)/io.o $(LDFLAGS)
	rm -f $(ODIR)/*.o		

%.o: %.c
	@mkdir -p $(ODIR)
	gcc -D $(MODE) $(CFLAGS) -o $(ODIR)/$@ -c $<


clean:	
	rm -rf $(ODIR)/*.o $(BDIR)/main
	rm -rf $(BDIR)
	rm -rf $(ODIR)

dist:
	tar -c --lzma -f DistelLouis-GoL-v3.0.tar.xz src include grilles Makefile Doxyfile
	