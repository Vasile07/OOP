//
// Created by Irimieş Vasile on 6/19/2023.
//

#include "SerivceStudenti.h"

void SerivceStudenti::intinerire() {
    bool varste_valide = true;
    for(auto& student : repo.get_all()) {
        if(student.get_varsta() == 0)
            varste_valide = false;
    }
    if(varste_valide) {
        for (auto &student: repo.get_all()) {
            Student student_nou{student.get_numar_matricol(), student.get_nume(), student.get_varsta() - 1,
                                student.get_facultate()};
            repo.modifica_student_repo(student_nou);
        }
    }
}

void SerivceStudenti::imbatranire() {
    for (auto &student: repo.get_all()) {
        Student student_nou{student.get_numar_matricol(), student.get_nume(), student.get_varsta() + 1,
                            student.get_facultate()};
        repo.modifica_student_repo(student_nou);
    }
}

void SerivceStudenti::sterge_student_dupa_id(int numar_matricol) {
    repo.sterge_student_dupa_id_repo(numar_matricol);
}

vector<Student> SerivceStudenti::get_all() const {
    return repo.get_all();
}

int SerivceStudenti::len() {
    return repo.len();
}
