all: programa limpa

programa: pecas.o tela.o engine.o main.o
	gcc pecas.o tela.o engine.o main.o -o main -lncurses

main.o: main.c engine.h engine.c pecas.h pecas.c tela.h tela.c bloco.h
	gcc -c main.c -lncurses

engine.o: engine.c engine.h
	gcc -c engine.c -lncurses
	
pecas.o: pecas.c pecas.h  tela.h
	gcc -c pecas.c -lncurses

tela.o: tela.c tela.h pecas.h 
	gcc -c tela.c -lncurses

limpa: 
	rm *.o

