/**\file*/
#ifndef PLACAR_TESTE_H
#define PLACAR_TESTE_H

#ifdef PLACAR_TESTE_OWN
  #define PLACAR_TESTE_EXT
#else
  #define PLACAR_TESTE_EXT extern
#endif

PLACAR_TESTE_EXT void test_cria_placar();

PLACAR_TESTE_EXT void test_atualiza_placar();

#undef PLACAR_TESTE_EXT
#endif
