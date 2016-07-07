#include<CUnit/CUnit.h>

#define TRUE 1
#define FALSE 0

#ifndef PECAS_H
#include"pecas.h"
#endif

#ifndef TELA_H
#include"tela.h"
#endif

#define PECAS_TESTE_OWN
#include"pecas_teste.h"
#undef PECAS_TESTE_OWN

static void test_nova_peca(){
  Tela* tela = cria_tela();
  if(!tela){
    return;
  }

  nova_peca(tela,TRUE, Tipo_I);
  CU_ASSERT_PTR_NOT_NULL(tela->peca);
  CU_ASSERT_EQUAL(tela->peca->tipo, Tipo_I);
  if(tela->peca->tamanho<3 || tela->peca->tamanho>6){
    CU_FAIL(" nova_peca(tela, TRUE, Tipo_I) executed to invalid size.\n");
  }
  else{
    CU_PASS(" nova_peca(tela, TRUE, Tipo_I) executed to valid size.\n");
  }
  
  nova_peca(tela,TRUE, Tipo_Z);
  CU_ASSERT_PTR_NOT_NULL(tela->peca);
  CU_ASSERT_EQUAL(tela->peca->tipo, Tipo_Z);
  CU_ASSERT_EQUAL(tela->peca->tamanho, 5);
  
  nova_peca(tela, TRUE, Tipo_T);
  CU_ASSERT_PTR_NOT_NULL(tela->peca);
  CU_ASSERT_EQUAL(tela->peca->tipo, Tipo_T);
  CU_ASSSERT_EQUAL(tela->peca->tamanho, 7);
  
  nova_peca(tela, TRUE, Tipo_O);
  CU_ASSERT_PTR_NOT_NULL(tela->peca);
  CU_ASSERT_EQUAL(tela->peca->tipo, Tipo_O);
  CU_ASSERT_EQUAL(tela->peca->tamanho, 4);

  nova_peca(tela, TRUE, Tipo_L);
  CU_ASSERT_PTR_NOT_NULL(tela->peca);
  CU_ASSERT_EQUAL(tela->peca->tipo, Tipo_L);
  CU_ASSERT_EQUAL(tela->peca->tamanho, 5);

  destroi_tela(tela);
}

void pecas_teste_add_tests(CU_pSuite ptr_suite){
  CU_pTest ptr_test;
  ptr_test = CU_add_test(ptr_suite, "test_nova_peca", test_nova_peca());
  check_pointer(ptr_test);
}

#undef TRUE
#undef FALSE
