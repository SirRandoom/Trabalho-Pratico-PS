#ifndef TELA_TESTE_H
#define TELA_TESTE_H

#ifdef TELA_TESTE_OWN
  #define TELA_TESTE_EXT
#else
  #define TELA_TESTE_EXT extern
#endif

TELA_TESTE_EXT void tela_teste_add_tests(CU_pSuite ptr);

#undef TELA_TESTE_EXT
#endif
