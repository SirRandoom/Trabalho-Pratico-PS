#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h" 

void adiciona_testes(void);

<<<<<<< HEAD
void teste_VerificaCriaTela(void);
void teste_VerificaComprimentoTela(void);
void teste_VerificaLarguraTela(void);
void teste_VerificaNovaTela(void);
void teste_VerificaMovePecaDireita(void);
void teste_VerificaMovePecaEsquerda(void);
void teste_VerificaMovePecaBaixo(void);
void teste_VerificaTeclaDireita(void);
void teste_VerificaTeclaEsquerda(void);
void teste_VerificaTeclaBaixo(void);
=======
void teste_VerificaCriaTela(void); //Teste que verifica se o ponteiro de tela foi criado
void teste_VerificaComprimentoTela(void); //Teste que verifica se o comprimento da Tela criada está correto
void teste_VerificaLarguraTela(void); //Teste que verifica se a largura da Tela criada está correto
void teste_VerificaNovaPeca(void); //Teste que verifica se a peca foi corretamente criada
void teste_VerificaMovePecaDireita(void); //Teste que verifica se a peça se movimenta para a direita
void teste_VerificaMovePecaEsquerda(void); //Teste que verifica se a peça se movimenta para a esquerda
void teste_VerificaMovePecaBaixo(void); //Teste que verifica se a peça se movimenta para baixo
void teste_VerificaTeclaDireita(void); //Teste que verifica se a leitura da tecla "seta" direita foi realizada corretamente
void teste_VerificaTeclaEsquerda(void); //Teste que verifica se a leitura da tecla "seta" esquerda foi realizada corretamente
void teste_VerificaTeclaBaixo(void); // Teste que verifica se a leitura da tecla "seta" baixo foi realizada corretamente
>>>>>>> 72af0d3d091e5e37306af7aa0379ad25a53b1ee3

void teste_VerificaCriaTela(void){
	Tela* tela = cria_tela();
	int pointer = (long int)tela;
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

void teste_VerificaNovaPeca(void){
	Tela* tela = cria_tela();
	nova_peca(tela);
	int pointer = (long int)(tela->peca);
	CU_ASSERT_TRUE( pointer );
}

void teste_VerificaMovePecaDireita(void){
	Tela* tela = cria_tela();
	int i, mover = 1;
	nova_peca(tela);
	int x[tela->peca->tamanho];
	for(i = 0; i < tela->peca->tamanho; i++){
		x[i] = tela->peca->blocos[i]->pos_x;
	}

	move_peca_x(tela->peca,1);
	for(i = 0; i < tela->peca->tamanho; i++){
		if(tela->peca->blocos[i]->pos_x == x[i]+1){
			mover = 1;
		}
		else{
			mover = 0;
			break;
		}
	}
	CU_ASSERT_TRUE( mover );
}

void teste_VerificaMovePecaEsquerda(void){
	Tela* tela = cria_tela();
	int i, mover = 1;
	nova_peca(tela);
	int x[tela->peca->tamanho];
	for(i = 0; i < tela->peca->tamanho; i++){
		x[i] = tela->peca->blocos[i]->pos_x;
	}

	move_peca_x(tela->peca,-1);
	for(i = 0; i < tela->peca->tamanho; i++){
		if(tela->peca->blocos[i]->pos_x == x[i]-1){
			mover = 1;
		}
		else{
			mover = 0;
			break;
		}
	}
	CU_ASSERT_TRUE( mover );
}

void teste_VerificaMovePecaBaixo(void){
	Tela* tela = cria_tela();
	int i, mover = 1;
	nova_peca(tela);
	int y[tela->peca->tamanho];
	for(i = 0; i < tela->peca->tamanho; i++){
		y[i] = tela->peca->blocos[i]->pos_y;
	}

	move_peca_y(tela->peca,1);
	for(i = 0; i < tela->peca->tamanho; i++){
		if(tela->peca->blocos[i]->pos_y == y[i]+1){
			mover = 1;
		}
		else{
			mover = 0;
			break;
		}
	}
	CU_ASSERT_TRUE( mover );
}

void teste_VerificaTeclaEsquerda(void){
	int get = KEY_LEFT;
	CU_ASSERT_TRUE(pega_input(get) == 4);
}

void teste_VerificaTeclaDireita(void){
	int get = KEY_RIGHT;
	CU_ASSERT_TRUE(pega_input(get) == 3);
}
void teste_VerificaTeclaBaixo(void){
	int get = KEY_DOWN;
	CU_ASSERT_TRUE(pega_input(get) == 2);
}

void adiciona_testes(void){
	CU_pSuite suite;
	
	suite = CU_add_suite("Testes",NULL,NULL);
	
	CU_ADD_TEST(suite, teste_VerificaCriaTela);
	CU_ADD_TEST(suite, teste_VerificaComprimentoTela);
	CU_ADD_TEST(suite, teste_VerificaLarguraTela);
	CU_ADD_TEST(suite, teste_VerificaNovaPeca);
	CU_ADD_TEST(suite, teste_VerificaMovePecaDireita);
	CU_ADD_TEST(suite, teste_VerificaMovePecaEsquerda);
	CU_ADD_TEST(suite, teste_VerificaMovePecaBaixo);
	CU_ADD_TEST(suite, teste_VerificaTeclaEsquerda);
	CU_ADD_TEST(suite, teste_VerificaTeclaDireita);
	CU_ADD_TEST(suite, teste_VerificaTeclaBaixo);
}

