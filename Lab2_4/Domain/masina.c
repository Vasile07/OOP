//
// Created by Irimieş Vasile on 3/9/2023.
//
#include "masina.h"
#include <string.h>
#include <stdlib.h>

Masina constructor_masina(char* numar_de_inmatriculare, char* model, char* categorie){
    Masina m;
    m.numar_de_inmatriculare = (char*) malloc((strlen(numar_de_inmatriculare)+1)*sizeof(char));
    m.model = (char*) malloc((strlen(model)+1) * sizeof(char) );
    m.categorie = (char*) malloc((strlen(categorie)+1) * sizeof(char));
    strcpy(m.numar_de_inmatriculare, numar_de_inmatriculare);
    strcpy(m.model, model);
    strcpy(m.categorie, categorie);
    m.status_inchiriere = 0;
    return m;
}

void set_numar_inmatriculare(Masina *m, char numar_inmatriculare_nou[]){
    free(m->numar_de_inmatriculare);
    m->numar_de_inmatriculare = (char*) malloc ((strlen(numar_inmatriculare_nou)+1) * sizeof(char));
    strcpy(m->numar_de_inmatriculare, numar_inmatriculare_nou);
}

void set_model(Masina *m, char model_nou[]){
    free(m->model);
    m->model = (char*) malloc ((strlen(model_nou)+1) * sizeof(char));
    strcpy(m->model, model_nou);
}

void set_categorie(Masina *m, char categorie_noua[]){
    free(m->categorie);
    m->categorie = (char*) malloc ((strlen(categorie_noua)+1) * sizeof(char));
    strcpy(m->categorie, categorie_noua);
}

void set_status_inchiriere(Masina *m, int status_inchiriere_noua){
    m->status_inchiriere = status_inchiriere_noua;
}

int eq(Masina m1, Masina m2){
    if (strcmp(m1.numar_de_inmatriculare, m2.numar_de_inmatriculare) == 0)
        return 1;
    return 0;
}

Masina CopyMasina(Masina m){
    Masina copie = constructor_masina(m.numar_de_inmatriculare, m.model, m.categorie);
    copie.status_inchiriere = m.status_inchiriere;
    return copie;
}

void Destroy_Masina(Masina m){
    free(m.numar_de_inmatriculare);
    free(m.categorie);
    free(m.model);
}