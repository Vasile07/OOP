//
// Created by Irimieş Vasile on 3/10/2023.
//
#include <malloc.h>
#include <string.h>
#include "repo_masini.h"

void redimensionare(ListaMasini *lista){
    Masina* lista_noua = (Masina*) malloc(2 * lista->capacitate * sizeof(Masina));
    for ( int i = 0 ; i < lista->dimensiune ; i ++ )
        lista_noua[i] = CopyMasina(lista->masini[i]);
    Destroy_Lista_Masini(*lista);
    lista->masini = lista_noua;
    lista->capacitate = 2 * lista->capacitate;
}

ListaMasini constructor_repo(){
    ListaMasini lista;
    lista.dimensiune = 0;
    lista.capacitate = 2;
    lista.masini = (Masina*)malloc(lista.capacitate * sizeof(Masina));
    return lista;
}

int adauga_masina_repo(ListaMasini *lista, Masina m){
    for ( int i = 0 ; i < lista->dimensiune ; i ++ )
        if (eq(lista->masini[i],m) == 1)
            return 1;
    if (lista->dimensiune == lista->capacitate)
        redimensionare(lista);
    lista->masini[lista->dimensiune] = CopyMasina(m); Destroy_Masina(m);
    lista->dimensiune++;
    return 0;
}

int modifica_masina_repo(ListaMasini lista, Masina m_nou){
    for ( int i = 0 ; i < lista.dimensiune ; i ++ )
        if (eq(lista.masini[i],m_nou)){
            set_model(&lista.masini[i], m_nou.model);
            set_categorie(&lista.masini[i], m_nou.categorie);
            set_status_inchiriere(&lista.masini[i], m_nou.status_inchiriere);
            Destroy_Masina(m_nou);
            return 0;
        }
    return 1;
}

int cauta_masina_dupa_nr_inmatriculare_repo(ListaMasini lista, char NumarInmatriculare[]){
    for ( int i = 0 ; i < lista.dimensiune ; i ++ )
        if(strcmp(lista.masini[i].numar_de_inmatriculare,NumarInmatriculare) == 0)
            return i;
    return -1;
}

int inchiriraza_repo(ListaMasini lista, char NumarInmatriculare[]){
    for ( int i = 0 ; i < lista.dimensiune ; i ++ )
        if(strcmp(lista.masini[i].numar_de_inmatriculare,NumarInmatriculare) == 0 && lista.masini[i].status_inchiriere == 0) {
            set_status_inchiriere(&lista.masini[i], 1);
            return 0;
        }
    return 1;
}

int returneaza_masina(ListaMasini lista, char NumarInmatriculare[]){
    for ( int i = 0 ; i < lista.dimensiune ; i ++ )
        if(strcmp(lista.masini[i].numar_de_inmatriculare,NumarInmatriculare) == 0 && lista.masini[i].status_inchiriere == 1) {
            set_status_inchiriere(&lista.masini[i], 0);
            return 0;
        }
    return 1;
}

int lungime_repo(ListaMasini lista){
    return lista.dimensiune;
}

ListaMasini get_all_disponibil_repo(ListaMasini lista){
    ListaMasini lista_noua = constructor_repo();
    for( int i = 0 ; i < lista.dimensiune ; i ++ )
        if ( lista.masini[i].status_inchiriere == 0)
            adauga_masina_repo(&lista_noua, CopyMasina(lista.masini[i]));
    return lista_noua;
}

void Destroy_Lista_Masini(ListaMasini lista){
    for(int i = 0 ; i < lista.dimensiune ; i++ )
        Destroy_Masina(lista.masini[i]);
    free(lista.masini);
}