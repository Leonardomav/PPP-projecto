#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "header.h"

void menu(Lista_viagens lista_principal_viagens, Lista_utilizadores lista_principal_utilizadores){
	int opcao = 0;

    verifica_ficheiros(); /*verifica que os ficheiros est�o dispon�veis e funcionais*/

    while(1){
        printf(" _____ _____ _____ _____ \n|     |   __|   | |  |  |\n| | | |   __| | | |  |  |\n|_|_|_|_____|_|___|_____|\n___________________________\n\n");
        printf("[1] Registar uma viagem\n");
        printf("[2] Registar um utilizador\n");
        printf("[3] Compra viagem para o utilizador\n");
        printf("[4] Cancelar viagem de um utilizador\n");
        printf("[5] Listar viagens para um destino\n");
        printf("[6] Listar viagens de um utilizador\n");
        printf("[7] Listar todos os utilizadores com viagens compradas\n");
        printf("[8] Sair do programa\n\n");

        opcao=devolve_inteiro();

        system("cls");
        switch(opcao){
            case 1:
                regista_viagem_manual(lista_principal_viagens);
                /*lista_para_ficheiro(lista_principal,"listas.txt");*/
                break;
            case 2:
                regista_cliente_manual(lista_principal_utilizadores);
                /*lista_para_ficheiro(lista_principal,"listas.txt");*/
                break;
            case 3:
                compra_viagem(lista_principal_utilizadores, lista_principal_viagens);
                /*lista_para_ficheiro(lista_principal,"listas.txt");*/
                break;
            case 4:

                break;
            case 5:
                viagens_destino(lista_principal_viagens);
                break;
            case 6:
                viagens_utilizador(lista_principal_utilizadores);
                break;
            case 7:
                todos_com_viagem(lista_principal_utilizadores);
                break;
            case 8:
                return;
                break;
            default:
                printf("Introduza uma op��o v�lida!\n");
                break;
        }
        printf("Prima Enter para voltar ao menu.");
        while(getchar()!='\n');
        system("cls");
    }
}

int main(){
    Lista_viagens lista_principal_viagens;
    Lista_utilizadores lista_principal_utilizadores;
    lista_principal_viagens = cria_lista_viagens();
    lista_principal_utilizadores = cria_lista_utilizadores();
    carrega_listas(lista_principal_viagens, lista_principal_utilizadores);
    setlocale(LC_ALL, "Portuguese");

    /*verifica_ficheiros(); verifica que os ficheiros est�o dispon�veis e funcionais
    ficheiro_para_lista(lista_principal ,"listas.txt");*/

    menu(lista_principal_viagens, lista_principal_utilizadores);
    guarda_listas(lista_principal_viagens, lista_principal_utilizadores);


    return 0;
}
