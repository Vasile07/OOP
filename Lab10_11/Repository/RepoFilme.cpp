//
// Created by Irimieş Vasile on 3/30/2023.
//

#include <iostream>
#include "RepoFilme.h"
#include "../Errors/Erori.h"
#include <algorithm>
using std::find_if;

void RepoFilme::adauga_film_repo(const Film& film) {
//    for (auto & item : repo_filme)
//        if ( item == film )
    auto found = find_if(repo_filme.begin(), repo_filme.end(), [film](const Film& item){
        return item == film;
    });
    if ( found != repo_filme.end())
            throw RepoError("Film existent!\n");
    repo_filme.push_back(film);
}

Film RepoFilme::modifica_film_repo(const Film& film_nou) {
//    bool gasit = false;
//    for (auto & film : repo_filme)
//        if ( film == film_nou ) {
//            film = film_nou;
//            gasit = true;
//        }
//    if(!gasit)
    auto found = find_if(repo_filme.begin(), repo_filme.end(), [film_nou](const Film& film){
        return film_nou == film;
    });
    if ( found == repo_filme.end())
        throw RepoError("Film inexistent!\n");
    else{
        Film film = *found;
        found->set_titlu(film_nou.get_titlu());
        found->set_gen(film_nou.get_gen());
        found->set_actor_principal(film_nou.get_actor_principal());
        found->set_an_aparitie(film_nou.get_an_aparitie());
        return film;
    }
}

const Film& RepoFilme::cauta_film_dupa_id_repo(int id) {
//    for (auto & film : repo_filme)
//        if ( film.get_id() == id )
//            return film;
    auto found = find_if(repo_filme.begin(), repo_filme.end(), [id](const Film& film){
        return id == film.get_id();
    });
    if ( found == repo_filme.end() )
        throw RepoError("Film inexistent!\n");
    else
        return *found;
}

Film RepoFilme::sterge_film_dupa_id_repo(int id) {
//    int poz = -1;
//    for ( int i = 0 ; i < repo_filme.size() ; i ++ )
//        if ( repo_filme[i].get_id() == id )
//            poz = i;
//    if( poz < 0 )
//        throw RepoError("Film inexistent!\n");
//    else {
//        for (int i = poz; i < repo_filme.size() - 1; i++)
//            repo_filme[i] = repo_filme[i + 1];
//        repo_filme.pop_back();
//    }
    auto found = find_if(repo_filme.begin(), repo_filme.end(), [id](const Film& film){
        return film.get_id() == id;
    });
    if ( found == repo_filme.end() )
        throw RepoError("Film inexistent!\n");
    else {
        Film film = *found;
        repo_filme.erase(found);
        return film;
    }
}

int RepoFilme::len() const {
    return (int)repo_filme.size();
}

//const MyVector<Film>& RepoFilme::get_all_repo() const {
//    return repo_filme;
//}
const vector<Film>& RepoFilme::get_all_repo() const {
    return repo_filme;
}
