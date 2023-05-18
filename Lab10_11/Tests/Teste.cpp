//
// Created by Irimieş Vasile on 3/30/2023.
//

#include <cassert>
#include <fstream>
#include "Teste.h"
#include "../Domain/Film.h"
#include "../Repository/RepoFilme.h"
#include "../Repository/FileRepoFilme.h"
#include "../Errors/Erori.h"
#include "../Validator/Validator.h"
#include "../Bussines/ServiceFilme.h"
#include "../Cos_Inchiriere/CosFilme.h"
#include "../Undo/ActiuneUndo.h"

void Teste::ruleaza_toate_testele() {
    ruleaza_teste_domain();
    ruleaza_teste_repo();
    ruleaza_teste_file_repo();
    ruleaza_teste_undo();
    ruleaza_teste_validator();
    ruleaza_teste_cos();
    ruleaza_teste_service();
}

void Teste::ruleaza_teste_domain() {
    ruleaza_teste_creare();
    ruleaza_teste_set();
    ruleaza_teste_eq();
}

void Teste::ruleaza_teste_creare() {
    Film film(id, titlu, gen, an_aparitie, actor_principal);
    assert ( film.get_id() == id );
    assert ( film.get_titlu() == titlu );
    assert ( film.get_gen() == gen );
    assert ( film.get_an_aparitie() == an_aparitie );
    assert ( film.get_actor_principal() == actor_principal );

}

void Teste::ruleaza_teste_set() {
    Film film(id, titlu, gen, an_aparitie, actor_principal);
    film.set_titlu(titlu_nou);
    film.set_gen(gen_nou);
    film.set_an_aparitie(an_aparitie_nou);
    film.set_actor_principal(actor_principal_nou);
    assert ( film.get_id() == id );
    assert ( film.get_titlu() == titlu_nou );
    assert ( film.get_gen() == gen_nou );
    assert ( film.get_an_aparitie() == an_aparitie_nou );
    assert ( film.get_actor_principal() == actor_principal_nou );
}

