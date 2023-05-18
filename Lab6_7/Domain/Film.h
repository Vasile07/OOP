//
// Created by Irimieş Vasile on 3/30/2023.
//

#ifndef LABORATORUL_6_7_FILM_H
#define LABORATORUL_6_7_FILM_H
#include <string>
#include <iostream>

using std::string;

class Film {
    private:
    string titlu, gen, actor_principal;
        int an_aparitie, id;
    public:
        /***
        * Constructorul filmului
        * @param id - int
        * @param titlu - string
        * @param gen - string
        * @param an_aparitie - string
        * @param actor_principal - string
        */
        Film(int id, string titlu, string gen, int an_aparitie, string actor_principal);

//        Film(const Film& film): id{film.get_id()}, titlu{film.get_titlu()}, gen{film.get_gen()}, an_aparitie{film.an_aparitie}, actor_principal{film.get_actor_principal()}{
//            std::cout << "\nCOPIERE EFECTUATA\n";
//        }
        //Film(const Film& film) = delete;

        /***
         * Returneaza id-ul filmului
         * @return id - int
         */
        int get_id() const;

        /***
         * Returneaza titlul filmului
         * @return titlu - string
         */
        string get_titlu() const;

        /***
         * Returneaza genul filmului
         * @return gen - string
         */
        string get_gen() const;

        /***
         * Returneaza anul de aparitie al filmului
         * @return an_aparitie - int
         */
        int get_an_aparitie() const;

        /***
         * Returnaza actorul principal al filmului
         * @return film - string
         */
        string get_actor_principal() const;

        /***
         * Modifica titlul filmului
         * @param titlu_nou - string
         */
        void set_titlu(string titlu_nou);

        /***
         * Modifica genul filmului
         * @param gen_nou - string
         */
        void set_gen(string gen_nou);

        /***
         * Modifica anul de aparitie al filmului
         * @param an_aparitie_nou - int
         */
        void set_an_aparitie(int an_aparitie_nou);

        /***
         * Modifica actorul principal al filmului
         * @param actor_principal_nou - string
         */
        void set_actor_principal(string actor_principal_nou);

        /***
         * Verifica daca filmul dat are acelasi id
         * @param film - Film
         * @return  True - id egal
         *          False - id inegal
         */
        bool operator== (const Film &f2) const{return this->get_id() == f2.get_id();}

    Film();
        ~Film() = default;
};


#endif //LABORATORUL_6_7_FILM_H
