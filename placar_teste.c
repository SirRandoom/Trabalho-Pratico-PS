#include"CUnit/CUnit.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
	FILE *arquivo;
	
	arquivo = fopen("pontuacao.txt","r");
	CU_ASSERT_PTR_NOT_NULL(arquivo);
}

void test_atualiza_placar(){
	Tela *t;
	int jogadores_antes = 0;
	int jogadores_depois = 0;
	char caracter = 0;
	
	FILE *arquivo = fopen("pontuacao.txt","r");
	t = cria_tela();

	while((caracter = fgetc(arquivo)) != EOF){
		if(caracter == '\n'){
			jogadores_antes++;
		}
	}
	fclose(arquivo);

	
	seta_jogador(t);
	atualiza_placar(t->pontos);
	
	FILE* arquivo2 = fopen("pontuacao.txt","r");
	
	while((caracter = fgetc(arquivo2)) != EOF){
		if(caracter == '\n'){
			jogadores_depois++;
		}
	}
	fclose(arquivo2);
	
	if(jogadores_antes == 5){
		CU_ASSERT_EQUAL(jogadores_antes,jogadores_depois);
	}
	else{
		CU_ASSERT_EQUAL(jogadores_depois - jogadores_antes, 1);
	}
}