void Teste::ruleaza_teste_eq() {
    Film f1(id, titlu, gen, an_aparitie, actor_principal);
    Film f2(id, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    assert ( f1 == f2 );
}

void Teste::ruleaza_teste_repo() {
    ruleaza_teste_adauga_repo();
    ruleaza_teste_modifica_repo();
    ruleaza_teste_cauta_repo();
    ruleaza_teste_get_all_repo();
    ruleaza_teste_sterge_repo();
}

void Teste::ruleaza_teste_adauga_repo() {
    RepoFilme repo = RepoFilme();
    assert ( repo.len() == 0 );
    Film film(id, titlu, gen, an_aparitie, actor_principal);
    repo.adauga_film_repo(film);
    assert ( repo.len() == 1) ;
    try {
        repo.adauga_film_repo(film);
    }catch( RepoError& re){
        assert( re.get_message() == "Film existent!\n");
    }
}

void Teste::ruleaza_teste_modifica_repo() {
    RepoFilme repo = RepoFilme();
    Film film(id, titlu, gen, an_aparitie, actor_principal);
    repo.adauga_film_repo(film);

    Film film_nou(id, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    repo.modifica_film_repo(film_nou);
    Film film_gasit = repo.cauta_film_dupa_id_repo(id);
    assert ( film_gasit.get_id() == id );
    assert ( film_gasit.get_titlu() == titlu_nou );
    assert ( film_gasit.get_gen() == gen_nou );
    assert ( film_gasit.get_an_aparitie() == an_aparitie_nou );
    assert ( film_gasit.get_actor_principal() == actor_principal_nou );

    try{
        Film film_inexistent(999, titlu, gen, an_aparitie, actor_principal);
        repo.modifica_film_repo(film_inexistent);
    }catch (RepoError& re){
        assert(re.get_message() == "Film inexistent!\n");
    }
}

void Teste::ruleaza_teste_cauta_repo() {
    RepoFilme repo = RepoFilme();
    Film film(id, titlu, gen, an_aparitie, actor_principal);
    repo.adauga_film_repo(film);
    assert(repo.cauta_film_dupa_id_repo(id) == film);
    try{
        repo.cauta_film_dupa_id_repo(999);
    }catch (RepoError& re){
        assert(re.get_message() == "Film inexistent!\n");
    }
}

void Teste::ruleaza_teste_get_all_repo() {
    RepoFilme repo = RepoFilme();
    Film film(id, titlu, gen, an_aparitie, actor_principal);
    Film film_nou(id + 1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    repo.adauga_film_repo(film);
    repo.adauga_film_repo(film_nou);

    const vector <Film>& lista_filme = repo.get_all_repo();
    assert ( lista_filme[0] == film && lista_filme[1] == film_nou );

}

void Teste::ruleaza_teste_sterge_repo() {
    RepoFilme repo = RepoFilme();
    Film film(id, titlu, gen, an_aparitie, actor_principal);
    Film film_nou(id+1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    repo.adauga_film_repo(film);
    repo.adauga_film_repo(film_nou);
    repo.sterge_film_dupa_id_repo(id);
    assert(repo.len() == 1);
    try{
        repo.sterge_film_dupa_id_repo(id);
    }catch (RepoError& re){
        assert(re.get_message() == "Film inexistent!\n");
    }
}

void Teste::ruleaza_teste_validator() {
    Film film(id, titlu, gen, an_aparitie, actor_principal);
    Film film_invalid(id_invalid, titlu_invalid, gen_invalid, an_aparitie_invalid, actor_principal_invalid);
    Validator validator;
    assert(validator.valideaza(film));
    try{
        validator.valideaza(film_invalid);
    }catch (ValidationError& ve){
        assert(ve.get_message() == "Id invalid!\nTitlu invalid!\nGen invalid!\nActor principal invalid!\nAn aparitie invalid!\n");
    }

}

void Teste::ruleaza_teste_service() {
    ruleaza_teste_adauga_service();
    ruleaza_teste_cauta_service();
    ruleaza_teste_modifica_service();
    ruleaza_teste_sterge_service();
    ruleaza_teste_get_all_service();
    ruleaza_teste_sort();
    ruleaza_teste_filtru();
    ruleaza_teste_comparator();
    ruleaza_teste_adauga_cos_service();
    ruleaza_teste_goleste_cos_service();
    ruleaza_teste_genereaza_cos_service();
    ruleaza_teste_get_cos_service();
    ruleaza_teste_export_cos_sevice();
    ruleaza_teste_undo_service();
}

void Teste::ruleaza_teste_adauga_service() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme lista(repo, validator);
    assert(lista.len() == 0);
    lista.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    assert(lista.len() == 1);

    try{
        lista.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    }catch (RepoError& re){
        assert ( re.get_message() == "Film existent!\n" );
    }

    try{
        lista.adauga_film_service(id_invalid, titlu_invalid, gen_invalid, an_aparitie_invalid, actor_principal_invalid);
    }catch (ValidationError& ve){
        assert( ve.get_message() == "Id invalid!\nTitlu invalid!\nGen invalid!\nActor principal invalid!\nAn aparitie invalid!\n");
    }

}

void Teste::ruleaza_teste_modifica_service() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme lista(repo, validator);
    assert(lista.len() == 0);
    lista.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    assert(lista.len() == 1);
    lista.modifica_film_service(id, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    Film film = lista.cauta_film_dupa_id_service(id);
    assert ( film.get_id() == id );
    assert ( film.get_titlu() == titlu_nou );
    assert ( film.get_gen() == gen_nou );
    assert ( film.get_an_aparitie() == an_aparitie_nou );
    assert ( film.get_actor_principal() == actor_principal_nou );

    try{
        lista.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    }catch (RepoError& re){
        assert ( re.get_message() == "Film existent!\n" );
    }

    try{
        lista.adauga_film_service(id, titlu_invalid, gen_invalid, an_aparitie_invalid, actor_principal_invalid);
    }catch (ValidationError& ve){
        assert( ve.get_message() == "Titlu invalid!\nGen invalid!\nActor principal invalid!\nAn aparitie invalid!\n");
    }
}

void Teste::ruleaza_teste_cauta_service() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme lista(repo, validator);
    assert(lista.len() == 0);
    lista.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    assert(lista.len() == 1);
    Film film = lista.cauta_film_dupa_id_service(id);
    assert ( film.get_id() == id );
    assert ( film.get_titlu() == titlu );
    assert ( film.get_gen() == gen );
    assert ( film.get_an_aparitie() == an_aparitie );
    assert ( film.get_actor_principal() == actor_principal );

    try{
        lista.cauta_film_dupa_id_service(8);
    }catch (RepoError& re){
        assert(re.get_message() == "Film inexistent!\n");
    }

}

void Teste::ruleaza_teste_get_all_service() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme lista(repo, validator);
    assert(lista.len() == 0);
    lista.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    assert(lista.len() == 1);
    Film film(id, titlu, gen, an_aparitie, actor_principal);
    const vector <Film>& v = lista.get_all_service();
    assert(v[0] == film);
}

void Teste::ruleaza_teste_sterge_service() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme lista(repo, validator);
    assert(lista.len() == 0);
    lista.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    assert(lista.len() == 1);
    lista.sterge_dupa_id_service(id);
    assert(lista.len() == 0);
    try{
        lista.sterge_dupa_id_service(id);
    }catch (RepoError& re){
        assert(re.get_message() == "Film inexistent!\n");
    }
}

