//
// Created by Irimieş Vasile on 4/1/2023.
//

#include "Console.h"
#include "../Errors/Erori.h"
#include <iostream>
using std::cout;
using std::cin;

int Console::ruleaza_ui() {
    string comanda;
    while(true){


        cout << "Numar de filme in cos: " << lista_filme.size_cos() << '\n';
        cout << "Introduceti comanda ( Pentru a vedea lista de comenzi tastati help )\n>>>";
        cin >> comanda;

        switch (decodificator(comanda)) {
            case 0:
                help();
                break;
            case 1:
                afiseaza_ui();
                break;
            case 2:
                adauga_ui();
                break;
            case 3:
                modifica_ui();
                break;
            case 4:
                sterge_ui();
                break;
            case 5:
                cauta_ui();
                break;
            case 6:
                filtrare_ui();
                break;
            case 7:
                sortare_ui();
                break;
            case 8:
                return 0;
            case 9:
                adauga_cos_ui();
                break;
            case 10:
                goleste_cos_ui();
                break;
            case 11:
                genereaza_cos_ui();
                break;
            case 12:
                afiseaza_cos_ui();
                break;
            case 13:
                export_cos_ui();
                break;
            case 14:
                undo_ui();
                break;
            case 15:
                see_map();
                break;
            default:
                cout << "Comanda invalida!\n";
                continue;
        }

    }
}

void Console::help() {
    cout << "COMENZI:\n\n";
    cout << "help:\n";                  // 0
    cout << "afiseaza\n";               // 1
    cout << "adauga\n";                 // 2
    cout << "modifica\n";               // 3
    cout << "sterge\n";                 // 4
    cout << "cauta\n";                  // 5
    cout << "filtrare\n";               // 6
    cout << "sortare\n";                // 7
    cout << "exit\n";                   // 8
    cout << "adauga_cos\n";             // 9
    cout << "goleste_cos\n";            // 10
    cout << "genereaza_cos\n";          // 11
    cout << "afiseaza_cos\n";           // 12
    cout << "export\n";                 // 13
    cout << "undo\n";                   // 14
    cout << "map\n";                    // 15
    cout << '\n';
}

int Console::decodificator(string comanda) {
    if ( comanda == "help" )        return 0;
    if ( comanda == "afiseaza" )    return 1;
    if ( comanda == "adauga" )      return 2;
    if ( comanda == "modifica" )    return 3;
    if ( comanda == "sterge" )      return 4;
    if ( comanda == "cauta" )       return 5;
    if ( comanda == "filtrare" )    return 6;
    if ( comanda == "sortare" )     return 7;
    if ( comanda == "exit" )        return 8;
    if ( comanda == "adauga_cos" )        return 9;
    if ( comanda == "goleste_cos" )        return 10;
    if ( comanda == "genereaza_cos" )        return 11;
    if ( comanda == "afiseaza_cos" )        return 12;
    if ( comanda == "export_cos" )        return 13;
    if ( comanda == "undo" )        return 14;
    if ( comanda == "map" )             return 15;
    return -1;
}

void Console::afiseaza_ui() {
    cout << "Lista de filme:\n\n";
    for ( auto & i : lista_filme.get_all_service()) {
        cout << "ID: " << i.get_id() << '\n';
        cout << "Titlu: " << i.get_titlu() << '\n';
        cout << "Gen: " << i.get_gen() << '\n';
        cout << "An aparitie: " << i.get_an_aparitie() << '\n';
        cout << "Actor principal: " << i.get_actor_principal() << '\n';
        cout << '\n';
    }
}

void Console::adauga_ui() {
    cout << "Introduceti id-ul, titlul, genul, anul aparitiei si actorul principal\n>>>";
    int id, an_aparitie;
    string titlu, gen, actor_principal;
    cin >> id >> titlu >> gen >> an_aparitie >> actor_principal;

    try{
        lista_filme.adauga_film_service(id, titlu, gen, an_aparitie, actor_principal);
        cout << "Film adaugat cu succes!\n";
    }catch (RepoError& re){
        cout << re.get_message() << '\n';
    }catch (ValidationError& ve){
        cout << ve.get_message() << '\n';
    }

}

void Console::sterge_ui() {
    cout << "Introduceti id-ul filmului\n>>>";
    int id;
    cin >> id;
    try{
        lista_filme.sterge_dupa_id_service(id);
        cout << "Film sters cu succes!\n";
    }catch (RepoError& re){
        cout << re.get_message() << '\n';
    }catch (ValidationError& ve){
        cout << ve.get_message() << '\n';
    }
}

