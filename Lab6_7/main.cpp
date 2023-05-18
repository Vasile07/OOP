#include <iostream>
#include "Repository/RepoFilme.h"
#include "Repository/FileRepoFilme.h"
#include "Validator/Validator.h"
#include "Bussines/ServiceFilme.h"
#include "Presentation/Console.h"
#include "Tests/Teste.h"

using std::cout;

int main() {

    Teste test;
    test.ruleaza_toate_testele();

//    std::cout << "TESTE RULATE CU SUCCES\n";
//
//    FileRepoFilme f_repo{"input.txt"};
//    cout << f_repo.len() << std::endl;
//    for ( auto& film : f_repo.get_all_repo() )
//        cout << film.get_titlu() << std::endl;
//
//    RepoFilme repo;

    FileRepoFilme f_repo{"input.txt"};
    Validator validator;
    ServiceFilme service(f_repo, validator);

//    map<string,vector<Film>>m=service.get_all_filme_dupa_actor();
//    auto it=m.begin();
//    while (it != m.end()){
//        cout << it->first << ' ';
//        for (const auto& film : it->second)
//            cout << film.get_titlu() << ' ';
//        cout << '\n';
//        it++;
//    }

    Console ui(service);
    //ui.ruleaza_ui();
    return 0;
}