void Teste::ruleaza_teste_sort() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme lista(repo, validator);
    Film film1(id, titlu, gen, an_aparitie, actor_principal);
    Film film2(id+1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    lista.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    lista.adauga_film_service(id+1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);

    lista.sortare("titlu");
    const vector <Film>& lista_sortata1 = lista.get_all_service();
    assert(lista_sortata1[0] == film2);
    assert(lista_sortata1[1] == film1);

    lista.sortare("gen");
    const vector <Film>& lista_sortata2 = lista.get_all_service();
    assert(lista_sortata2[0] == film1);
    assert(lista_sortata2[1] == film2);

    lista.sortare("an_aparitie");
    const vector <Film>& lista_sortata3 = lista.get_all_service();
    assert(lista_sortata3[0] == film1);
    assert(lista_sortata3[1] == film2);

    lista.sortare("actor_principal");
    const vector <Film>& lista_sortata4 = lista.get_all_service();
    assert(lista_sortata4[0] == film1);
    assert(lista_sortata4[1] == film2);

}

void Teste::ruleaza_teste_filtru() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme lista(repo, validator);
    Film film1(id, titlu, gen, an_aparitie, actor_principal);
    Film film2(id+1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    lista.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    lista.adauga_film_service(id+1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);

    vector <Film> v;
    v = lista.filtrare_dupa_an(an_aparitie);
    assert(v[0] == film1 && v.size() == 1);

    v = lista.filtrare_dupa_titlu(titlu_nou);
    assert(v[0] == film2 && v.size() == 1);

}

void Teste::ruleaza_teste_comparator() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme lista(repo, validator);
    Film film1(id, titlu, gen, an_aparitie, actor_principal);
    Film film2(id+1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);

    assert(lista.comparator(film1, film2, "titlu") == false);
    assert(lista.comparator(film2, film1, "titlu") == true);
    assert(lista.comparator(film1, film2, "gen") == true);
    assert(lista.comparator(film2, film1, "gen") == false);
    assert(lista.comparator(film1, film2, "an_aparitie") == true);
    assert(lista.comparator(film2, film1, "an_aparitie") == false);
    assert(lista.comparator(film1, film2, "actor_principal") == true);
    assert(lista.comparator(film2, film1, "actor_principal") == false);
    assert(lista.comparator(film2, film1, "") == false);
}

void Teste::ruleaza_teste_cos() {
    ruleaza_test_adauga_cos();
    ruleaza_test_goleste_cos();
    ruleaza_generaza_cos();
    ruleaza_get_all_cos();
}

void Teste::ruleaza_test_adauga_cos() {
    CosFilme cos;
    Film film{id, titlu, gen, an_aparitie, actor_principal};
    assert( cos.size() == 0 );
    cos.adauga_cos(film);
    assert( cos.size() == 1 );
}

void Teste::ruleaza_test_goleste_cos() {
    CosFilme cos;
    Film film{id, titlu, gen, an_aparitie, actor_principal};
    assert( cos.size() == 0 );
    cos.adauga_cos(film);
    assert( cos.size() == 1 );
    cos.goleste_cos();
    assert( cos.size() == 0 );
}

void Teste::ruleaza_generaza_cos() {
    CosFilme cos;
    Film film{id, titlu, gen, an_aparitie, actor_principal};
    vector <Film> filme;
    filme.push_back(film);
    assert( cos.size() == 0);
    cos.genereaza_cos(3, filme);
    assert( cos.size() == 3);
    const vector<Film>& all_cos = cos.get_all_cos();
    assert( all_cos[0] == film && all_cos[1] == film && all_cos[2] == film );
}

void Teste::ruleaza_get_all_cos() {
    CosFilme cos;
    Film film1{id, titlu, gen, an_aparitie, actor_principal};
    Film film2{id+1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou};
    cos.adauga_cos(film1);
    cos.adauga_cos(film2);
    const vector<Film>& all_cos = cos.get_all_cos();
    assert( all_cos[0] == film1 && all_cos[1] == film2);
}

