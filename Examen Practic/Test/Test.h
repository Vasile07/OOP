//
// Created by Irimieş Vasile on 6/19/2023.
//

#ifndef IRIMIES_VASILE_EMILIAN_TEST_H
#define IRIMIES_VASILE_EMILIAN_TEST_H
#include "string"

using std::string;

class Test {
private:
    int numar_matricol = 10;
    string nume = "Ion Pop";
    int varsta = 10;
    string facultate = "mate";

    string nume_fisier = "test.txt";

    /// TESTE DOMAIN
    void ruleaza_test_domain();
    void ruleaza_teste_get();

    ///TESTE REPO
    void ruleaza_teste_repo();
    void ruleaza_teste_sterge_repo();
    void ruleaza_teste_modifica_repo();
    void ruleaza_teste_get_all_repo();

    ///TESTE SERVICE
    void ruleaza_teste_service();
    void ruleaza_teste_adauga_service();
    void ruleaza_teste_sterge_service();
    void ruleaza_teste_intinereste_service();
    void ruleaza_teste_imabtraneste_service();

public:
    Test(){}
    void ruleaza_toate_testele();

};


#endif //IRIMIES_VASILE_EMILIAN_TEST_H
