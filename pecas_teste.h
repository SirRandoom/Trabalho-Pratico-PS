#ifndef PECAS_TESTE_H
#define PECAS_TESTE_H

#ifdef PECAS_TESTE_OWN
  #define PECAS_TESTE_EXT
#else
  #define PECAS_TESTE_EXT extern
#endif

PECAS_TESTE_EXT void pecas_teste_add_test(CU_pSuite ptr_suite);

#undef PECAS_TESTE_EXT
#endif
