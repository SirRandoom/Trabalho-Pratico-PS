/** \file */

#include<curses.h>
#include<stdlib.h>
#include<string.h>

#ifndef BLOCO_H
#include "bloco.h"
#endif

#ifdef PECAS_H
#include"pecas.h"
#endif

#define TELA_OWN
#include "tela.h"
#undef TELA_OWN

/**Cria uma tela de jogo com os parâmetros corretos.
   \return Retorna um ponteiro para tal tela.*/
Tela* cria_tela(){

	int i,j;
	Tela* t = malloc(sizeof(Tela) + COMPRIMENTO*LARGURA*sizeof(bloco));

	t->comprimento = COMPRIMENTO;
	t->largura = LARGURA;
	t->estado = INICIO;
	strcpy(t->jogador, "AAA");
	t->letra = 0;	
	t->pontos = 0;
	t->tempo_m = t->tempo_s = 0;
	t->peca = NULL;
	for(i=0; i < t->comprimento; i++){
		for(j=0; j < t->largura; j++){
			t->blocos[j+i*t->largura].bolinha = ' ';
			t->blocos[j+i*t->largura].move = 0;
			t->blocos[j+i*t->largura].pos_x = j;
			t->blocos[j+i*t->largura].pos_y = i;
			t->blocos[j+i*t->largura].cor = 0;
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
			if(i!=0)
				t->blocos[j+i*t->largura].acima = &(t->blocos[j+(i-1)*t->largura]);
			else
				t->blocos[j+i*t->largura].acima = NULL;
		}
	}

	t->janela = newwin(t->comprimento + 2, t->largura + 2, 5, 10);
	box(t->janela, ACS_VLINE, ACS_HLINE);
	return t;
}

/**Mostra a tela de jogo, conforme seu atual estado.
   Também inicializa os pares de cores a serem utilizados.
   \param t Ponteiro para tela a ser mostrada.
*/

void mostra_tela(Tela* t){

	init_pair(1,COLOR_BLACK,COLOR_BLUE);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_BLACK,COLOR_WHITE);
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
		int i,j;
		bkgd(COLOR_PAIR(2));
		refresh();
		wbkgd(t->janela,COLOR_PAIR(2));
		mvprintw(11,8,"=>");
		mvprintw(11,37,"<=");
		refresh();
		move(0,0);
		for(i = 0; i < t->comprimento; i++){
			for(j = 0; j < t->largura; j++){
				wattron(t->janela,COLOR_PAIR(t->blocos[j+i*t->largura].cor));
				mvwprintw(t->janela,i+1,j+1,&(t->blocos[j+i*t->largura].bolinha));
								
			}
			/*wprintw(t->janela,"\n");*/
		}
		wrefresh(t->janela);
	}

	else if(t->estado == FINAL){
		char tempo_m[15], tempo_s[15], pontos[15];
		snprintf(tempo_m,sizeof("%d"),"%d",t->tempo_m);
		snprintf(tempo_s,sizeof("%d"),"%d",t->tempo_s);
		snprintf(pontos,sizeof("%d"),"%d",t->pontos);
		bkgd(COLOR_PAIR(3));
		mvprintw(1,1,"Fim de Jogo :c");
		mvprintw(2,1,"Pontuação-> ");
		mvprintw(2,15,pontos);
		mvprintw(3,1,"Tempo->");
		mvprintw(3,9,tempo_m);
		mvprintw(3,11,":");
		mvprintw(3,13,tempo_s);
		mvprintw(5,1,"Pressione Qualquer Tecla para finalizar o jogo.");
	}
	refresh();
}

/** Mostra a pontuação do jogados.
    \param pontos O escore atual.
*/
void mostra_pontos(int pontos){
	WINDOW* janela;
	char str[15];
	snprintf(str,15,"%d",pontos);
	janela = newwin(1,20,5,50);
	wclear(janela);
	mvwprintw(janela,0,0,"Pontuação:");
	mvwprintw(janela,0,15,str);
	wrefresh(janela);	
}

