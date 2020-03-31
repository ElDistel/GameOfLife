
# variables associees aux dossiers 

SDIR = src
ODIR = obj
BDIR = bin
IDIR = include

# compile flags

CFLAGS = -Wall -Iinclude
CPPFLAGS += -Iinclude -I/usr/include/cairo
LDFLAGS += -lcairo -lm -lX11




main:		main.o grille.o jeu.o io.o
		@mkdir -p $(BDIR)
		@mkdir -p $(BDIR)
		gcc $(CFLAGS) -o $(BDIR)/main $(ODIR)/main.o $(ODIR)/grille.o $(ODIR)/jeu.o $(ODIR)/io.o -lm

%.o : $(SDIR)%.c
	mkdir -p $(ODIR)
	gcc $(CFLAGS) -o $(ODIR)/$@ -c $<
	

clean:	
		rm -rf $(ODIR)/*.o $(BDIR)/main
		rm -rf dist/
		rm -rf $(BDIR)
		rm -rf $(ODIR)

dist:
		tar -c --lzma -f DistelLouis-GoL-v3.0.tar.xz src include grilles Makefile Doxyfile
