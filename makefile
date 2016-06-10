all: programa  limpa

programa: pecas.o tela.o engine.o main.o placar.o
	gcc placar.o pecas.o tela.o engine.o main.o -o main -g -lncurses -L./ -lcunit 

<<<<<<< HEAD
testes.o: testes.c tela.h tela.c engine.c engine.h
	gcc -c testes.c -L./CUnit -lcunit
=======
testes.o: testes.c tela.h tela.c
	gcc -c testes.c -L./CUnit -lcunit -g
>>>>>>> 41d44ab225b11c93e84864c99c48b42b61d3b834

main.o: main.c engine.h engine.c pecas.h pecas.c tela.h tela.c bloco.h placar.c placar.h
	gcc -c main.c -lncurses -L./CUnit -lcunit -g

engine.o: engine.c engine.h
	gcc -c engine.c -lncurses -g
	
pecas.o: pecas.c pecas.h  tela.h
	gcc -c pecas.c -lncurses -g
 
tela.o: tela.c tela.h pecas.h 
	gcc -c tela.c -lncurses -g
	
placar.o: placar.h placar.c
	gcc -c placar.c -lncurses -g

limpa: 
	rm *.o

