#include "engine.h"

//Função responsável por iniciar a ncurses
void inicia_ncurses(){
	initscr();
	start_color();
//	raw();
	keypad(stdscr,TRUE);
//	noecho();
}

//Função responsável por finalizar a ncurses
void finaliza_ncurses(){
	endwin();
}

//Função que interpreta uma entrada do teclado
int pega_input(int input){
	switch(input){
	case KEY_DOWN:
	case 's':
		return 2;
		break;
	case KEY_RIGHT:	
	case 'd':
		return 3;
		break;
	case KEY_LEFT:	
	case 'a':
		return 4;
		break;
	case KEY_F(4):
		return 0;
		break;	
	default:
		return 1;
		break;
	}
	 
}
