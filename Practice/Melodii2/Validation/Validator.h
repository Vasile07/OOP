//
// Created by Irimieş Vasile on 6/15/2023.
//

#ifndef MELODII_2_VALIDATOR_H
#define MELODII_2_VALIDATOR_H


#include "../Domain/Melodie.h"
#include <string>

class Validator {
public:
    Validator(){}
    bool valideaza(const Melodie& melodie)const;
};


#endif //MELODII_2_VALIDATOR_H
