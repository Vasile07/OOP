//
// Created by Irimieş Vasile on 6/18/2023.
//

#include "Validator.h"
#include "../Erori/Erori.h"

bool Validator::valideaza(const Produs &produs) {
    string erori;
    if(produs.get_id() < 0 )
        erori += "Id invalid!\n";
    if(produs.get_nume().empty())
        erori += "Nume invalid!\n";
    if(produs.get_tip().empty())
        erori += "Tip invalid!\n";
    if( !(1.0 <= produs.get_pret() && produs.get_pret() <= 100.0) )
        erori += "Pret invalid!\n";
    if(!erori.empty())
        throw ValidationError(erori);
    return true;
}
