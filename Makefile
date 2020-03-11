
# variables associees aux dossiers 

SDIR = src
ODIR = obj
BDIR = bin
IDIR = include

# compile flags

CFLAGS = -Wall -Iinclude




main:		main.o grille.o jeu.o io.o
		@mkdir -p $(BDIR)
		gcc $(CFLAGS) -o $(BDIR)/main $(ODIR)/main.o $(ODIR)/grille.o $(ODIR)/jeu.o $(ODIR)/io.o -lm

main.o:		$(SDIR)/main.c
		@mkdir -p $(ODIR)
		gcc $(CFLAGS) -o $(ODIR)/main.o -c $(SDIR)/main.c

grille.o:	$(SDIR)/grille.c 
		@mkdir -p $(ODIR)
		gcc $(CFLAGS) -o $(ODIR)/grille.o -c $(SDIR)/grille.c

io.o:		$(SDIR)/io.c 
		@mkdir -p $(ODIR)
		gcc $(CFLAGS) -o $(ODIR)/io.o -c $(SDIR)/io.c

jeu.o:		$(SDIR)/jeu.c
		@mkdir -p $(ODIR)
		gcc $(CFLAGS) -o $(ODIR)/jeu.o -c $(SDIR)/jeu.c

clean:	
		rm -rf $(ODIR)/*.o $(BDIR)/main
		rm -rf dist/
		rm -rf $(BDIR)
		rm -rf $(ODIR)

dist:
		tar -c --lzma -f DistelLouis-GoL-v3.0.tar.xz src include grilles Makefile Doxyfile
