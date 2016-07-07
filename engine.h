/** \file */

#ifndef ENGINE_H
#define ENGINE_H

#ifdef ENGINE_OWN
  #define ENGINE_EXT
#else
  #define ENGINE_EXT extern
#endif

ENGINE_EXT void inicia_ncurses(); 
ENGINE_EXT void finaliza_ncurses();
ENGINE_EXT int pega_input(int input);

#undef ENGINE_EXT
#endif
