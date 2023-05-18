//
// Created by Irimieş Vasile on 3/31/2023.
//

#ifndef LABORATORUL_6_7_VALIDATOR_H
#define LABORATORUL_6_7_VALIDATOR_H


#include "../Domain/Film.h"

class Validator {
    private:
    public:
        /**
         * Constructor Validator
         */
        Validator() = default;

        /**
         * Verifica validitatea datelor filmului dat
         * @param film - Film
         * @return True - datele sunt valide
         * @throw ValidationError   ->  id < 0 - "Id invalid!\n"
         *                          ->  titlul e vid - "Titlu invalid!\n"
         *                          ->  genul e vid - "Gen invalid!\n"
         *                          ->  actor principal vid - "Actor principal invalid!\n"
         *                          ->  anul de aparitie e negativ - "An aparitie invalid!\n"
         */
        bool valideaza(const Film& film) const;

};


#endif //LABORATORUL_6_7_VALIDATOR_H
