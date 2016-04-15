#include "engine.h"

void inicia_ncurses(){
	initscr();
	start_color();
//	raw();
	keypad(stdscr,TRUE);
//	noecho();
}

void finaliza_ncurses(){
	endwin();
}

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
