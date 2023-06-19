//
// Created by Irimieş Vasile on 6/15/2023.
//

#ifndef MELODII_2_MELODIE_H
#define MELODII_2_MELODIE_H
#include <string>

using std::string;

class Melodie {
private:
    int id;
    string titlu;
    string artist;
    string gen;

public:
    Melodie(int id, string titlu, string artist, string gen):id{id},titlu{titlu},artist{artist},gen{gen}{}

    int get_id()const;

    string get_titlu()const;

    string get_artist()const;

    string get_gen()const;

};


#endif //MELODII_2_MELODIE_H
