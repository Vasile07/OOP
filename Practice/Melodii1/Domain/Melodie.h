//
// Created by Irimieş Vasile on 6/13/2023.
//

#ifndef MELODII_1_MELODIE_H
#define MELODII_1_MELODIE_H
#include <string>

using std::string;

class Melodie {
private:
    int id;
    string titlu;
    string artist;
    int rank;

public:
    /**
     * Constructor
     * @param id int
     * @param titlu string
     * @param artist string
     * @param rank int
     */
    Melodie(int id, string titlu, string artist, int rank): id{id}, titlu{titlu}, artist{artist}, rank{rank}{}

    int get_id()const;

    string get_titlu()const;

    string get_artist()const;

    int get_rank()const;

    void set_rank(int rank_nou);

    void set_titlu(string titlu_nou);

};


#endif //MELODII_1_MELODIE_H
