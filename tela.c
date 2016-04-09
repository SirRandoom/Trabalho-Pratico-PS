#include<stdio.h>
#include<stdlib.h>
#include"tela.h"
#define COMPRIMENTO 15
#define LARGURA 25

Tela* cria_tela(){
	Tela* t = malloc(sizeof(Tela) + COMPRIMENTO*LARGURA*sizeof(char));
	t->comprimento = COMPRIMENTO;
	t->largura = LARGURA;	
	return t;
}

void mostra_tela(Tela* t){
	int i,j;
	for(i = 0; i < t->comprimento; i++){
		for(j = 0; j < t->largura; j++){
			move(i,j);
			printw(&(t->celulas[j+i*t->comprimento]));
		}
		printf("\n");
	}
	refresh();
}

int main(){
	initscr();
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	bkgd(COLOR_PAIR(1));
	Tela* t = cria_tela();
	
	t->celulas[10 + t->comprimento * 11] = t->celulas[10 + t->comprimento * 12] = t->celulas[10 + t->comprimento * 13] = 'o';
	
	mostra_tela(t);
	getch();
	
	endwin();
	return 0;
}