void Teste::ruleaza_teste_adauga_cos_service() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme service(repo, validator);
    service.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    service.adauga_film_service(id+1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    assert( service.size_cos() == 0 );
    service.adauga_cos_service(titlu);
    assert( service.size_cos() == 1 );
}

void Teste::ruleaza_teste_goleste_cos_service() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme service(repo, validator);
    service.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    service.adauga_film_service(id+1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    assert( service.size_cos() == 0 );
    service.adauga_cos_service(titlu);
    service.adauga_cos_service(titlu_nou);
    assert( service.size_cos() == 2 );
    service.goleste_cos_service();
    assert( service.size_cos() == 0 );
}

void Teste::ruleaza_teste_genereaza_cos_service() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme service(repo, validator);
    service.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    Film film{id, titlu, gen, an_aparitie, actor_principal};
    service.genereaza_cos_service(4);
    assert( service.size_cos() == 4 );
    auto all_cos = service.get_cos();
    for ( auto& film_cos : all_cos )
        assert( film_cos == film );
}

void Teste::ruleaza_teste_get_cos_service() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme service(repo, validator);
    service.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    service.adauga_film_service(id+1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    Film film1{id, titlu, gen, an_aparitie, actor_principal};
    Film film2{id+1, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou};
    service.adauga_cos_service(titlu);
    service.adauga_cos_service(titlu_nou);
    auto all_cos = service.get_cos();
    assert( all_cos[0] == film1 && all_cos[1] == film2 );

}

void Teste::ruleaza_teste_export_cos_sevice() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme service(repo, validator);
    service.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    Film film1{id, titlu, gen, an_aparitie, actor_principal};
    string film_string = std::to_string(id) + "," + titlu + "," + gen + "," + std::to_string(an_aparitie) + "," + actor_principal;
    service.adauga_cos_service(titlu);
    service.export_cos_service("test_export");
    std::ifstream fin("test_export");
    char linie_char[1001];
    fin.getline(linie_char, 1001);
    string linie = linie_char;
    assert( linie == film_string );
    fin.close();
}

void Teste::ruleaza_teste_file_repo() {
    ruleaza_teste_load_from_file_file_repo();
    ruleaza_teste_adauga_file_repo();
    ruleaza_teste_modifica_file_repo();
    ruleaza_teste_sterge_file_repo();
}

void Teste::ruleaza_teste_load_from_file_file_repo() {
    FileRepoFilme f_repo{"input_test.txt"};
    assert( f_repo.len() == 2 );
}

void Teste::ruleaza_teste_adauga_file_repo() {
    FileRepoFilme f_repo{"input_test.txt"};
    assert( f_repo.len() == 2 );
    Film film{id*5, titlu, gen, an_aparitie, actor_principal};
    f_repo.adauga_film_repo(film);
    assert( f_repo.len() == 3 );
    try{
        f_repo.adauga_film_repo(film);
        assert(false);
    }catch( RepoError& re ) {
        assert(re.get_message() == "Film existent!\n");
        f_repo.sterge_film_dupa_id_repo(id*5);
    }

}

void Teste::ruleaza_teste_sterge_file_repo() {
    FileRepoFilme f_repo{"input_test.txt"};
    assert( f_repo.len() == 2 );
    Film film{id*5, titlu, gen, an_aparitie, actor_principal};
    f_repo.adauga_film_repo(film);
    assert( f_repo.len() == 3 );
    f_repo.sterge_film_dupa_id_repo(id*5);
    assert( f_repo.len() == 2 );
    try{
        f_repo.sterge_film_dupa_id_repo(id*5);
    }catch ( RepoError& re ){
        assert ( re.get_message() == "Film inexistent!\n");
    }
}

void Teste::ruleaza_teste_modifica_file_repo() {
    FileRepoFilme f_repo{"input_test.txt"};
    assert( f_repo.len() == 2 );
    Film film{id*5, titlu, gen, an_aparitie, actor_principal};
    f_repo.adauga_film_repo(film);
    Film film_nou{id*5, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou};
    f_repo.modifica_film_repo(film_nou);
    auto film_gasit = f_repo.cauta_film_dupa_id_repo(5*id);
    assert( film_gasit.get_id() == film_nou.get_id() );
    assert( film_gasit.get_titlu() == film_nou.get_titlu() );
    assert( film_gasit.get_gen() == film_nou.get_gen() );
    assert( film_gasit.get_an_aparitie() == film_nou.get_an_aparitie() );
    assert( film_gasit.get_actor_principal() == film_nou.get_actor_principal() );
    f_repo.sterge_film_dupa_id_repo(5*id);
}

