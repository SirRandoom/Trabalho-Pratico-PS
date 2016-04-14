typedef struct Bloco{
	char bolinha;
	unsigned short int cor;
	int pos_x, pos_y;
	unsigned short int move;
	struct Bloco* esquerda;
	struct Bloco* direita;
	struct Bloco* abaixo;
}bloco;

#define COMPRIMENTO 15
#define LARGURA 25