//Struct que define os blocos da Tela

typedef struct Bloco{
	char bolinha; //caracter atual do bloco
	unsigned short int cor; //cor do bloco
	int pos_x, pos_y; // posições cartesianas do bloco
	unsigned short int move; //boleano que verifica se o bloco está em movimento
	struct Bloco* esquerda; 
	struct Bloco* direita;
	struct Bloco* abaixo;
}bloco;

#define COMPRIMENTO 15
#define LARGURA 25

