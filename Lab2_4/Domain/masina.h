//
// Created by Irimieş Vasile on 3/9/2023.
//
#pragma once
#ifndef LABORATORUL_2_4_MASINA_H
#define LABORATORUL_2_4_MASINA_H

#endif //LABORATORUL_2_4_MASINA_H
/***
 * numar_de_imatriculare - char
 * model - char
 * categorie - char
 * status_inchiriere - int
 */
typedef struct {
    char* numar_de_inmatriculare;
    char* model;
    char* categorie;
    int status_inchiriere;
}Masina;

/***
 * Returneaza un "obiect" de tip Masina
 * @param numar_de_inmatriculare - char
 * @param model - char
 * @param categorie - char
 * @return m - Masina
 */
Masina constructor_masina(char* numar_de_inmatriculare, char* model, char* categorie);

/***
 * Updateaza numarul de inmatriculare a masinii cu numarul de inmatriculare nou
 * @param m - Masina
 * @param numar_inmatriculare_nou - string
 */
void set_numar_inmatriculare(Masina *m, char numar_inmatriculare_nou[]);

/***
 * Updateaza modelul masinii cu model_nou
 * @param m - Masina
 * @param model_nou - string
 */
void set_model(Masina *m, char model_nou[]);

/***
 * Updateaza categoria masinii cu categorie_noua
 * @param m - Masina
 * @param categorie_noua - string
 */
void set_categorie(Masina *m, char categorie_noua[]);

void set_status_inchiriere(Masina *m, int status_inchiriere_nou);

/***
 * Verifica daca numarul de inmatriculare a celor doua masinii sunt egale
 * @param m1 - Masina
 * @param m2 - Masina
 * @return 1 - Egal, 0 - Altfel
 */
int eq(Masina m1, Masina m2);

Masina CopyMasina(Masina m);

void Destroy_Masina(Masina m);