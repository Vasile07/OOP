//
// Created by Irimieş Vasile on 6/18/2023.
//

#ifndef PRODUSE_BUN_REPOPRODUSE_H
#define PRODUSE_BUN_REPOPRODUSE_H
#include <vector>
#include "../Domain/Produs.h"

using std::vector;

class RepoProduse {

private:

    vector<Produs> lista_produse;
    string nume_fisier;

    /**
     * Incarca datele din fisier
     */
    void load_from_file();

    /**
     * Incarca datele in fisier
     */
    void store_to_file();

public:

    /**
     * Constructor RepoProduse
     * @param nume_fisier string
     */
    RepoProduse(string nume_fisier):nume_fisier{nume_fisier}{
        load_from_file();
    }

    /**
     * Adauga un produs in lista daca id-ul aestuia nu se regaseste deja
     * @param produs Produs
     * @throw RepoError("Produs existent!\n) daca id-ul se regaseste in lista
     */
    void adauga_produs_repo(const Produs& produs);

    /**
     * Sterge un produs din lista dca id-ul dat se regaseste in lista
     * @param id int
     * @throw RepoError("Produs inexistent!\n");
     */
    void sterge_produs_dupa_id_repo(int id);

    /**
     * Returneaza lista de porduse
     * @return vector<Produs>
     */
    vector<Produs> get_all()const;

    /**
     * Returneaza numarul de produse din lista
     * @return int
     */
    int len()const;

};


#endif //PRODUSE_BUN_REPOPRODUSE_H
