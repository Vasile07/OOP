//
// Created by Irimieş Vasile on 3/10/2023.
//
#pragma once
#ifndef LABORATORUL_2_4_REPO_MASINI_H
#define LABORATORUL_2_4_REPO_MASINI_H

#endif //LABORATORUL_2_4_REPO_MASINI_H
#include "../Domain/masina.h"

typedef struct{
    int dimensiune;
    int capacitate;
    Masina* masini;
}ListaMasini;

/***
 * Redimensioneaza capacitatea listei de masini
 * @param lista - ListaMasini
 */
void redimensionare(ListaMasini *lista);

/***
 * Returneaza o ListaMasini
 * @return ListaMasini
 */
ListaMasini constructor_repo();

/***
 * Adauga o masina in lista de masini
 * @param lista - ListaMasini
 * @param m - Masina
 * @return  0 - A fost adaugata cu succes
 *          1 - Exista deja numarul de inmatriculare al masinii in lista
 */
int adauga_masina_repo(ListaMasini *lista, Masina m);

/***
 * Modifica o masina din lista de masini
 * @param lista - ListaMasini
 * @param m_nou - masina
 * @return  0 - A fost modificata cu succes
 *          1 - Nu exista masina cu numarul de inmatriculare respectiv
 */
int modifica_masina_repo(ListaMasini lista, Masina m_nou);

/***
 * Returneaza pozitia din lista al masinii cu nr de inmatriculare respectiv
 * @param lista - ListaMasini
 * @param Numar_Inmatriculare - string
 * @return -1 - Nu exista masina in lista
 *          pozitia - Altfel
 */
int cauta_masina_dupa_nr_inmatriculare_repo(ListaMasini lista, char Numar_Inmatriculare[]);

/***
 * Inchiriaza o masina din lista de masini cu nr de inmatriculare dat
 * @param lista - ListaMasini
 * @param NumarInmatriculare - string
 * @return  0 - Inchiriere cu succes
 *          1 - Nu exista nr de inmatriculare
 */
int inchiriraza_repo(ListaMasini lista, char NumarInmatriculare[]);

/***
 * Returneaza o masina
 * @param lista - ListaMasini
 * @param NumarInmatriculare - string
 * @return  0 - Returnare cu succes
 *          1 - Nu exista nr de inmatriculare
 */
int returneaza_masina(ListaMasini lista, char NumarInmatriculare[]);

/***
 * Returneaza lungimea listei
 * @param lista - ListaMasini
 * @return lungime
 */
int lungime_repo(ListaMasini lista);

/***
 * Returneaza lista de masini disponibile
 * @param lista
 * @return
 */
ListaMasini get_all_disponibil_repo(ListaMasini lista);

void Destroy_Lista_Masini(ListaMasini lista);