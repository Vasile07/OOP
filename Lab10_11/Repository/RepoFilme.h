//
// Created by Irimieş Vasile on 3/30/2023.
//

#ifndef LABORATORUL_6_7_REPOFILME_H
#define LABORATORUL_6_7_REPOFILME_H
#include <vector>
#include "../Domain/Film.h"
#include "../Utilitar/MyVector.h"
#include "BaseRepo.h"

using std::vector;

class RepoFilme: public BaseRepo {
    private:
//        MyVector <Film> repo_filme;
        vector <Film> repo_filme;

    public:
        /***
         * Contructorul listei de filme din repo
         */
        RepoFilme() = default;

        RepoFilme(const RepoFilme& ot) = delete;

        /***
         * Adauga un film in lista de filme
         * @param film - Film
         * @throw RepoException - "Film existent!" - Daca id-ul filmului existenta in lista
         */
        virtual void adauga_film_repo(const Film& film) override;

        /***
         * Modifica un film din lista de filme
         * @param film_nou - Film
         * @throw RepoException - "Film inexistent!" - Daca id-ul filmului nu existenta in lista
         */
        virtual Film modifica_film_repo(const Film& film_nou) override;

        /***
         * Returneaza filmul cu id-ul dat din lista
         * @param id - int
         * @throw RepoException - "Film inexistent!" - Daca id-ul filmului nu existenta in lista
         */
        const Film& cauta_film_dupa_id_repo(int id) override;

        /***
         * Sterge filmul cu id-ul dat din lista de filme
         * @param id - int
         * @throw RepoException - "Film inexistent!" - Daca id-ul filmului nu existenta in lista
         */
         virtual Film sterge_film_dupa_id_repo(int id) override;

        /***
         * Returneaza numarul de filme din lista
         * @return NrFilme - int
         */
        [[nodiscard]] int len()const override;

//        [[nodiscard]] const MyVector <Film>& get_all_repo() const;
        [[nodiscard]] const vector <Film>& get_all_repo() const override;

        virtual ~RepoFilme() = default;
};


#endif //LABORATORUL_6_7_REPOFILME_H
