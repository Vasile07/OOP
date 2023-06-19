//
// Created by Irimieş Vasile on 6/18/2023.
//

#ifndef PRODUSE_BUN_SERVICEPRODUSE_H
#define PRODUSE_BUN_SERVICEPRODUSE_H
#include "../Persistance/RepoProduse.h"
#include "../Validator/Validator.h"
#include <map>

using std::map;

class ServiceProduse {

private:

    RepoProduse repo;
    Validator validator;

public:

    /**
     * Constructorul ServiceProduse
     * @param repo RepoProduse
     * @param validator Validator
     */
    ServiceProduse(RepoProduse repo, Validator validator): repo{repo},validator{validator}{}

    /**
     * Adauga un produs in lista
     * @param id int
     * @param nume string
     * @param tip string
     * @param pret double
     * @throw RepoError - id-ul exista in lista
     * @throw ValidationError - datele sunt invalide ( id < 0, nume,tip = "", pret != 1...100 )
     */
    void adauga_produs_service(int id, string nume, string tip, double pret);

    /**
     * Sterge produsul cu id-ul dat din lista
     * @param id int
     * @throw RepoError - produs inexistent in lista
     */
    void sterge_produs_dupa_id_service(int id);

    /**
     * Returneaza lista de produse
     * @return vector<Produs>
     */
    vector<Produs> get_all()const;

    /**
     * Returneaza numarul de elemente din lista
     * @return int
     */
    int len()const;

    /**
     * Returneaza o lista de perechi (tip,numar_aparitii) a tuturor tipurilor existente in lista
     * impreuna cu numarul de aparitii ale acestuia
     * @return map<string,int>
     */
    map<string,int> tipuri_si_nr_aparitii()const;

};


#endif //PRODUSE_BUN_SERVICEPRODUSE_H
