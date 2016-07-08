/**\file*/
#include<stdlib.h>
#include<curses.h>
#include<CUnit/CUnit.h>

#ifndef ENGINE_H
#include"engine.h"
#endif

#define ENGINE_TESTE_OWN
#include"engine_teste.h"
#undef ENGINE_TESTE_OWN

/**Verifica se o ponteiro é NULL. Se o for, encerra o programa.
   \param p Ponteiro genérico.
*/
static void check_pointer(void* p){
  if(!p){
    fprintf(stderr, "Invalid NULL pointer.\n");
    exit(EXIT_FAILURE);
  }
}

/**Verifica se é possível inicializar e finalizar as funções do curses corretamente. */
void test_ncurses(){
  inicia_ncurses();
  CU_PASS("inicia_ncurses() succeeded");
  finaliza_ncurses();
  CU_PASS("finaliza_ncurses() succeeded");
}

/**Testa a função peca_input(). Garante que dentro da faixa de caracteres ascii que não são caracteres de controle são interpretados corretamente. Além disso, verifica alguns caracteres especiais do curses que serão usados no programa.*/
void test_pega_input(){

  /*Testa todas os valores de entradas ascii que não são caracteres de controle*/
  int c;
  for(c=32;c<128;++c){
    if(c=='s'){
      CU_ASSERT_EQUAL(pega_input(c), 2);
    }
    else if(c=='d'){
      CU_ASSERT_EQUAL(pega_input(c), 3);
    }
    else if(c=='a'){
      CU_ASSERT_EQUAL(pega_input(c), 4);
    }
    else if(c=='w'){
      CU_ASSERT_EQUAL(pega_input(c), 5);
    }
    else if(c=='\n'){
      CU_ASSERT_EQUAL(pega_input(c), 6);
    }
    else{
      CU_ASSERT_EQUAL(pega_input(c), 1);
    }
  }

  /*Testa as entradas próprias das definições no curses*/
  CU_ASSERT_EQUAL(pega_input(KEY_DOWN), 2);
  CU_ASSERT_EQUAL(pega_input(KEY_RIGHT), 3);
  CU_ASSERT_EQUAL(pega_input(KEY_LEFT), 4);
  CU_ASSERT_EQUAL(pega_input(KEY_UP), 5);
  CU_ASSERT_EQUAL(pega_input(KEY_F(4)), 0);
  
}

