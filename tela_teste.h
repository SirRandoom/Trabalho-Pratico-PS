#ifndef TELA_TESTE_H
#define TELA_TESTE_H

#ifdef TELA_TESTE_OWN
  #define TELA_TESTE_EXT
#else
  #define TELA_TESTE_EXT extern
#endif

TELA_TESTE_EXT void test_cria_tela();

#undef TELA_TESTE_EXT
#endif
