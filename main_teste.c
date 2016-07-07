#include<stdlib.h>
#include<CUnit/CUnit.h>
#include<CUnit/Basic.h>

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

void check_pointer(void* p){
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

  CU_pSuite ptr;
  
  ptr = CU_add_suite("tela_teste_suite", NULL, NULL);
  check_pointer(ptr);
  tela_teste_add_tests(ptr);
  ptr = CU_add_suite("pecas_teste_suite", NULL, NULL);
  check_pointer(ptr);
  pecas_teste_add_tests(ptr);
  ptr = CU_add_suite("placar_teste_suite", NULL, NULL);
  check_pointer(ptr);
  placar_teste_adds_tests(ptr);
  ptr = CU_add_suite("engine_teste_suite", NULL, NULL);
  check_pointer(ptr);
  engine_teste_add_tests(ptr);
  
  CU_basic_set_mode(CU_BRM_VERBOSE);
  code =  CU_basic_run_tests();
  if(code != CUE_SUCCESS){
    fprintf(stderr, "An error occured!\n");
    code = CU_get_error;
    fprintf(stderr, "Raising error: %d\n", code);
    exit(EXIT_FAILURE);
  }
  
  CU_cleanup_registry();
  return 0;
}
