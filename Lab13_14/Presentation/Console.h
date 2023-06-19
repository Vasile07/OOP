//
// Created by Irimieş Vasile on 4/1/2023.
//

#ifndef LABORATORUL_6_7_CONSOLE_H
#define LABORATORUL_6_7_CONSOLE_H


#include <utility>

#include "../Bussines/ServiceFilme.h"

class Console {
    private:
        ServiceFilme lista_filme;
        /**
         * Afiseaza lista de comenzi
         */
        void help();
        /**
         * Decodifica lista de comenzi
         * @return
         */
        int decodificator(string comanda);

        void afiseaza_ui();///
        void adauga_ui();///
        void sterge_ui();///
        void modifica_ui();///
        void cauta_ui();///
        void filtrare_ui();///
        void sortare_ui();///
        void adauga_cos_ui();
        void afiseaza_cos_ui();
        void goleste_cos_ui();
        void genereaza_cos_ui();
        void export_cos_ui();
        void undo_ui();///
        void see_map();

    public:
        Console(ServiceFilme lista): lista_filme{std::move(lista)}{}
        int ruleaza_ui();


};


#endif //LABORATORUL_6_7_CONSOLE_H
