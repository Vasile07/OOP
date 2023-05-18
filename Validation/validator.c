//
// Created by Irimieş Vasile on 3/16/2023.
//
#include <string.h>
#include "validator.h"

int valideaza(Masina m){
    if( ! (m.numar_de_inmatriculare[0] <= 'Z' && m.numar_de_inmatriculare[0] >= 'A') || ! (m.numar_de_inmatriculare[1] <= 'Z' && m.numar_de_inmatriculare[1] >= 'A') || m.numar_de_inmatriculare[2] != '.' || ! (m.numar_de_inmatriculare[3] <= '9' && m.numar_de_inmatriculare[3] >= '0') || m.numar_de_inmatriculare[5] != '.' || ! (m.numar_de_inmatriculare[6] <= 'Z' && m.numar_de_inmatriculare[6] >= 'A') || ! (m.numar_de_inmatriculare[7] <= 'Z' && m.numar_de_inmatriculare[7] >= 'A') || ! (m.numar_de_inmatriculare[8] <= 'Z' && m.numar_de_inmatriculare[8] >= 'A') )
        return -2;
    if( strcmp(m.categorie,"") == 0)
        return -2;
    if( strcmp(m.model,"") == 0)
        return -2;
    return 0;
}
