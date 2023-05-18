//
// Created by Irimieş Vasile on 3/31/2023.
//

#ifndef LABORATORUL_6_7_SERVICEFILME_H
#define LABORATORUL_6_7_SERVICEFILME_H


#include <memory>
#include "../Repository/RepoFilme.h"
#include "../Validator/Validator.h"
#include "../Cos_Inchiriere/CosFilme.h"
#include "../Undo/ActiuneUndo.h"
#include <map>
using std::map;

class ServiceFilme {
    private:
        BaseRepo& lista;
        Validator validator;
        CosFilme cos;
        vector<ActiuneUndo*> undo_list;

    public:
        /**
         * Constructor service
         * @param repo RepoFilme
         * @param validator Validator
         */
        ServiceFilme(BaseRepo& repo, Validator validator): lista{repo}, validator{validator}{}

        /**
         * Adauga un film in lista
         * @param id - int
         * @param titlu - string
         * @param gen - string
         * @param an_aparitie - int
         * @param actor_principal - string
         * @throw RepoError_ValidationError
         */
        void adauga_film_service(int id, string titlu, string gen, int an_aparitie, string actor_principal);

        /**
         * Modifica un film cu id egal cu id dat
         * @param id - int
         * @param titlu_nou- string
         * @param gen_nou - string
         * @param an_aparitie_nou - int
         * @param actor_principal_nou - string
         */
        void modifica_film_service(int id, string titlu_nou, string gen_nou, int an_aparitie_nou, string actor_principal_nou);

        /***
         * Sterge cartea cu id-ul dat
         * @param id - int
         */
        void sterge_dupa_id_service(int id);

        /***
         * Returneaza cartea cu id-ul dat
         * @param id - int
         * @return Carte
         */
        const Film& cauta_film_dupa_id_service(int id);

        /**
         * Returneaza lista de carti
         * @return vector
         */
//        const MyVector<Film>& get_all_service() const;
        const vector<Film>& get_all_service() const;

        /**
         * Returneaza lungimea listei
         * @return int
         */
        int len() const;

        /**
         * Returneaza filmele care au titlul la fel cu cel dat
         * @param titlu - string
         * @return vector
         */
        vector<Film> filtrare_dupa_titlu(const string& titlu) const;

        /**
         * Returneaza filmele care au aparut in data data
         * @param an_aparitie - int
         * @return vector
         */
        vector<Film> filtrare_dupa_an(int an_aparitie) const;

        /**
         * Sorteaza lista de filme
         * @param criteriu - string
         */
        void sortare(const string& criteriu);

        /**
         * Compara doua filme dupa un criteriu
         * @param film1 - Film
         * @param film2 - Film
         * @param criteriu - string
         * @return  True : film1 < film2
         *          False : film1 >= film2
         */
        bool comparator(const Film& film1, const Film& film2, const string& criteriu);

        /***
         * Adauga filmele cu titlul dat in cosul de cumparaturi
         * @param titlu - string
         */
        void adauga_cos_service(const string& titlu);

        /***
         * Goleste cosul de cumparaturi
         */
        void goleste_cos_service();

        /***
         * Populeaza cosul de cumparaturi cu numarul de filme date
         * @param numar_filme - Film
         */
        void genereaza_cos_service(int numar_filme);

        /***
         * Returneaza constinutul cosului de cumparaturi
         * @return vector<Film>
         */
        [[nodiscard]] const vector<Film>& get_cos() const;

        /***
         * Returneaza dimensiunea cosului
         * @return int
         */
        int size_cos() const;

        /***
         * Exporta constinutul cosului de cumparaturi in fisierul dat
         * @param fisier - string
         */
        void export_cos_service(const string& fisier);

        void undo();

        map<string,vector<Film>> get_all_filme_dupa_actor();

        ~ServiceFilme(){
            for (auto u : undo_list)
                delete u;
        }
};


#endif //LABORATORUL_6_7_SERVICEFILME_H
