//
// Created by Irimieş Vasile on 4/23/2023.
//

#ifndef LABORATORUL_6_7_COSFILME_H
#define LABORATORUL_6_7_COSFILME_H
#include "../Domain/Film.h"
#include <vector>

using std::vector;

class CosFilme {
private:
    vector <Film> cos;
public:

    CosFilme() = default;

    /***
     * Adauga in film in cosul de cumparaturi
     * @param film - Film
     */
    void adauga_cos(const Film& film);

    /***
     * Goleste cosul de cumparaturi
     */
    void goleste_cos();

    /***
     * Populeaza cosul de cumparaturi cu un numar de filme generate random
     * @param numar_filme - int
     * @param all_films  vector<Film>
     */
    void genereaza_cos(int numar_filme,const vector<Film>& all_films);

    /***
     * Returneaza cosul de cumparaturi
     * @return vector<Film>
     */
    [[nodiscard]] const vector<Film>& get_all_cos() const;

    /***
     * Returneaza size-ul cosului de cumparturi
     * @return int
     */
    [[nodiscard]] int size() const;
};


#endif //LABORATORUL_6_7_COSFILME_H
