#include<curses.h>
#include<stdlib.h>
#include<stdio.h>
#include"bloco.h"

enum estado {INICIO,JOGO,FINAL};

typedef struct Tela{
	int estado;
	int pontos;
	int tempo_m,tempo_s;
	int comprimento;
	int largura;
	WINDOW *janela;
	struct Peca* peca;
	bloco blocos[];
}Tela;

Tela* cria_tela();
void mostra_tela(Tela* t);
void mostra_pontos(int pontos);
void mostra_tempo(int minutos,int segundos);
void destroi_tela(Tela* t);
void limpa_linha (Tela* t, int y);
void desce_linhas (Tela* t, int y);
int verifica_linha(Tela* t);
int checa_fim(Tela* t);
