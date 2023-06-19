//
// Created by Irimieş Vasile on 6/13/2023.
//

#ifndef MELODII_1_VALIDATOR_H
#define MELODII_1_VALIDATOR_H
#include <string>
#include "../Domain/Melodie.h"
#include "../Erori/Erori.h"

using std::string;

class Validator{
public:
    bool valideaza(const Melodie& melodie){
        string erori;
        if ( melodie.get_id() < 0 )
            erori+="Id invalid!\n";
        if( melodie.get_titlu().empty()){
            erori+="Titlu invalid!\n";
        }
        if( melodie.get_artist().empty() ){
            erori+="Artist invalid!\n";
        }
        if( !( 0 <= melodie.get_rank() && melodie.get_rank() <= 10 ) ){
            erori+="Rank invalid!\n";
        }
        if(!erori.empty())
            throw ValidationError(erori);
        return true;
    }
};
#endif //MELODII_1_VALIDATOR_H
