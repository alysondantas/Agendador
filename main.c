#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void agendador();
void agendar_por_horario();
void agendar_por_hora_restante();
void cancela();
int main(int argc, char *argv[]) {
	
	int opcao;
	for(;;){
		system("cls");
	printf("============MENU DE AGENDA PARA O WINDOWS DESLIGAR============\n");
	printf("Você deseja:\n	1-Agendar horario para desligar:\n	2-Cancelar horario agendado:\n	3-Outra para sair do programa.\n");//menu criado pra navegar entre as opções que estão nas funçoes
	scanf("%i",&opcao);//pega a opção do menu
	getchar();
	switch(opcao){
		case 1:
			agendador();
			break;
		case 2:
			cancela();
			break;
		default:
			return 0;
			break;
	}}
}

void cancela(){
	char comando[30]="shutdown -a";
	printf("agendamento cancelado cancelado!");
	system(comando);
}

void agendador(){
	int opcao;
	
	printf("============MENU DE AGENDA PARA O WINDOWS DESLIGAR OU REINICIAR============\n");
	printf("Você deseja:\n	1-Agendar por horario:\n	2-Agendar por horas restantes:\n	3-Para voltar ao menu principal:\n");//menu criado pra navegar entre as opções que estão nas funçoes
	scanf("%i",&opcao);//pega a opção do menu
	getchar();
	switch(opcao){
		case 1:
			agendar_por_horario();
			break;
		case 2:
			agendar_por_hora_restante();
			break;
		default:
			return 0;
			break;
	}
	
}

void agendar_por_horario(){
	int hora=0;
	int hora2=0;
	int minuto=0;
	int minuto2=0;
	int i,c=0;
	char horas[3];
	char minutos[3];
	char horario[9];
	char comando[30]="shutdown -s -t ";
	_strtime(horario);//função pra pegar a data atual do sistema e colocar na variavel

	strncpy (horas,horario,2);
	horas[2]='\0';
	
	for(i=3;i<5;i++){
		minutos[c]=horario[i];
		c=c+1;
	}
	minutos[2]='\0';

	FILE *saida; //ponteiro para o arquivo txt de saida relatorio.txt
	FILE *saida2; //ponteiro para o arquivo txt de saida relatorio.txt
		saida = fopen("processando.txt", "w");
		fprintf(saida,"%s ",horas);
		fprintf(saida,"%s",minutos);
		fclose(saida);
	
		saida2=fopen("processando.txt","r");
		fscanf(saida2,"%i",&hora2);
		fscanf(saida2,"%i",&minuto2);
		fclose(saida2);
	
/*	puts(horas);
	printf("\n");
	puts(minutos);
	printf("\n");
	puts(horario);
	printf("\n");
	printf("hora: %i e minuto %i",hora2,minuto2);
	getchar();*/

	printf("qual a hora DE HOJE que deseja agendar? exemplo 16 ou 17\n");
	scanf("%i",&hora);
	getchar();
	printf("digite os minutos agora: exemplo 40\n");
	scanf("%i",&minuto);
	getchar();
	if(hora>24){
		printf("hora invalida alterada para 23 horas");
		hora=23;
	}
	if(minuto>60){
		printf("hora invalida alterada para 00 minutos.");
		minuto=23;
	}
	if(hora==24 && minuto>1){
		printf("Horario invalido foi convertido pra 00:00");
		hora=00;
		minuto=00;
	}
	
	hora=hora2-hora;
	if(minuto>minuto2){
		minuto=minuto-minuto2;
	}
	else{
		minuto=minuto2-minuto;
	}
	hora=hora*60;
	hora=hora*60;
	minuto=minuto*60;
	hora=hora+minuto;
	if(hora<0){
		hora=hora*-1;
	}
	
			//	FILE *saida; //ponteiro para o arquivo txt de saida relatorio.txt
				saida = fopen("processando.txt", "w");
				fprintf(saida,"%i",hora);
				fclose(saida);
				
			//	FILE *saida2; //ponteiro para o arquivo txt de saida relatorio.txt
				saida2 = fopen("processando.txt", "r");
				fgets(horario,40,saida2);//pega informação do arquivo
				fclose(saida2);
				strcat(comando,horario);
				system(comando);	
}

void agendar_por_hora_restante(){
	int opcao;
	int tempo;
	char tempo1[40];
	char comando[30]="shutdown -s -t ";
	printf("deseja agendar por hor, minutos ou segundos?\n");
	printf("	1-Agendar por hora:\n	2-Agendar por minutos:\n	3-Agendar por segundos:\n	4-Sair para o menu:\n");
	scanf("%i",&opcao);
	FILE *saida; //ponteiro para o arquivo txt de saida relatorio.txt
	FILE *saida2; //ponteiro para o arquivo txt de saida relatorio.txt
	getchar();
		switch(opcao){
		case 1:
			printf("Quantas horas daqui ate que o desligamento? exemplo 4\n");
			scanf("%d",&tempo);
			getchar();
			tempo = tempo * 60;
			tempo = tempo * 60;
				saida = fopen("processando.txt", "w");
				fprintf(saida,"%i",tempo);
				fclose(saida);
				saida2 = fopen("processando.txt", "r");
				fgets(tempo1,40,saida2);//pega informação do arquivo
				fclose(saida2);
				strcat(comando,tempo1);
				system(comando);
				
			break;
		case 2:
			printf("Quantos minutos daqui ate que o desligamento? exemplo 160\n");
			scanf("%d",&tempo);
			getchar();
			tempo = tempo * 60;
			itoa(tempo,tempo1,40);
				
			//	FILE *saida; //ponteiro para o arquivo txt de saida relatorio.txt
				saida = fopen("processando.txt", "w");
				fprintf(saida,"%i",tempo);
				fclose(saida);
				
			//	FILE *saida2; //ponteiro para o arquivo txt de saida relatorio.txt
				saida2 = fopen("processando.txt", "r");
				fgets(tempo1,40,saida2);//pega informação do arquivo
				fclose(saida2);
				strcat(comando,tempo1);
				system(comando);				
			break;
		case 3:
			printf("Quantas segundos daqui ate que o desligamento? exemplo 40\n");
			scanf("%d",&tempo);
			//	FILE *saida; //ponteiro para o arquivo txt de saida relatorio.txt
				saida = fopen("processando.txt", "w");
				fprintf(saida,"%i",tempo);
				fclose(saida);
				
			//	FILE *saida2; //ponteiro para o arquivo txt de saida relatorio.txt
				saida2 = fopen("processando.txt", "r");
				fgets(tempo1,40,saida2);//pega informação do arquivo
				fclose(saida2);
				strcat(comando,tempo1);
				system(comando);
			break;
	}
	return 0;
}
