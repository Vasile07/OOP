//
// Created by Irimieş Vasile on 4/23/2023.
//
#include <random>
#include "CosFilme.h"

void CosFilme::adauga_cos(const Film &film) {
    cos.push_back(film);
}

void CosFilme::goleste_cos() {
    cos.clear();
}

void CosFilme::genereaza_cos(int numar_filme, const vector<Film> &all_films) {
    if ( !all_films.empty()) {
        std::mt19937 mt{std::random_device{}()};
        std::uniform_int_distribution<> dist(0, (int) all_films.size() - 1);
        while (numar_filme) {
            int indice = dist(mt);
            cos.push_back(all_films[indice]);
            numar_filme--;
        }
    }
}

const vector<Film> &CosFilme::get_all_cos() const {
    return cos;
}

int CosFilme::size() const {
    return (int)cos.size();
}
