//
// Created by Irimieş Vasile on 6/15/2023.
//

#include <cassert>
#include "Teste.h"
#include "../Erors/Erori.h"

void Teste::ruleaza_toate_testele() {
    ruleaza_teste_domain();
    ruleaza_teste_repo();
    ruleaza_teste_validator();
    ruleaza_teste_service();
}

void Teste::ruleaza_teste_domain() {
    ruleaza_teste_create();
}

void Teste::ruleaza_teste_create() {
    Melodie melodie{id,titlu,artist,gen};
    assert(melodie.get_id() == id);
    assert(melodie.get_titlu() == titlu);
    assert(melodie.get_artist() == artist);
    assert(melodie.get_gen() == gen);
}

void Teste::ruleaza_teste_validator() {
    Melodie melodie{id, titlu, artist, gen};
    Validator validator;
    assert(validator.valideaza(melodie) == true);
    try{
        validator.valideaza({-12,"","","aafa"});
        assert(false);
    }catch (ValidationError& ve){
        assert(ve.get_msg() == "Id invalid!\nTitlu invalid!\nArtist invalid!\nGen invalid!\n");
    }
}

void Teste::ruleaza_teste_repo() {
    ruleaza_teste_adauga_repo();
    ruleaza_teste_sterge_repo();
}

void Teste::ruleaza_teste_adauga_repo() {
    RepoMelodii repo{numeFisier};
    assert(repo.len() == 3);
    repo.adauga_melodie_repo({id,titlu,artist,gen});
    assert(repo.len() == 4);
    try{
        repo.adauga_melodie_repo({id,titlu,artist,gen});
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Melodie existenta!\n");
    }
    repo.sterge_melodie_dupa_id_repo(id);
}

void Teste::ruleaza_teste_sterge_repo() {
    RepoMelodii repo{numeFisier};
    assert(repo.len() == 3);
    repo.adauga_melodie_repo({id,titlu,artist,gen});
    assert(repo.len()==4);
    repo.sterge_melodie_dupa_id_repo(id);
    assert(repo.len() == 3);
    try{
        repo.sterge_melodie_dupa_id_repo(id);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Melodie inexistenta!\n");
    }
}

void Teste::ruleaza_teste_service() {
    ruleaza_teste_adauga_service();
    ruleaza_teste_sterge_service();
}

void Teste::ruleaza_teste_adauga_service() {
    RepoMelodii repo{numeFisier};
    Validator validator;
    ServiceMelodii service{repo,validator};
    assert(service.len() == 3);
    service.adauga_melodie_service(id,titlu,artist,gen);
    assert(service.len() == 4);
    try{
        service.adauga_melodie_service(id,titlu,artist,gen);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Melodie existenta!\n");
    }
    try{
        service.adauga_melodie_service(-1,"","","dada");
        assert(false);
    }catch (ValidationError& ve){
        assert(ve.get_msg() == "Id invalid!\nTitlu invalid!\nArtist invalid!\nGen invalid!\n");
    }
    service.sterge_melodie_dupa_id_service(id);
}

void Teste::ruleaza_teste_sterge_service() {
    RepoMelodii repo{numeFisier};
    Validator validator;
    ServiceMelodii service{repo,validator};
    assert(service.len() == 3);
    service.adauga_melodie_service(id,titlu,artist,gen);
    assert(service.len() == 4);
    service.sterge_melodie_dupa_id_service(id);
    assert(service.len()==3);
    try{
        service.sterge_melodie_dupa_id_service(id);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Melodie inexistenta!\n");
    }
}
