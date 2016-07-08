/**\file*/
#include<stdlib.h>
#include"CUnit/CUnit.h"
#include"CUnit/Basic.h"

#ifndef BLOCO_H
#include"bloco.h"
#endif

#ifndef TELA_H
#include"tela.h"
#endif

#ifndef PECAS_H
#include"pecas.h"
#endif

#ifndef PLACAR_H
#include"placar.h"
#endif

#ifndef ENGINE_H
#include"engine.h"
#endif

#ifndef TELA_TESTE_H
#include"tela_teste.h"
#endif

#ifndef PECAS_TESTE_H
#include"pecas_teste.h"
#endif

#ifndef PLACAR_TESTE_H
#include"placar_teste.h"
#endif

#ifndef ENGINE_TESTE_H
#include"engine_teste.h"
#endif

/**Avalia se o ponteiro é NULL. Se o for, finaliza o programa.
   \param p Ponteiro genérico. 
*/
static void check_pointer(void* p){
  if(!p){
    fprintf(stderr, "Invalid NULL pointer.\n");
    exit(EXIT_FAILURE);
  }
}

int main(){

  CU_ErrorCode code;

  code = CU_initialize_registry();
  if(code!=CUE_SUCCESS){
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  CU_pSuite ptr_suite;
  CU_pTest ptr_test;
  
  ptr_suite = CU_add_suite("tela_teste_suite", NULL, NULL);
  check_pointer(ptr_suite);
  ptr_test = CU_add_test(ptr_suite, "test_cria_tela",  test_cria_tela);
  check_pointer(ptr_test);

  ptr_suite = CU_add_suite("pecas_teste_suite", NULL, NULL);
  check_pointer(ptr_suite);
  ptr_test = CU_add_test(ptr_suite, "test_nova_peca", test_nova_peca);
  check_pointer(ptr_test);
  
  ptr_suite = CU_add_suite("placar_teste_suite", NULL, NULL);
  check_pointer(ptr_suite);
  ptr_test = CU_add_test(ptr_suite, "test_cria_placar", test_cria_placar);
  check_pointer(ptr_test);
  ptr_test = CU_add_test(ptr_suite, "test_atualiza_placar", test_atualiza_placar);
  check_pointer(ptr_test);
  
  ptr_suite = CU_add_suite("engine_teste_suite", NULL, NULL);
  check_pointer(ptr_suite);
  ptr_test = CU_add_test(ptr_suite, "test_ncurses", test_ncurses);
  check_pointer(ptr_test);
  ptr_test = CU_add_test(ptr_suite, "test_pega_input", test_pega_input);
  check_pointer(ptr_test);
  
  
  CU_basic_set_mode(CU_BRM_VERBOSE);
  code =  CU_basic_run_tests();
  if(code != CUE_SUCCESS){
    fprintf(stderr, "An error occured!\n");
    code = CU_get_error();
    fprintf(stderr, "Raising error: %d\n", code);
    exit(EXIT_FAILURE);
  }
  
  CU_cleanup_registry();
  return 0;
}
