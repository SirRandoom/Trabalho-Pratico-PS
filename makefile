all: programa limpa

programa: pecas.o tela.o  
	gcc pecas.o tela.o -o tela -lncurses

pecas.o: pecas.c pecas.h tela.o 
	gcc -c pecas.c -lncurses

tela.o: tela.c tela.h 
	gcc -c tela.c -lncurses

limpa: 
	rm *.o