void Teste::ruleaza_teste_undo() {
    ruleaza_teste_adauga_undo();
    ruleaza_teste_modifica_undo();
    ruleaza_teste_sterge_undo();
}

void Teste::ruleaza_teste_adauga_undo() {
    RepoFilme repo;
    Film film{id, titlu, gen, an_aparitie, actor_principal};
    UndoAdauga undo(repo, film);
    repo.adauga_film_repo(film);
    assert(repo.len() == 1);
    undo.doUndo();
    assert(repo.len() == 0);
}

void Teste::ruleaza_teste_sterge_undo() {
    RepoFilme repo;
    Film film{id, titlu, gen, an_aparitie, actor_principal};
    UndoSterge undo(repo, film);
    repo.adauga_film_repo(film);
    assert(repo.len() == 1);
    repo.sterge_film_dupa_id_repo(id);
    assert(repo.len() == 0);
    undo.doUndo();
    assert(repo.len() == 1);
}

void Teste::ruleaza_teste_modifica_undo() {
    RepoFilme repo;
    Film film{id, titlu, gen, an_aparitie, actor_principal};
    Film film_nou{id, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou};
    UndoModifica undo(repo, film);
    repo.adauga_film_repo(film);
    assert(repo.len() == 1);
    repo.modifica_film_repo(film_nou);
    auto& film_gasit = repo.cauta_film_dupa_id_repo(id);

    assert( film_gasit.get_id() == film_nou.get_id() );
    assert( film_gasit.get_titlu() == film_nou.get_titlu() );
    assert( film_gasit.get_gen() == film_nou.get_gen() );
    assert( film_gasit.get_an_aparitie() == film_nou.get_an_aparitie() );
    assert( film_gasit.get_actor_principal() == film_nou.get_actor_principal() );

    undo.doUndo();
    auto& film_gasit_dupa_undo = repo.cauta_film_dupa_id_repo(id);
    assert( film_gasit_dupa_undo.get_id() == film.get_id() );
    assert( film_gasit_dupa_undo.get_titlu() == film.get_titlu() );
    assert( film_gasit_dupa_undo.get_gen() == film.get_gen() );
    assert( film_gasit_dupa_undo.get_an_aparitie() == film.get_an_aparitie() );
    assert( film_gasit_dupa_undo.get_actor_principal() == film.get_actor_principal() );

}

void Teste::ruleaza_teste_undo_service() {
    RepoFilme repo;
    Validator validator;
    ServiceFilme service(repo, validator);
    Film film{id, titlu, gen, an_aparitie, actor_principal};
    service.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
    service.modifica_film_service(id, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
    service.sterge_dupa_id_service(id);
    assert(service.len() == 0);

    service.undo();
    assert(service.len() == 1);
    const Film& film_gasit = service.cauta_film_dupa_id_service(id);
    assert( film_gasit.get_id() == id );
    assert( film_gasit.get_titlu() == titlu_nou );
    assert( film_gasit.get_gen() == gen_nou );
    assert( film_gasit.get_an_aparitie() == an_aparitie_nou );
    assert( film_gasit.get_actor_principal() == actor_principal_nou );

    service.undo();
    assert(service.len() == 1);
    const Film& film_gasit2 = service.cauta_film_dupa_id_service(id);
    assert( film_gasit2.get_id() == id );
    assert( film_gasit2.get_titlu() == titlu );
    assert( film_gasit2.get_gen() == gen );
    assert( film_gasit2.get_an_aparitie() == an_aparitie );
    assert( film_gasit2.get_actor_principal() == actor_principal );

    service.undo();
    assert( service.len() == 0 );

    try{
        service.undo();
        assert(false);
    }catch (ValidationError& ve){
        assert(ve.get_message() == "Undo imposibil!\n");
    }

    try{
        service.adauga_film_service(id_invalid, titlu_invalid, gen_invalid, an_aparitie_invalid, actor_principal_invalid);
        assert(false);
    }catch (ValidationError& ve){
        try{
            service.undo();
            assert(false);
        }catch (ValidationError& ve1){
            assert(ve1.get_message() == "Undo imposibil!\n");
        }
    }


}


