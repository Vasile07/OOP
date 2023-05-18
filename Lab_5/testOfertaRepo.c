#include <assert.h>
#include <string.h>
#include "ofertaRepo.h"
#include "oferta.h"
#include <stdlib.h>
#pragma warning(disable:4996)

void testAdaugareOferta() {
    listaOferte *o = createOList();

    oferta* OfertaNoua = createOferta(1,"mare", "spania", "23.01",100);
    assert(adauga_oferta(o, OfertaNoua) == 0);

    oferta* of = o->lista[0] ;
    assert(of->id == OfertaNoua->id);
    assert(strcmp(of->tip, OfertaNoua->tip) == 0);
    assert(strcmp(of->destinatie, OfertaNoua->destinatie) == 0);
    assert(strcmp(of->data_plecare, OfertaNoua->data_plecare) == 0);
    assert(of->pret == OfertaNoua->pret);

    //assert(adauga_oferta(o, OfertaNoua) == -1);
    deleteLista(o, (DeleteFuncion) deleteOferta);
}

void testStergereOferta() {
    listaOferte *o = createOList();

    oferta* OfertaNoua = createOferta(1, "mare", "spania", "21.01", 100);

    adauga_oferta(o, OfertaNoua);
    oferta* OfertaNoua2 = createOferta(2,"mare","spania","21.01",100);
    adauga_oferta(o, OfertaNoua2);

    assert(sterge_oferta(o, OfertaNoua) == 0);
    assert(o->size == 1);
    OfertaNoua = createOferta(1, "mare", "spania", "21.01", 100);
    assert(sterge_oferta(o, OfertaNoua) == -1);
    deleteLista(o, (DeleteFuncion) deleteOferta);
    deleteOferta(OfertaNoua);

}

void testModificareOferta() {
    listaOferte *o = createOList();

    oferta* OfertaNoua = createOferta(1,"mare","spania","21.01", 100);

    oferta* OfertaMod = createOferta(1,"munte","italia","21.03",150);

    adauga_oferta(o, OfertaNoua);
    assert(modifica_oferta(o, OfertaMod) == 0);
    oferta* of =o->lista[0];
    assert(of->id == OfertaMod->id);
    assert(strcmp(of->tip, OfertaMod->tip) == 0);
    assert(strcmp(of->destinatie, OfertaMod->destinatie) == 0);
    assert(strcmp(of->data_plecare, OfertaMod->data_plecare) == 0);
    assert(of->pret == OfertaMod->pret);

    oferta* OfertaMod2 = createOferta(2,"mare","spania","21.11",123);
    assert(modifica_oferta(o, OfertaMod2) == -1);
    deleteLista(o, (DeleteFuncion) deleteOferta);
    deleteOferta(OfertaMod2);

}

void test_destroy(){
    listaOferte *o = createOList();
    oferta* OfertaNoua = createOferta(1,"mare","spania","21.01", 100);
    adauga_oferta(o, OfertaNoua);
    listaOferte* copie = CopyListaOferte(o);
    deleteListaOferte(o);
    deleteListaOferte(copie);

}