typedef struct{
	short int cor;
	int pos_x, pox_y;
}bloco;

typedef struct{
	int tamanho;
	bloco blocos[];
	bool move;
}peca;

void nova_peca(Tela* tela);
void move_peca_x(peca* peca, int x);
void move_peca_y(peca* peca, int y);
