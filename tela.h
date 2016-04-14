#include<curses.h>
#include<stdlib.h>
#include<stdio.h>
#include"bloco.h"

enum estado {INICIO,JOGO,FINAL};

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

