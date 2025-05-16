#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>                      
	

#define MAX_CANDIDATOS 10

typedef struct {
	char numero[3];
	char nome[50];
	int votos;
} Candidato;

Candidato candidatos[MAX_CANDIDATOS];



int limiteCandidatos;
int totalVotos = 0;
int totalBranco = 0;
int totalNulo = 0;



void limparTela() {
	system("cls");
}



void delay(int tempo) {
	int win;
	win = tempo * 1000;
	Sleep(win);
}



void progresso() {
	
	limparTela();
	printf("\n\t\t\t\t\t\t  [          ] 0%% ");		
	delay(1); 	  	  	    
	limparTela();	
	printf("\n\t\t\t\t\t\t  [==        ] 25%% ");		
	delay(1); 	  	  	    
	limparTela();
	printf("\n\t\t\t\t\t\t  [=====     ] 50%% ");		
	delay(1); 	  	  	    
	limparTela();
	printf("\n\t\t\t\t\t\t  [========  ] 75%% ");		
	delay(1); 	  	  	    
	limparTela();
	printf("\n\t\t\t\t\t\t      CARREGADO     ");		
	delay(2);   	  	    
	limparTela();
}



void confirmarVoto() {
	
	limparTela();
	printf("\n\t\t\t\t\t\t  [          ] 0%% ");		
	delay(1); 	  	  	    
	limparTela();	
	printf("\n\t\t\t\t\t\t  [==        ] 25%% ");		
	delay(1); 	  	  	    
	limparTela();
	printf("\n\t\t\t\t\t\t  [=====     ] 50%% ");		
	delay(1); 	  	  	    
	limparTela();
	printf("\n\t\t\t\t\t\t  [========  ] 75%% ");		
	delay(1); 	  	  	    
	limparTela();
	printf("\n\t\t\t\t\t\t      VOTO COMPUTADO     ");		
	delay(2); 	  	  	    
	limparTela();
}



void menu() {						    

	limparTela();   	
	printf("\t\t\t\t# #  ##   ###   #     ### #   ### ### ### ###  ### # ###  # \n");
	printf("\t\t\t\t# #  # #  # #  # #    #   #   #    #  # # # #  # # # #   # #\n");
	printf("\t\t\t\t# #  ##   # #  ###    ### #   ###  #  ##  # #  # # # #   ###\n");
	printf("\t\t\t\t# #  # #  # #  # #    #   #   #    #  # # # #  # # # #   # #\n");	
	printf("\t\t\t\t###  # #  # #  # #    ### ### ###  #  # # ###  # # # ### # #\n");
	printf("\n\t\t\t\t***		VOTACAO PARA REPRESENTANTE		***\n\n\n");

	printf("\n\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n\n");
	printf("\t\t\t\t             	   ELEICOES ESTUDANTIS           \n");
	printf("\t\t\t\t                                                 \n");
	printf("\t\t\t\t             1  -  CADASTRAR CANDIDATOS          \n");
	printf("\t\t\t\t             2  -  INICIAR VOTACAO               \n");
	printf("\t\t\t\t             3  -  CONTABILIZAR VOTOS            \n");
	printf("\t\t\t\t             4  -  SAIR                          \n");
	printf("\n\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n\n");
}



int login() {
	
	char tituloEleitor[12];
	printf("\n\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n\n");
	printf("\t\t\t\t\t            LOGIN URNA ELETRONICA           \n\n");
	printf("\t\t\t\t\t       Informe o TITULO para prosseguir     \n\n");
	printf("\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n");
	printf("\n\n  -> Titulo: \n\n");
	scanf("%s", tituloEleitor);
	
	progresso();
	return 1;
}



void cadastrarCandidato() {
	
	printf("\n\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n\n");
	printf("\t\t\t\t\t               URNA ELETRONICA               \n\n");
	printf("\t\t\t\t\t            CADASTRAR CANDIDATOS             \n\n");
	printf("\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n");
	
	
	printf("\n\n  -> Quantos candidatos deseja colocar?      \n");
	printf("                  (MAXIMO 10)               \n\n");
	scanf("%d", &limiteCandidatos);
	
	if(limiteCandidatos > 10 || limiteCandidatos < 1) {
		limparTela();
		printf("\t\t\t\t\t\n\n       Opcao Invalida!      \n");
		delay(2);
		
	} else {
		int i;
		for(i = 0; i < limiteCandidatos; i++) {
			printf("\n\n  -> Nome: \n\n");
			scanf(" %49[^\n]", candidatos[i].nome);
			printf("\n\n -> Numero: [2 digitos] \n\n");
			scanf("%s", candidatos[i].numero);
			candidatos[i].votos = 0;
		}	
	}
	
	limparTela();
}



void votar() {
	
	char opcaoVoto[3];
	int encontrou = 0;
	
	printf("\n\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n\n");
	printf("\t\t\t\t\t               URNA ELETRONICA               \n\n");
	printf("\t\t\t\t\t            ESCOLHA UM CANDIDATO             \n\n");
	int i;
	for(i = 0; i < limiteCandidatos; i++) {
		printf("\t\t\t\t\t          %s - %s          \n", candidatos[i].numero, candidatos[i].nome);
	}
	printf("\t\t\t\t\t          00 - Voto em branco             \n\n");
	printf("\t\t\t\t\t            Digite sua opcao             \n\n");
	printf("\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n");
	scanf("%s", opcaoVoto);
	
	if(strcmp(opcaoVoto, "00") == 0 || strcmp(opcaoVoto, "0") == 0) {
		totalBranco++;
		totalVotos++;
		confirmarVoto();
		
	} else {
		
		int i;
		for(i = 0; i < limiteCandidatos; i++) {
			
			if(strcmp(opcaoVoto, candidatos[i].numero) == 0) {
				candidatos[i].votos++;
				totalVotos++;
				encontrou = 1;
				confirmarVoto();
			}
		}
		
		if(encontrou == 0) {
			printf("\t\t\t\t\t\n\n       Opcao Invalida!      \n");
			totalNulo++;
			totalVotos++;
		}
	}
	
	limparTela();
}



