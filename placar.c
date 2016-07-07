/**\file*/

#include<curses.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#ifndef BLOCO_H
#include"bloco.h"
#endif

#ifndef TELA_H
#include"tela.h"
#endif

#define PLACAR_OWN
#include"placar.h"
#undef PLACAR_OWN

static placar *score;

/** Cria o placar, inicializando ou lendo o arquivo de pontuação, carregando pro programa os valores obtidos.*/
void cria_placar(){
	score = malloc(sizeof(placar));
	score->contador_jogadores = 0;
	/*FILE *Debug = fopen("saida.txt","w");*/
	
	score->arquivo = fopen("pontuacao.txt","r");
	if(score->arquivo == NULL){
		score->arquivo = fopen("pontuacao.txt","w");
	}
	else{
		int c;
		int caracteres = 0, tabulacoes = 0;
		int min = 0, sec = 0, data = 0;
		char* pontuacao = NULL, *tempo_m = NULL, *tempo_s = NULL, *dia = NULL, *mes = NULL, *ano = NULL;
		char* nova_pontuacao = NULL, *novo_tempo_m = NULL, *novo_tempo_s = NULL, *novo_dia = NULL, *novo_mes = NULL, *novo_ano = NULL;
		while((c = fgetc(score->arquivo)) != EOF){
			if(c == '\n'){
				/*fprintf(Debug,"%s\t%s-%s-%s/%s:%s\n",pontuacao,dia,mes,ano,tempo_m,tempo_s);*/
				score->pontuacoes[score->contador_jogadores] = (int) strtol(pontuacao, NULL, 10);
				score->tempos_m[score->contador_jogadores] = (int) strtol(tempo_m,NULL,10);
				score->tempos_s[score->contador_jogadores] = (int) strtol(tempo_s,NULL,10);
				score->anos[score->contador_jogadores] = (int) strtol(ano,NULL,10);
				score->meses[score->contador_jogadores] = (int) strtol(mes,NULL,10);
				score->dias[score->contador_jogadores] = (int) strtol(dia,NULL,10);
				score->contador_jogadores++;
				tabulacoes = 0;
				caracteres = 0;
				min = sec = data = 0;
				pontuacao = NULL;
				tempo_m = NULL;
				tempo_s = NULL;
				ano = NULL;
				mes = NULL;
				dia = NULL;
				nova_pontuacao = NULL;
				novo_tempo_m = NULL;
				novo_tempo_s = NULL;
				novo_dia = NULL;
				novo_mes = NULL;
				novo_ano = NULL;
				continue;
			}
			if(c == '\t'){
				tabulacoes++;
				caracteres = 0;
				continue;
			}
			
			switch(tabulacoes){
				case 0:
					score->jogadores[score->contador_jogadores][caracteres] = c;
					break;
				case 1:
					nova_pontuacao = realloc(pontuacao,(caracteres+1)*sizeof(char));
					if(nova_pontuacao != NULL){
						pontuacao = nova_pontuacao;
						pontuacao[caracteres] = c;
					}
					break;
				case 2:
					if(c == '-'){
							data++;
							caracteres = 0;
							continue;
						}
					if(c == '/'){
						min = 1;
						caracteres = 0;
						continue;
					}
					if(c == ':'){
						min = 0;
						sec = 1;
						caracteres = 0;
						continue;
					}
					if(min){
						novo_tempo_m = realloc(tempo_m,(caracteres+1)*sizeof(char));
						if(novo_tempo_m != NULL){
							tempo_m = novo_tempo_m;
							tempo_m[caracteres] = c;
						}						
					}
					if(sec){
						novo_tempo_s = realloc(tempo_s,(caracteres+1)*sizeof(char));
						if(novo_tempo_s != NULL){
							tempo_s = novo_tempo_s;
							tempo_s[caracteres] = c;	
						}
					}
					if(!min && !sec){
						if(!data){
							novo_dia = realloc(dia,(caracteres+1)*sizeof(char));
							if(novo_dia != NULL){
								dia = novo_dia;
								dia[caracteres] = c;
							}
						}
						if(data==1){
							novo_mes = realloc(mes,(caracteres+1)*sizeof(char));
							if(novo_mes != NULL){
								mes = novo_mes;
								mes[caracteres] = c;
							}
						}
						if(data==2){
							novo_ano = realloc(ano,(caracteres+1)*sizeof(char));
							if(novo_ano != NULL){
								ano = novo_ano;
								ano[caracteres] = c;
							}
						}
					}
			}
			
			caracteres++;
			
		}
		free(pontuacao);
		free(tempo_m);
		free(tempo_s);
		free(ano);
		free(mes);
		free(dia);
		free(nova_pontuacao);
		free(novo_tempo_m);
		free(novo_tempo_s);
		free(novo_dia);
		free(novo_mes);
		free(novo_ano);		
	}
	
	fclose(score->arquivo);  
}


