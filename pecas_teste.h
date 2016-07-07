#ifndef PECAS_TESTE_H
#define PECAS_TESTE_H

#ifdef PECAS_TESTE_OWN
  #define PECAS_TESTE_EXT
#else
  #define PECAS_TESTE_EXT extern
#endif

PECAS_TESTE_EXT void test_nova_peca();

#undef PECAS_TESTE_EXT
#endif
