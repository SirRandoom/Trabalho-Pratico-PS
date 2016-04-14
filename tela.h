#include <curses.h>
#include "bloco.h"

enum{INICIO,JOGO,FINAL};

typedef struct{
	int estado;
	int comprimento;
	int largura;
	WINDOW *janela;
	bloco blocos[];
}Tela;

Tela* cria_tela();
void mostra_tela(Tela* t);
void destroi_tela(Tela* t);