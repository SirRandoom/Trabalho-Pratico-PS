/** \file */

#include<curses.h>
#include<stdlib.h>
#include<time.h>

#ifndef BLOCO_H
#include"bloco.h"
#endif

#ifndef TELA_H
#include"tela.h"
#endif

#ifndef PECAS_H
#include"pecas.h"
#endif

/** Par de cores das peças variam entre 4 e 7.*/
unsigned short int cor_nova_peca = 4;
/** Indica quantas chamadas bem-sucedidas para a função speed_up foi feita para uma peça. Valor máximo de 5*/
unsigned short int speed_ups = 0;

/** Cria nova peça na tela do jogo. O tipo de peça a ser criado é randomizado. A coloração das peças se dá de forma cíclica.
    \param tela Ponteiro para tela de jogo.
*/
void nova_peca(Tela* tela){
	int tipo; /**<Indica o tipo da peça*/
	speed_ups = 0;
	srand((unsigned int)time(NULL));
	tipo = rand()%5;
	
	switch (tipo){
		case Tipo_I:
			tela->peca = cria_peca_I(tela);
			break;

		case Tipo_Z:
			tela->peca = cria_peca_Z(tela);
			break;

		case Tipo_T:
			tela->peca = cria_peca_T(tela);
			break;

		case Tipo_O:
			tela->peca = cria_peca_O(tela);
			break;

		case Tipo_L:
			tela->peca = cria_peca_L(tela);
			break;
	}

	if(cor_nova_peca == 7){
		cor_nova_peca = 4;
	}
	cor_nova_peca++;
}

/** Cria uma peça do tipo I na tela.
    \param tela Ponteiro para tela.
    \return Ponteiro para a peça.
*/

peca* cria_peca_I(Tela* tela){
	int i;
	int orientacao = rand()%2; 
	int tamanho = rand()%3 + 3;
	int tipo = Tipo_I;

	peca *p = malloc(sizeof(peca));

	p->blocos = (bloco**)NULL;
	p->tamanho = tamanho;
	p->cor_peca = cor_nova_peca;
	p->tipo = tipo;
	p->velocidade = 1;
	p->move_peca = 1;
	p->centro_de_rotacao = NULL;

	for(i = 0; i < p->tamanho; i++){
		if(i==0){
			p->blocos = malloc(sizeof(bloco*)*p->tamanho);
		}
			p->blocos[i] = malloc(sizeof(bloco));
		if(orientacao){
			p->blocos[i] = &(tela->blocos[i*tela->largura + tela->largura/2]);
		}else{
			p->blocos[i] = &(tela->blocos[i - (p->tamanho)/2 + tela->largura/2]);		
		}

		if(i-tamanho/2 == 0){
			p->centro_de_rotacao = p->blocos[i];
		}

		p->blocos[i]->cor = p->cor_peca;
		p->blocos[i]->bolinha = 'o';
		p->blocos[i]->move = 1;
	}
	return(p);
}

/** Cria uma peça do tipo Z na tela.
    \param tela Ponteiro para a tela de jogo.
    \return Ponteiro para a peça.
*/
peca* cria_peca_Z(Tela* tela){
	int i;
	int orientacao = rand()%2;
	int tamanho = 5; 
	int tipo = Tipo_Z;

	peca *p = malloc(sizeof(peca));

	p->blocos = (bloco**)NULL;
	p->tamanho = tamanho;
	p->cor_peca = cor_nova_peca;
	p->tipo = tipo;
	p->velocidade = 1;
	p->move_peca = 1;
	p->centro_de_rotacao = NULL;

	for(i = 0; i < p->tamanho; i++){
		if(i==0){
			p->blocos = malloc(sizeof(bloco*)*p->tamanho);
		}
			p->blocos[i] = malloc(sizeof(bloco));
		if(orientacao){
			if(i<2){
				p->blocos[i] = &(tela->blocos[tela->largura/2 + i]);
			}else{
				if(i==2){
					p->blocos[i] = &(tela->blocos[tela->largura + tela->largura/2 + 1]);
				}else{
					p->blocos[i] = &(tela->blocos[2*tela->largura + tela->largura/2 + i - 2]);
				}
			}
			
		}else{
			if(i>0&&i<4){
				p->blocos[i] = &(tela->blocos[tela->largura + tela->largura/2 + i - 1]);
			}else{
				if(i==0){
					p->blocos[i] = &(tela->blocos[2*tela->largura + tela->largura/2]);
				}else{
					p->blocos[i] = &(tela->blocos[tela->largura/2 + 2]);
				}
			}
		}

		if(i==2){
			p->centro_de_rotacao = p->blocos[i];
		}
		p->blocos[i]->cor = p->cor_peca;
		p->blocos[i]->bolinha = 'o';
		p->blocos[i]->move = 1;
	}
	return (p);
}

