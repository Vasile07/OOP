//
// Created by Irimieş Vasile on 6/15/2023.
//

#include "RepoMelodii.h"
#include "../Erors/Erori.h"
#include <fstream>
#include <cstring>
#include <algorithm>

void RepoMelodii::load_from_file() {
    std::ifstream fin(numeFisier);
    char line[1000];
    while(fin.getline(line, 1000)){
        char* param = strtok(line,",");
        int id = atoi(param);
        param = strtok(NULL, ",");
        string titlu = param;
        param = strtok(NULL, ",");
        string artist = param;
        param = strtok(NULL, ",");
        string gen = param;

        Melodie melodie{id, titlu,artist, gen};
        lista_melodii.push_back(melodie);
    }
    fin.close();

}

void RepoMelodii::store_to_file() {
    std::ofstream fout(numeFisier);
    for (const auto& melodie : lista_melodii ){
        fout << melodie.get_id() << "," << melodie.get_titlu() << "," << melodie.get_artist() << "," << melodie.get_gen() << "\n";
    }
    fout.close();
}

int RepoMelodii::len() const {
    return lista_melodii.size();
}

vector<Melodie> RepoMelodii::get_all_repo() const {
    return lista_melodii;
}

void RepoMelodii::adauga_melodie_repo(const Melodie &melodie) {
    auto it = std::find_if(lista_melodii.begin(), lista_melodii.end(), [&](const Melodie& mel){
        return mel.get_id() == melodie.get_id();
    });
    if(it != lista_melodii.end())
        throw RepoError("Melodie existenta!\n");
    lista_melodii.push_back(melodie);
    store_to_file();
}

void RepoMelodii::sterge_melodie_dupa_id_repo(int id) {
    auto it = std::find_if(lista_melodii.begin(), lista_melodii.end(), [&](const Melodie& mel){
        return mel.get_id() == id;
    });
    if ( it  == lista_melodii.end() )
        throw RepoError("Melodie inexistenta!\n");
    lista_melodii.erase(it);
    store_to_file();
}
