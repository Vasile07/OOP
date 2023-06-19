//
// Created by Irimieş Vasile on 6/18/2023.
//

#include <cassert>
#include "Test.h"
#include "../Erori/Erori.h"
#include "../Persistance/RepoProduse.h"
#include "../Business/ServiceProduse.h"

void Test::ruleaza_toate_testele() {
    ruleaza_teste_domain();
    ruleaza_teste_validator();
    ruleaza_teste_repo();
    ruleaza_teste_service();
}

void Test::ruleaza_teste_domain() {
    ruleaza_teste_get();
}

void Test::ruleaza_teste_get() {
    Produs produs{id,nume,tip,pret};
    assert(produs.get_id() == id);
    assert(produs.get_nume() == nume);
    assert(produs.get_tip() == tip);
    assert(produs.get_pret() == pret);
}

void Test::ruleaza_teste_validator() {
    Validator validator;
    assert(validator.valideaza({id,nume,tip,pret})== true);
    try{
        validator.valideaza({-1,"","",101});
        assert(false);
    }catch (ValidationError& ve){
        assert(ve.get_msg() == "Id invalid!\nNume invalid!\nTip invalid!\nPret invalid!\n");
    }
}

void Test::ruleaza_teste_repo() {
    ruleaza_teste_adauga_repo();
    ruleaza_teste_sterge_repo();
    ruleaza_teste_get_all_repo();
}

void Test::ruleaza_teste_adauga_repo() {
    RepoProduse repo{nume_fisier};
    assert(repo.len() == 3);
    repo.adauga_produs_repo({id,nume,tip,pret});
    assert(repo.len() == 4);
    try{
        repo.adauga_produs_repo({id,nume, tip, pret});
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Produs existent!\n");
    }
    repo.sterge_produs_dupa_id_repo(id);
}

void Test::ruleaza_teste_sterge_repo() {
    RepoProduse repo{nume_fisier};
    assert(repo.len() == 3);
    repo.adauga_produs_repo({id,nume,tip,pret});
    assert(repo.len() == 4);
    repo.sterge_produs_dupa_id_repo(id);
    assert(repo.len() == 3);
    try{
        repo.sterge_produs_dupa_id_repo(id);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Produs inexistent!\n");
    }
}

void Test::ruleaza_teste_get_all_repo() {
    RepoProduse repo{nume_fisier};
    auto l = repo.get_all();
    assert(l.empty() == false);
    assert(l.size() == repo.len());
}


void Test::ruleaza_teste_service() {
    ruleaza_teste_adauga_service();
    ruleaza_teste_sterge_service();
    ruleaza_teste_get_all_service();
    ruleaza_teste_map_service();
}

void Test::ruleaza_teste_adauga_service() {
    RepoProduse repo{nume_fisier};
    Validator validator;
    ServiceProduse service{repo,validator};
    assert(service.len() == 3);
    service.adauga_produs_service(id,nume,tip,pret);
    assert(service.len() == 4);
    try{
        service.adauga_produs_service(id,nume,tip, pret);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Produs existent!\n");
    }
    service.sterge_produs_dupa_id_service(id);
}

void Test::ruleaza_teste_sterge_service() {
    RepoProduse repo{nume_fisier};
    Validator validator;
    ServiceProduse service{repo,validator};
    assert(service.len() == 3);
    service.adauga_produs_service(id,nume,tip, pret);
    assert(service.len() == 4);
    service.sterge_produs_dupa_id_service(id);
    assert(service.len() == 3);
    try{
        service.sterge_produs_dupa_id_service(id);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Produs inexistent!\n");
    }
}


void Test::ruleaza_teste_get_all_service() {
    RepoProduse repo{nume_fisier};
    Validator validator;
    ServiceProduse service{repo,validator};
    auto l = service.get_all();
    assert(l.empty() == false);
    assert(l.size() == service.len());
}


void Test::ruleaza_teste_map_service() {
    RepoProduse repo{nume_fisier};
    Validator validator;
    ServiceProduse service{repo,validator};
    assert(service.tipuri_si_nr_aparitii().size() == 3);
}
