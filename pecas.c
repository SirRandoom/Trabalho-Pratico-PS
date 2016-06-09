/** \file */

#include "pecas.h"
#include <time.h>

/** Par de cores das peças variam entre 4 e 7.*/
unsigned short int cor_nova_peca = 4;

/** Gera nova peça do jogo. Orientação e tamanho são dados de forma pseudoaleatória.
    A cor é dada de forma cíclica.
    \param tela Ponteiro para tela de jogo.
*/

void nova_peca(Tela* tela){
	srand(time(NULL));
	int i;
	int orientacao = rand()%2; /**<Indica a orientação da peça. Se 1, a orientação é vertical. Se 0, a orientação é horizontal*/
	int tamanho = rand()%3 + 3; /**<Indica o tamanho da peça*/

	peca *p = malloc(sizeof(peca) + tamanho*sizeof(bloco*));

	p->tamanho = tamanho;
	p->cor_peca = cor_nova_peca;
	p->move_peca = 1;

	for(i = 0; i < p->tamanho; i++){
		if(orientacao){
			p->blocos[i] = &(tela->blocos[i*tela->largura + tela->largura/2]);
			p->blocos[i]->cor = p->cor_peca;
			p->blocos[i]->bolinha = 'o';
			p->blocos[i]->move = 1;
		}else{
			p->blocos[i] = &(tela->blocos[i - (p->tamanho)/2 + tela->largura/2]);
			p->blocos[i]->cor = p->cor_peca;
			p->blocos[i]->bolinha = 'o';
			p->blocos[i]->move = 1;
		}
	}
	if(cor_nova_peca == 7){
		cor_nova_peca = 4;
	}
	cor_nova_peca++;
	tela->peca = p;
}

/** Movimenta a peça no eixo x, ou seja no sentido horizontal.
    \param p A peça a ser movimentada.
    \param x Indica a direção do movimento. Se positivo, para a direita. Se negativo, para a esquerda.
*/
void move_peca_x(peca* p, int x){

	unsigned short int colisao = 0;
	int i;

	switch(x){
		case 1:
			for (i = 0; i < p->tamanho; i++){
				if(p->blocos[i]->pos_x != 24){
					if(((p->blocos[i]->direita->bolinha == 'o')&&(p->blocos[i]->direita->move == 0))){
						colisao = 1;
						break;
					}
				}
				else{
					colisao = 1;
					break;
				}
			}
			if(colisao != 1){
				for (i = p->tamanho - 1; i >= 0; i--){
					p->blocos[i]->cor = 2;
					p->blocos[i]->bolinha = ' ';
					p->blocos[i]->move = 0;

					p->blocos[i] = p->blocos[i]->direita;
					p->blocos[i]->cor = p->cor_peca;
					p->blocos[i]->bolinha = 'o';
					p->blocos[i]->move = 1;
				}
			}
			break;
		case -1:
			for (i = 0; i < p->tamanho; i++){
				if((p->blocos[i]->pos_x != 0)){
					if(((p->blocos[i]->esquerda->bolinha == 'o')&&(p->blocos[i]->esquerda->move == 0))){
						colisao = 1;
						break;
					}
				}
				else{
					colisao = 1;
					break;
				}
			}
			if(colisao != 1){
				for (i = 0; i < p->tamanho; i++){
					p->blocos[i]->cor = 2;
					p->blocos[i]->bolinha = ' ';
					p->blocos[i]->move = 0;

					p->blocos[i] = p->blocos[i]->esquerda;
					p->blocos[i]->cor = p->cor_peca;
					p->blocos[i]->bolinha = 'o';
					p->blocos[i]->move = 1;
				}
			}
			break;
		default:
			break;
	}
}

/** Movimenta a peça no eixo y, ou seja, na direção vertical.
    \param p Peça a ser movida.
    \param y Sempre deve ser positivo, pois a peça só pode se movimentar para baixo.
*/
void move_peca_y(peca* p, int y){

	int i;
	unsigned short int colisao = 0;
	unsigned short int limite_inferior =0;

	if (y>0){
		for (i = 0; i < p->tamanho; i++){
			if(p->blocos[i]->pos_y != 14){
				if(((p->blocos[i]->abaixo->bolinha == 'o')&&(p->blocos[i]->abaixo->move == 0))){
					colisao = 1;			
					break;
				}
			}
			else{
				colisao = 1;
				break;
			}
		}
		if (colisao != 1){
			for (i = p->tamanho - 1; i >= 0; i--){
				p->blocos[i]->cor = 2;
				p->blocos[i]->bolinha = ' ';
				p->blocos[i]->move = 0;

				p->blocos[i] = p->blocos[i]->abaixo;
				p->blocos[i]->cor = p->cor_peca;
				p->blocos[i]->bolinha = 'o';
				p->blocos[i]->move = 1;
				if (p->blocos[i]->pos_y == 14){
					limite_inferior = 1;
				}
			}
		}
	}

	if (colisao==1 || limite_inferior == 1){
		for (i = 0; i < p->tamanho; i++){
			p->blocos[i]->move = 0;
		}
		p->move_peca = 0;
	}

}

/** Libera a memória alocada para a peça.
    \param p Ponteiro para a peça a ser liberada.
*/

void libera_peca(peca* p){
	free(p);
}
