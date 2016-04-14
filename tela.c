#include <stdio.h>
#include <stdlib.h>
#include "tela.h"


Tela* cria_tela(){
	int i,j;
	Tela* t = malloc(sizeof(Tela) + COMPRIMENTO*LARGURA*sizeof(bloco));
	t->comprimento = COMPRIMENTO;
	t->largura = LARGURA;
	t->estado = INICIO;	
	for(i=0; i < t->comprimento; i++){
		for(j=0; j < t->largura; j++){
			t->blocos[j+i*t->largura].bolinha = ' ';
			t->blocos[j+i*t->largura].move = 0;
			t->blocos[j+i*t->largura].pos_x = j;
			t->blocos[j+i*t->largura].pos_y = i;
			if(j!=0)
				t->blocos[j+i*t->largura].esquerda = &(t->blocos[j-1+i*t->largura]);
			else
				t->blocos[j+i*t->largura].esquerda = NULL;
			if(j!= t->largura - 1)
				t->blocos[j+i*t->largura].direita = &(t->blocos[j+1+i*t->largura]);
			else
				t->blocos[j+i*t->largura].direita = NULL;
			if(i!= t->comprimento - 1)
				t->blocos[j+i*t->largura].abaixo = &(t->blocos[j+(i+1)*t->largura]);
			else
				t->blocos[j+i*t->largura].abaixo = NULL;
		}
	}
	return t;
}

void mostra_tela(Tela* t){
	init_pair(1,COLOR_BLACK,COLOR_BLUE);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(4,COLOR_YELLOW,COLOR_BLACK);
	init_pair(5,COLOR_BLUE,COLOR_BLACK);
	init_pair(6,COLOR_RED,COLOR_BLACK);
	init_pair(7,COLOR_GREEN,COLOR_BLACK);
	
	
	clear();
	refresh();	
	if(t->estado == INICIO){
		
		bkgd(COLOR_PAIR(1));
		move(1,1);
		printw("Pressione Qualquer Tecla Para Iniciar o Jogo.");

	}
	else if(t->estado == JOGO){
	
		t->janela = newwin(t->comprimento + 2, t->largura + 2, 5, 10);
		box(t->janela, ACS_VLINE, ACS_HLINE);
		bkgd(COLOR_PAIR(2));
		refresh();
		wbkgd(t->janela,COLOR_PAIR(2));
		int i,j;
		for(i = 0; i < t->comprimento; i++){
			for(j = 0; j < t->largura; j++){
				wattron(t->janela,COLOR_PAIR(t->blocos[j+i*t->largura].cor));
				mvwprintw(t->janela,i+1,j+1,&(t->blocos[j+i*t->largura].bolinha));
				wrefresh(t->janela);				
			}
			/*wprintw(t->janela,"\n");*/
		}
	}
	else if(t->estado == FINAL){}
	refresh();
}

void destroi_tela(Tela* t){
	free(t);
}	

/*int main(){
	initscr();
	start_color();
	Tela* t = cria_tela();
	
	
	t->blocos[4].bolinha = 'o';
	t->blocos[4].cor = 1;
	t->blocos[23].bolinha = t->blocos[54].bolinha = t->blocos[100].bolinha = 'o';
	t->blocos[23].cor = 2; t->blocos[54].cor = 3; t->blocos[100].cor = 4;
		
	
	mostra_tela(t);
	if(getch()) t->estado = JOGO;
	mostra_tela(t);
	getch();

	endwin();
	destroi_tela(t);
	return 0;
}*/
