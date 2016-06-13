[1mdiff --cc testes.c[m
[1mindex 1c588ea,3cb7a84..0000000[m
[1m--- a/testes.c[m
[1m+++ b/testes.c[m
[36m@@@ -6,16 -6,16 +6,29 @@@[m
  [m
  void adiciona_testes(void);[m
  [m
[32m++<<<<<<< HEAD[m
[32m +void teste_VerificaCriaTela(void);[m
[32m +void teste_VerificaComprimentoTela(void);[m
[32m +void teste_VerificaLarguraTela(void);[m
[32m +void teste_VerificaNovaTela(void);[m
[32m +void teste_VerificaMovePecaDireita(void);[m
[32m +void teste_VerificaMovePecaEsquerda(void);[m
[32m +void teste_VerificaMovePecaBaixo(void);[m
[32m +void teste_VerificaTeclaDireita(void);[m
[32m +void teste_VerificaTeclaEsquerda(void);[m
[32m +void teste_VerificaTeclaBaixo(void);[m
[32m++=======[m
[32m+ void teste_VerificaCriaTela(void); //Teste que verifica se o ponteiro de tela foi criado[m
[32m+ void teste_VerificaComprimentoTela(void); //Teste que verifica se o comprimento da Tela criada está correto[m
[32m+ void teste_VerificaLarguraTela(void); //Teste que verifica se a largura da Tela criada está correto[m
[32m+ void teste_VerificaNovaPeca(void); //Teste que verifica se a peca foi corretamente criada[m
[32m+ void teste_VerificaMovePecaDireita(void); //Teste que verifica se a peça se movimenta para a direita[m
[32m+ void teste_VerificaMovePecaEsquerda(void); //Teste que verifica se a peça se movimenta para a esquerda[m
[32m+ void teste_VerificaMovePecaBaixo(void); //Teste que verifica se a peça se movimenta para baixo[m
[32m+ void teste_VerificaTeclaDireita(void); //Teste que verifica se a leitura da tecla "seta" direita foi realizada corretamente[m
[32m+ void teste_VerificaTeclaEsquerda(void); //Teste que verifica se a leitura da tecla "seta" esquerda foi realizada corretamente[m
[32m+ void teste_VerificaTeclaBaixo(void); // Teste que verifica se a leitura da tecla "seta" baixo foi realizada corretamente[m
[32m++>>>>>>> 72af0d3d091e5e37306af7aa0379ad25a53b1ee3[m
  [m
  void teste_VerificaCriaTela(void){[m
  	Tela* tela = cria_tela();[m
