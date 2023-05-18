//
// Created by Irimieş Vasile on 3/10/2023.
//
#include <string.h>
#include "service_masini.h"
#include "../Validation/validator.h"

ListaMasini constructor_service(){
    ListaMasini lista = constructor_repo();
    return lista;
}

int adauga_masina_service(ListaMasini* lista, char* NumarInmatriculare, char* Model, char* Categorie){
    Masina m = constructor_masina(NumarInmatriculare, Model, Categorie);
    if(valideaza(m) == -2) {
        Destroy_Masina(m);
        return -2;
    }
    int return_value = adauga_masina_repo(lista, m);
    if (return_value == 1)
        Destroy_Masina(m);
    return return_value;
}

int modifica_masina_service(ListaMasini lista, char* NumarInmatriculare, char* Model_nou, char* Categorie_noua){
    Masina m_nou = constructor_masina(NumarInmatriculare, Model_nou, Categorie_noua);
    if(valideaza(m_nou) == -2) {
        Destroy_Masina(m_nou);
        return -2;
    }
    int return_value = modifica_masina_repo(lista, m_nou);
    if(return_value == 1)
        Destroy_Masina(m_nou);
    return return_value;
}

int inchiriaza_masina_service(ListaMasini lista, char* NumarInmatriculare){
    int return_value = inchiriraza_repo(lista, NumarInmatriculare);
    return return_value;
}

int returneaza_masina_service(ListaMasini lista, char* NumarInmatriculare){
    int return_value = returneaza_masina(lista, NumarInmatriculare);
    return return_value;
}

int lungime_service(ListaMasini lista){
    return lungime_repo(lista);
}

ListaMasini filtrare_masini_dupa_categorie(ListaMasini lista, char* Categorie){
    ListaMasini lista_filtrata = constructor_repo();
    for ( int i = 0 ; i < lungime_repo(lista) ; i ++ )
        if ( strcmp(lista.masini[i].categorie, Categorie) == 0 )
            adauga_masina_repo(&lista_filtrata, CopyMasina(lista.masini[i]));
    return lista_filtrata;
}

ListaMasini filtreaza_masini_dupa_model(ListaMasini lista, char* Model){
    ListaMasini lista_filtrata = constructor_repo();
    for ( int i = 0 ; i < lungime_repo(lista) ; i ++ )
        if ( strcmp(lista.masini[i].model, Model) == 0 )
            adauga_masina_repo(&lista_filtrata, CopyMasina(lista.masini[i]));
    return lista_filtrata;
}

ListaMasini filtrare(ListaMasini lista, char* criteriu, char* item){
    //ListaMasini lista_filtrata= constructor_repo();
    if ( strcmp(criteriu, "-c") == 0 )
        return filtrare_masini_dupa_categorie(lista, item);
    if ( strcmp(criteriu, "-m") == 0 )
        return filtreaza_masini_dupa_model(lista, item);
    return constructor_repo();
}

void sortare_dupa_model(ListaMasini *lista, char* orientare){
    for( int i = 0 ; i < lungime_repo(*lista) - 1 ; i ++ )
        for ( int j = i + 1 ; j < lungime_repo(*lista) ; j ++ )
            if ( (strcmp(lista->masini[i].model, lista->masini[j].model) > 0 ) ^ (strcmp(orientare, "-r") == 0) )
            {
                Masina m = lista->masini[i];
                lista->masini[i] = lista->masini[j];
                lista->masini[j] = m;
            }
}

void sortare_dupa_categorie(ListaMasini *lista, char* orientare){
    for( int i = 0 ; i < lungime_repo(*lista) -1 ; i ++ )
        for ( int j = i + 1 ; j < lungime_repo(*lista) ; j ++ )
            if ( (strcmp(lista->masini[i].categorie, lista->masini[j].categorie) > 0 ) ^ (strcmp(orientare, "-r") == 0) )
            {
                Masina m = lista->masini[i];
                lista->masini[i] = lista->masini[j];
                lista->masini[j] = m;
            }
}

void sortare(ListaMasini *lista, char* criteriu, char* orientare){
    if(strcmp(criteriu, "-m") == 0)
        sortare_dupa_model(lista, orientare);
    if(strcmp(criteriu, "-c") == 0)
        sortare_dupa_categorie(lista, orientare);
}

void Destroy_Lista_Masini_service(ListaMasini lista){
    Destroy_Lista_Masini(lista);
}