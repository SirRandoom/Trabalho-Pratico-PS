/** \file */

#define TELA_H

/** \enum estado Variável enumerada que indica o estado do jogo.*/
enum estado {INICIO,JOGO,FINAL}; 

/** /struct Define a tela do jogo.*/
typedef struct tela{
  char jogador[3]; /**<Nome do atual jogador.*/ 
  int letra;
  int estado; /**<Estado atual do jogo.*/
  int pontos; /**<Pontuação do jogador.*/
  int tempo_m; /**<Tempo de execução em minutos.*/
  int tempo_s; /**<Tempo de execução em segundos.*/
  int comprimento; /**<Comprimento da tela.*/
  int largura; /**<Largura da tela.*/
  WINDOW *janela; /**<Ponteiro para a janela do jogo.*/
  struct Peca* peca; /**<Ponteiro para a peça em movimento.*/
  bloco blocos[]; /**<Matriz dos blocos na tela.*/
}Tela;

extern Tela* cria_tela(); 
extern void mostra_tela(Tela* t);
extern void mostra_pontos(int pontos);
extern void mostra_tempo(int minutos,int segundos); 
extern void destroi_tela(Tela* t);
extern void define_jogador(Tela* t);
extern void troca_letra(Tela *t,int valor);
extern void muda_letra(Tela *t, int valor); 
extern void limpa_linha (Tela* t, int y);
extern void desce_linhas (Tela* t, int y);
extern int verifica_linha(Tela* t);
extern int checa_fim(Tela* t);

