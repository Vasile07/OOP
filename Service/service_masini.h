//
// Created by Irimieş Vasile on 3/10/2023.
//
#pragma once
#ifndef LABORATORUL_2_4_SERVICE_MASINI_H
#define LABORATORUL_2_4_SERVICE_MASINI_H

#endif //LABORATORUL_2_4_SERVICE_MASINI_H
#include "../Repository/repo_masini.h"


/***
 * Returneaza un "obiect" de tipul repo(Tipul ListaMasini)
 * @return ListaMasini
 */
ListaMasini constructor_service();

/***
 * Adauga o masina in lista cu datele date
 * @param lista - ListaMasini
 * @param NumarInmatriculare - string
 * @param Model - string
 * @param Categorie - string
 * @return 0 - Masina adaugata cu succes
 *         1 - Numar de inmatriculare existent
 *         2 - Date invalide
 */
int adauga_masina_service(ListaMasini* lista, char* NumarInmatriculare, char* Model, char* Categorie);

/***
 * Modifica o masina din lista de masini cu nrInmatriculare dat
 * @param lista - ListaMasini
 * @param NumarInmatriculare - string
 * @param Model_nou - string
 * @param Categorie_noua - string
 * @return 0 - Masina modificata cu succes
 *         1 - Numar de inmatriculare inexistent
 *         2 - Date invalide
 */
int modifica_masina_service(ListaMasini lista, char* NumarInmatriculare, char* Model_nou, char* Categorie_noua);

/***
 * Inchiriaza o masina din lista de masini
 * @param lista - ListaMasini
 * @param NumarInmatriculare - string
 * @return 0 - Masina adaugata cu succes
 *         1 - Numar de inmatriculare inexistent
 *         2 - Date invalide
 */
int inchiriaza_masina_service(ListaMasini lista, char* NumarInmatriculare);

/***
 * Returneaza o masina din lista de masini
 * @param lista - ListaMasini
 * @param NumarInmatriculare - string
 * @return 0 - Masina returnata cu succes
 *         1 - Numar de inmatriculare inexistent
 *         2 - Date invalide
 */
int returneaza_masina_service(ListaMasini lista, char* NumarInmatriculare);

/***
 *
 * @param lista
 * @return
 */
int lungime_service(ListaMasini lista);

ListaMasini filtrare_masini_dupa_categorie(ListaMasini lista, char* Categorie);

ListaMasini filtreaza_masini_dupa_model(ListaMasini lista, char* Model);

ListaMasini filtrare(ListaMasini lista, char* criteriu, char* item);

void sortare_dupa_model(ListaMasini *lista, char* orientare);

void sortare_dupa_categorie(ListaMasini *lista, char* orientare);

void sortare(ListaMasini *lista, char* criteriu, char* orientare);

void Destroy_Lista_Masini_service(ListaMasini lista);