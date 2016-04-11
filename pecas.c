
void nova_peca(Tela* tela){
	int tamanho,i;
	peca *p = malloc(sizeof(peca) + tamanho*sizeof(bloco));
	p->tamanho = tamanho;
	for(i = 0; i < p->tamanho; i++){
		tela->celulas[p->blocos[i].pos_y+p->blocos[i].pos_x*tela->comprimento] = 'o';
	}
}
	
void move_peca_x(peca* peca, int x){
	int i;
	switch(x){
		case 1:
			for(i=0;i < peca->tamanho;i++){
				peca->blocos[i].pos_x++;
			}
			break;
		case 2: 
			for(i=0;i < peca->tamanho;i++){
				peca->blocos[i].pos_x--;
			}
			break;
		default:
			break;
	}
}

void move_peca_y(peca* peca, int y){
	int i;
	for(i = 0; i < peca->tamanho; i++){
		peca->blocos[i].pos_y--;
	}
}
