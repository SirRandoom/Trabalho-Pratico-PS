/** \file */

#ifndef BLOCO_H
#include"bloco.h"
#endif

#ifndef TELA_H
#include"tela.h"
#endif

#ifndef PECAS_H
#define PECAS_H

#ifdef PECAS_OWN
  #define PECAS_EXT
#else
  #define PECAS_EXT extern
#endif

/** \enum Tipo_Peca Indica qual é o formato da peça a ser mostrada na tela.*/
enum Tipo_Peca {
	Tipo_I,
	Tipo_Z,
	Tipo_T,
	Tipo_O,
	Tipo_L,
};typedef enum Tipo_Peca tp_peca; 

/** \struct Peca */
typedef struct Peca{ 
  int tamanho; /**<Tamanho da peça.*/
  unsigned short int cor_peca; /**<Cor da peça.*/
  unsigned short int move_peca; /**<Booleano que checa se a peça está em movimento ou não.*/
  float velocidade;/**<Velocidade na qual a peça está caindo.*/
  tp_peca tipo;/**< Qual o formato da peça. */
  bloco /*@out@*/ *centro_de_rotacao; /**< Ponteiro para o bloco de centro de rotação. */
  bloco /*@out@*/ **blocos; /**<Referência para blocos na tela.*/
}peca; 

PECAS_EXT void nova_peca(Tela* tela,int teste, int valor); 
PECAS_EXT void move_peca_x(peca* peca, int x);
PECAS_EXT void move_peca_y(peca* peca, int y);
PECAS_EXT void rotaciona_peca(peca* peca);
PECAS_EXT void speed_up (peca* peca, int y);
PECAS_EXT void libera_peca(peca* p);
PECAS_EXT peca* cria_peca_I(Tela* tela);
PECAS_EXT peca* cria_peca_Z(Tela* tela);
PECAS_EXT peca* cria_peca_T(Tela* tela);
PECAS_EXT peca* cria_peca_O(Tela* tela);
PECAS_EXT peca* cria_peca_L(Tela* tela);

#undef PECAS_EXT
#endif
