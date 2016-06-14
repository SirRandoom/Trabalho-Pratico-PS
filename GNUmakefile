SHELL=/bin/bash
GCC=gcc -g
CLIBS=-lncurses -lcunit
OBJS= pecas.o tela.o placar.o engine.o
LINK=-L./CUnit

all: programa teste_exe limpa

programa: $(OBJS)  main.o
	$(GCC) main.o $(OBJS) -o tetris $(CLIBS) $(LINK)

main.o: main.c tela.h tela.c pecas.h pecas.c placar.h placar.c engine.h engine.c
	$(GCC) main.c -c $(CLIBS) $(LINK)

teste_exe: teste_exe.c testes.o
	$(GCC) testes.o teste_exe.c $(OBJS) -o testes_exe $(CLIBS) $(LINK)

testes.o: $(OBJS) testes.c testes.h
	$(GCC) testes.c -c $(CLIBS) $(LINK)

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