/** Mostra o tempo da partida.
    \param minutos Tempo em minutos.
    \param segundos Tempo em segundos.
*/
void mostra_tempo(int minutos,int segundos){
	WINDOW* janela;
	char str_m[15],str_s[15];
	snprintf(str_m,sizeof("%d"),"%d",minutos);
	snprintf(str_s,sizeof("%d"),"%d",segundos);
	janela = newwin(1,20,6,50);
	wclear(janela);
	mvwprintw(janela,0,0,"Tempo:");
	mvwprintw(janela,0,10,str_m);
	mvwprintw(janela,0,12,":");
	mvwprintw(janela,0,14,str_s);
	wrefresh(janela);
}	

/** Verifica se uma linha horizontal do jogo está completamente preenchida.
    \param t Ponteiro para a tela do jogo.
    \return 100 se a linha estiver preenchida. 0 caso contrário.
*/

int verifica_linha (Tela* t){

	int x, y;
	int counter = 0;
	int points = 0;

	for(y = t->comprimento - 1;  y >= 0; y--){
		for(x = 0; x < t->largura; x++){
			if (t->blocos[x+y*t->largura].bolinha == 'o'){
				counter++;
			}
		}
		if (counter == 25){
			limpa_linha(t, y);
			desce_linhas(t, y);
			points += 100;
			y++;
		}
		counter = 0;
	}
	return points;
}

/** Limpa uma determinada linha do jogo.
    \param t Ponteiro para a tela do jogo.
    \param y Posição da linha a ser eliminada.
*/
void limpa_linha (Tela* t, int y){

	int x;

	for (x = 0; x < t->largura; x++){
		t->blocos[x+y*t->largura].bolinha = ' ';
		t->blocos[x+y*t->largura].cor = 2;
	}
}

/**Desce determinada linha da tela.
   \param t Ponteiro para a tela de jogo.
   \param y Posição para a linha.
*/

void desce_linhas (Tela* t, int y){

	int i,j;
	int counter=0;

	for(i = y-1;  i >= 0; i--){
		for(j = 0; j < t->largura; j++){
			if(t->blocos[j+i*t->largura].bolinha == 'o'){
				counter++;
			}
			t->blocos[j+(i+1)*t->largura].bolinha = t->blocos[j+i*t->largura].bolinha;
			t->blocos[j+(i+1)*t->largura].cor = t->blocos[j+i*t->largura].cor;
		}
		if(counter==0){
			break;
		}
		counter = 0;
	}
}

/** Verifica se as peças ultrapassaram o limite superior do jogo.
    \param t Ponteiro para a tela de jogo.
    \return Verdadeiro se ultrapassou o limite. Falso caso contrário.
*/
int checa_fim(Tela* t){
	int i;
	
	for(i = 0; i < t->largura; i++){
		if((t->blocos[i+5*t->largura].bolinha == 'o')&&(!t->blocos[i+5*t->largura].move)){
			return true;
		}
	}
	return false; 
}

/** Libera o espaço de memória reservado para a tela de jogo.
    \param t Ponteiro para a tela de jogo.
*/
void destroi_tela(Tela* t){
	free(t);
}	

/** Estado da tela onde o jogador escolhe o seu apelido.
    \param t Ponteiro para tela.
*/
void define_jogador(Tela* t){
	clear();
	mvprintw(1,3,"Defina seu apelido (utilize as setas para alterar as letras e pressione ENTER quando pronto)");
	mvprintw(5,30,"%c      %c      %c",t->jogador[0],t->jogador[1],t->jogador[2]);
	mvprintw(6,30+t->letra*7,"_");
	refresh();	
}

/**Função que altera a atual letra selecionada para escolha do apelido.
   \param t Ponteiro para tela.
   \param valor Quantidade a ser incrementada.
*/
void troca_letra(Tela* t,int valor){
	t->letra += valor;
}

/**Função que alatera o caracter da atual letra selecionada para escolha do apelido.
   \param t  Ponteiro para tela.
   \param valor Quantidade a ser incrementada.
*/
void muda_letra(Tela* t,int valor){
	t->jogador[t->letra] += valor;
}
