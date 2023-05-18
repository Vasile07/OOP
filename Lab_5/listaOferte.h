#include <stdio.h>
#include "oferta.h"
#pragma once


typedef void* TElem;
typedef void (*DeleteFuncion)(TElem);

typedef struct {
    int size;
    int maxSize;
    TElem* lista;

}listaOferte;

listaOferte* createOList();

void deleteLista(listaOferte *o, DeleteFuncion delete_element);