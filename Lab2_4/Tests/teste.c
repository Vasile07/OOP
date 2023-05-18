//
// Created by Irimieş Vasile on 3/10/2023.
//
#include <assert.h>
#include <string.h>
#include "teste.h"
//#include "..\Domain\masina.h"
#include "../Service//service_masini.h"
#include "../Validation/validator.h"
void ruleaza_toate_testele(){
    ruleaza_teste_domain();
    ruleaza_teste_repository();
    ruleaza_teste_validator();
    ruleaza_teste_service();
}

void ruleaza_teste_domain(){
    ruleaza_teste_create();
    ruleaza_teste_set();
    ruleaza_teste_eq();
}

void ruleaza_teste_create(){
    Masina m = constructor_masina("CJ.22.MAS", "4x4", "Road");
    assert(strcmp(m.numar_de_inmatriculare,"CJ.22.MAS") == 0);
    assert(strcmp(m.model,"4x4") == 0);
    assert(strcmp(m.categorie, "Road") == 0);
    assert(m.status_inchiriere == 0);
    Destroy_Masina(m);
}

void ruleaza_teste_set(){
    Masina m = constructor_masina("CJ.22.MAS", "4x4", "Road");
    set_numar_inmatriculare(&m, "BN.18.SAM");
    set_model(&m,"2x2");
    set_categorie(&m,"Tractor");
    set_status_inchiriere(&m, 1);
    assert(strcmp(m.numar_de_inmatriculare,"BN.18.SAM") == 0);
    assert(strcmp(m.model,"2x2") == 0);
    assert(strcmp(m.categorie, "Tractor") == 0);
    assert(m.status_inchiriere == 1);
    Destroy_Masina(m);
}

void ruleaza_teste_eq(){
    Masina m1, m2, m3;
    m1 = constructor_masina("CJ.18.MAS", "4x4", "Road");
    m2 = constructor_masina("CJ.18.MAS", "2x2", "Tractor");
    m3 = constructor_masina("BN.27.SAM", "4x4", "Road");
    assert(eq(m1, m2) == 1);
    assert(eq(m1, m3) == 0);
    Destroy_Masina(m1);Destroy_Masina(m2);Destroy_Masina(m3);
}

void ruleaza_teste_repository(){
    ruleaza_teste_redimensionare();
    ruleaza_teste_adauga_repo();
    ruleaza_teste_modifica_repo();
    ruleaza_teste_cauta_repo();
    ruleaza_teste_inchiriere_si_retur_repo();
    ruleaza_teste_get_neinchiriate();
}

void ruleaza_teste_redimensionare(){
    ListaMasini lista = constructor_repo();
    assert(lista.capacitate == 2);
    assert(lista.dimensiune == 0);
    redimensionare(&lista);
    assert(lista.capacitate == 4);
    assert(lista.dimensiune == 0);
    redimensionare(&lista);
    assert(lista.capacitate == 8);
    assert(lista.dimensiune == 0);
    Destroy_Lista_Masini(lista);
}

void ruleaza_teste_adauga_repo(){
    ListaMasini lista = constructor_repo();
    Masina m = constructor_masina("CJ.18.MAS", "4x4", "Road");
    Masina m_cop = CopyMasina(m);
    Masina m1 = constructor_masina("CJ.18.SAM", "7x7", "Tractor");
    Masina m2 = constructor_masina("CJ.18.OOO", "5x5", "Ana");
    assert(lungime_repo(lista) == 0);
    assert(adauga_masina_repo(&lista, m) == 0);
    assert(lungime_repo(lista) == 1);
    assert(eq(lista.masini[0], m_cop));
    assert(adauga_masina_repo(&lista, m_cop) == 1);
    assert(lungime_repo(lista) == 1);
    adauga_masina_repo(&lista, m1);
    adauga_masina_repo(&lista, m2);
    assert(lungime_repo(lista) == 3);
    Destroy_Lista_Masini(lista);
    Destroy_Masina(m_cop);
}

void ruleaza_teste_modifica_repo(){
    ListaMasini lista = constructor_repo();
    Masina m = constructor_masina("CJ.18.MAS", "4x4", "Road");
    Masina m_nou = constructor_masina("CJ.18.MAS", "2x2", "Tractor");
    adauga_masina_repo(&lista, m);
    modifica_masina_repo(lista, m_nou);
    assert(strcmp(lista.masini[0].categorie, "Tractor") == 0);
    assert(strcmp(lista.masini[0].model, "2x2") == 0);
    assert(strcmp(lista.masini[0].numar_de_inmatriculare, "CJ.18.MAS") == 0);
    m = constructor_masina("BN.12.SAM", "ada", "ada");
    assert(modifica_masina_repo(lista, m) == 1 );
    Destroy_Lista_Masini(lista);
    Destroy_Masina(m);
}

