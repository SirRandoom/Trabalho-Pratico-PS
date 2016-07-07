#include<stdlib.h>
#include<CUnit/CUnit.h>

#ifndef BLOCO_H
#include"bloco.h"
#endif

#ifndef TELA_H
#include"tela.h"
#endif

#define TELA_TESTE_OWN
#include"tela_teste.h"
#undef TELA_TESTE_OWN

static void check_pointer(void* p){
  if(!p){
    fprintf(stderr, "Invalid NULL pointer.\n");
    exit(EXIT_FAILURE);
  }
}

void test_cria_tela(){
  Tela* tela = cria_tela();
  CU_ASSERT_PTR_NOT_NULL(tela);
  CU_ASSERT_EQUAL(sizeof(tela), sizeof(Tela)+COMPRIMENTO*LARGURA*sizeof(bloco));
  CU_ASSERT_EQUAL(tela->comprimento, COMPRIMENTO);
  CU_ASSERT_EQUAL(tela->largura, LARGURA);
  CU_ASSERT_EQUAL(tela->estado, INICIO);
  CU_ASSERT_EQUAL(tela->letra, 0);
  CU_ASSERT_EQUAL(tela->pontos, 0);
  CU_ASSERT_EQUAL(tela->tempo_m, 0);
  CU_ASSERT_EQUAL(tela->tempo_s, 0);
  CU_ASSERT_PTR_NULL(tela->peca);
  CU_ASSERT_PTR_NOT_NULL(tela->janela);
  destroi_tela(tela);
}

