/** \file */

#include "engine.h"

/**Inicializa o modo ncurses e determina as funcionalidades dele que serão usadas.*/
void inicia_ncurses(){
	initscr();
	start_color();
//	raw();
	keypad(stdscr,TRUE);
//	noecho();
}

/**Finaliza o modo ncurses.*/
void finaliza_ncurses(){
	endwin();
}

/**Determina como interpretar a entrada do teclado.
   \param input Entrada.
   \return Saída convertida.
*/
int pega_input(int input){
	switch(input){

	case KEY_UP:
	case 'w':
		return 5;
		break;
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
	case KEY_UP:
	case 'w':
		return 5;
		break;	
	case '\n':
		return 6;
		break;	
	case KEY_F(4):
		return 0;
		break;	
	default:
		return 1;
		break;
	}
}
