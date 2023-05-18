//
// Created by Irimieş Vasile on 5/4/2023.
//

#ifndef LABORATORUL_6_7_BASEREPO_H
#define LABORATORUL_6_7_BASEREPO_H
#include "../Domain/Film.h"
#include <vector>
class BaseRepo {
public:
    virtual void adauga_film_repo(const Film& film) = 0;
    virtual Film modifica_film_repo(const Film& film_nou) = 0;
    virtual const Film& cauta_film_dupa_id_repo(int id) = 0;
    virtual Film sterge_film_dupa_id_repo(int id) = 0;
    virtual int len() const = 0;
    virtual const std::vector<Film>& get_all_repo() const = 0;
    virtual ~BaseRepo() = default;
};


#endif //LABORATORUL_6_7_BASEREPO_H
