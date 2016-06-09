#include<stdio.h>
#include<stdlib.h>
#include "placar.h"
#include<string.h>

static placar *score;

void cria_placar(){
	score = malloc(sizeof(placar));
	score->contador_jogadores = 0;
	FILE *Debug = fopen("saida.txt","w");
	
	score->arquivo = fopen("pontuacao.txt","r");
	if(score->arquivo == NULL){
		score->arquivo = fopen("pontuacao.txt","w");
	}
	else{
		int c;
		int caracteres = 0, tabulacoes = 0;
		int min = 0, sec = 0;
		char* pontuacao = NULL, *tempo_m = NULL, *tempo_s = NULL;
		char* nova_pontuacao = NULL, *novo_tempo_m = NULL, *novo_tempo_s = NULL;
		while((c = fgetc(score->arquivo)) != EOF){
			if(c == '\n'){
				fputs(pontuacao,Debug);
				fputc('\t',Debug);
				fputs(tempo_m,Debug);
				fputc('\t',Debug);
				fputs(tempo_s,Debug);
				fputc('\n',Debug);
				score->pontuacoes[score->contador_jogadores] = (int) strtol(pontuacao, NULL, 10);
				score->tempos_m[score->contador_jogadores] = (int) strtol(tempo_m,NULL,10);
				score->tempos_s[score->contador_jogadores] = (int) strtol(tempo_s,NULL,10);
				score->contador_jogadores++;
				tabulacoes = 0;
				caracteres = 0;
				min = sec = 0;
				free(pontuacao);
				free(tempo_m);
				free(tempo_s);
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
			}
			
			caracteres++;
			
		}
	}
	fclose(score->arquivo);  
}

void atualiza_placar(int pontuacao){
	extern char* jogador;
	extern int tempo_s, tempo_m;
	
	cria_placar();
	
	score->arquivo = fopen("texte.txt","w");
	char* valor;
	sprintf(valor,"%d",score->tempos_m[2]);
	fputs(valor,score->arquivo);
	
}



void destroi_placar(){
	free(score);
}
