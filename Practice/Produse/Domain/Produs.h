//
// Created by Irimieş Vasile on 6/18/2023.
//

#ifndef PRODUSE_BUN_PRODUS_H
#define PRODUSE_BUN_PRODUS_H
#include <string>

using std::string;

class Produs {

private:

    int id;
    double pret;
    string nume;
    string tip;

public:

    /**
     * Constructor Produs
     * @param id int
     * @param nume string
     * @param tip string
     * @param pret double
     */
    Produs(int id, string nume, string tip, double pret):id{id},nume{nume},tip{tip},pret{pret}{}

    /**
     * Returnaza id-ul produsului
     * @return id
     */
    int get_id()const;

    /**
     * Returneaza numele produsului
     * @return string
     */
    string get_nume()const;

    /**
     * Returneaza tiul produsului
     * @return string
     */
    string get_tip()const;

    /**
     * Returneaza pretul produsului
     * @return double
     */
    double get_pret()const;

};


#endif //PRODUSE_BUN_PRODUS_H
