#include"CUnit/CUnit.h"
#include <string.h>

#define TRUE 1
#define FALSE 0

#ifndef PLACAR_H
#include "placar.h"
#endif

#ifndef TELA_H
#include"tela.h"
#endif

#define PLACAR_TESTE_OWN
#include"placar_teste.h"
#undef PLACAR_TESTE_OWN

void test_cria_placar(){
	cria_placar();
	FILE *arquivo
	
	arquivo = fopen("pontuacao.txt","r");
	CU_ASSERT_PTR_NOT_NULL(arquivo);
}

void test_atualiza_placar(){
	tela* t = nova_tela();
	int linhas_antes = 0;
	int linhas_depois = 0;
	char caracter;
	
	cria_placar();
	FILE *arquivo;
	arquivo = fopen("pontuacao.txt","r");

	while(caracter = fgetc(arquivo) != EOF){
		if(caracter == '\n'){
			linhas_antes++;
		}
	}
	fclose(arquivo);
	
	strcpy(t->jogador,"TST");
	t->pontos = 0;
	t->tempo_m = 0;
	t->tempo_s = 0; 
	
	seta_jogador(t);
	atualiza_placar(t->pontos);
	
	arquivo = fopen("pontuacao.txt","r");
	
	while(caracter = fgetc(arquivo) != EOF){
		if(caracter == '\n'){
			linhas_depois++;
		}
	}
	fclose(arquivo);
	
	if(linhas_antes == 5){
		CU_ASSERT_EQUAL(linhas_antes,linhas_depois);
	}
	else{
		CU_ASSERT_EQUAL(linhas_depois - linhas_antes, 1);
	}
}
