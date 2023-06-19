//
// Created by Irimieş Vasile on 4/23/2023.
//

#include <fstream>
#include <sstream>
#include "FileRepoFilme.h"

void FileRepoFilme::adauga_film_repo(const Film &film) {
    RepoFilme::adauga_film_repo(film);
//    std::cout<<"add\n";
    store_to_file();
}

Film FileRepoFilme::sterge_film_dupa_id_repo(int id) {
    Film film = RepoFilme::sterge_film_dupa_id_repo(id);
//    std::cout<<"delete\n";
    store_to_file();
    return film;
}

Film FileRepoFilme::modifica_film_repo(const Film &film_nou) {
    Film film = RepoFilme::modifica_film_repo(film_nou);
    store_to_file();
    return film;
}

void FileRepoFilme::load_from_file() {
    std::ifstream fin(file);
    string line;
    while (getline(fin, line)){
        int id, an;
        string titlu, gen, actor;
        string param;
        std::stringstream for_line(line);

        std::getline(for_line, param, ',');
        id = stoi(param);
        std::getline(for_line, param, ',');
        titlu = param;
        std::getline(for_line, param, ',');
        gen = param;
        std::getline(for_line, param, ',');
        an = stoi(param);
        std::getline(for_line, param, ',');
        actor = param;

        Film film{id, titlu, gen, an, actor};
        RepoFilme::adauga_film_repo(film);
    }
    fin.close();
}

void FileRepoFilme::store_to_file() {
    remove(file.c_str());

    std::ofstream fout(file);
//
//    //fout.open(file, std::ofstream::out | std::ofstream::trunc);

    for ( auto& film : RepoFilme::get_all_repo() ){
//        std::cout<<film.get_titlu()<<'\n';
        string film_string = std::to_string(film.get_id()) + "," + film.get_titlu() + "," + film.get_gen() + "," + std::to_string(film.get_an_aparitie()) + "," + film.get_actor_principal() + "\n";
        fout << film_string;
    }
    fout.close();
}