void ruleaza_teste_cauta_repo(){
    ListaMasini lista = constructor_repo();
    Masina m1 = constructor_masina("CJ.18.MAS", "4x4", "Road");
    Masina m2= constructor_masina("BN.18.SAM", "2x2", "Tractor");
    adauga_masina_repo(&lista, m1);
    adauga_masina_repo(&lista, m2);
    assert(cauta_masina_dupa_nr_inmatriculare_repo(lista, "BN.18.SAM") == 1);
    assert(cauta_masina_dupa_nr_inmatriculare_repo(lista, "CJ.18.MAS") == 0);
    assert(cauta_masina_dupa_nr_inmatriculare_repo(lista, "CJ.17.MAT") == -1);
    Destroy_Lista_Masini(lista);
}

void ruleaza_teste_inchiriere_si_retur_repo(){
    ListaMasini lista = constructor_repo();
    Masina m1 = constructor_masina("CJ.18.MAS", "4x4", "Road");
    adauga_masina_repo(&lista, m1);
    assert(inchiriraza_repo(lista, "CJ.18.MAS") == 0);
    int poz = cauta_masina_dupa_nr_inmatriculare_repo(lista, "CJ.18.MAS");
    assert(lista.masini[poz].status_inchiriere == 1);
    assert(inchiriraza_repo(lista, "CJ.18.MAS") == 1);
    assert(inchiriraza_repo(lista, "CJ.19.SAM") == 1);
    assert(returneaza_masina(lista, "CJ.18.MAS") == 0);
    assert(lista.masini[poz].status_inchiriere == 0);
    assert(returneaza_masina(lista, "CJ.18.MAS") == 1);
    assert(returneaza_masina(lista, "CJ.19.SAM") == 1);
    Destroy_Lista_Masini(lista);
}

void ruleaza_teste_get_neinchiriate(){
    ListaMasini lista = constructor_repo();
    Masina m1 = constructor_masina("CJ.18.MAS", "4x4", "Road");
    Masina m2= constructor_masina("BN.18.SAM", "2x2", "Tractor");
    adauga_masina_repo(&lista, m1);
    adauga_masina_repo(&lista, m2);
    inchiriraza_repo(lista, "BN.18.SAM");
    ListaMasini lista_neinchiriat = get_all_disponibil_repo(lista);
    assert(lungime_repo(lista_neinchiriat) == 1);
    m1 = constructor_masina("CJ.18.MAS", "4x4", "Road");
    assert(eq(lista_neinchiriat.masini[0], m1) == 1);
    Destroy_Masina(m1);
    Destroy_Lista_Masini(lista);
    Destroy_Lista_Masini(lista_neinchiriat);
}

void ruleaza_teste_service(){
    ruleaza_teste_adauga_service();
    ruleaza_teste_modifica_service();
    ruleaza_teste_cauta_service();
    ruleaza_teste_inchiriare_retur_service();
    ruleaza_teste_filtre();
    ruleaza_teste_sortare();
}

void ruleaza_teste_adauga_service(){
    ListaMasini lista = constructor_service();
    assert(lungime_service(lista) == 0);
    assert(adauga_masina_service(&lista,"CJ.18.MAS", "4x4", "Road" ) == 0);
    assert(lungime_service(lista) == 1);
    assert(adauga_masina_service(&lista,"CJ.18.MAS", "4x4", "Road" ) == 1);
    assert(adauga_masina_service(&lista, "123.Ana.JDJA","2x2", "Road") == -2);
    assert(adauga_masina_service(&lista, "BN.12.MMM","", "Road") == -2);
    assert(adauga_masina_service(&lista, "BN.12.MMM","2x2", "") == -2);
    Destroy_Lista_Masini_service(lista);
}
void ruleaza_teste_modifica_service(){
    ListaMasini lista = constructor_service();
    adauga_masina_service(&lista,"CJ.18.MAS", "4x4", "Road" );
    assert( modifica_masina_service(lista, "CJ.18.MAS", "2x2", "Tractor") == 0) ;
    assert( modifica_masina_service(lista, "BN.18.SAM", "2x2", "Tractor") == 1);
    assert( modifica_masina_service(lista, "12,18.SAM", "2x2", "Tractor") == -2);
    assert( modifica_masina_service(lista, "CJ.18.MAS", "", "Tractor") == -2);
    assert( modifica_masina_service(lista, "CJ.18.MAS", "2x2", "") == -2);
    assert(strcmp(lista.masini[0].model, "2x2") == 0);
    assert(strcmp(lista.masini[0].categorie, "Tractor") == 0);
    Destroy_Lista_Masini_service(lista);
}
void ruleaza_teste_cauta_service(){
    ListaMasini lista = constructor_service();
    Masina m1 = constructor_masina("CJ.18.MAS", "4x4", "Road");
    adauga_masina_service(&lista,"CJ.18.MAS", "4x4", "Road" );
    int p = cauta_masina_dupa_nr_inmatriculare_repo(lista, "CJ.18.MAS");
    assert(eq(lista.masini[p], m1) == 1);
    assert(cauta_masina_dupa_nr_inmatriculare_repo(lista, "CJ.99.MAS") == -1);
    Destroy_Lista_Masini_service(lista);
    Destroy_Masina(m1);
}

