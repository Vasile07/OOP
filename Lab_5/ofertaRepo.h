#include "oferta.h"
#include "listaOferte.h"
#pragma once

int adauga_oferta(listaOferte *o, TElem OfertaNoua);

int modifica_oferta(listaOferte *o, TElem OfertaNoua);

int sterge_oferta(listaOferte *o, TElem Oferta_de_sters);

/**
 * Distruge o lista cu oferte
 * @param lista
 */
void deleteListaOferte(listaOferte* lista);

/**
 * Returneaza o copie a listei date
 * @param lista - listaOferta
 */
listaOferte* CopyListaOferte(listaOferte* lista);