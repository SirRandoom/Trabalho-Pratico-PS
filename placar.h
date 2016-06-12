#include<stdio.h>
#include<stdlib.h>
#include"engine.h"
#include"tela.h"

typedef struct placar{
	char jogadores[5][4]; //vetor de jogadores no placar
	int pontuacoes[5]; //vetor de pontuação dos jogadores no placar
	int tempos_m[5];//vetor de tempo em minutos dos jogadores no placar
	int tempos_s[5];//vetor de tempo em segundos dos jogadores no placar
	int contador_jogadores; //contador de jogadores presentes no placar (máximo 5)
	FILE *arquivo; //arquivo usado para abrir o placar (pontuacao.txt) para leitura e escrita
	Tela* tela; //temporário (?)
}placar;



void cria_placar();
void atualiza_placar(int pontuacao);
void mostra_placar();
void destroi_placar();
void seta_Tela(Tela *t);
