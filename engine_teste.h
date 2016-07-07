#ifndef ENGINE_TESTE_H
#define ENGINE_TESTE_H

#ifdef ENGINE_TESTE_OWN
  #define ENGINE_TESTE_EXT
#else
  #define ENGINE_TESTE_EXT extern
#endif

ENGINE_TESTE_EXT engine_test_add_tests(CU_pSuite ptr);

#undef ENGINE_TESTE_EXT
#endif 
