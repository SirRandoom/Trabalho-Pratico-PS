#include<stdio.h>
#include<stdlib.h>
#include"tela.h"
#define COMPRIMENTO 15
#define LARGURA 25

Tela* cria_tela(){
	Tela* t = malloc(sizeof(Tela) + COMPRIMENTO*LARGURA*sizeof(bloco));
	t->comprimento = COMPRIMENTO;
	t->largura = LARGURA;
	t->estado = INICIO;	
	int i, j;
	for(i = 0; i < t->comprimento; i++){
		for(j = 0; j < t->largura; j++){
			t->blocos[j+i*t->comprimento].bolinha = ' ';
		}
	}
	return t;
}

void mostra_tela(Tela* t){
	clear();
	refresh();	
	if(t->estado == INICIO){
		init_pair(6,COLOR_BLACK,COLOR_BLUE);
		bkgd(COLOR_PAIR(6));
		move(1,1);
		printw("Pressione Qualquer Tecla Para Iniciar o Jogo.");

	}
	else if(t->estado == JOGO){
		init_pair(5,COLOR_WHITE,COLOR_BLACK);
		t->janela = newwin(t->comprimento + 2, t->largura + 2, 5, 10);
		box(t->janela, ACS_VLINE, ACS_HLINE);
		wbkgd(t->janela,COLOR_PAIR(5));
		int i,j;
		for(i = 1; i < t->comprimento + 1; i++){
			for(j = 1; j < t->largura + 1; j++){
				wattron(t->janela,COLOR_PAIR(t->blocos[(j-1)+(i-1)*t->comprimento].cor));
				mvwprintw(t->janela,i,j,&(t->blocos[(j-1)+(i-1)*t->comprimento].bolinha));
				wrefresh(t->janela);				
			}
			wprintw(t->janela,"\n");
		}
		wgetch(t->janela);
		wclear(t->janela);
	}
	else if(t->estado == FINAL){}
	refresh();
}

void destroi_tela(Tela* t){
	free(t);
}	

int main(){
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	init_pair(2,COLOR_BLUE,COLOR_BLACK);
	init_pair(3,COLOR_RED,COLOR_BLACK);
	init_pair(4,COLOR_GREEN,COLOR_BLACK);
	initscr();
	start_color();
	Tela* t = cria_tela();
	
	t->blocos[0].bolinha = 'o';
	t->blocos[0].cor = 1;
/*	t->blocos[23].bolinha = t->blocos[54].bolinha = t->blocos[100].bolinha = 'o';
	t->blocos[23].cor = 2; t->blocos[54].cor = 3; t->blocos[100].cor = 4;
*/		
	mostra_tela(t);
	if(getch()) t->estado = JOGO;
	mostra_tela(t);
	getch();

	endwin();
	destroi_tela(t);
	return 0;
}
