#include<stdio.h>
#include<stdlib.h>
#include"tela.h"
#define COMPRIMENTO 15
#define LARGURA 25

Tela* cria_tela(){
	int i,j;
	Tela* t = malloc(sizeof(Tela) + COMPRIMENTO*LARGURA*sizeof(bloco));
	t->comprimento = COMPRIMENTO;
	t->largura = LARGURA;
	t->estado = INICIO;	
	for(i=0; i < t->comprimento; i++){
		for(j=0; j < t->largura; j++){
			t->blocos[j+i*t->comprimento].bolinha = ' ';
			if(j!=0)
				t->blocos[j+i*t->comprimento].esquerda = &(t->blocos[j-1+i*t->comprimento]);
			else
				t->blocos[j+i*t->comprimento].esquerda = NULL;
			if(j!= t->largura - 1)
				t->blocos[j+i*t->comprimento].direita = &(t->blocos[j+1+i*t->comprimento]);
			else
				t->blocos[j+i*t->comprimento].direita = NULL;
			if(i!= t->comprimento - 1)
				t->blocos[j+i*t->comprimento].abaixo = &(t->blocos[j+(i+1)*t->comprimento]);
			else
				t->blocos[j+i*t->comprimento].abaixo = NULL;
		}
	}
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
				printw('o');
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
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	init_pair(2,COLOR_BLUE,COLOR_WHITE);
	init_pair(3,COLOR_RED,COLOR_WHITE);
	init_pair(4,COLOR_GREEN,COLOR_BLACK);
	initscr();
	start_color();
	Tela* t = cria_tela();
	
	mostra_tela(t);
	if(getch()) t->estado = JOGO;
	mostra_tela(t);
	getch();

	endwin();
	destroi_tela(t);
	return 0;
}
