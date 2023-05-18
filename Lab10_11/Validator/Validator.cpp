//
// Created by Irimieş Vasile on 3/31/2023.
//

#include "Validator.h"
#include "../Errors/Erori.h"

bool Validator::valideaza(const Film& film) const{
    string erori;

    if ( film.get_id() < 0 )
        erori += "Id invalid!\n";

    if( film.get_titlu() == "")
        erori += "Titlu invalid!\n";

    if( film.get_gen() == "")
        erori += "Gen invalid!\n";

    if( film.get_actor_principal() == "")
        erori += "Actor principal invalid!\n";

    if( film.get_an_aparitie() < 0 )
        erori += "An aparitie invalid!\n";

    if ( erori.empty() )
        return true;
    else
        throw ValidationError(erori);
}
