#include<stdio.h>
#include<stdlib.h>
#include"engine.h"

typedef struct placar{
	char jogadores[5][4];
	int pontuacoes[5];
	int tempos_m[5];
	int tempos_s[5];
	int contador_jogadores;
	FILE *arquivo;
}placar;

void cria_placar();
void atualiza_placar(int pontuacao);
void mostra_placar();
void destroi_placar();
