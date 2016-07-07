SHELL=/bin/bash
C=gcc -g
CLIBS=-lncurses -lcunit
OBJS= pecas.o tela.o placar.o engine.o
TESTE_OBJS= tela_teste.o pecas_teste.o placar_teste.o engine_teste.o
LINK=-L./CUnit

all: programa teste

programa: $(OBJS)  main.o
	$(C) main.o $(OBJS) -o tetris $(CLIBS) $(LINK)

main.o: main.c tela.h tela.c pecas.h pecas.c placar.h placar.c engine.h engine.c
	$(C) main.c -c $(CLIBS) $(LINK)

teste: main_teste.c $(TESTE_OBJS)
	$(C) main_teste.c $(OBJS) $(TESTE_OBJS) -o testes.exe $(CLIBS) $(LINK)

engine_teste.o: engine.o
	$(C) engine_teste.c -c $(CLIBS)

placar_teste.o: placar.o
	$(C) placar_teste.c -c $(CLIBS)

pecas_teste.o: pecas.o
	$(C) pecas_teste.c -c $(CLIBS)

tela_teste.o: tela.o
	$(C) tela_teste.c -c $(CLIBS)

engine.o: engine.c engine.h
	$(C) engine.c -c $(CLIBS)

placar.o: placar.c placar.h tela.o
	$(C) placar.c -c $(CLIBS)

pecas.o: pecas.c pecas.h tela.h tela.c bloco.h
	$(C) pecas.c -c $(CLIBS)

tela.o: tela.c tela.h pecas.h pecas.c bloco.h
	$(C) tela.c -c $(CLIBS)

limpa: 
	rm *.o