void Console::modifica_ui() {
    cout << "Introduceti id-ul, titlul_nou, genul_nou, anul aparitiei nou si actorul principal nou\n>>>";
    int id, an_aparitie_nou;
    string titlu_nou, gen_nou, actor_principal_nou;
    cin >> id >> titlu_nou >> gen_nou >> an_aparitie_nou >> actor_principal_nou;

    try{
        lista_filme.modifica_film_service(id, titlu_nou, gen_nou, an_aparitie_nou, actor_principal_nou);
        cout << "Film modificat cu succes!\n";
    }catch (RepoError& re){
        cout << re.get_message() << '\n';
    }catch (ValidationError& ve){
        cout << ve.get_message() << '\n';
    }
}

void Console::cauta_ui() {
    cout << "Introduceti id-ul filmului cautat\n>>>";
    int id;
    cin >> id;

    try{
        const Film& film = lista_filme.cauta_film_dupa_id_service(id);
        cout << "Filmul cautat:\n";
        cout << "ID: " << film.get_id() << '\n';
        cout << "Titlu: " << film.get_titlu() << '\n';
        cout << "Gen: " << film.get_gen() << '\n';
        cout << "An aparitie: " << film.get_an_aparitie() << '\n';
        cout << "Actor principal: " << film.get_actor_principal() << '\n';
        cout << '\n';
    }catch (RepoError& re){
        cout << re.get_message() << '\n';
    }catch (ValidationError& ve){
        cout << ve.get_message() << '\n';
    }
}

void Console::filtrare_ui() {
    string criteriu;
    cout << "Introduceti criteriul de sortare (titlu/an_aparitie)\n>>>";
    cin >> criteriu;
    if ( criteriu != "titlu" && criteriu != "an_aparitie" ) {
        cout << "Criteriu invalid!\n";
    }
    else {
        if ( criteriu == "titlu" ){
            string titlu;
            cout << "Intruduceti titlul: >" ; cin >> titlu;
            const vector <Film>& lista = lista_filme.filtrare_dupa_titlu(titlu);
            for (const auto & film : lista) {
                cout << "ID: " << film.get_id() << '\n';
                cout << "Titlu: " << film.get_titlu() << '\n';
                cout << "Gen: " << film.get_gen() << '\n';
                cout << "An aparitie: " << film.get_an_aparitie() << '\n';
                cout << "Actor principal: " << film.get_actor_principal() << '\n';
                cout << '\n';
            }
        }
        else{
            int an_aparitie;
            cout << "Intruduceti anul aparitiei: >" ; cin >> an_aparitie;
            const vector <Film>& lista = lista_filme.filtrare_dupa_an(an_aparitie);
            for (const auto & film : lista) {
                cout << "ID: " << film.get_id() << '\n';
                cout << "Titlu: " << film.get_titlu() << '\n';
                cout << "Gen: " << film.get_gen() << '\n';
                cout << "An aparitie: " << film.get_an_aparitie() << '\n';
                cout << "Actor principal: " << film.get_actor_principal() << '\n';
                cout << '\n';
            }
        }
        cout << "Lista de filme dupa filtrare:\n\n";

    }
}

void Console::sortare_ui() {
    string criteriu;
    cout << "Introduceti criteriul de sortare (titlu, actor_principal, an_aparitie, gen)\n>>";
    cin >> criteriu;
    lista_filme.sortare(criteriu);
}

void Console::adauga_cos_ui() {
    string titlu;
    cout << "Introduceti titlul pe care il doriti\n>>";
    cin >> titlu;
    lista_filme.adauga_cos_service(titlu);
}


void Console::afiseaza_cos_ui() {
    cout << "Cosul:\n\n";
    for ( auto& film : lista_filme.get_cos()) {
        cout << "ID: " << film.get_id() << '\n';
        cout << "Titlu: " << film.get_titlu() << '\n';
        cout << "Gen: " << film.get_gen() << '\n';
        cout << "An aparitie: " << film.get_an_aparitie() << '\n';
        cout << "Actor principal: " << film.get_actor_principal() << '\n';
        cout << '\n';
    }
}

void Console::goleste_cos_ui() {
    lista_filme.goleste_cos_service();
}

void Console::genereaza_cos_ui() {
    int numar_filme;
    cout << "Introduceti cate filme doriti sa fie adaugate\n>>";
    cin >> numar_filme;
    lista_filme.genereaza_cos_service(numar_filme);
}

void Console::export_cos_ui() {
    string fisier;
    cout << "Introduceti numele fisierului in care doriti sa se exporte cosul\n>>";
    cin >> fisier;
    lista_filme.export_cos_service(fisier);
}

void Console::undo_ui() {
    try{
        lista_filme.undo();
        cout << "Undo efectuat cu succes!\n";
    }catch (ValidationError& ve){
        cout << ve.get_message() << '\n';
    }
}

void Console::see_map() {
    auto m = lista_filme.get_all_filme_dupa_actor();
    auto it = m.begin();
    while ( it != m.end() ) {
        cout << "Actor: " << it->first << std::endl;
        for (auto &film: it->second) {
            cout << film.get_titlu() << '\n';
        }
        cout << '\n';
        it++;
    }
}




