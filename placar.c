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
				fprintf(Debug,"%s\t",pontuacao);
				fprintf(Debug,"%s\t",tempo_m);
				fprintf(Debug,"%s\n",tempo_s);
				score->pontuacoes[score->contador_jogadores] = (int) strtol(pontuacao, NULL, 10);
				score->tempos_m[score->contador_jogadores] = (int) strtol(tempo_m,NULL,10);
				score->tempos_s[score->contador_jogadores] = (int) strtol(tempo_s,NULL,10);
				score->contador_jogadores++;
				tabulacoes = 0;
				caracteres = 0;
				min = sec = 0;
				pontuacao = NULL;
				tempo_m = NULL;
				tempo_s = NULL;
				nova_pontuacao = NULL;
				novo_tempo_m = NULL;
				novo_tempo_s = NULL;
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
		free(pontuacao);
		free(tempo_m);
		free(tempo_s);
		free(nova_pontuacao);
		free(novo_tempo_m);
		free(novo_tempo_s);
				
	}
	
	fclose(score->arquivo);  
}

void atualiza_placar(int pontuacao){
	
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
		}
	}
	
	if(indice!=5){
		strcpy(score->jogadores[indice],"POP");
		score->pontuacoes[indice] = pontuacao;
		score->tempos_m[indice] = score->tela->tempo_m;
		score->tempos_s[indice] = score->tela->tempo_s;
	}
	
	if(score->contador_jogadores != 5){
		score->contador_jogadores++;
	}
	
	score->arquivo = fopen("pontuacao.txt","w");
	
	for(i = 0; i < score->contador_jogadores; i++){
		fprintf(score->arquivo,"%s\t%d\t/%d:%d\n",score->jogadores[i],score->pontuacoes[i],score->tempos_m[i],score->tempos_s[i]);
	}
	
	fclose(score->arquivo);
}

void seta_Tela(Tela *t){
	score->tela = t;
}


void destroi_placar(){
	free(score);
}