void exibirResultados() {
	printf("\n\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n\n");
	printf("\t\t\t\t\t               URNA ELETRONICA               \n\n");
	printf("\t\t\t\t\t             RESULTADOS ELEICOES             \n\n");
	printf("\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n\n");
	
	if(totalVotos == 0) {
		printf("\n\n\t\t\t\t\t       Nenhum voto registrado.      \n");
		delay(5);
		return;
	}
	
	int i;
	int maiorVoto = 0;
	int maisVotado = 0;
	int contadorEmpate = 0;
	int empate = 0;
	
	for(i = 0; i < limiteCandidatos; i++) {
		if(candidatos[i].votos > maiorVoto) {
			maiorVoto = candidatos[i].votos;
		}
	}

	for(i = 0; i < limiteCandidatos; i++) {
		if(candidatos[i].votos == maiorVoto) {
			contadorEmpate++;
			maisVotado = i;
		}
	}

	if(contadorEmpate > 1) {
		empate = 1;
	} else {
		empate = 0;
	}
	
	for(i = 0; i < limiteCandidatos; i++) {
		float porcentagem = (candidatos[i].votos * 100.00)	/ totalVotos;
		printf("\t\t\t\t\t          %s : %d (%.2f%%)          \n", candidatos[i].nome, candidatos[i].votos, porcentagem);
	}
	
	float porcentagemBranco = (totalBranco * 100.00) / totalVotos;
	float porcentagemNulo = (totalNulo * 100.00) / totalVotos;
	printf("\t\t\t\t\t          Votos em branco: %d (%.2f%%)          \n", totalBranco, porcentagemBranco);
	printf("\t\t\t\t\t          Votos nulos: %d (%.2f%%)          \n", totalNulo, porcentagemNulo);
	printf("\t\t\t\t\t          Total de votos validos: %d          \n", totalVotos - totalBranco - totalNulo);
	
	if(empate == 1) {
		for(i = 0; i < limiteCandidatos; i++) {
			candidatos[i].votos = 0;
		}
		empate = 0;
		totalVotos = 0;
		totalBranco = 0;
		totalNulo = 0;

		printf("\n\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n");
		printf("\n\t\t\t\t                   HOUVE UM EMPATE!            \n");
		printf("\t\t\t\t             SERA NECESSARIO UMA NOVA ELEICAO  \n\n");
		printf("\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n");
	} else {
		printf("\n\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n\n");
		printf("\t\t\t\t\t                 VENCEDOR                \n\n");
		printf("\t\t\t\t                       %s                        \n\n", candidatos[maisVotado].nome);
		printf("\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - +\n");
	}
	
	int voltarMenu;
	do {
		printf("\n\n  -> Digite 0 para voltar ao menu:      \n");
		scanf("%d", &voltarMenu);
	} while(voltarMenu != 0);

	limparTela();
}



void despedida() {
	limparTela();   	
	printf("\t\t\t\t# #  ##   ###   #     ### #   ### ### ### ###  ### # ###  # \n");
	printf("\t\t\t\t# #  # #  # #  # #    #   #   #    #  # # # #  # # # #   # #\n");
	printf("\t\t\t\t# #  ##   # #  ###    ### #   ###  #  ##  # #  # # # #   ###\n");
	printf("\t\t\t\t# #  # #  # #  # #    #   #   #    #  # # # #  # # # #   # #\n");	
	printf("\t\t\t\t###  # #  # #  # #    ### ### ###  #  # # ###  # # # ### # #\n\n");
	
	printf("\n\t\t\t\t\t\t * OBRIGADO POR PARTICIPAR *\n\n");
	
	printf("\t\t\t\t\t\t\t### # #####\n");
	printf("\t\t\t\t\t\t\t#   # # # #\n");
	printf("\t\t\t\t\t\t\t### # # # #\n");
	printf("\t\t\t\t\t\t\t#   # # # #\n");	
	printf("\t\t\t\t\t\t\t#   # # # #\n\n");
}



int main() {
	
	setlocale(LC_ALL, "Portuguese_Brazil");
	int opcao;
	int candidatosCadastrados = 0;
	
	while(login() != 1);
	
	do {
		menu();
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1:
				limparTela();
				cadastrarCandidato();
				candidatosCadastrados = 1;
				break;
				
			case 2: 
				limparTela();
				if(candidatosCadastrados == 0) {
					printf("\n\n\t\t\t\t       Cadastre os candidatos primeiro!      \n");
					delay(3);
				} else {
					votar();
				}
				break;
				
			case 3: 
				limparTela();
				exibirResultados();
				break;
				
			case 4: 
				limparTela();
				despedida();
				break;
				
			default: 
				limparTela();
				printf("\n\n\t\t\t\t       Opcao Invalida!      \n");
		}	
			
	} while(opcao != 4);
	
	system("pause");
	return 0;
}
