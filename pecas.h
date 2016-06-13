/** \file */

#define PECAS_H

#ifndef BLOCO_H
#include"bloco.h"
#endif

#ifndef TELA_H
#include"tela.h"
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

extern void nova_peca(Tela* tela); 
extern void move_peca_x(peca* peca, int x);
extern void move_peca_y(peca* peca, int y);
extern void rotaciona_peca(peca* peca);
extern void speed_up (peca* peca, int y);
extern void libera_peca(peca* p);
extern peca* cria_peca_I(Tela* tela);
extern peca* cria_peca_Z(Tela* tela);
extern peca* cria_peca_T(Tela* tela);
extern peca* cria_peca_O(Tela* tela);
extern peca* cria_peca_L(Tela* tela);
