#include "bloco.h"

enum estado {INICIO,JOGO,FINAL};

typedef struct Tela{
	int estado;
	int comprimento;
	int largura;
	WINDOW *janela;
	struct Peca* peca;
	bloco blocos[];
}Tela;

Tela* cria_tela();
void mostra_tela(Tela* t);
void destroi_tela(Tela* t);
