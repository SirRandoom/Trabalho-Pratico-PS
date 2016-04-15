#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h" 

void adiciona_testes(void);

void teste_VerificaCriaTela(void);
void teste_VerificaComprimentoTela(void);
void teste_VerificaLarguraTela(void);

void teste_VerificaCriaTela(void){
	Tela* tela = cria_tela();
	int pointer = tela;
	CU_ASSERT_TRUE( pointer );
}

void teste_VerificaComprimentoTela(void){
	Tela* tela = cria_tela();
	int comprimento;
	comprimento = tela->comprimento;
	CU_ASSERT_TRUE( comprimento == 15 );
}

void teste_VerificaLarguraTela(void){
	Tela* tela = cria_tela();
	int largura;
	largura = tela->largura;
	CU_ASSERT_TRUE( largura == 25);
}

void adiciona_testes(void){
	CU_pSuite suite;
	
	suite = CU_add_suite("Testes",NULL,NULL);
	
	CU_ADD_TEST(suite, teste_VerificaCriaTela);
	CU_ADD_TEST(suite, teste_VerificaComprimentoTela);
	CU_ADD_TEST(suite, teste_VerificaLarguraTela);
}

