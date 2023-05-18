//
// Created by Irimieş Vasile on 4/23/2023.
//

#ifndef LABORATORUL_6_7_ACTIUNEUNDO_H
#define LABORATORUL_6_7_ACTIUNEUNDO_H


#include "../Domain/Film.h"
#include "../Repository/RepoFilme.h"

class ActiuneUndo {
private:

public:
    virtual void doUndo() = 0;
    virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo{
private:
    Film film;
    BaseRepo& repo;

public:
    UndoAdauga(BaseRepo& repo, const Film& film): repo{repo}, film{film}{}
    void doUndo() override{
        repo.sterge_film_dupa_id_repo(film.get_id());
    }

};

class UndoSterge : public ActiuneUndo{
private:
    Film film;
    BaseRepo& repo;

public:
    UndoSterge(BaseRepo& repo, const Film& film): repo{repo}, film{film}{}
    void doUndo() override{
        repo.adauga_film_repo(film);
    }
};

class UndoModifica : public ActiuneUndo{
private:
    Film film_vechi;
    BaseRepo& repo;

public:
    UndoModifica(BaseRepo& repo, const Film& film): repo{repo}, film_vechi{film}{}
    void doUndo() override{
        repo.modifica_film_repo(film_vechi);
    }
};


#endif //LABORATORUL_6_7_ACTIUNEUNDO_H
