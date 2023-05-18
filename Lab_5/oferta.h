#pragma once

typedef struct{
    int id;
    char *tip;
    char *destinatie;
    char *data_plecare;
    int pret;
}oferta;

oferta* createOferta(int id, char *tip, char *destinatie, char *data_plecare, int pret);

void deleteOferta(oferta *o);
