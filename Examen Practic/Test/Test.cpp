//
// Created by Irimieş Vasile on 6/19/2023.
//

#include <cassert>
#include "Test.h"
#include "../Domain/Student.h"
#include "../Persistance/RepoStudenti.h"
#include "../Errors/Erori.h"
#include "../Business/SerivceStudenti.h"

void Test::ruleaza_toate_testele() {
    ruleaza_test_domain();
    ruleaza_teste_repo();
    ruleaza_teste_service();
}

void Test::ruleaza_test_domain() {
    ruleaza_teste_get();
}

void Test::ruleaza_teste_get() {
    Student student{numar_matricol,nume,varsta,facultate};
    assert(student.get_numar_matricol() == numar_matricol);
    assert(student.get_nume() == nume);
    assert(student.get_varsta() == varsta);
    assert(student.get_facultate() == facultate);
}

void Test::ruleaza_teste_repo() {
    ruleaza_teste_sterge_repo();
    ruleaza_teste_modifica_repo();
    ruleaza_teste_get_all_repo();
}

void Test::ruleaza_teste_sterge_repo() {
    RepoStudenti repo{nume_fisier};
    assert(repo.len() == 3);
    repo.adauga_student_repo({numar_matricol,nume,varsta,facultate});
    assert(repo.len() == 4);
    repo.sterge_student_dupa_id_repo(numar_matricol);
    assert(repo.len()==3);
    try{
        repo.sterge_student_dupa_id_repo(numar_matricol);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Student inexistent!\n");
    }
}

void Test::ruleaza_teste_modifica_repo() {
    RepoStudenti repo{nume_fisier};
    assert(repo.len() == 3);
    repo.adauga_student_repo({numar_matricol,nume,varsta,facultate});
    assert(repo.len() == 4);
    repo.modifica_student_repo({numar_matricol,nume,varsta+1,facultate});
    assert(repo.len() == 4);
    try{
        repo.modifica_student_repo({numar_matricol+1,nume,varsta,facultate});
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Student inexistent!\n");
    }
    repo.sterge_student_dupa_id_repo(numar_matricol);
}

void Test::ruleaza_teste_get_all_repo() {
    RepoStudenti repo{nume_fisier};
    assert(repo.len() == 3);
    assert(repo.get_all().size() == 3);
}

void Test::ruleaza_teste_service() {
    ruleaza_teste_adauga_service();
    ruleaza_teste_sterge_service();
    ruleaza_teste_intinereste_service();
    ruleaza_teste_imabtraneste_service();
}

void Test::ruleaza_teste_adauga_service() {
    RepoStudenti repo{nume_fisier};
    SerivceStudenti service{repo};

    assert(service.len() == 3);
    service.adauga_student({numar_matricol,nume,varsta,facultate});
    assert(service.len() == 4);
    try{
        service.adauga_student({numar_matricol,nume,varsta,facultate});
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Student existent!\n");
    }
    service.sterge_student_dupa_id(numar_matricol);
}

void Test::ruleaza_teste_sterge_service() {
    RepoStudenti repo{nume_fisier};
    SerivceStudenti service{repo};

    assert(service.len() == 3);
    service.adauga_student({numar_matricol,nume,varsta,facultate});
    assert(service.len() == 4);
    service.sterge_student_dupa_id(numar_matricol);
    assert(service.len() == 3);
    try{
        service.sterge_student_dupa_id(numar_matricol);
        assert(false);
    }catch (RepoError& re){
        assert(re.get_msg() == "Student inexistent!\n");
    }
}

void Test::ruleaza_teste_intinereste_service() {
    RepoStudenti repo{nume_fisier};
    SerivceStudenti service{repo};
    auto l = service.get_all();
    service.intinerire();
    auto l1 = service.get_all();
    for(int i = 0 ; i < l.size() ; i ++ )
        assert(l[i].get_varsta()-1 == l1[i].get_varsta() );
    service.imbatranire();
}

void Test::ruleaza_teste_imabtraneste_service() {
    RepoStudenti repo{nume_fisier};
    SerivceStudenti service{repo};
    auto l = service.get_all();
    service.imbatranire();
    auto l1 = service.get_all();
    for(int i = 0 ; i < l.size() ; i ++ )
        assert(l[i].get_varsta()+1 == l1[i].get_varsta());
    service.intinerire();
}

