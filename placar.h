/**\file*/

#ifndef BLOCO_H
#include"bloco.h"
#endif

#ifndef PECAS_H
#include"pecas.h"
#endif

#ifndef TELA_H
#include"tela.h"
#endif

#ifndef PLACAR_H
#define PLACAR_H

#ifdef PLACAR_OWN
  #define PLACAR_EXT
#else
  #define PLACAR_EXT extern
#endif

/** \struct Placar */
typedef struct Placar{
  char jogadores[5][4]; /**<Vetor de jogadores.*/
  int pontuacoes[5]; /**<Vetor de pontuação dos jogadores no placar.*/
  int tempos_m[5];/**<Vetor de tempo em minutos dos jogadores.*/
  int tempos_s[5];/**<Vetor de tempo em segundos dos jogadores.*/
  int anos[5]; /**<Vetor de anos dos jogadores.*/
  int meses[5]; /**<Vetor de meses dos jogadores no placar.*/
  int dias[5]; /**<Vetor de dias dos jogadores no placar.*/
  int contador_jogadores; /**<Contador de jogadores presentes no placar (máximo 5).*/
  FILE *arquivo; /**<Ponteiro para o arquivo usado para abrir o placar (pontuacao.txt) para leitura e escrita.*/
  char jogador[3]; /**<Nome do jogador atual.*/
  int pontuacao; /**<Pontuacao do jogador atual.*/
  int tempo_m; /**<Tempo em minutos do jogador atual.*/
  int tempo_s; /**<Tempo em segundos do jogador atual.*/
}placar; 

PLACAR_EXT void cria_placar();
PLACAR_EXT void atualiza_placar(int pontuacao);
PLACAR_EXT void mostra_placar();
PLACAR_EXT void destroi_placar();
PLACAR_EXT void seta_jogador(Tela *t);

#undef PLACAR_EXT
#endif
