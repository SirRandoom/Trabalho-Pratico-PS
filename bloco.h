typedef struct bloco {
	char bolinha;
	unsigned short int cor;
	int pos_x, pox_y;
	unsigned short int move;
	struct bloco* esquerda;
	struct bloco* direita;
	struct bloco* abaixo;
}
