//
// Created by Irimieş Vasile on 6/18/2023.
//

#include "RepoProduse.h"
#include "../Erori/Erori.h"
#include <algorithm>
#include <fstream>
#include <cstring>
using std::sort;
using std::find_if;

void RepoProduse::load_from_file() {
    char line[1000];
    std::ifstream fin(nume_fisier);
    while(fin.getline(line,1000)){
        char* param = strtok(line,",");
        int id = atoi(param);
        param = strtok(NULL,",");
        string nume = param;
        param = strtok(NULL,",");
        string tip = param;
        param = strtok(NULL,",");
        double pret = atof(param);
        Produs produs{id, nume,tip, pret};
        lista_produse.push_back(produs);
    }
    fin.close();
}

void RepoProduse::store_to_file() {
    sort(lista_produse.begin(),lista_produse.end(),[](const Produs& p1, const Produs& p2){
       return p1.get_pret() < p2.get_pret();
    });
    std::ofstream fout(nume_fisier);
    for(const auto& produs : lista_produse ){
        fout << produs.get_id() << "," << produs.get_nume() << "," << produs.get_tip() << "," << produs.get_pret() << "\n";
    }
    fout.close();
}

void RepoProduse::adauga_produs_repo(const Produs &produs) {
    auto it = find_if(lista_produse.begin(),lista_produse.end(),[&](const Produs& p){
        return p.get_id() == produs.get_id();
    });
    if(it != lista_produse.end())
        throw RepoError("Produs existent!\n");
    lista_produse.push_back(produs);
    store_to_file();
}

void RepoProduse::sterge_produs_dupa_id_repo(int id) {
    auto it = find_if(lista_produse.begin(),lista_produse.end(),[&](const Produs& p){
        return p.get_id() == id;
    });
    if(it == lista_produse.end())
        throw RepoError("Produs inexistent!\n");
    lista_produse.erase(it);
    store_to_file();
}

vector<Produs> RepoProduse::get_all() const {
    return lista_produse;
}

int RepoProduse::len() const {
    return (int)lista_produse.size();
}
