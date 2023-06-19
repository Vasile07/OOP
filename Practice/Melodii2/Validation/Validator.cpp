//
// Created by Irimieş Vasile on 6/15/2023.
//

#include "Validator.h"
#include "../Erors/Erori.h"

bool Validator::valideaza(const Melodie &melodie) const {
    string erori;
    if ( melodie.get_id() < 0 )
        erori += "Id invalid!\n";
    if( melodie.get_titlu().empty() )
        erori += "Titlu invalid!\n";
    if(melodie.get_artist().empty())
        erori += "Artist invalid!\n";
    if(melodie.get_gen() != "pop" && melodie.get_gen() != "rock" && melodie.get_gen() != "folk" && melodie.get_gen() != "disco")
        erori += "Gen invalid!\n";
    if(!erori.empty())
        throw ValidationError(erori);
    return true;
}
