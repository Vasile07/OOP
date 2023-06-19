//
// Created by Irimieş Vasile on 6/18/2023.
//

#ifndef PRODUSE_BUN_TEST_H
#define PRODUSE_BUN_TEST_H
#include "../Domain/Produs.h"
#include "../Validator/Validator.h"

class Test {
private:
    int id = 10;
    string nume = "Banane";
    string tip = "Fruct";
    double pret = 10.29;

    string nume_fisier = "test.txt";
///                                                    *** TESTE DOMAIN ***
    void ruleaza_teste_domain();
    void ruleaza_teste_get();
///                                                    ***--------------***

///                                                   *** TESTE VALIDATOR ***
    void ruleaza_teste_validator();
///                                                   ***-----------------***

///                                                     *** TESTE REPO ***
    void ruleaza_teste_repo();
    void ruleaza_teste_adauga_repo();
    void ruleaza_teste_sterge_repo();
    void ruleaza_teste_get_all_repo();
///                                                     ***------------***

///                                                    *** TESTE SERVICE ***
    void ruleaza_teste_service();
    void ruleaza_teste_adauga_service();
    void ruleaza_teste_sterge_service();
    void ruleaza_teste_get_all_service();
    void ruleaza_teste_map_service();
///                                                    ***---------------***


public:
    void ruleaza_toate_testele();
};


#endif //PRODUSE_BUN_TEST_H
