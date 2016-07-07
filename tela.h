/** \file */

#include<curses.h>

#ifndef TELA_H
#define TELA_H

#ifdef TELA_OWN
  #define TELA_EXT
#else
  #define TELA_EXT extern
#endif

/** \enum estado Variável enumerada que indica o estado do jogo.*/
enum estado {INICIO,JOGO,FINAL}; 

/** /struct Define a tela do jogo.*/
typedef struct tela{
  char jogador[3]; /**<Nome do atual jogador.*/ 
  int letra; /**<Auxiliar na escolha de nome do jogador.*/
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

TELA_EXT Tela* cria_tela(); 
TELA_EXT void mostra_tela(Tela* t);
TELA_EXT void mostra_pontos(int pontos);
TELA_EXT void mostra_tempo(int minutos,int segundos); 
TELA_EXT void destroi_tela(Tela* t);
TELA_EXT void define_jogador(Tela* t);
TELA_EXT void troca_letra(Tela *t,int valor);
TELA_EXT void muda_letra(Tela *t, int valor); 
TELA_EXT void limpa_linha (Tela* t, int y);
TELA_EXT void desce_linhas (Tela* t, int y);
TELA_EXT int verifica_linha(Tela* t);
TELA_EXT int checa_fim(Tela* t);

#undef TELA_EXT
#endif
