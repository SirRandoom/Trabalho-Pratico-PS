Alunos: 
	Luís Felipe de Melo Nunes - 11/0129849 - Usuário Git: SirRandoom
	Luís Fernando Mendes Cury - 15/0041292 - Usuário Git: lfmc
	Rafael Koji - 11/0137078 - Usuário Git: RafaelKoji

Reposítório GitHub:
	https://github.com/SirRandoom/Trabalho-Pratico-PS
	
Compilando e Executando o Programa:
	Inicialmente deve-se extrair os arquivos enviados em zip para um diretório a ser utilizado. Para compilar basta abrir um terminal apontando para o diretório em que os arquivos foram extraídos e utilizar o comando make junto ao makefile enviado com os módulos, executando a main (./main) após o termino da compilação para  iniciar o programa.

Obs: é necessário ter a biblioteca ncurses instalada para compilação correta.
Obs2: A CUnit utilizada é para sitemas 64 bits.
	
Funções do Programa:
F4 - finaliza o programa
setas direcionais - movimenta peças durante o jogo

Para utilizar o splint foi utilizada a seguinte linha de comando no diretório do trabalho

	splint *.c *.h -weak +infloops +compdef +sysdirerrors -redef

As bibliotecas do sistema (timeb.h, features.h, cdefs.h, stubs.h, stubs-64.h, wordsize.h) foram incluídas no diretório do trabalho devido a problemas de uso do splint.
Caso o sistema a ser utilizado seja 32 bits, ou algum erro do splint for detectado, deve-se trocar na main o #include "timeb.h" por #include <timeb.h>, e utilizar a diretiva -preproc (além das demais na linha de comando acima referente ao splint) para que seja chamada a timeb.h do sistema e não ocorram erros (pois a timeb.h não se encontra na pasta usr/include, necessitando da diretiva -preproc). O -redef foi utilizado, pois o módulo de testes foi realizado em um executável a parte da main.c, apresentando também a função main para funcionar de forma independente, inibindo o warning do splint de redefinição.
