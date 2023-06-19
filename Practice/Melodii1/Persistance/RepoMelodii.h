//
// Created by Irimieş Vasile on 6/13/2023.
//

#ifndef MELODII_1_REPOMELODII_H
#define MELODII_1_REPOMELODII_H
#include <string>
#include <vector>
#include "../Domain/Melodie.h"

using std::string;
using std::vector;


class RepoMelodii {
private:
    vector<Melodie> lista;
    string fisier;

    void load_from_file();
    void store_to_file();

public:
    RepoMelodii(string fisier):fisier{fisier}{
        load_from_file();
    }

    void adauga_melodie_repo(const Melodie& melodie);

    void modifica_melodie_repo(const Melodie& melodie_noua);

    void sterge_melodie_dupa_id_repo(int id);

    vector<Melodie> get_all()const;

    int len()const;

};


#endif //MELODII_1_REPOMELODII_H
