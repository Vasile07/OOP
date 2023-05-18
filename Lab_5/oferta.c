#include "oferta.h"
#include <stdlib.h>
#include <string.h>

oferta* createOferta(int id, char *tip, char *destinatie, char *data_plecare, int pret){
    oferta *o = (oferta*)malloc(sizeof(oferta));
    if (o){
        o->id = id;
        o->tip = (char*)malloc((strlen(tip) + 1) * sizeof(char));
        strcpy(o->tip,tip);
        o->destinatie = (char*)malloc((strlen(destinatie) + 1) * sizeof(char));
        strcpy(o->destinatie, destinatie);
        o->data_plecare = (char*)malloc((strlen(data_plecare) + 1) * sizeof(char));
        strcpy(o->data_plecare, data_plecare);
        o->pret = pret;
    }
    return o;
}

void deleteOferta(oferta *o){
    free(o->tip);
    free(o->destinatie);
    free(o->data_plecare);
    free(o);
}