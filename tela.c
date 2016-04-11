#include<stdio.h>
#include<stdlib.h>
#include"tela.h"
#define COMPRIMENTO 15
#define LARGURA 25

Tela* cria_tela(){
	Tela* t = malloc(sizeof(Tela) + COMPRIMENTO*LARGURA*sizeof(char));
	t->comprimento = COMPRIMENTO;
	t->largura = LARGURA;
	t->estado = INICIO;	
	return t;
}

void mostra_tela(Tela* t){
	clear();
	
	if(t->estado == INICIO){
		init_pair(1,COLOR_BLACK,COLOR_BLUE);
		bkgd(COLOR_PAIR(1));
		move(1,1);
		printw("Pressione Qualquer Tecla Para Iniciar o Jogo.");

	}
	else if(t->estado == JOGO){
		init_pair(1,COLOR_WHITE,COLOR_BLACK);
		bkgd(COLOR_PAIR(1));
		int i,j;
		for(i = 0; i < t->comprimento; i++){
			for(j = 0; j < t->largura; j++){
				move(i,j);
				printw(&(t->celulas[j+i*t->comprimento]));
			}
			printf("\n");
		}
	}
	else if(t->estado == FINAL){}
	refresh();
}

void destroi_tela(Tela* t){
	free(t);
}	

int main(){
	initscr();
	start_color();
	Tela* t = cria_tela();
	
	t->celulas[10 + t->comprimento * 11] = t->celulas[10 + t->comprimento * 12] = t->celulas[10 + t->comprimento * 13] = 'o';
	
	mostra_tela(t);
	if(getch()) t->estado = JOGO;
	mostra_tela(t);
	getch();

	endwin();
	destroi_tela(t);
	return 0;
}
