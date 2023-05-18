//
// Created by Irimieş Vasile on 3/10/2023.
//
#include <stdio.h>
#include <string.h>
#include "console.h"
//#include "../Service/service_masini.h"

void help_ui(){
    printf("COMENZI:                                                        PARAMETRI:\n");
    printf("afiseaza                                                        \n");
    printf("adauga                                                          Numar Inmatriculare(CC.NN.CCC) + Model + Categorie\n");
    printf("modifica                                                        Numar Inmatriculare(CC.NN.CCC) + Model + Categorie\n");
    printf("inchiriaza                                                      Numar Inmatriculare(CC.NN.CCC)\n");
    printf("returneaza                                                      Numar Inmatriculare(CC.NN.CCC)\n");
    printf("filtrare                                                        -c + Categorie\n");
    printf("                                                                -m + Model\n");
    printf("sortare                                                         -c - pt criteriu\n");
    printf("                                                                -m - pt model\n");
    printf("                                                                -r - pt reverse\n");
    printf("exit                                                            \n");

}

void ruleaza_ui(){
    ListaMasini lista = constructor_service();
    printf("help - Lista de comenzi si parametri\n");
    repeta:
    while(1){
        char comanda[1001];
        printf(">>>");
        fgets(comanda, 1000, stdin);
        strip(comanda);
        if(strcmp(comanda, "help") == 0 ) {
            help_ui();
            goto repeta;
        }
        if(strcmp(comanda, "exit") == 0) {
            Destroy_Lista_Masini_service(lista);
            break;
        }
        switch (convert_comand(comanda)) {
            case 0:
                afisare_ui(lista);
                goto repeta;
            case 1:
                adauga_ui(&lista, strchr(comanda,' ') + 1);
                goto repeta;
            case 2:
                actualizeaza_ui(lista, strchr(comanda,' ') + 1);
                goto repeta;
            case 3:
                inchiriere_masina(lista, strchr(comanda,' ') + 1);
                goto repeta;
            case 4:
                returnare_masina(lista, strchr(comanda,' ') + 1);
                goto repeta;
            case 5:
                filtrare_ui(lista, strchr(comanda,' ') + 1);
                goto repeta;
            case 6:
                sort_ui(&lista, strchr(comanda,' ') + 1);
                goto repeta;
            default:
                printf("Comanda invalida!\n");
                goto repeta;
        }
    }
}

int convert_comand(char* comanda){

    if (strcmp(comanda,"afiseaza") == 0) return 0;
    if ( !strchr(comanda,' ') ) return -1;
    int poz =(int) ( strchr(comanda, ' ') - comanda );

    char S[1001];

    strncpy(S, comanda, poz);
    S[poz] = '\0';
    if (strcmp(S, "adauga") == 0) return 1;
    if (strcmp(S, "modifica") == 0) return 2;
    if (strcmp(S, "inchiriaza") == 0) return 3;
    if (strcmp(S, "returneaza") == 0) return 4;
    if (strcmp(S, "filtrare") == 0) return 5;
    if (strcmp(S, "sortare") == 0) return 6;
    return -1;
}

void afisare_ui(ListaMasini lista){
    for ( int i = 0; i < lungime_service(lista) ; i ++ ) {
        char* S = (lista.masini[i].status_inchiriere == 0 ? "Disponibil" : "Inchiriat");
        printf("Numar de inmatriculare: %s\nModel: %s\nCategorie: %s\nStatus inchiriere: %s\n\n", lista.masini[i].numar_de_inmatriculare,
               lista.masini[i].model, lista.masini[i].categorie, S);
    }
}


void adauga_ui(ListaMasini *lista,char* parametri) {
    char NrInmatriculare[101], Model[101], Categorie[101];
    char* p, S[3][101];
    p = strtok(parametri, " ");
    int i  = 0;
    while(p){
        strcpy(S[i], p);
        i ++;
        p = strtok(NULL, " ");
    }
    strcpy(NrInmatriculare, S[0]);
    strcpy(Model, S[1]);
    strcpy(Categorie, S[2]);
    int return_code = adauga_masina_service(lista, NrInmatriculare, Model, Categorie);
    if ( return_code == 0 ) printf("Adaugare efectuata cu succes\n");
    if ( return_code == 1 ) printf("Numar de inmatriculare existent\n");
    if ( return_code == -2) printf("Date invalide!\n");

}

void actualizeaza_ui(ListaMasini lista, char* parametri){
    char NrInmatriculare[101], Model[101], Categorie[101];
    char* p, S[3][101];
    p = strtok(parametri, " ");
    int i  = 0;
    while(p){
        strcpy(S[i], p);
        i ++;
        p = strtok(NULL, " ");
    }
    strcpy(NrInmatriculare, S[0]);
    strcpy(Model, S[1]);
    strcpy(Categorie, S[2]);
    int return_code = modifica_masina_service(lista, NrInmatriculare, Model, Categorie);
    if ( return_code == 0 ) printf("Actualizare efectuata cu succes\n");
    if ( return_code == 1 ) printf("Numar de inmatriculare inexistent\n");
    if ( return_code == -2 ) printf("Date invalide\n");
}

void inchiriere_masina(ListaMasini lista, char* parametri){
    int return_code = inchiriaza_masina_service(lista, parametri);
    if ( return_code == 0 ) printf("Inchriere efectuata cu succes\n");
    if ( return_code == 1 ) printf("Inchiriere indisponibila\n");
}

void returnare_masina(ListaMasini lista, char* parametri){
    int return_code = returneaza_masina_service(lista, parametri);
    if ( return_code == 0 ) printf("Retur efectuat cu succes\n");
    if ( return_code == 1 ) printf("Retur indisponibila\n");
}

void filtrare_ui(ListaMasini lista, char* parametri){
    char Criteriu[101], item[101];
    char* p = strtok(parametri, " ");
    strcpy(Criteriu, p);
    p = strtok(NULL, " ");
    strcpy(item, p);
    printf("%s\n", Criteriu);
    ListaMasini lista_filtrata = filtrare(lista, Criteriu, item);
    afisare_ui(lista_filtrata);
    Destroy_Lista_Masini_service(lista_filtrata);
}

void sort_ui(ListaMasini *lista, char *parametri){

    char criteriu[101], orientare[101] = "";
    char* p = strtok(parametri, " ");
    strcpy(criteriu, p);
    p = strtok(NULL, " ");
    if ( p )
        strcpy(orientare, p);
    sortare(lista, criteriu, orientare);
}

void strip(char* comanda){
    char new_comand[1001] = "";
    char* p = strtok(comanda, " \n");
    int i = 0;
    while(p){
        if ( i > 0 )
            strcat(new_comand, " ");
        strcat(new_comand, p);
        i ++;
        p = strtok(NULL, " \n");
    }
    strcpy(comanda, new_comand);
}

/***
adauga CJ.33.ANA 1x1 tractor
adauga CJ.18.MOS 2x2 ana
adauga CJ.01.AAA 2x2 ana
adauga CJ.02.BBB 3x3 ajn
adauga CJ.03.CCC 1x1 ana
 *
*/