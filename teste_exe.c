#include"testes.h"

int main(){
  if(CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  adiciona_testes();
  CU_basic_set_mode(CU_BRM_VERBOSE);
  (void)CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
