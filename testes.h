#define TESTES_H

#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<time.h>
#include"timeb.h"

#ifndef BLOCO_H
#include"bloco.h"
#endif

#ifndef PECAS_H
#include"pecas.h"
#endif

#ifndef TELA_H
#include"tela.h"
#endif

#ifndef PLACAR_H
#include"placar.h"
#endif

#ifndef ENGINE_H
#include"engine.h"
#endif

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

extern void adiciona_testes(void);
extern void teste_VerificaCriaTela(void); //Teste que verifica se o ponteiro de tela foi criado
extern void teste_VerificaComprimentoTela(void); //Teste que verifica se o comprimento da Tela criada está correto
extern void teste_VerificaLarguraTela(void); //Teste que verifica se a largura da Tela criada está correto
extern void teste_VerificaNovaPeca(void); //Teste que verifica se a peca foi corretamente criada
extern void teste_VerificaMovePecaDireita(void); //Teste que verifica se a peça se movimenta para a direita
extern void teste_VerificaMovePecaEsquerda(void); //Teste que verifica se a peça se movimenta para a esquerda
extern void teste_VerificaMovePecaBaixo(void); //Teste que verifica se a peça se movimenta para baixo
extern void teste_VerificaTeclaDireita(void); //Teste que verifica se a leitura da tecla "seta" direita foi realizada corretamente
extern void teste_VerificaTeclaEsquerda(void); //Teste que verifica se a leitura da tecla "seta" esquerda foi realizada corretamente
extern void teste_VerificaTeclaBaixo(void); // Teste que verifica se a leitura da tecla "seta" baixo foi realizada corretamente

