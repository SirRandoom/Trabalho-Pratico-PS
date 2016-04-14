#include "pecas.h"
#include <time.h>

//Par de cores das peças variam entre 4~7
unsigned short int cor_nova_peca = 4;

void nova_peca(Tela* tela){
	srand(time(NULL));
	int i;
	int orientacao = rand()%2;
	int tamanho = rand()%3 + 3;

	peca *p = malloc(sizeof(peca) + tamanho*sizeof(bloco*));

//Inicializar os parâmetros da peça
	p->tamanho = tamanho;
	p->cor_peca = cor_nova_peca;
	p->move_peca = 1;

//Orientação vertical = 1; Orientação horizontal = 0
//Associa os blocos da tela que irão fazer parte da peça
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
	
void move_peca_x(peca* p, int x){

	unsigned short int colisao = 0;
	int i;

// Movimento para direita: x>0;  Movimento para esquerda: x<0
// Se os blocos estejam tentando se mover para uma posição ocupada
// por blocos estáticos ou os limites de tela ele não irá se mover.
// Caso contrário os blocos atuais da peça são "limpos" e 
// os ponteiros da peça e as informações dos novos blocos
// são atualizados.
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

void move_peca_y(peca* p, int y){

	int i;
	unsigned short int colisao = 0;
	unsigned short int limite_inferior =0;
// A peça não pode se mover para cima.
// A variável Y cresce para baixo, ou seja, y deve ser maior que 0.

// Se os blocos estejam tentando se mover para uma posição ocupada
// por blocos estáticos ou os limites de tela ele não irá se mover.
// Caso contrário os blocos atuais da peça são "limpos" e 
// os ponteiros da peça e as informações dos novos blocos
// são atualizados.

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

void libera_peca(peca* p){
	free(p);
}
