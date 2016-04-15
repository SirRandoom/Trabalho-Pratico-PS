#include <stdlib.h>
#include <stdio.h>
#include "pecas.h"

int main(){
	inicia_ncurses();
	Tela* tela = cria_tela();
	mostra_tela(tela);
	
	char get = getch();
	if(pega_input(get)){
		tela->estado = JOGO;
	}
	
	nova_peca(tela);
	mostra_tela(tela);
		
	while(pega_input(get)){
		get=getch();
		if(pega_input(get) == 2){
			move_peca_y(tela->peca,1);
			mostra_tela(tela);
		}
		if(pega_input(get) == 3){
			move_peca_x(tela->peca,1);
			mostra_tela(tela);
		}
		if(pega_input(get) == 4){
			move_peca_x(tela->peca,-1);
			mostra_tela(tela);
		}
		if(!tela->peca->move_peca){
			verifica_linha(tela);
			libera_peca(tela->peca);
			nova_peca(tela);
			mostra_tela(tela);
		}
	}	
			
	
	destroi_tela(tela);
	finaliza_ncurses();

	return 0;
	
}
