/** \file */

#include <stdio.h>
#include <stdlib.h>
#include "tela.h"

/** \struct Peca */
typedef struct Peca{ 
  int tamanho; /**<Tamanho da peça.*/
  unsigned short int cor_peca; /**<Cor da peça.*/
  unsigned short int move_peca; /**<Booleano que checa se a peça está em movimento ou não.*/
  bloco* blocos[]; /**<Referência para blocos na tela.*/
}peca;

void nova_peca(Tela* tela); 
void move_peca_x(peca* peca, int x);
void move_peca_y(peca* peca, int y);
void libera_peca(peca* p);
