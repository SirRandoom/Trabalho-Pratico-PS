/**\file*/

#define PLACAR_H

/** \struct Placar */
typedef struct Placar{
  char jogadores[5][4]; /**<Vetor de jogadores.*/
  int pontuacoes[5]; /**<Vetor de pontuação dos jogadores no placar.*/
  int tempos_m[5];/**<Vetor de tempo em minutos dos jogadores.*/
  int tempos_s[5];/**<Vetor de tempo em segundos dos jogadores.*/
  int anos[5]; /**<Vetor de anos dos jogadores.*/
  int meses[5]; /**<Vetor de meses dos jogadores no placar.*/
  int dias[5]; /**<Vetor de dias dos jogadores no placar.*/
  int contador_jogadores; /**<Contador de jogadores presentes no placar (máximo 5).*/
  FILE *arquivo; /**<Ponteiro para o arquivo usado para abrir o placar (pontuacao.txt) para leitura e escrita.*/
  char jogador[3]; /**<Nome do jogador atual.*/
  int pontuacao; /**<Pontuacao do jogador atual.*/
  int tempo_m; /**<Tempo em minutos do jogador atual.*/
  int tempo_s; /**<Tempo em segundos do jogador atual.*/
}placar; /**<\typedef Placar::placar*/

extern void cria_placar();
extern void atualiza_placar(int pontuacao);
extern void mostra_placar();
extern void destroi_placar();
extern void seta_jogador(Tela *t);
