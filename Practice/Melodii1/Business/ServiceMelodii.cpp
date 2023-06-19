//
// Created by Irimieş Vasile on 6/13/2023.
//

#include <algorithm>
#include "ServiceMelodii.h"

void ServiceMelodii::adauga_melodie_service(int id, string titlu, string artist, int rank) {
    Melodie melodie{id, titlu, artist, rank};
    if ( validator.valideaza(melodie) ){
        repo.adauga_melodie_repo(melodie);
    }
}

void ServiceMelodii::modifica_melodie_service(int id, string titlu_nou, string artist, int rank_nou) {
    Melodie melodie{id, titlu_nou, artist, rank_nou};
    if( validator.valideaza(melodie) ){
        repo.modifica_melodie_repo(melodie);
    }
}

void ServiceMelodii::sterge_melodie_dupa_id_service(int id) {
    auto lista = repo.get_all();
    auto it = std::find_if(lista.begin(), lista.end(), [=](const Melodie& melodie){
        return melodie.get_id() == id;
    });
    if( it != lista.end()){
        auto l = filtru_dupa_artist(it->get_artist());
        if(l.size() == 1)
            throw ValidationError("Ultima melodie a artistului, nu se poate sterge!\n");
    }
    repo.sterge_melodie_dupa_id_repo(id);
}

vector<Melodie> ServiceMelodii::filtru_dupa_rank(int rank) const {
    vector <Melodie> lista;
    for ( const auto& melodie : repo.get_all() ){
        if ( melodie.get_rank() == rank )
            lista.push_back(melodie);
    }
    return lista;
}

vector<Melodie> ServiceMelodii::filtru_dupa_artist(string artist) const {
    vector <Melodie> lista;
    for(const auto& melodie : repo.get_all() ){
        if ( melodie.get_artist() == artist ){
            lista.push_back(melodie);
        }
    }
    return lista;
}

vector<Melodie> ServiceMelodii::get_all() const {
    return repo.get_all();
}

int ServiceMelodii::len() const {
    return repo.len();
}

void ServiceMelodii::sterge_util(int id) {
    repo.sterge_melodie_dupa_id_repo(id);
}