void ruleaza_teste_inchiriare_retur_service(){
    ListaMasini lista = constructor_service();
    adauga_masina_service(&lista, "CJ.18.MAS", "4x4", "Road");
    assert(inchiriaza_masina_service(lista, "CJ.18.MAS") == 0);
    assert(lista.masini[0].status_inchiriere == 1);
    assert(inchiriaza_masina_service(lista, "CJ.18.MAS") == 1);
    assert(inchiriaza_masina_service(lista, "CJ.19.SAM") == 1);
    assert(returneaza_masina_service(lista, "CJ.18.MAS") == 0);
    assert(lista.masini[0].status_inchiriere == 0);
    assert(returneaza_masina_service(lista, "CJ.18.MAS") == 1);
    assert(returneaza_masina_service(lista, "CJ.19.SAM") == 1);
    Destroy_Lista_Masini_service(lista);
}

void ruleaza_teste_filtre(){
    ListaMasini lista = constructor_service();
    adauga_masina_service(&lista, "CJ.18.ABC", "1x1", "Tractor");
    adauga_masina_service(&lista, "CJ.18.DEF", "2x2", "Road");
    adauga_masina_service(&lista, "CJ.18.HIJ", "2x2", "Tractor");
    ListaMasini lista_filtrata;
    lista_filtrata = filtrare(lista,"-m", "2x2");
    assert(lungime_service(lista_filtrata) == 2);
    Destroy_Lista_Masini_service(lista_filtrata);

    lista_filtrata = filtrare(lista, "-c", "Tractor");
    assert(lungime_service(lista_filtrata) == 2);
    Destroy_Lista_Masini_service(lista_filtrata);
    lista_filtrata = filtrare(lista, " ", "");
    assert(lungime_service(lista_filtrata) == 0);
    Destroy_Lista_Masini_service(lista);
    Destroy_Lista_Masini_service(lista_filtrata);

}

void ruleaza_teste_sortare(){
    ListaMasini lista = constructor_service();
    Masina m1,m2,m3;
    m1 = constructor_masina("CJ.18.ABC", "1x1", "Tractor");
    m2 = constructor_masina("CJ.18.DEF", "2x2", "Road");
    m3 = constructor_masina("CJ.18.HIJ", "2x2", "Masina");
    adauga_masina_service(&lista, "CJ.18.ABC", "1x1", "Tractor");
    adauga_masina_service(&lista, "CJ.18.DEF", "2x2", "Road");
    adauga_masina_service(&lista, "CJ.18.HIJ", "2x2", "Masina");
    sortare(&lista, "-c", "");
    assert(eq(m3,lista.masini[0] ) == 1 && eq(m2,lista.masini[1] ) == 1 && eq(m1,lista.masini[2] ) == 1 );
    sortare(&lista, "-c", "-r");
    assert(eq(m3,lista.masini[2] ) == 1 && eq(m2,lista.masini[1] ) == 1 && eq(m1,lista.masini[0] ) == 1 );
    sortare(&lista, "-m", "");
    assert(eq(m1,lista.masini[0] ) == 1 && eq(m2,lista.masini[1] ) == 1 && eq(m3,lista.masini[2] ) == 1 );
    sortare(&lista, "-m", "-r");
    assert(eq(m1,lista.masini[2] ) == 1 && eq(m2,lista.masini[1] ) == 1 && eq(m3,lista.masini[0] ) == 1 );
    Destroy_Lista_Masini_service(lista);
    Destroy_Masina(m1);
    Destroy_Masina(m2);
    Destroy_Masina(m3);
}

void ruleaza_teste_validator(){
    Masina m1 = constructor_masina("CJ.18.MAS", "4x4", "Road");
    Masina m2= constructor_masina("12.Ana.1fa", "2x2", "Tractor");
    Masina m3= constructor_masina("BN.12.ANA", "", "Tractor");
    Masina m4= constructor_masina("BN.12.ANA", "2x2", "");
    assert(valideaza(m1) == 0);
    assert(valideaza(m2) == -2);
    assert(valideaza(m3) == -2);
    assert(valideaza(m4) == -2);
    Destroy_Masina(m1);
    Destroy_Masina(m2);
    Destroy_Masina(m3);
    Destroy_Masina(m4);
}