/** Ordena o placar por ordem de pontuação. O limite é de 5 jogadores, sendo excluída a menor pontuação para manter este padrão.
    \param pontuacao Pontuação do jogador atual.
*/
void atualiza_placar(int pontuacao){
	
	time_t temp = time(NULL);
	struct tm tempo_local = *localtime(&temp);
	int i, indice = score->contador_jogadores;
	for(i = score->contador_jogadores-1; i >= 0 ; i--){
		if(pontuacao > score->pontuacoes[i]){
			indice = i;
		}
	}
	
	for(i = score->contador_jogadores-1; i >= indice; i--){
		if(i!=4){
			strcpy(score->jogadores[i+1],score->jogadores[i]);
			score->pontuacoes[i+1] = score->pontuacoes[i];
			score->tempos_m[i+1] = score->tempos_m[i];
			score->tempos_s[i+1] = score->tempos_s[i];
			score->anos[i+1] = score->anos[i];
			score->meses[i+1] = score->meses[i];
			score->dias[i+1] = score->dias[i];
		}
	}
	
	if(indice!=5){
		strcpy(score->jogadores[indice],score->jogador);
		score->pontuacoes[indice] = pontuacao;
		score->tempos_m[indice] = score->tempo_m;
		score->tempos_s[indice] = score->tempo_s;
		score->anos[indice] = 1900 + tempo_local.tm_year;
		score->meses[indice] = tempo_local.tm_mon+1;
		score->dias[indice] = tempo_local.tm_mday;
	}
	
	if(score->contador_jogadores != 5){
		score->contador_jogadores++;
	}
	
	score->arquivo = fopen("pontuacao.txt","w");
	
	for(i = 0; i < score->contador_jogadores; i++){
		fprintf(score->arquivo,"%c%c%c\t%d\t%d-%d-%d/%d:%d\n",score->jogadores[i][0],score->jogadores[i][1],score->jogadores[i][2],score->pontuacoes[i],score->dias[i],score->meses[i],score->anos[i],score->tempos_m[i],score->tempos_s[i]);
	}
	
	fclose(score->arquivo);
}

/** Mostra o placar ao fim do jogo.*/
void mostra_placar(){
	WINDOW *janela;
	int i;
	
	janela = newwin(score->contador_jogadores+2,35,8,25);
	wbkgd(janela,COLOR_PAIR(3));
	
	for(i = 0; i < score->contador_jogadores; i++){
		mvwprintw(janela,i+1,1,"%s\t%d\t%d-%d-%d/%d:%d\n",score->jogadores[i],score->pontuacoes[i],score->dias[i],score->meses[i],score->anos[i],score->tempos_m[i],score->tempos_s[i]);
	}
	box(janela, ACS_VLINE, ACS_HLINE);
	mvwprintw(janela,0,14,"Placar");
	wrefresh(janela);
}

/** Copia os dados da variável local de escore para a tela de execução.
    \param t Ponteiro para tela.
*/
void seta_jogador(Tela *t){
	strcpy(score->jogador,t->jogador);
	score->pontuacao = t->pontos;
	score->tempo_m = t->tempo_m;
	score->tempo_s = t->tempo_s;
}

/** Libera a memória alocada para o placar.*/
void destroi_placar(){
	free(score);
}
