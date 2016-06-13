all: programa  limpa

programa: pecas.o tela.o engine.o main.o placar.o testes.o
	gcc testes.o placar.o pecas.o tela.o engine.o main.o -o main -g -lncurses -L./ -lcunit 

main.o: main.c engine.h engine.c pecas.h pecas.c tela.h tela.c bloco.h placar.c placar.h testes.c testes.h
	gcc -c main.c -lncurses -L./CUnit -lcunit -g

engine.o: engine.c engine.h
	gcc -c engine.c -lncurses -g
	
pecas.o: pecas.c pecas.h  tela.h
	gcc -c pecas.c -lncurses -g
 
tela.o: tela.c tela.h pecas.h 
	gcc -c tela.c -lncurses -g
	
placar.o: placar.h placar.c
	gcc -c placar.c -lncurses -g

testes.o: testes.h testes.c tela.h tela.c pecas.h pecas.c
	gcc -c testes.c -L./CUnit -lcunit -g

limpa: 
	rm *.o

