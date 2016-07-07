#ifndef PLACAR_TESTE_H
#define PLACAR_TESTE_H

#ifdef PLACAR_TESTE_OWN
  #define PLACAR_TESTE_EXT
#else
  #define PLACAR_TESTE_EXT extern
#endif

PLACAR_TESTE_EXT void placar_teste_add_tests(CU_pSuite ptr_suite);

#undef PLACAR_TESTE_EXT
#endif
