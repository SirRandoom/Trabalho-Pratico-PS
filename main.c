#include<curses.h>
#include<time.h>
#include"timeb.h"


#ifndef BLOCO_H
#include"bloco.h"
#endif

#ifndef PECAS_H
#include"pecas.h"
#endif

#ifndef TELA_H
#include"tela.h"
#endif

#ifndef PLACAR_H
#include"placar.h"
#endif

#ifndef ENGINE_H
#include"engine.h"
#endif

int main(){
	Tela* tela;
	struct timeb inicio, atual, peca_drop;
	int pontos = 0;
	int get;
	float time;
	
	inicio.time = atual.time = peca_drop.time = 0;
	inicio.millitm = atual.millitm = peca_drop.millitm = 0;
	inicio.timezone = atual.timezone = peca_drop.timezone = 0;
	inicio.dstflag = atual.dstflag = peca_drop.dstflag = 0;
	
	inicia_ncurses();
	tela = cria_tela();
	mostra_tela(tela);
	
	get = getch();
	if(pega_input(get)){
		tela->estado = JOGO;
	}
	ftime(&inicio);
	ftime(&peca_drop);
	nova_peca(tela);
	mostra_tela(tela);
		
	while(pega_input(get)){
		ftime(&atual);
		mostra_tempo((int)(atual.time - inicio.time)/60,(int)(atual.time - inicio.time)%60);		
		mostra_pontos(pontos);
		timeout(60);
		get=getch();
	
		if(tela->estado == JOGO){
			if(pega_input(get) == 2){
				speed_up(tela->peca, 1);
			}
			if(pega_input(get) == 3){
				move_peca_x(tela->peca,1);
				mostra_tela(tela);
			}
			if(pega_input(get) == 4){
				move_peca_x(tela->peca,-1);
				mostra_tela(tela);
			}
			if(pega_input(get) == 5){
				rotaciona_peca(tela->peca);
				mostra_tela(tela);
			}
			time = (float) (atual.time - peca_drop.time + 0.001*(atual.millitm - peca_drop.millitm));
			if(time >= 1/tela->peca->velocidade){
				move_peca_y(tela->peca,1);
				ftime(&peca_drop);
				mostra_tela(tela);
			}
			if(!tela->peca->move_peca){
				pontos += verifica_linha(tela);
				libera_peca(tela->peca);
				nova_peca(tela);
				mostra_tela(tela);
			}
		}
		if(checa_fim(tela)){
			cria_placar();
			ftime(&atual);
			tela->estado = FINAL;
			tela->pontos = pontos;
			tela->tempo_m = (int)(atual.time - inicio.time)/60;
			tela->tempo_s = (int)(atual.time - inicio.time)%60;
			while(pega_input(get)!=6){
				define_jogador(tela);
				get = getch();
				if(tela->jogador[tela->letra]!=' '){
					if(tela->jogador[tela->letra]!='A' && pega_input(get) == 5){
						muda_letra(tela,-1);
						continue;
					}
					if(tela->jogador[tela->letra]!='Z' && pega_input(get) == 2){
						muda_letra(tela,1);
						continue;
					}
					if(tela->jogador[tela->letra]=='A' && pega_input(get) == 5){
						muda_letra(tela,' '-'A');
						continue;
					}
					if(tela->jogador[tela->letra]=='Z' && pega_input(get) == 2){
						muda_letra(tela,' '-'Z');
						continue;	
					}
				}
				else{
					if(pega_input(get) == 5){
						muda_letra(tela,'Z'-' ');
					}
					if(pega_input(get) == 2){
						muda_letra(tela,'A'-' ');
					}
				}
				if(tela->letra!=0){
					if(pega_input(get) == 4){
						troca_letra(tela,-1);
					}
				}
				if(tela->letra!=2){
					if(pega_input(get) == 3){
						troca_letra(tela,1);
					}
				}
			}
			seta_jogador(tela);
			atualiza_placar(tela->pontos);
			mostra_tela(tela);
			mostra_placar();			
			timeout(-1);
			getch();
			destroi_placar();
			get = KEY_F(4);
		}
	}	
			
	
	destroi_tela(tela);
	finaliza_ncurses();
	
	return 0;
	
}

