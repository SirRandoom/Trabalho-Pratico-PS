/** \file */

#include<curses.h>
#include<stdlib.h>
#include<stdio.h>
#include"bloco.h"
#include<string.h>

/** Variável enumerada que indica o estado do jogo.*/
enum estado {INICIO,JOGO,FINAL}; 

/** /struct Define a tela do jogo.*/
typedef struct Tela{
  char jogador[3]; /**<Nome do atual jogador.*/ 
  int letra;
  int estado; /**<Estado atual do jogo.*/
  int pontos; /**<Pontuação do jogador.*/
  int tempo_m; /**<Tempo de execução em minutos.*/
  int tempo_s; /**<Tempo de execução em segundos.*/
  int comprimento; /**<Comprimento da tela.*/
  int largura; /**<Largura da tela.*/
  WINDOW *janela; /**<Ponteiro para a janela do jogo.*/
  struct Peca* peca; /**<Ponteiro para a peça em movimento.*/
  bloco /*@out@*/ blocos[]; /**<Matriz dos blocos na tela.*/
}Tela;

Tela* cria_tela(); 
void mostra_tela(Tela* t);
void mostra_pontos(int pontos);
void mostra_tempo(int minutos,int segundos); 
void destroi_tela(Tela* t);
void define_jogador(Tela* t);
void troca_letra(Tela *t,int valor);
void muda_letra(Tela *t, int valor); 
void limpa_linha (Tela* t, int y);
void desce_linhas (Tela* t, int y);
int verifica_linha(Tela* t);
int checa_fim(Tela* t);

