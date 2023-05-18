#include "oferta.h"
#include "listaOferte.h"
#pragma once

int adauga_oferta_service(listaOferte *o, int id, char *tip, char *destinatie, char *data_plecare, int pret);

int sterge_oferta_service(listaOferte *o, int id);

int modifica_oferta_service(listaOferte *o, int id, char *tip, char *destinatie, char *data_plecare, int pret);

void sortareDupaPretsiDestinatie(listaOferte *o, listaOferte *o_ordonat);

void filtrareDupaCriteriu(listaOferte *o, listaOferte *o_filtrata, char *criteriu, char *argument);

/**
 * Returneaza pretul mediu din lista de oferte
 * @param lista - listaOferte
 * @return pret_mediu - int
 */
int pret_mediu(listaOferte* lista);

/**
 * Returneaza o lista cu toate ofertele de clatorie care au pretul sub pretul mediu
 * @param o - listaOferte
 * @return listaOferte
 */
void filtrarePretMediu(listaOferte* lista, listaOferte* o);

