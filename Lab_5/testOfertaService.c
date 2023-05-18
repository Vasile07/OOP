#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "oferta.h"
#include "ofertaService.h"
#include "listaOferte.h"
#include "ofertaRepo.h"
#pragma warning(disable:4996)

void testAdaugaOfertaService() {
    listaOferte *o = createOList();

    assert(adauga_oferta_service(o, 1, "mare", "spania", "21.04", 100) == 0);
    oferta* of = o->lista[0];
    assert(of->id == 1);
    assert(strcmp(of->tip, "mare") == 0);
    assert(strcmp(of->destinatie, "spania") == 0);
    assert(strcmp(of->data_plecare, "21.04") == 0);
    assert(of->pret == 100);
    deleteLista(o, (DeleteFuncion) deleteOferta);
}

void testStergeOfertaService() {
    listaOferte *o = createOList();

    adauga_oferta_service(o, 1, "mare", "spania", "21.04", 100);
    assert(sterge_oferta_service(o, 1) == 0);
    assert(o->size == 0);
    deleteLista(o, (DeleteFuncion) deleteOferta);
}

void testModificaOfertaService() {
    listaOferte *o = createOList();

    adauga_oferta_service(o, 1, "mare", "spania", "21.04", 100);
    assert(modifica_oferta_service(o, 1, "munte", "italia", "21.05", 150) == 0);
    oferta* of = o->lista[0];
    assert(of->id == 1);
    assert(strcmp(of->tip, "munte") == 0);
    assert(strcmp(of->destinatie, "italia") == 0);
    assert(strcmp(of->data_plecare, "21.05") == 0);
    assert(of->pret == 150);
    deleteLista(o, (DeleteFuncion) deleteOferta);
}

void testSortareDupaPretSiDestinatie() {
    listaOferte *o = createOList();

    adauga_oferta_service(o, 1, "mare", "spania", "22.04", 100);
    adauga_oferta_service(o, 2, "munte", "italia", "23.05", 100);
    adauga_oferta_service(o, 3, "mare", "turcia", "24.06", 50);

    listaOferte *o_sortat = createOList();
    sortareDupaPretsiDestinatie(o, o_sortat);
    oferta* of1 = o_sortat->lista[0];
    oferta* of2 = o_sortat->lista[1];
    oferta* of3 = o_sortat->lista[2];
    assert(of1->id == 3);
    assert(of2->id == 2);
    assert(of3->id == 1);
    deleteLista(o, (DeleteFuncion) deleteOferta);
    free(o_sortat->lista);
    free(o_sortat);

}

void testFiltrareDupaCriteriu(){
    listaOferte *o = createOList();
    adauga_oferta_service(o, 1, "mare", "spania", "21.02", 100);
    adauga_oferta_service(o, 2, "munte", "italia", "22.03", 150);
    adauga_oferta_service(o, 3, "mare", "turcia", "22.04", 300);

    listaOferte *o_filtrat1 = createOList();
    char criteriu1[25] = "tip";
    char argument1[25] = "mare";
    filtrareDupaCriteriu(o, o_filtrat1, criteriu1, argument1);
    assert(o_filtrat1->size == 2);

    listaOferte *o_filtrat2 = createOList();
    char criteriu2[25] = "destinatie";
    char argument2[25] = "spania";
    filtrareDupaCriteriu(o, o_filtrat2, criteriu2, argument2);
    assert(o_filtrat2->size == 1);

    listaOferte *o_filtrat3 = createOList();
    char criteriu3[25] = "pret";
    char argument3[25] = "200";
    filtrareDupaCriteriu(o, o_filtrat3,  criteriu3, argument3);
    assert(o_filtrat3->size == 2);

    listaOferte* o_filtrat4 = createOList();
    char criteriu4[25] = "mediu";
    char argument4[25] = "";
    filtrareDupaCriteriu(o, o_filtrat4, criteriu4, argument4);
    assert(o_filtrat4->size == 2);

    deleteLista(o, (DeleteFuncion) deleteOferta);
    free(o_filtrat1->lista);
    free(o_filtrat1);
    free(o_filtrat2->lista);
    free(o_filtrat2);
    free(o_filtrat3->lista);
    free(o_filtrat3);
    free(o_filtrat4->lista);
    free(o_filtrat4);

}

void test_lista_generica(){
    listaOferte* lista = createOList();
    listaOferte* lista1 = createOList();
    listaOferte* lista2 = createOList();
    listaOferte* c_lista1 = CopyListaOferte(lista1);
    listaOferte* c_lista2 = CopyListaOferte(lista2);

    adauga_oferta(lista, c_lista1);
    adauga_oferta(lista, c_lista2);

    deleteLista(lista, (DeleteFuncion) deleteListaOferte);
    deleteLista(lista1, (DeleteFuncion) deleteOferta);
    deleteLista(lista2, (DeleteFuncion) deleteOferta);
}