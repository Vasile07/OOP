//
// Created by Irimieş Vasile on 6/13/2023.
//

#ifndef MELODII_1_SERVICEMELODII_H
#define MELODII_1_SERVICEMELODII_H
#include <vector>
#include <string>
#include "../Persistance/RepoMelodii.h"
#include "../Validator/Validator.h"
#include "../Domain/Melodie.h"

using std::vector;
using std::string;

class ServiceMelodii {
private:
    RepoMelodii& repo;
    Validator& validator;
public:
    ServiceMelodii(RepoMelodii& repo, Validator& validator):repo{repo},validator{validator}{}

    void adauga_melodie_service(int id, string titlu, string artist, int rank);

    void modifica_melodie_service(int id, string titlu_nou, string artist, int rank_nou);

    void sterge_melodie_dupa_id_service(int id);

    void sterge_util(int id);

    vector<Melodie> filtru_dupa_rank(int rank)const;

    vector<Melodie> filtru_dupa_artist(string artist)const;

    vector<Melodie> get_all()const;

    int len()const;
};


#endif //MELODII_1_SERVICEMELODII_H
