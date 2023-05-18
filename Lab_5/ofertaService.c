#include <string.h>
#include <stdlib.h>
#include "oferta.h"
#include "ofertaRepo.h"
#include <stdio.h>
#include "listaOferte.h"
#include "ofertaService.h"


int adauga_oferta_service(listaOferte *o, int id, char *tip, char *destinatie, char *data_plecare, int pret){
    oferta *Oferta_noua = createOferta(id, tip, destinatie, data_plecare, pret);
    adauga_oferta(o, Oferta_noua);
    return 0;

}

int sterge_oferta_service(listaOferte *o, int id){
    oferta* Oferta_de_sters;
    for(int i = 0; i < o->size; i++) {
        oferta* of  =o->lista[i];
        if (of->id == id)
            Oferta_de_sters = o->lista[i];
    }
    sterge_oferta(o, Oferta_de_sters);
    return 0;

}

int modifica_oferta_service(listaOferte *o, int id, char *tip, char *destinatie, char *data_plecare, int pret){
    oferta *Oferta_noua = createOferta(id, tip, destinatie, data_plecare, pret);
    modifica_oferta(o, Oferta_noua);
    return 0;

}

void sortareDupaPretsiDestinatie(listaOferte *o, listaOferte *o_ordonat){
    for(int i = 0; i < o->size; i++)
        adauga_oferta(o_ordonat, o->lista[i]);
    for (int i = 0; i < o_ordonat->size - 1; i++)
        for (int j = 0; j < o_ordonat->size - i - 1; j++) {
            oferta* of1 = o_ordonat->lista[j];
            oferta* of2 = o_ordonat->lista[j+1];
            if (of1->pret > of2->pret) {
                oferta *aux = o_ordonat->lista[j];
                o_ordonat->lista[j] = o_ordonat->lista[j + 1];
                o_ordonat->lista[j + 1] = aux;
            } else if (of1->pret == of2->pret) {
                if (strcmp(of1->destinatie, of2->destinatie) > 0) {
                    oferta *aux = o_ordonat->lista[j];
                    o_ordonat->lista[j] = o_ordonat->lista[j + 1];
                    o_ordonat->lista[j + 1] = aux;
                }
            }
        }
}

void filtrareDupaCriteriu(listaOferte *o, listaOferte *o_filtrata, char *criteriu, char *argument){
    if(strcmp(criteriu, "destinatie") == 0){
        for(int i = 0; i < o->size; i++) {
            oferta* of = o->lista[i];
            if (strcmp(of->destinatie, argument) == 0)
                adauga_oferta(o_filtrata, o->lista[i]);
        }
    }
    else if (strcmp(criteriu, "tip") == 0){
        for(int i = 0; i < o->size; i++) {
            oferta* of = o->lista[i];
            if (strcmp(of->tip, argument) == 0)
                adauga_oferta(o_filtrata, o->lista[i]);
        }
    }
    else if(strcmp(criteriu, "pret") == 0){
        int pret = atoi(argument);
        for(int i = 0; i < o->size; i++) {
            oferta* of = o->lista[i];
            if (of->pret <= pret)
                adauga_oferta(o_filtrata, o->lista[i]);
        }
    }
    else if ( strcmp ( criteriu, "mediu") == 0) {
        filtrarePretMediu(o, o_filtrata);
    }

}

int pret_mediu(listaOferte* l){
    int suma =  0;
    for ( int i  =  0 ; i < l->size ; i++ ) {
        oferta* of = l->lista[i];
        suma += of->pret;
    }
    return suma/l->size;
}

void filtrarePretMediu(listaOferte* l, listaOferte* o_filtrat){
    int PretMediu = pret_mediu(l);
    for ( int i = 0 ; i < l->size ; i ++ ){
        oferta* o = l->lista[i];
        if ( o->pret <= PretMediu )
            adauga_oferta(o_filtrat, o);
    }
}

