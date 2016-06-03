#include <stdio.h>
#include <stdlib.h>
#include "tela.h"

typedef struct Peca{ //Struct que define a peça do jogo
	int tamanho; //tamanho da peça
	unsigned short int cor_peca, move_peca; //cor da peça e boleano que checa se a peça está em movimento
	bloco* blocos[]; //Vetor de ponteiros de bloco (referências para blocos da Tela)
}peca;

void nova_peca(Tela* tela); //cria uma nova peça na e passa sua referência para Tela
void move_peca_x(peca* peca, int x); //função que movimenta a peça no eixo cartesiano x
void move_peca_y(peca* peca, int y); //função que movimenta a peça no eixo cartesiano y
void libera_peca(peca* p); //desaloca o espaço de memória da peça
