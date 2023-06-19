//
// Created by Irimieş Vasile on 6/19/2023.
//

#include "RepoStudenti.h"
#include <fstream>
#include <cstring>
#include <algorithm>
#include "../Errors/Erori.h"

void RepoStudenti::load_from_file() {
    char line[1000];
    std::ifstream fin(nume_fisier);
    while(fin.getline(line,1000)){
        char* param = strtok(line,",");
        int numar_matricol = atoi(param);
        param = strtok(NULL,",");
        string nume = param;
        param = strtok(NULL,",");
        int varsta = atoi(param);
        param = strtok(NULL,",");
        string facultate = param;

        Student student{numar_matricol,nume, varsta, facultate};
        repo_studenti.push_back(student);
    }
    fin.close();
}

void RepoStudenti::store_to_file() {
    std::sort(repo_studenti.begin(),repo_studenti.end(),[](const Student& s1, const Student& s2){
        return s1.get_varsta() < s2.get_varsta();
    });
    std::ofstream fout(nume_fisier);
    for(const auto& student : repo_studenti)
        fout << student.get_numar_matricol() << "," << student.get_nume() << "," << student.get_varsta() << "," << student.get_facultate() << "\n";
    fout.close();
}

void RepoStudenti::sterge_student_dupa_id_repo(int id) {
    auto it = repo_studenti.begin();
    while(it != repo_studenti.end() && it->get_numar_matricol() != id)
        it++;
    if(it == repo_studenti.end())
        throw RepoError("Student inexistent!\n");
    repo_studenti.erase(it);
    store_to_file();
}

void RepoStudenti::modifica_student_repo(Student student_nou) {
    for(auto& student : repo_studenti)
        if(student.get_numar_matricol() == student_nou.get_numar_matricol()) {
            student.set_varsta(student_nou.get_varsta());
            store_to_file();
            return;
        }
    throw RepoError("Student inexistent!\n");

}

vector<Student> RepoStudenti::get_all() const {
    return repo_studenti;
}

int RepoStudenti::len() const {
    return (int)repo_studenti.size();
}

void RepoStudenti::adauga_student_repo(Student student) {
    for(const auto& st : repo_studenti)
        if(st.get_numar_matricol() == student.get_numar_matricol())
            throw RepoError("Student existent!\n");
    repo_studenti.push_back(student);
    store_to_file();
}
