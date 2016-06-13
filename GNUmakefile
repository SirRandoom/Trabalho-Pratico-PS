SHELL=/bin/bash
GCC=gcc -Wall -g
CLIBS=-lncurses -lcunit
OBJS= pecas.o tela.o placar.o engine.o

all: programa teste_exe limpa

programa: $(OBJS) main.c
	$(GCC) main.c $(OBJS) -o tetris $(CLIBS)

teste_exe: testes_exe.c testes.o
	$(GCC) testes_exe.c $(OBJS) -o testes_exe $(CLIBS)

testes.o: $(OBJS) testes.c testes.h
	$(GCC) testes.c -c $(CLIBS)

engine.o: engine.c engine.h
	$(GCC) engine.c -c $(CLIBS)

placar.o: placar.c placar.h tela.o
	$(GCC) placar.c -c $(CLIBS)

pecas.o: pecas.c pecas.h tela.h tela.c bloco.h
	$(GCC) pecas.c -c $(CLIBS)

tela.o: tela.c tela.h pecas.h pecas.c bloco.h
	$(GCC) tela.c -c $(CLIBS)

limpa: 
	rm *.o

