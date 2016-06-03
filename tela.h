#include<curses.h>
#include<stdlib.h>
#include<stdio.h>
#include"bloco.h"

enum estado {INICIO,JOGO,FINAL}; //enumerador que define o estado do jogo

typedef struct Tela{ //Struct que define a Tela do jogo
	int estado; //estado atual do jogo
	int pontos; //pontuação do jogador
	int tempo_m,tempo_s; //Tempo em minutos (tempo_m) e tempo em segundos (tempo_s)
	int comprimento; //Comprimento da Tela
	int largura; //Largura da Tela
	WINDOW *janela; //ponteiro da janela do jogo
	struct Peca* peca; //ponteiro da peça em movimento
	bloco blocos[]; //matriz de blocos da tela (TAD = vetor)
}Tela;

Tela* cria_tela(); //Função que cria um novo ponteiro de tela tela
void mostra_tela(Tela* t); //função responsável por mostrar os elementos da tela
void mostra_pontos(int pontos); //função responsável por mostrar a pontuação do jogador
void mostra_tempo(int minutos,int segundos); //função responsável por mostrar o tempo de partida
void destroi_tela(Tela* t); //função responsável por finalizar a tela do jogo
void limpa_linha (Tela* t, int y); //função responsável por limpar uma linha de blocos completa
void desce_linhas (Tela* t, int y); //função responsável por descer os blocos das linhas superiores quando uma linha for limpa
int verifica_linha(Tela* t); //função que verifica se a linha está preenchida com blocos de peça
int checa_fim(Tela* t); //função que verifica se uma peça atingiu o limite superior, finalizando o jogo.
