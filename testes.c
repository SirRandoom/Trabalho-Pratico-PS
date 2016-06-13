#include "testes.h"

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
	int pointer;
	Tela* tela = cria_tela();
	nova_peca(tela);
	pointer = (long int)(tela->peca);
	CU_ASSERT_TRUE( pointer );
}

void teste_VerificaMovePecaDireita(void){
	int i, mover = 1;
	Tela* tela = cria_tela();
	int* x = NULL;
	nova_peca(tela);
	x = malloc(sizeof(int)*tela->peca->tamanho);
	
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
	int* x = NULL;
	nova_peca(tela);
	x = malloc(sizeof(int)*tela->peca->tamanho);
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
	int* y = NULL;
	nova_peca(tela);
	y = malloc(sizeof(int)*tela->peca->tamanho);
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

