main:		main.o grille.o jeu.o io.o
		gcc -o main main.o grille.o jeu.o io.o -lm

main.o:		main.c grille.h jeu.h io.h
		gcc -c main.c

grille.o:	grille.c grille.h
		gcc -c grille.c

io.o:		io.c io.h
		gcc -c io.c

jeu.o:		jeu.c jeu.h
		gcc -c jeu.c

clean:
		rm -rf *.o

dist:
		tar -c --lzma -f DISTEL_Louis_tar.xz *.c *.h Makefile
