//
// Created by Irimieş Vasile on 6/18/2023.
//

#include "ServiceProduse.h"

void ServiceProduse::adauga_produs_service(int id, string nume, string tip, double pret) {
    Produs produs{id,nume,tip,pret};
    if(validator.valideaza(produs))
        repo.adauga_produs_repo(produs);
}

void ServiceProduse::sterge_produs_dupa_id_service(int id) {
    repo.sterge_produs_dupa_id_repo(id);
}

vector<Produs> ServiceProduse::get_all() const {
    return repo.get_all();
}

int ServiceProduse::len() const {
    return repo.len();
}

map<string, int> ServiceProduse::tipuri_si_nr_aparitii() const {
    map<string, int> m;
    for(const auto& produs : repo.get_all() ){
        m[produs.get_tip()]++;
    }
    return m;
}
