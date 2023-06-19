//
// Created by Irimieş Vasile on 6/13/2023.
//

#include "Test.h"
#include "../Domain/Melodie.h"
#include "../Persistance/RepoMelodii.h"
#include "../Erori/Erori.h"
#include "../Validator/Validator.h"
#include "../Business/ServiceMelodii.h"
#include <cassert>

void Test::ruleaza_toate_testele() {
    ruleaza_teste_domain();
    ruleaza_teste_repo();
    ruleaza_teste_validator();
    ruleaza_teste_serivce();
}

void Test::ruleaza_teste_domain() {
    ruleaza_teste_create();
    ruleaza_teste_set();
}

void Test::ruleaza_teste_create() {
    Melodie melodie{id, titlu, artist, rank};
    assert(melodie.get_id() == id);
    assert(melodie.get_titlu() == titlu);
    assert(melodie.get_artist() == artist);
    assert(melodie.get_rank() == rank);
}

void Test::ruleaza_teste_set() {
    Melodie melodie{id, titlu, artist, rank};
    melodie.set_titlu(titlu_nou);
    melodie.set_rank(rank_nou);

    assert(melodie.get_id() == id);
    assert(melodie.get_titlu() == titlu_nou);
    assert(melodie.get_artist() == artist);
    assert(melodie.get_rank() == rank_nou);
}

void Test::ruleaza_teste_repo() {
    ruleaza_teste_adauga_repo();
    ruleaza_teste_modifica_repo();
    ruleaza_teste_sterge_repo();
    ruleaza_teste_get_all_repo();
}

void Test::ruleaza_teste_adauga_repo() {
    RepoMelodii repo{fisier};
    assert(repo.len() == 3);
    Melodie melodie{id, titlu, artist, rank};
    repo.adauga_melodie_repo(melodie);
    assert(repo.len() == 4);
    try{
        repo.adauga_melodie_repo(melodie);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Melodie existenta!\n");
    }
    repo.sterge_melodie_dupa_id_repo(id);
}

void Test::ruleaza_teste_modifica_repo() {
    RepoMelodii repo{fisier};
    assert(repo.len() == 3);
    Melodie melodie{id, titlu, artist, rank};
    repo.adauga_melodie_repo(melodie);
    Melodie melodie_noua{id, titlu_nou, artist, rank_nou};
    repo.modifica_melodie_repo(melodie_noua);
    assert(repo.len() == 4);
    try{
        Melodie m{id+1, titlu, artist, rank};
        repo.modifica_melodie_repo(m);
        assert(false);
    }catch (RepoError& re){
        assert( re.get_msg() == "Melodie inexistenta!\n");
    }
    repo.sterge_melodie_dupa_id_repo(id);
}

void Test::ruleaza_teste_sterge_repo() {
    RepoMelodii repo{fisier};
    assert(repo.len() == 3);
    Melodie melodie{id, titlu, artist, rank};
    repo.adauga_melodie_repo(melodie);
    assert(repo.len() == 4);
    repo.sterge_melodie_dupa_id_repo(id);
    assert(repo.len() == 3);
    try{
        repo.sterge_melodie_dupa_id_repo(id);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Melodie inexistenta!\n");
    }
}

void Test::ruleaza_teste_get_all_repo() {
    RepoMelodii repo{fisier};
    assert(repo.len() == 3);
    assert(repo.get_all().size() == 3);
}


void Test::ruleaza_teste_validator() {
    Melodie melodie{id,titlu,artist,rank};
    Validator validator;

    assert(validator.valideaza(melodie) == true);
    try{
        validator.valideaza({-1,"","",19});
    }catch (ValidationError& ve){
        assert(ve.get_msg() == "Id invalid!\nTitlu invalid!\nArtist invalid!\nRank invalid!\n");
    }
}

void Test::ruleaza_teste_serivce() {
    ruleaza_teste_adauga_service();
//    ruleaza_teste_modifica_service();
//    ruleaza_teste_sterge_service();
//    ruleaza_teste_get_all_service();
//    ruleaza_teste_filtru_rank();
}

void Test::ruleaza_teste_adauga_service() {
    RepoMelodii repo{fisier};
    Validator validator;
    ServiceMelodii service{repo, validator};
    assert(service.len() == 3);
    service.adauga_melodie_service(id, titlu, artist, rank);
    assert(service.len() == 4);
    try{
        service.adauga_melodie_service(id, titlu, artist, rank);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Melodie existenta!\n");
    }

    try{
        service.adauga_melodie_service(-1,"","",12);
        assert(false);
    }catch (ValidationError& ve){
        assert(ve.get_msg() == "Id invalid!\nTitlu invalid!\nArtist invalid!\nRank invalid!\n");
    }

    service.sterge_util(id);
}

void Test::ruleaza_teste_modifica_service() {
    RepoMelodii repo{fisier};
    Validator validator;
    ServiceMelodii service{repo, validator};
    assert(service.len() == 3);
    service.adauga_melodie_service(id, titlu, artist, rank);
    assert(service.len() == 4);
    service.modifica_melodie_service(id, titlu_nou, artist, rank_nou);
    assert(service.len() == 4);

    try{
        service.modifica_melodie_service(id+1, titlu, artist, rank);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Melodie inexistenta!\n");
    }

    service.sterge_util(id);
}

void Test::ruleaza_teste_sterge_service() {
    RepoMelodii repo{fisier};
    Validator validator;
    ServiceMelodii service{repo, validator};
    assert(service.len() == 3);
    service.adauga_melodie_service(id, titlu, artist, rank);
    service.adauga_melodie_service(10+id, titlu+" remake", artist, rank+1);
    assert(service.len() == 5);
    service.sterge_melodie_dupa_id_service(id);
    assert(service.len() == 4);
    try{
        service.sterge_melodie_dupa_id_service(10*id);
        assert(false);
    }catch (ValidationError& ve){
        assert(ve.get_msg() == "Ultima melodie a artistului, nu se poate sterge!\n");
    }

    service.sterge_util(10*id);
}

void Test::ruleaza_teste_get_all_service() {
    RepoMelodii repo{fisier};
    Validator validator;
    ServiceMelodii service{repo, validator};
    assert(service.len() == 3);
    assert(service.get_all().size() == 3);
}

void Test::ruleaza_teste_filtru_rank() {
    RepoMelodii repo{fisier};
    Validator validator;
    ServiceMelodii service{repo, validator};
    assert(service.len() == 3);
    assert(service.filtru_dupa_rank(7).size() == 2);
}