/** Cria peça T na tela.
    \param tela Ponteiro para tela de jogo.
    \return Ponteiro para a peça.
*/
peca* cria_peca_T(Tela* tela){
	int i;
	int orientacao = rand()%2; 
	int tamanho = 7; 
	int tipo = Tipo_T;

	peca *p = malloc(sizeof(peca));

	p->blocos = (bloco**)NULL;
	p->tamanho = tamanho;
	p->cor_peca = cor_nova_peca;
	p->tipo = tipo;
	p->velocidade = 1;
	p->move_peca = 1;
	p->centro_de_rotacao = NULL;

	for(i = 0; i < p->tamanho; i++){
		if(i==0){
			p->blocos = malloc(sizeof(bloco*)*p->tamanho);
		}
			p->blocos[i] = malloc(sizeof(bloco));
		if(orientacao){
			if(i<5){
				p->blocos[i] = &(tela->blocos[i*tela->largura + tela->largura/2]);
			}else{
				p->blocos[i] = &(tela->blocos[2*tela->largura + tela->largura/2 - i + 4]);
			}
		}else{
			if(i<5){
				p->blocos[i] = &(tela->blocos[i - 2 + tela->largura/2]);
			}else{
				p->blocos[i] = &(tela->blocos[(i-4)*tela->largura + tela->largura/2]);
			}
		}

		if(i==2){
			p->centro_de_rotacao = p->blocos[i];
		}
		p->blocos[i]->cor = p->cor_peca;
		p->blocos[i]->bolinha = 'o';
		p->blocos[i]->move = 1;
	}
	return(p);
}

/** Cria peça O na tela.
    \param tela Ponteiro para a tela de jogo.
    \return Ponteiro para a peça.
*/
peca* cria_peca_O(Tela* tela){
	int i;
	int tamanho = 4; 
	int tipo = Tipo_O;

	peca *p = malloc(sizeof(peca));

	p->blocos = (bloco**) NULL;
	p->tamanho = tamanho;
	p->cor_peca = cor_nova_peca;
	p->tipo = tipo;
	p->velocidade = 1;
	p->move_peca = 1;
	p->centro_de_rotacao = NULL;

	for(i = 0; i < p->tamanho; i++){
		if(i==0){
			p->blocos = malloc(sizeof(bloco*)*p->tamanho);
		}
		p->blocos[i] = malloc(sizeof(bloco));
		if(i<2){
			p->blocos[i] = &(tela->blocos[tela->largura/2 +i]);
		}else{
			p->blocos[i] = &(tela->blocos[tela->largura + tela->largura/2 + i - 2]);
		}

		p->centro_de_rotacao = p->blocos[i];
		p->blocos[i]->cor = p->cor_peca;
		p->blocos[i]->bolinha = 'o';
		p->blocos[i]->move = 1;
	}
	return(p);
}

/**Cria peça L na tela.
   \param tela Ponteiro para a tela.
   \return Ponteiro  para peça.
*/
peca* cria_peca_L(Tela* tela){
	int i;
	int orientacao = rand()%2;
	int tamanho = 5; 
	int tipo = Tipo_L;

	peca *p = malloc(sizeof(peca));

	p->blocos = (bloco**)NULL;
	p->tamanho = tamanho;
	p->cor_peca = cor_nova_peca;
	p->tipo = tipo;
	p->velocidade = 1;
	p->move_peca = 1;
	p->centro_de_rotacao = NULL;

	for(i = 0; i < p->tamanho; i++){
		if(i==0){
			p->blocos = malloc(sizeof(bloco*)*p->tamanho);
		}
		p->blocos[i] = malloc(sizeof(bloco));
		if(orientacao){
			if(i<3){
				p->blocos[i] = &(tela->blocos[i*tela->largura + tela->largura/2]);
				if(i==1){
					p->centro_de_rotacao = p->blocos[i]->direita;
				}
			}else{
				p->blocos[i] = &(tela->blocos[2*tela->largura + tela->largura/2 + i - 2]);
			}
		}else{
			if(i<3){
				p->blocos[i] = &(tela->blocos[2*tela->largura + tela->largura/2 + i]);
			}else{
				p->blocos[i] = &(tela->blocos[(4-i)*tela->largura + tela->largura/2 + 2]);
				if(i==3){
					p->centro_de_rotacao = p->blocos[i]->esquerda;
				}
			}
		}
		p->blocos[i]->cor = p->cor_peca;
		p->blocos[i]->bolinha = 'o';
		p->blocos[i]->move = 1;
	}
	return(p);
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
				}
				for (i = p->tamanho - 1; i >= 0; i--){
					p->blocos[i] = p->blocos[i]->direita;
					p->blocos[i]->cor = p->cor_peca;
					p->blocos[i]->bolinha = 'o';
					p->blocos[i]->move = 1;
				}
				p->centro_de_rotacao = p->centro_de_rotacao->direita;
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
					
				}
				for (i = 0; i < p->tamanho; i++){
					p->blocos[i] = p->blocos[i]->esquerda;
					p->blocos[i]->cor = p->cor_peca;
					p->blocos[i]->bolinha = 'o';
					p->blocos[i]->move = 1;
				}
				p->centro_de_rotacao = p->centro_de_rotacao->esquerda;
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
			}

			for (i = p->tamanho - 1; i >= 0; i--){
				p->blocos[i] = p->blocos[i]->abaixo;
				p->blocos[i]->cor = p->cor_peca;
				p->blocos[i]->bolinha = 'o';
				p->blocos[i]->move = 1;
				if (p->blocos[i]->pos_y == 14){
					limite_inferior = 1;
				}
			}
			p->centro_de_rotacao = p->centro_de_rotacao->abaixo;
		}
	}

	if (colisao==1 || limite_inferior == 1){
		for (i = 0; i < p->tamanho; i++){
			p->blocos[i]->move = 0;
		}
		p->move_peca = 0;
	}

}

