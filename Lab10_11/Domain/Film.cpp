//
// Created by Irimieş Vasile on 3/30/2023.
//

#include "Film.h"

#include <utility>


Film::Film(int id, string titlu, string gen, int an_aparitie, string actor_principal) {
    this->id = id;
    this->titlu = std::move(titlu);
    this->gen = std::move(gen);
    this->an_aparitie = an_aparitie;
    this->actor_principal = std::move(actor_principal);
}


int Film::get_id() const {
    return id;
}

string Film::get_titlu() const {
    return titlu;
}

string Film::get_gen() const {
    return gen;
}

int Film::get_an_aparitie() const {
    return an_aparitie;
}

string Film::get_actor_principal() const {
    return actor_principal;
}

void Film::set_titlu(string titlu_nou) {
    titlu = std::move(titlu_nou);
}

void Film::set_gen(string gen_nou) {
    gen = std::move(gen_nou);
}

void Film::set_an_aparitie(int an_aparitie_nou) {
    an_aparitie = an_aparitie_nou;
}

void Film::set_actor_principal(string actor_principal_nou) {
    actor_principal = std::move(actor_principal_nou);
}

//Film::Film() = default;


