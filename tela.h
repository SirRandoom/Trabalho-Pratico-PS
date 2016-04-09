#include<curses.h>
typedef struct{
	int comprimento;
	int largura;
	char celulas[];
}Tela;

Tela* cria_tela();
void mostra_tela(Tela* t);
	


