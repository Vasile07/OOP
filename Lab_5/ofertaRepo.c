#include "oferta.h"
#include <stdio.h>
#include <stdlib.h>
#include "listaOferte.h"



int adauga_oferta(listaOferte *o, TElem OfertaNoua){
//    for(int i = 0; i < o->size; i++)
//        if (o->lista[i]->id == OfertaNoua->id)
//            return -1;

    if(o->size == o->maxSize) {
        o->maxSize = o->maxSize * 2;
        TElem* auxO = malloc(sizeof(oferta) * o->maxSize);
        for (int i = 0; i < o->size; i++)
            auxO[i] = o->lista[i];
        free(o->lista);
        o->lista = auxO;
    }
    o->lista[o->size] = OfertaNoua;
    o->size++;
    return 0;

}

int modifica_oferta(listaOferte *o, TElem OfertaNoua){
    for(int i = 0; i < o->size; i++) {
        oferta* of = o->lista[i];
        oferta* of_noua = OfertaNoua;
        if (of->id == of_noua->id) {
            oferta *de_sters = o->lista[i];
            o->lista[i] = OfertaNoua;
            deleteOferta(de_sters);
            return 0;
        }
    }
    return -1;

}

int sterge_oferta(listaOferte *o, TElem Oferta_de_sters){
    for(int i= 0; i < o->size; i++) {
        oferta* of = o->lista[i];
        oferta* of_de_sters = Oferta_de_sters;
        if (of->id == of_de_sters->id) {
            deleteOferta(o->lista[i]);
            for (int j = i; j < o->size - 1; j++)
                o->lista[j] = o->lista[j + 1];
            o->size--;
            return 0;
        }
    }
        return -1;
}

void deleteListaOferte(listaOferte* lista){
    for (int i = 0 ; i < lista->size ; i ++ ) {
        oferta* of = lista->lista[i];
        deleteOferta(of);
    }
    free(lista->lista);
    free(lista);
}

listaOferte* CopyListaOferte(listaOferte* lista){
    listaOferte* copie = createOList();
    for ( int i = 0 ; i < lista->size ; i ++ ) {
        oferta* of = lista->lista[i];
        adauga_oferta(copie, createOferta(of->id, of->tip, of->destinatie, of->data_plecare, of->pret));
    }
    return copie;
}