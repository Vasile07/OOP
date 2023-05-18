#include <stdio.h>
#include <string.h>
#include "ofertaRepo.h"
#include "ofertaService.h"
#include <stdlib.h>
#include "listaOferte.h"

void printMeniu() {
    printf("* Adaugarea de noi oferte				      - add, [id], [tip], [destinatie], [data_plecarii], [pret]\n");
    printf("* Stergere oferte				 	      - pop, [id]\n");
    printf("* Modificare oferta					      - mod, [id], [tip], [destinatie], [data_plecarii], [pret]\n");
    printf("* Vizualizare oferete ordonat dupa pret, tip    - srt\n");
    printf("* Vizualizare oferta filtrate dupa un criteriu		      - fil, [criteriu], [argument]\n");
    printf("* Vizualizare oferte                            - print\n");
    printf("* Iesire                                        -  exit\n\n");
}

void clearScreen() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void printareOferte(listaOferte *o) {
    for (int i = 0; i < o->size; i++) {
        oferta* of = o->lista[i];
        printf("id: %d, tip: %s, destinatie: %s, data plecarii: %s, pret: %d\n",
               of->id, of->tip, of->destinatie, of->data_plecare, of->pret);
        printf("\n");
    }
}

void run(listaOferte *o, listaOferte* ListaUndo) {
    int id, pret;
    char tip[25], destinatie[25], data_plecarii[25], criteriu[25], argument[25];

    while (1) {
        printMeniu();
        char comanda[200];
        fgets(comanda, sizeof(comanda), stdin);
        comanda[strcspn(comanda, "\n")] = '\0';
        clearScreen();

        if (strcmp(comanda, "") == 0)
            continue;
        else if (strcmp(comanda, "exit") == 0) {
            deleteLista(o, (DeleteFuncion) deleteOferta);
            deleteLista(ListaUndo, (DeleteFuncion) deleteListaOferte);
            return;
        }

        char parti[100][100];
        char *token = strtok(comanda, ", ");
        int i = 0;
        while (token != NULL) {
            strcpy(parti[i++], token);
            token = strtok(NULL, ", ");
        }
        char *nume_comanda = parti[0];
        int num_params = i - 1;

        if (strcmp(nume_comanda, "add") == 0) {
            if (num_params != 5) {
                printf("Numar parametrii invalid!\n");
                continue;
            }

            id = atoi(parti[1]);
            strcpy(tip, parti[2]);
            strcpy(destinatie, parti[3]);
            strcpy(data_plecarii, parti[4]);
            pret = atoi(parti[5]);
            adauga_oferta(ListaUndo, CopyListaOferte(o));
            adauga_oferta_service(o, id, tip, destinatie, data_plecarii, pret);



        }
        else if (strcmp(nume_comanda, "pop") == 0) {
            if (num_params != 1) {
                printf("Numar parametrii invalid!\n");
                continue;
            }

            id = atoi(parti[1]);
            adauga_oferta(ListaUndo, CopyListaOferte(o));
            sterge_oferta_service(o, id);
        }
        else if (strcmp(nume_comanda, "mod") == 0) {
            if (num_params != 5) {
                printf("Numar parametrii invalid!\n");
                continue;
            }
            id = atoi(parti[1]);
            strcpy(tip, parti[2]);
            strcpy(destinatie, parti[3]);
            strcpy(data_plecarii, parti[4]);
            pret = atoi(parti[5]);
            adauga_oferta(ListaUndo, CopyListaOferte(o));
            modifica_oferta_service(o, id, tip, destinatie, data_plecarii, pret);
        }
        else if (strcmp(nume_comanda, "fil") == 0) {
//            if (num_params !) {
//                printf("Numar parametrii invalid!\n");
//                continue;
//            }
            strcpy(criteriu, parti[1]);
            //strcpy(argument, parti[2]);
            listaOferte* o_filtrat = createOList();
            filtrareDupaCriteriu(o, o_filtrat, criteriu, argument);
            printareOferte(o_filtrat);
            free(o_filtrat->lista);
            free(o_filtrat);
        }
        else if(strcmp(nume_comanda, "srt") == 0){
            if (num_params != 0) {
                printf("Numar parametrii invalid!\n");
                continue;
            }
            listaOferte* o_ordonat = createOList();
            sortareDupaPretsiDestinatie(o, o_ordonat);
            printareOferte(o_ordonat);
            deleteLista(o_ordonat, (DeleteFuncion) deleteOferta);
        }
        else if(strcmp(nume_comanda, "print") == 0) {
            if (num_params != 0) {
                printf("Numar parametrii invalid!\n");
                continue;
            }
            printareOferte(o);
        }
        else if(strcmp(nume_comanda, "undo") == 0){
            for ( int j  = 0 ; j < o->size ; j ++ )
                deleteOferta(o->lista[j]);
            o->size = 0;
            listaOferte* lista = ListaUndo->lista[ListaUndo->size - 1];
            ListaUndo->size = ListaUndo->size - 1;
            for ( int j  = 0 ; j < lista->size ; j ++ )
                adauga_oferta(o, lista->lista[j]);
            free(lista->lista);
            free(lista);
        }
    }
}