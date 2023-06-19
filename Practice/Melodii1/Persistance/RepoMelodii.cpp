//
// Created by Irimieş Vasile on 6/13/2023.
//

#include <algorithm>
#include <fstream>
#include "RepoMelodii.h"
#include "../Erori/Erori.h"
#include <cstring>
#include <iostream>

void RepoMelodii::load_from_file() {
    std::ifstream fin(fisier);
    char parametri[1000];
    while(fin.getline(parametri,1000)){
        char* p = strtok(parametri,",");
        int id = atoi(p);
        p = strtok(NULL,",");
        string titlu = p;
        p = strtok(NULL,",");
        string artist = p;
        p = strtok(NULL,",");
        int rank = atoi(p);

        Melodie melodie{id, titlu, artist, rank};

        lista.push_back(melodie);
    }
    fin.close();
}

void RepoMelodii::store_to_file() {
    std::ofstream fout(fisier);
    for ( const auto& melodie : lista ){
        fout << melodie.get_id() << "," << melodie.get_titlu() << "," << melodie.get_artist() << "," << melodie.get_rank() << "\n";
    }
    fout.close();
}

void RepoMelodii::adauga_melodie_repo(const Melodie &melodie) {
    auto it = std::find_if(lista.begin(), lista.end(), [=](const Melodie& mel){
        return mel.get_id() == melodie.get_id();
    });
    if ( it != lista.end() )
        throw RepoError("Melodie existenta!\n");
    lista.push_back(melodie);
    store_to_file();
}

void RepoMelodii::modifica_melodie_repo(const Melodie &melodie_noua) {
    auto it = std::find_if(lista.begin(), lista.end(), [=](const Melodie& melodie){
        return melodie.get_id() == melodie_noua.get_id();
    });
    if ( it == lista.end() )
        throw RepoError("Melodie inexistenta!\n");
    it->set_titlu(melodie_noua.get_titlu());
    it->set_rank(melodie_noua.get_rank());
    store_to_file();
}

void RepoMelodii::sterge_melodie_dupa_id_repo(int id) {
    auto it = std::find_if(lista.begin(), lista.end(), [=](const Melodie& melodie){
        return melodie.get_id() == id;
    });
    if ( it == lista.end() )
        throw RepoError("Melodie inexistenta!\n");
    lista.erase(it);
    store_to_file();
}

vector<Melodie> RepoMelodii::get_all() const {
    return lista;
}

int RepoMelodii::len() const {
    return (int)lista.size();
}
