//
// Created by Irimieş Vasile on 6/15/2023.
//

#ifndef MELODII_2_REPOMELODII_H
#define MELODII_2_REPOMELODII_H
#include <vector>
#include <string>
#include "../Domain/Melodie.h"

using std::vector;
using std::string;

class RepoMelodii {
private:
    vector<Melodie> lista_melodii;
    string numeFisier;

    void load_from_file();

    void store_to_file();

public:

    RepoMelodii(string numeFisier):numeFisier{numeFisier}{
        load_from_file();
    }

    int len()const;

    vector<Melodie> get_all_repo()const;

    void adauga_melodie_repo(const Melodie& melodie);

    void sterge_melodie_dupa_id_repo(int id);
};


#endif //MELODII_2_REPOMELODII_H
