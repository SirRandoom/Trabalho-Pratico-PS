/** \file */

#include <stdio.h>
#include <stdlib.h>
#include "tela.h"

enum Tipo_Peca {
	Tipo_I,
	Tipo_Z,
	Tipo_T,
	Tipo_O,
	Tipo_L,
}; typedef enum Tipo_Peca tp_peca;

/** \struct Peca */
typedef struct Peca{ 
  int tamanho; /**<Tamanho da peça.*/
  unsigned short int cor_peca; /**<Cor da peça.*/
  unsigned short int move_peca; /**<Booleano que checa se a peça está em movimento ou não.*/
  float velocidade;
  tp_peca tipo;
  bloco* centro_de_rotacao;
  bloco** blocos; /**<Referência para blocos na tela.*/
}peca;

void nova_peca(Tela* tela); 
void move_peca_x(peca* peca, int x);
void move_peca_y(peca* peca, int y);
void rotaciona_peca(peca* peca);
void speed_up (peca* peca, int y);
void libera_peca(peca* p);

peca* cria_peca_I(Tela* tela);
peca* cria_peca_Z(Tela* tela);
peca* cria_peca_T(Tela* tela);
peca* cria_peca_O(Tela* tela);
peca* cria_peca_L(Tela* tela);
