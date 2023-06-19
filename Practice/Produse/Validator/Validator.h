//
// Created by Irimieş Vasile on 6/18/2023.
//

#ifndef PRODUSE_BUN_VALIDATOR_H
#define PRODUSE_BUN_VALIDATOR_H
#include <string>
#include "../Domain/Produs.h"

using std::string;

class Validator {
private:
public:
    Validator(){}
    /**
     * Valideaza un produs dat
     * Daca id < 0 textul "Id invalid!\n" va fi adauga la stringul de erori
     * Daca nume e vid textul "Nume invalid!\n" va fi adauga la stringul de erori
     * Daca tip e vid textul "Tip invalid!\n" va fi adauga la stringul de erori
     * Daca pret < 1 sau pret > 100 textul "Pret invalid!\n" va fi adauga la stringul de erori
     * @param produs Produs
     * @return True - produs valid
     * @throw ValidationError(erori)
     */
    bool valideaza(const Produs& produs);
};


#endif //PRODUSE_BUN_VALIDATOR_H
