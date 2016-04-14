typedef struct{
	char bolinha;
	unsigned short int cor;
	int pos_x, pos_y;
	unsigned short int move;
	struct bloco* esquerda;
	struct bloco* direita;
	struct bloco* abaixo;
}bloco;

#define COMPRIMENTO 15
#define LARGURA 25