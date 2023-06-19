//
// Created by Irimieş Vasile on 3/30/2023.
//

#ifndef LABORATORUL_6_7_TESTE_H
#define LABORATORUL_6_7_TESTE_H
#include <string>
using std::string;

class Teste {
    public:
        void ruleaza_toate_testele();
    private:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        int id = 1;
        int an_aparitie = 1978;
        string titlu = "Razboi si pace", gen = "Actiune", actor_principal = "Ionut Pop";

        int an_aparitie_nou = 2007;
        string titlu_nou = "Rapid si furios", gen_nou = "Drama", actor_principal_nou = "Sofer Jhon";

        int id_invalid = -1, an_aparitie_invalid = -812 ;
        string titlu_invalid, gen_invalid, actor_principal_invalid;

    /////////////////////////////////////////////    DOMAIN    /////////////////////////////////////////////////////////
        void ruleaza_teste_domain();
        void ruleaza_teste_creare();
        void ruleaza_teste_set();
        void ruleaza_teste_eq();

    ////////////////////////////////////////////     REPO      /////////////////////////////////////////////////////////
        void ruleaza_teste_repo();
        void ruleaza_teste_adauga_repo();
        void ruleaza_teste_modifica_repo();
        void ruleaza_teste_cauta_repo();
        void ruleaza_teste_get_all_repo();
        void ruleaza_teste_sterge_repo();

    ///////////////////////////////////////////      VALIDATOR       ///////////////////////////////////////////////////
        void ruleaza_teste_validator();

    ///////////////////////////////////////////      SERVICE         ///////////////////////////////////////////////////
        void ruleaza_teste_service();
        void ruleaza_teste_adauga_service();
        void ruleaza_teste_modifica_service();
        void ruleaza_teste_cauta_service();
        void ruleaza_teste_get_all_service();
        void ruleaza_teste_sterge_service();
        void ruleaza_teste_filtru();
        void ruleaza_teste_sort();
        void ruleaza_teste_comparator();
        void ruleaza_teste_adauga_cos_service();
        void ruleaza_teste_goleste_cos_service();
        void ruleaza_teste_genereaza_cos_service();
        void ruleaza_teste_get_cos_service();
        void ruleaza_teste_export_cos_sevice();
        void ruleaza_teste_undo_service();

    /////////////////////////////////////////////      COS         /////////////////////////////////////////////////////
        void ruleaza_teste_cos();
        void ruleaza_test_adauga_cos();
        void ruleaza_test_goleste_cos();
        void ruleaza_generaza_cos();
        void ruleaza_get_all_cos();

    //////////////////////////////////////////     FILEREPO      ///////////////////////////////////////////////////////
        void ruleaza_teste_file_repo();
        void ruleaza_teste_load_from_file_file_repo();
        void ruleaza_teste_adauga_file_repo();
        void ruleaza_teste_sterge_file_repo();
        void ruleaza_teste_modifica_file_repo();

    ////////////////////////////////////////////     UNDO      /////////////////////////////////////////////////////////
        void ruleaza_teste_undo();
        void ruleaza_teste_adauga_undo();
        void ruleaza_teste_sterge_undo();
        void ruleaza_teste_modifica_undo();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


};


#endif //LABORATORUL_6_7_TESTE_H
