//
// Created by Irimieş Vasile on 4/23/2023.
//

#ifndef LABORATORUL_6_7_FILEREPOFILME_H
#define LABORATORUL_6_7_FILEREPOFILME_H
#include "RepoFilme.h"

#include <utility>

class FileRepoFilme: public RepoFilme {
private:
    string file;

    /**
     * Stocheaza in file datele din lista
     */
    void store_to_file();

    /**
     * Incarca datele din file
     */
    void load_from_file();

public:
    explicit FileRepoFilme(const string& file): RepoFilme(), file{std::move(file)}{
        load_from_file();
    }

    void adauga_film_repo(const Film& film) override;

    Film sterge_film_dupa_id_repo(int id) override;

    Film modifica_film_repo(const Film& film_nou) override;

    ~FileRepoFilme() override = default;
};


#endif //LABORATORUL_6_7_FILEREPOFILME_H
