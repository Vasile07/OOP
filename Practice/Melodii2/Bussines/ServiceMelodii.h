//
// Created by Irimieş Vasile on 6/15/2023.
//

#ifndef MELODII_2_SERVICEMELODII_H
#define MELODII_2_SERVICEMELODII_H


#include "../Persistance/RepoMelodii.h"
#include "../Validation/Validator.h"

class ServiceMelodii {
private:
    RepoMelodii repo;
    Validator validator;

public:
    ServiceMelodii(RepoMelodii repo, Validator validator):repo{repo},validator{validator}{}

    void adauga_melodie_service(int id, string titlu, string artist, string gen);

    void sterge_melodie_dupa_id_service(int id);

    int len()const;

    vector<Melodie> get_all()const;

    int numar_melodii_gen_dat(string gen);
};


#endif //MELODII_2_SERVICEMELODII_H
