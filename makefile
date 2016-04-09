all: programa limpa

programa: tela.o 
	gcc tela.o -o tela -lncurses

tela.o: tela.c tela.h
	gcc -c tela.c -lncurses

limpa: 
	rm *.o

