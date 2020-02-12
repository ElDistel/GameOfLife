main:		main.o grille.o jeu.o io.o
		gcc -o main main.o grille.o jeu.o io.o -lm

main.o:		code/main.c code/grille.h code/jeu.h code/io.h
		gcc -c code/main.c

grille.o:	code/grille.c code/grille.h
		gcc -c code/grille.c

io.o:		code/io.c code/io.h
		gcc -c code/io.c

jeu.o:		code/jeu.c code/jeu.h
		gcc -c code/jeu.c

clean:
		rm -rf *.o main

dist:
		tar -c --lzma -f DISTEL_Louis_tar.xz *.c *.h Makefile
