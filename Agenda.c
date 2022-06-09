#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct evento{
	int type_event; // 1- Tarefa / 2- Reuniao/ 3- Aniversario
	char assunto[100];
	int horario_i;
	int horario_f;
	int esforco;
	int prioridade;
	char info_local[100];
	char pres_obrigatoria;
	char nome[20];
	int vaga; // 0-DISPONIVEL / 1-INDISPONIVEL
}Evento;

typedef struct agenda{
	char nomee[20];
	char email[30];
	int vagaa; // 0-DISPONIVEL / 1- INDISPONIVEL
	Evento event[10];
}Agenda;

Agenda *cria_agenda(int tam, int events){
	Agenda* A = (Agenda*)malloc(tam * sizeof(Agenda));
	A->vagaa = 0;
	return A;
}

Evento cria_tarefa(){
	Evento x;
	printf("\n\nDigite o assunto da tarefa: \n");
	scanf("%s",x.assunto);
	while(true){
		printf("\n\nDigite o horario de inicio da tarefa: \n");
		scanf("%d",&x.horario_i);
		printf("\n\nDigite o horario de termino da tarefa: \n");
		scanf("%d",&x.horario_f);
		printf("\n\nDigite o grau de esforco da tarefa: \n");
		scanf("%d",&x.esforco);
		printf("\n\nDigite a prioridade da tarefa: \n");
		scanf("%d",&x.prioridade);
		if(x.horario_i < 0 || x.horario_i > 23 || x.horario_f < 0 || x.horario_f > 23 || x.horario_i >= x.horario_f || x.esforco < 1 || x.esforco > 5 || x.prioridade < 1 || x.prioridade > 10){
			printf("\nInformacoes invalidas!(DIGITE UM HORARIO ENTRE 0 E 23, ESFORCO ENTRE 1 E 5 E PRIORIDADE 1 A 10\n");
		}else{
			break;
		}
	}
	x.type_event = 1;
	return x;
}

Evento cria_reuniao(){
	Evento x;
	printf("\n\nDigite o assunto da reuniao: \n");
	scanf("%s",x.assunto);
	while(true){
		printf("\n\nDigite o horario de inicio da reuniao: \n");
		scanf("%d",&x.horario_i);
		printf("\n\nDigite o horario de termino da reuniao: \n");
		scanf("%d",&x.horario_f);
		if(x.horario_i < 0 || x.horario_i > 23 || x.horario_f < 0 || x.horario_f > 23 || x.horario_i >= x.horario_f){
			printf("Horario invalido(COLOQUE UM HORARIO DE 0 A 23!\n");
		}else{
			break;
		}
	}
	printf("\n\nDigite as informacoes sobre o local: \n");
	scanf("%s",x.info_local);
	printf("A presenca eh obrigatoria?(s/n): \n");
	scanf( " %c",&x.pres_obrigatoria);
	x.type_event = 2;
	return x;
}

Evento cria_aniversario(){
	Evento x;
	printf("\n\nDigite o assunto do aniversario: \n");
	scanf("%s",x.assunto);
		while(true){
		printf("\n\nDigite o horario de inicio do aniversario: \n");
		scanf("%d",&x.horario_i);
		printf("\n\nDigite o horario de termino do aniversario: \n");
		scanf("%d",&x.horario_f);
		if(x.horario_i < 0 || x.horario_i > 23 || x.horario_f < 0 || x.horario_f > 23 || x.horario_i >= x.horario_f){
			printf("Horario invalido(COLOQUE UM HORARIO DE 0 A 23!\n");
		}else{
			break;
		}
	}
	printf("\n\nDigite as informacoes sobre o local: \n");
	scanf("%s",x.info_local);
	printf("\n\nDigite o nome do aniversariante: \n");
	scanf("%s",x.nome);
	x.type_event = 3;
	return x;
}

Agenda cadastra_usuario(int tam_events){
	Agenda A;
	printf("\n\nDigite o nome do usuario a cadastrar: \n");
	scanf("%s",A.nomee);
	printf("\n\nDigite o e-mail do usuario a cadastrar: \n");
	scanf("%s",A.email);
	A.vagaa = 1;
	for(int i=0;i<10;i++){
		A.event[i].vaga = 0;
		A.event[i].horario_i = -1;
		A.event[i].horario_f = -1;
	}
	return A;
}

void lista_usuarios(Agenda *x,int tam){
	for(int i=0;i<tam;i++){
		if(x[i].vagaa == 1){
			printf("\n\nNome: %s\ne-mail: %s\n\n",x[i].nomee,x[i].email);
		}
	}
}

void freeall(Agenda *x){
	free(x);
}

void imprime_agenda(Agenda x, int tam){
	for(int i=0;i<tam;i++){
		if(x.event[i].vaga == 1){
			if(x.event[i].type_event == 1){
				printf("\n\nTarefa das %d as %d\n",x.event[i].horario_i,x.event[i].horario_f);
				printf("\n-Assunto-\n%s",x.event[i].assunto);
				printf("\nGrau de esforco: %d",x.event[i].esforco);
				printf("\nPrioridade: %d",x.event[i].prioridade);		
			}else if(x.event[i].type_event == 2){
				printf("\n\nReuniao das %d as %d\n",x.event[i].horario_i,x.event[i].horario_f);
				printf("\nInformacoes sobre o local:\n%s",x.event[i].info_local);
				printf("\nA presenca e obrigatoria? %c",x.event[i].pres_obrigatoria);
			}else{
				printf("\n\nAniversario das %d as %d\n",x.event[i].horario_i,x.event[i].horario_f);
				printf("\nInformacoes sobre o local:\n%s",x.event[i].info_local);
				printf("\nNome do aniversariante:\n%s",x.event[i].nome);
			}
		}
	}
}

