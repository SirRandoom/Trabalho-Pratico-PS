#include<stdlib.h>
#include<stdio.h>
#include"pecas.h"
#include<sys/timeb.h>

int main(){
	inicia_ncurses();
	Tela* tela = cria_tela();
	mostra_tela(tela);
	struct timeb inicio, atual;
	int pontos = 0;
	int get = getch();
	if(pega_input(get)){
		tela->estado = JOGO;
	}
	ftime(&inicio);
	nova_peca(tela);
	mostra_tela(tela);
		
	while(pega_input(get)){
		ftime(&atual);
		mostra_tempo((atual.time - inicio.time)/60,(atual.time - inicio.time)%60);		
		mostra_pontos(pontos);
		timeout(1000);
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
			pontos += verifica_linha(tela);
			libera_peca(tela->peca);
			nova_peca(tela);
			mostra_tela(tela);
		}
		if(checa_fim(tela)){
			ftime(&atual);
			tela->estado = FINAL;
			tela->pontos = pontos;
			tela->tempo_m = (atual.time - inicio.time)/60;
			tela->tempo_s = (atual.time - inicio.time)%60;
			mostra_tela(tela);
			timeout(-1);
			getch();
			get = KEY_F(4);
		}	
	}	
			
	
	destroi_tela(tela);
	finaliza_ncurses();

	return 0;
	
}
