//
// Created by Irimieş Vasile on 6/13/2023.
//

#include "Melodie.h"

int Melodie::get_id() const {
    return id;
}

string Melodie::get_titlu() const {
    return titlu;
}

string Melodie::get_artist() const {
    return artist;
}

int Melodie::get_rank() const {
    return rank;
}

void Melodie::set_rank(int rank_nou) {
    rank = rank_nou;
}

void Melodie::set_titlu(string titlu_nou) {
    titlu = titlu_nou;
}