void inicializa(){
	int tam = 10;
	int tam_events = 10;
	int menu_command;
	int submenu_command;
	Agenda *P = cria_agenda(tam,tam_events);
	while(true){
		menu_command = 0;
		printf("\n\n1-GERENCIAR USUARIO\n2-GERENCIAR AGENDA\n3-SAIR\nDigite a opcao: ");
		scanf("%d",&menu_command);
		if(menu_command == 1){
			while(true){
				submenu_command = 0;
			printf("\n\n1-CADASTRAR USUARIO\n2-LISTAR USUARIOS\n3-VOLTAR\nDigite a opcao: ");
			scanf("%d",&submenu_command);
			if(submenu_command == 1){
				for(int i=0;i<tam;i++){
					if(P[i].vagaa == 0){
						P[i] = cadastra_usuario(tam_events);
						break;
					}else if(i==tam-1){
						printf("\nNAO HA VAGAS DISPONIVEIS NA AGENDA");
					}
				}
			}else if(submenu_command == 2){
				for(int i=0;i<tam;i++){
					if(P[i].vagaa = 1){
						lista_usuarios(P,tam);
						break;
					}
				}
			}else if(submenu_command == 3){
				break;
			}else{
				printf("\n\nCOMANDO INVALIDO!\n\n");
			}
		}


		}else if(menu_command == 2){
				int usuario_id;
				int voltax = 0;
			while(true){
				if(voltax == -1){
					break;
				}
				int tetst = 0;
				char r_nome[20];
				printf("\n\nDigite o nome da pessoa a cadastrar o Evento:\n");
				scanf("%s",r_nome);
				for(int i=0;i<tam;i++){
					if(P[i].vagaa == 1){
						if(strcmp(r_nome,P[i].nomee)==0){
							usuario_id = i;
							break;
						}
					}else if(i==tam-1){
						printf("\n\nUSUARIO NAO ENCONTRADO\n");
						tetst = 1;
					}
				}if(tetst == 0){
					printf("\n\nBEM VINDO %s\n\n",P[usuario_id].nomee);
				}else{
					continue;
				}
				while(true){
					printf("\n\n1-CADASTRAR TAREFA\n2-CADASTRAR REUNIAO\n3-CADASTRAR ANIVERSARIO\n4-IMPRIMIR AGENDA\n5-VOLTAR\nDigite a opcao: ");
					scanf("%d",&submenu_command);
					if(submenu_command == 1){
						Evento R = cria_tarefa();
						int verificacao;
						for(int i=0;i<tam_events;i++){
							verificacao = 0;
							if(P[usuario_id].event[i].vaga == 0){
								for(int j=0;j<tam_events;j++){
									if((R.horario_i < P[usuario_id].event[j].horario_i && R.horario_f <= P[usuario_id].event[j].horario_i)||(R.horario_i >= P[usuario_id].event[j].horario_f)){
								}else{
									verificacao = -1;
								}
								}if(verificacao == 0){
									printf("\n*TAREFA ADICIONADA COM SUCESSO*\n");
									P[usuario_id].event[i] = R;
									P[usuario_id].event[i].vaga = 1;
									break;
								}else{
									printf("\n\nCOINCIDENCIA DE HORARIOS!TENTE NOVAMENTE\n\n");
									break;
								}
							}
						}
					}else if(submenu_command == 2){
						Evento R = cria_reuniao();
						int verificacao;
						for(int i=0;i<tam_events;i++){
							verificacao = 0;
							if(P[usuario_id].event[i].vaga == 0){
								for(int j=0;j<tam_events;j++){
									if((R.horario_i < P[usuario_id].event[j].horario_i && R.horario_f <= P[usuario_id].event[j].horario_i)||(R.horario_i >= P[usuario_id].event[j].horario_f)){
								}else{
									verificacao = -1;
								}
								}if(verificacao == 0){
									printf("\n*REUNIAO ADICIONADA COM SUCESSO*\n");
									P[usuario_id].event[i] = R;
									P[usuario_id].event[i].vaga = 1;
									break;
								}else{
									printf("\n\nCOINCIDENCIA DE HORARIOS!TENTE NOVAMENTE\n\n");
									break;
								}
							}
						}
					}else if(submenu_command == 3){
						Evento R = cria_aniversario();
						int verificacao;
						for(int i=0;i<tam_events;i++){
							verificacao = 0;
							if(P[usuario_id].event[i].vaga == 0){
								for(int j=0;j<tam_events;j++){
									if((R.horario_i < P[usuario_id].event[j].horario_i && R.horario_f <= P[usuario_id].event[j].horario_i)||(R.horario_i >= P[usuario_id].event[j].horario_f)){
								}else{
									verificacao = -1;
								}
								}if(verificacao == 0){
									printf("\n*ANIVERSARIO ADICIONADA COM SUCESSO*\n");
									P[usuario_id].event[i] = R;
									P[usuario_id].event[i].vaga = 1;
									break;
								}else{
									printf("\n\nCOINCIDENCIA DE HORARIOS!TENTE NOVAMENTE\n\n");
									break;
								}
							}
						}
					}else if(submenu_command == 4){
						imprime_agenda(P[usuario_id],tam_events);

					}else if(submenu_command == 5){
						voltax = -1;
						break;
					}else{
						printf("\n\nCOMANDO INVALIDO!DIGITE NOVAMENTE!\n\n");
					}
				}
			}
		}else if(menu_command == 3){
			break;
		}else{
			printf("\n\nCOMANDO INVALIDO!");
		}
	}
	freeall(P);
}

int main(void){
	inicializa();
	return 0;
}