/** Rotaciona a peça no sentido horário em torno de seu centro de rotação.
    \param peca Ponteiro para a peça.
*/

void rotaciona_peca(peca* peca){

	int x,y,i,j;
	unsigned short int colisao = 0;
	bloco* aux[peca->tamanho];

	if(peca->tipo != Tipo_O){
		for (i = 0; i < peca->tamanho; i++){

			aux[i] = peca->centro_de_rotacao;

			if (peca->blocos[i] != peca->centro_de_rotacao){
				x = peca->centro_de_rotacao->pos_x - peca->blocos[i]->pos_x;
				y = peca->centro_de_rotacao->pos_y - peca->blocos[i]->pos_y;

				if(x>0){
					for (j = 0; j < x; j++){
						if(aux[i]->acima != NULL){
							if((aux[i]->acima->bolinha == 'o')&&(aux[i]->acima->move == 0)){
								colisao = 1;
							}else{
								aux[i] = aux[i]->acima;
							}
						}else{
							colisao = 1;
						}
					}
				}else{
					for (j = 0; j > x; j--){
						if(aux[i]->abaixo != NULL){
							if((aux[i]->abaixo->bolinha == 'o')&&(aux[i]->abaixo->move == 0)){
								colisao = 1;
							}else{
								aux[i] = aux[i]->abaixo;
							}
						}else{
							colisao = 1;
						}
					}
				}
				if(y>0){
					for (j = 0; j < y; j++){
						if(aux[i]->direita != NULL){
							if((aux[i]->direita->bolinha == 'o')&&(aux[i]->direita->move == 0)){
								colisao = 1;
							}else{
								aux[i] = aux[i]->direita;
							}
						}else{
							colisao = 1;
						}
					}
				}else{
					for (j = 0; j > y; j--){
						if(aux[i]->esquerda != NULL){
							if((aux[i]->esquerda->bolinha == 'o')&&(aux[i]->esquerda->move == 0)){
								colisao = 1;
							}else{
								aux[i] = aux[i]->esquerda;
							}
						}else{
							colisao = 1;
						}
					}
				}				
			}
		}

		if(colisao!=1){
			for (i = 0; i < peca->tamanho; i++){
				peca->blocos[i]->cor = 2;
				peca->blocos[i]->bolinha = ' ';
				peca->blocos[i]->move = 0;
				peca->blocos[i] = aux[i];
			}
			for (i = 0; i < peca->tamanho; i++){
				peca->blocos[i]->cor = peca->cor_peca;
				peca->blocos[i]->bolinha = 'o';
				peca->blocos[i]->move = 1;
			}
		}			
	}
}

/**Dobra a velocidade da peça. Pode ser chamada com sucesso no máximo 5 vezes para a mesma peça.
   \param peca Ponteiro para peça.
*/
void speed_up (peca* peca, int y){

	if(speed_ups<5){
		peca->velocidade = peca->velocidade *2;
		speed_ups++;
	}
	

}

/** Libera a memória alocada para a peça.
    \param p Ponteiro para a peça a ser liberada.
*/
void libera_peca(peca* p){
	free(p);
}

