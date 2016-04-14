#include "engine.h"

void inicia_ncurses(){
	initscr();
	start_color();
}

void finaliza_ncurses(){
	endwin();
}

int pega_input(int input){
	switch(input){
	case 's':
		return 2;
		break;
	case 'd':
		return 3;
		break;
	case 'a':
		return 4;
		break;
	case 27:
		return 0;
		break;
	default:
		return 1;
		break;
	}
	 
}
