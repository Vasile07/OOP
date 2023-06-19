//
// Created by Irimieş Vasile on 6/13/2023.
//

#ifndef MELODII_1_TEST_H
#define MELODII_1_TEST_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class Test {
public:
    void ruleaza_toate_testele();
private:
    int id = 20;
    string titlu = "Razboi si pace";
    string artist = "Ionuta Pop";
    int rank = 5;

    string titlu_nou = "Marea albastra";
    int rank_nou = 7;

    string fisier = "text.txt";

    void ruleaza_teste_domain();
    void ruleaza_teste_create();
    void ruleaza_teste_set();

    void ruleaza_teste_repo();
    void ruleaza_teste_adauga_repo();
    void ruleaza_teste_modifica_repo();
    void ruleaza_teste_sterge_repo();
    void ruleaza_teste_get_all_repo();

    void ruleaza_teste_validator();

    void ruleaza_teste_serivce();
    void ruleaza_teste_adauga_service();
    void ruleaza_teste_modifica_service();
    void ruleaza_teste_sterge_service();
    void ruleaza_teste_get_all_service();
    void ruleaza_teste_filtru_rank();
};


#endif //MELODII_1_TEST_H
