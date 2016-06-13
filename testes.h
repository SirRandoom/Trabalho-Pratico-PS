#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "placar.h"


void adiciona_testes(void);
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

