#ifndef ENGINE_TESTE_H
#define ENGINE_TESTE_H

#ifdef ENGINE_TESTE_OWN
  #define ENGINE_TESTE_EXT
#else
  #define ENGINE_TESTE_EXT extern
#endif

ENGINE_TESTE_EXT void test_ncurses();

ENGINE_TESTE_EXT void test_pega_input();

#undef ENGINE_TESTE_EXT
#endif 
