//
// Created by Irimieş Vasile on 3/31/2023.
//

#include "ServiceFilme.h"
#include "../Errors/Erori.h"

#include <utility>
#include <algorithm>
#include <fstream>
#include <memory>

using std::swap;
using std::copy_if;


void ServiceFilme::adauga_film_service(int id, string titlu, string gen, int an_aparitie, string actor_principal) {
    Film film{id, titlu, gen, an_aparitie, actor_principal};
    if(validator.valideaza(film)) {
        lista.adauga_film_repo(film);
        undo_list.push_back(new UndoAdauga(lista, film));
    }
    notify();
}

void ServiceFilme::modifica_film_service(int id, string titlu_nou, string gen_nou, int an_aparitie_nou, string actor_principal_nou) {
    Film film_nou(id, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    if(validator.valideaza(film_nou)) {
        Film film = lista.modifica_film_repo(film_nou);
        undo_list.push_back(new UndoModifica(lista,film));
    }
    notify();
}

void ServiceFilme::sterge_dupa_id_service(int id) {
    Film film = lista.sterge_film_dupa_id_repo(id);
    undo_list.push_back(new UndoSterge(lista,film));
    notify();
}

const Film& ServiceFilme::cauta_film_dupa_id_service(int id) {
    return lista.cauta_film_dupa_id_repo(id);
}

//const MyVector<Film>& ServiceFilme::get_all_service() const {
//    return lista.get_all_repo();
//}
const vector<Film>& ServiceFilme::get_all_service() const {
    return lista.get_all_repo();
}

int ServiceFilme::len() const {
    return lista.len();
}

vector<Film> ServiceFilme::filtrare_dupa_titlu(const string& titlu) const{
    vector<Film> lista_filtrata;
//    for (auto & film : lista.get_all_repo())
//        if (film.get_titlu() == titlu )
//            lista_filtrata.push_back(film);
//
    const vector <Film>& lista_filme = lista.get_all_repo();
    copy_if(lista_filme.begin(), lista_filme.end(), std::back_inserter(lista_filtrata), [=](const Film& film){
        return film.get_titlu() == titlu;
    });
    return lista_filtrata;
}

vector<Film> ServiceFilme::filtrare_dupa_an(int an_aparitie) const{
    vector <Film> lista_filtrata;
//    for (auto & film : lista.get_all_repo())
//        if ( film.get_an_aparitie() == an_aparitie )
//            lista_filtrata.push_back(film);
    const vector <Film>& lista_filme = lista.get_all_repo();
    copy_if(lista_filme.begin(), lista_filme.end(), std::back_inserter(lista_filtrata), [=](const Film& film){
        return film.get_an_aparitie() == an_aparitie;
    });
    return lista_filtrata;
}

void ServiceFilme::sortare(const string& criteriu) {
//    MyVector <Film> lista_filme;
//    for (auto& film : lista.get_all_repo() )
//        lista_filme.push_back(film);
//    for ( int i = 0 ; i < lista_filme.size() - 1 ; i ++ )
//        for ( int j = i + 1 ; j < lista_filme.size() ; j ++ )
//            if ( !comparator(lista_filme[i], lista_filme[j], criteriu) )
//                swap(lista_filme[i], lista_filme[j]);

    auto lista_filme = lista.get_all_repo();
    if ( criteriu == "titlu" )
        std::sort(lista_filme.begin(), lista_filme.end(), [](const Film& film1, const Film& film2){
            return film1.get_titlu() < film2.get_titlu();
        });
    else
        if ( criteriu == "actor_principal" )
            std::sort(lista_filme.begin(), lista_filme.end(), [](const Film& film1, const Film& film2){
                return film1.get_actor_principal() < film2.get_actor_principal();
            });
        else
            if ( criteriu == "an_aparitie" )
                std::sort(lista_filme.begin(), lista_filme.end(), [](const Film& film1, const Film& film2){
                    return film1.get_an_aparitie() < film2.get_an_aparitie();
                });
            else
                if ( criteriu == "gen" )
                    std::sort(lista_filme.begin(), lista_filme.end(), [](const Film& film1, const Film& film2){
                        return film1.get_gen() < film2.get_gen();
                    });
    for ( auto & i : lista_filme)
        lista.sterge_film_dupa_id_repo(i.get_id());

    for ( auto & i : lista_filme)
        lista.adauga_film_repo(i);
    notify();
}

bool ServiceFilme::comparator(const Film& film1, const Film& film2, const string& criteriu) {
    if ( criteriu == "titlu" )
        if (film1.get_titlu() < film2.get_titlu() )
            return true;
        else
            return false;
    if( criteriu == "actor_principal" )
        if (film1.get_actor_principal() < film2.get_actor_principal() )
            return true;
        else
            return false;
    if( criteriu == "an_aparitie" )
        if (film1.get_an_aparitie() < film2.get_an_aparitie() )
            return true;
        else
            return false;
    if( criteriu == "gen" )
        if (film1.get_gen() < film2.get_gen() )
            return true;
        else
            return false;
    return false;
}

void ServiceFilme::adauga_cos_service(const string &titlu) {
    for ( auto& film : filtrare_dupa_titlu(titlu) )
        cos.adauga_cos(film);
    notify();
}

void ServiceFilme::goleste_cos_service() {
    cos.goleste_cos();
    notify();
}

void ServiceFilme::genereaza_cos_service(int numar_filme) {
    cos.genereaza_cos(numar_filme, get_all_service());
    notify();
}

void ServiceFilme::export_cos_service(const string &fisier) {
    std::ofstream fout(fisier);
    for ( auto& film : cos.get_all_cos() ){
        string film_string;
        film_string = std::to_string(film.get_id()) + "," + film.get_titlu() + "," + film.get_gen() + "," + std::to_string(film.get_an_aparitie()) + "," + film.get_actor_principal() + "\n";
        fout << film_string;
    }
    fout.close();
}

const vector<Film> &ServiceFilme::get_cos() const {
    return cos.get_all_cos();
}

int ServiceFilme::size_cos() const {
    return cos.size();
}

void ServiceFilme::undo() {
    if (!undo_list.empty()) {
        ActiuneUndo *u = undo_list.back();
        undo_list.pop_back();
        u->doUndo();
        delete u;
        notify();
    }
    else
        throw ValidationError("Undo imposibil!\n");

}

map<string, vector<Film>> ServiceFilme::get_all_filme_dupa_actor() {
    map<string,vector<Film>> m;
    for (const auto& film:get_all_service()){
        m[film.get_actor_principal()].push_back(film);
    }
    return m;
}

