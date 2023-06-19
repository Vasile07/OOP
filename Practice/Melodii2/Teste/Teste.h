//
// Created by Irimieş Vasile on 6/15/2023.
//

#ifndef MELODII_2_TESTE_H
#define MELODII_2_TESTE_H
#include "../Bussines/ServiceMelodii.h"

class Teste {
private:
    int id = 10;
    string titlu = "Magarusii";
    string artist = "Ionut Pop";
    string gen = "pop";
    string numeFisier = "test.txt";

    void ruleaza_teste_domain();
    void ruleaza_teste_create();

    void ruleaza_teste_validator();

    void ruleaza_teste_repo();
    void ruleaza_teste_adauga_repo();
    void ruleaza_teste_sterge_repo();

    void ruleaza_teste_service();
    void ruleaza_teste_adauga_service();
    void ruleaza_teste_sterge_service();

public:
    Teste(){}
    void ruleaza_toate_testele();
};


#endif //MELODII_2_TESTE_H
