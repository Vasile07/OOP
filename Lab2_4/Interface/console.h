//
// Created by Irimieş Vasile on 3/9/2023.
//
#ifndef LABORATORUL_2_4_CONSOLE_H
#define LABORATORUL_2_4_CONSOLE_H

#endif //LABORATORUL_2_4_CONSOLE_H
#include "../Service/service_masini.h"

void ruleaza_ui();

void help_ui();

void adauga_ui(ListaMasini *lista,  char* parametri);

void actualizeaza_ui(ListaMasini lista, char* parametri);

void inchiriere_masina(ListaMasini lista, char* parametri);

void returnare_masina(ListaMasini lista, char* parametri);

void filtrare_ui(ListaMasini lista, char* parametri);

void sort_ui(ListaMasini *lista, char* parametri);

void afisare_ui(ListaMasini lista);

int convert_comand(char* comanda);

void strip(char* comanda);