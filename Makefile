
# variables associees aux dossiers 

SDIR = src
ODIR = obj
BDIR = bin
IDIR = include
LDIR = lib
MODE = CAIRO

# compile flags

CPPFLAGS = -Iinclude -I/usr/include/cairo
LDFLAGS = -lcairo -lm -lX11 -ljeu -L lib/

CFLAGS = $(CPPFLAGS) -Wall -g

vpath %.h $(IDIR)
vpath %.c $(SDIR)
vpath %.o $(ODIR)


main: main.o grille.o jeu.o io.o
	@mkdir -p $(BDIR)
	@mkdir -p $(LDIR)

	ar -crv $(LDIR)/libjeu.a $(ODIR)/jeu.o $(ODIR)/grille.o
	ranlib $(LDIR)/libjeu.a

	gcc -D $(MODE) $(CFLAGS) -o $(BDIR)/$@ $(ODIR)/main.o $(ODIR)/grille.o $(ODIR)/jeu.o $(ODIR)/io.o $(LDFLAGS)
	rm -f $(ODIR)/*.o		

%.o: %.c
	@mkdir -p $(ODIR)
	gcc -D $(MODE) $(CFLAGS) -o $(ODIR)/$@ -c $<


clean:	
	rm -rf $(ODIR)/*.o $(BDIR)/main
	rm -rf $(BDIR)
	rm -rf $(ODIR)
	rm -rf $(LDIR)

dist:
	tar -c --lzma -f DistelLouis-GoL-v6.0.tar.xz src include grilles Makefile Doxyfile
