/** \file */

#ifndef BLOCO_H
#define BLOCO_H

/** \struct Bloco*/
typedef struct Bloco{
  char bolinha; /**< Caractere atual da peça. */
  unsigned short int cor; /**< Cor da peça. */
  int pos_x; /**<Coordenada cartesiana horizontal do bloco.*/
  int pos_y; /**< Coordenada cartesiana vertical do bloco.*/
  unsigned short int move; /**< Valor booleano que indica se o bloco está em movimento ou não.*/
  struct Bloco* esquerda; /**<Ponteiro para vizinho à esquerda.*/
  struct Bloco* direita; /**<Ponteiro para vizinho à direita.*/
  struct Bloco* abaixo; /**<Ponteiro para vizinho abaixo.*/
  struct Bloco* acima; /**<Ponteiro para vizinho acima.*/
}bloco; 

/** \def COMPRIMENTO Comprimento do mapa.*/
#define COMPRIMENTO 15
/** \def LARGURA Largura do mapa.*/
#define LARGURA 25

#endif
