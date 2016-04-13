typedef struct{
	char bolinha = ' ';
	unsigned short int cor = 0;
	int pos_x, pox_y;
	unsigned short int move = 0;
	bloco* esquerda;
	bloco* direita;
	bloco* abaixo;
}bloco;
