//
// Created by Irimieş Vasile on 6/15/2023.
//

#include "ServiceMelodii.h"

void ServiceMelodii::adauga_melodie_service(int id, string titlu, string artist, string gen) {
    Melodie melodie{id, titlu, artist, gen};
    if ( validator.valideaza(melodie))
        repo.adauga_melodie_repo(melodie);
}

void ServiceMelodii::sterge_melodie_dupa_id_service(int id) {
    repo.sterge_melodie_dupa_id_repo(id);
}

int ServiceMelodii::len() const {
    return repo.len();
}

vector<Melodie> ServiceMelodii::get_all() const {
    return repo.get_all_repo();
}

int ServiceMelodii::numar_melodii_gen_dat(string gen) {
    int cont=0;
    for (const auto &melodie: repo.get_all_repo()) {
        if(melodie.get_gen() == gen)
            cont++;
    }
    return cont;
}
