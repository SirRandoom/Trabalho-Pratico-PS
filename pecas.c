#include "pecas.h"
int cor_peca = 1;

void nova_peca(Tela* tela){
	int i;
	int orientacao = rand()%2;
	int tamanho = rand()%3 + 3;
	peca *p = malloc(sizeof(peca) + tamanho*sizeof(bloco*));
	p->tamanho = tamanho;
	for(i = 0; i < p->tamanho; i++){
		if(orientacao){
		}
		if(!orientacao){
		}
	}
	for(i = 0; i < p->tamanho; i++){
	}
	cor_peca++;
	if(cor_peca == 4){
		cor_peca = 1;
	}
}
	
void move_peca_x(peca* peca, int x){
	int i;
	switch(x){
		case 1:

			break;
		case 2: 

			break;
		default:
			break;
	}
}

void move_peca_y(peca* peca, int y){
	int i;

}
